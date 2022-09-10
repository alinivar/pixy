
#include <pixy.h>

#include "wgl_context.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif

#include <Windows.h>

enum {
    /*! Determines if the window is closed.
     */
    CLOSE_FLAG      = 1 << 0,
};

struct PixyWindow {
    /*! Window handle.
     */
    HWND Hwnd;
    /*! Window device context.
     */
    HDC Hdc;
    /*! OpenGL rendering context.
     */
    HGLRC Hglrc;
    /*! The user data pointer.
     */
    void* UserData;
    /*! The window size callback. 
     *  Gets called when the window gets resized.
     */
    PixyWindowSizeCallback SizeCallback;
    /*! Set if the window is closed.
     */
    int Closed : 1;
};

static LRESULT CALLBACK wndproc(HWND Hwnd, UINT Msg, WPARAM Wparam, LPARAM Lparam);

PIXYAPI PixyWindow* pixyNewWindow(PixyWindowConfig cfg) {
    PixyWindow* win = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*win));
    if (!win) {
        return NULL;
    }

    /*! Window creation
     */
    {
        const HICON icon = LoadIcon(NULL, IDI_APPLICATION);
        const HCURSOR cursor = LoadCursor(NULL, IDC_ARROW);

        const HINSTANCE hinstance = GetModuleHandleA(NULL);

        const WNDCLASSEXA wndcls    = {
            .cbSize                 = sizeof(wndcls),
            .style                  = CS_VREDRAW | CS_HREDRAW | CS_OWNDC,
            .lpfnWndProc            = wndproc,
            .hIcon                  = icon,
            .hIconSm                = icon,
            .hCursor                = cursor,
            .hInstance              = hinstance,
            .lpszClassName          = cfg.Title,
        };

        if (0 == RegisterClassExA(&wndcls)) {
            HeapFree(GetProcessHeap(), 0, win);
            return NULL;
        }

        if (NULL == CreateWindowExA(0, wndcls.lpszClassName, cfg.Title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, cfg.Width, cfg.Height, NULL, NULL, hinstance, win)) {
            HeapFree(GetProcessHeap(), 0, win);
            return NULL;
        }

        const HDC prevHDC = wglGetCurrentDC();
        const HGLRC prevHGLRC = wglGetCurrentContext();

        wglMakeCurrent(win->Hdc, win->Hglrc);

        /* Process window options */

        /* cfg.VSync */
        if (cfg.VSync) {
            _pixySwapIntervalWGL(PIXY_TRUE);
        }
        else {
            _pixySwapIntervalWGL(PIXY_FALSE);
        }

        /* cfg.Visible */
        if (cfg.Visible) {
            ShowWindow(win->Hwnd, SW_SHOW);
        }
        else {
            ShowWindow(win->Hwnd, SW_HIDE);
        }

        wglMakeCurrent(prevHDC, prevHGLRC);
    }

    return win;
}

PIXYAPI void pixySwapInterval(int interval) {
    wglSwapIntervalEXT(interval);
}

PIXYAPI void pixySetUser(PixyWindow* win, void* userData) {
    win->UserData = userData;
}

PIXYAPI void pixySetClosed(PixyWindow* win, int value) {
    win->Closed = value;
}

PIXYAPI void* pixyGetUser(PixyWindow* win) {
    return win->UserData;
}

PIXYAPI void pixyShowWindow(PixyWindow* win) {
    ShowWindow(win->Hwnd, SW_SHOW);
}

PIXYAPI void pixyHideWindow(PixyWindow* win) {
    ShowWindow(win->Hwnd, SW_HIDE);
}

PIXYAPI void pixySetWindowSizeCallback(PixyWindow* win, PixyWindowSizeCallback callback) {
    win->SizeCallback = callback;
}

PIXYAPI void pixyMakeCurrent(PixyWindow* win) {
    if (!win) {
        wglMakeCurrent(NULL, NULL);
    }
    else {
        wglMakeCurrent(win->Hdc, win->Hglrc);
    }

}

PIXYAPI int pixyWindowClosed(PixyWindow* win) {
    if (!win) return PIXY_TRUE;

    return win->Closed;
}

PIXYAPI void pixyPollEvents() {
    static MSG msg = { 0 };

    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
        DispatchMessageA(&msg);
    }
}

PIXYAPI void pixySwapBuffers(PixyWindow* win) {
    if (!win) return;

    SwapBuffers(win->Hdc);
}

PIXYAPI void pixyDeleteWindow(PixyWindow* win) {
    if (!win) return;

    win->Closed = PIXY_TRUE;

    _pixyDeleteContextWGL(win->Hglrc);

    ReleaseDC(win->Hwnd, win->Hdc);

    DestroyWindow(win->Hwnd);
}

static LRESULT CALLBACK wndproc(HWND Hwnd, UINT Msg, WPARAM Wparam, LPARAM Lparam) {
    PixyWindow* win = (PixyWindow*)GetWindowLongPtrA(Hwnd, GWLP_USERDATA);

    /*! Initializes the window.
     */
    if (Msg == WM_CREATE) {
        const CREATESTRUCT* cs = (const CREATESTRUCT*)Lparam;

        win = (PixyWindow*)cs->lpCreateParams;

        win->Hwnd = Hwnd;
        win->Hdc = GetDC(Hwnd);

        static const int pixAttribs[] = {
            WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
            WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
            WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
            WGL_PIXEL_TYPE_ARB,     WGL_TYPE_RGBA_ARB,
            WGL_COLOR_BITS_ARB,     32,
            WGL_DEPTH_BITS_ARB,     24,
            WGL_STENCIL_BITS_ARB,   8,
            0,
        };

        static const int ctxAttribs[] = {
            WGL_CONTEXT_MAJOR_VERSION_ARB,  4,
            WGL_CONTEXT_MINOR_VERSION_ARB,  6,
            WGL_CONTEXT_PROFILE_MASK_ARB,   WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            WGL_CONTEXT_FLAGS_ARB,          WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
            0,
        };

        win->Hglrc = _pixyNewContextWGL(win->Hdc, pixAttribs, ctxAttribs);

        win->Closed = PIXY_FALSE;

        SetWindowLongPtrA(Hwnd, GWLP_USERDATA, (LONG_PTR)win);

        return 0;
    }
    /*! Resizes the window.
     */
    else if (Msg == WM_SIZE) {
        if (win->SizeCallback) {
            RECT r;
            GetClientRect(Hwnd, &r);
            
            const int width = r.right - r.left;
            const int height = r.bottom - r.top;

            win->SizeCallback(win, width, height);
        }

        return 0;
    }
    /*! Closes the window.
     */
    else if (Msg == WM_CLOSE) {
        win->Closed = PIXY_TRUE;

        return 0;
    }

    return DefWindowProcA(Hwnd, Msg, Wparam, Lparam);
}
