
#include <pixy.h>

#include "wgl_context.h"

#define FAKE_CLASS_NAME "FakeClassName"

int _pixyInitWGL() {
    HWND fakeHWND = NULL;
    HDC fakeHDC = NULL;
    HGLRC fakeHGLRC = NULL;

    HDC prevHDC = NULL;
    HGLRC prevHGLRC = NULL;

    /*! Fake context creation
     */
    {
        const WNDCLASSEXA wndcls    = { 
            .cbSize                 = sizeof(WNDCLASSEXA),
            .lpfnWndProc            = DefWindowProcA,
            .lpszClassName          = FAKE_CLASS_NAME,
        };

        if (0 == RegisterClassExA(&wndcls)) {
            return PIXY_FALSE;
        }

        fakeHWND = CreateWindowExA(0, FAKE_CLASS_NAME, NULL, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL);
        if (!fakeHWND) {
            return PIXY_FALSE;
        }

        fakeHDC = GetDC(fakeHWND);

        int pf = ChoosePixelFormat(fakeHDC, &_pixy_wgl_pfd);
        if (!pf) {
            return PIXY_FALSE;
        }

        SetPixelFormat(fakeHDC, pf, &_pixy_wgl_pfd);

        fakeHGLRC = wglCreateContext(fakeHDC);
        if (!fakeHGLRC) {
            return PIXY_FALSE;
        }

        prevHDC = wglGetCurrentDC();
        prevHGLRC = wglGetCurrentContext();

        wglMakeCurrent(fakeHDC, fakeHGLRC);
    }

    /*! Load WGL functions
     */
    {
        _pixy_wglChoosePixelFormatARB =
            (PFNWGLCHOOSEPIXELFORMATARBPROC       )wglGetProcAddress("wglChoosePixelFormatARB");
        
        _pixy_wglCreateContextAttribsARB =
            (PFNWGLCREATECONTEXTATTRIBSARBPROC    )wglGetProcAddress("wglCreateContextAttribsARB");
        
        _pixy_wglSwapIntervalEXT =
            (PFNWGLSWAPINTERVALEXTPROC            )wglGetProcAddress("wglSwapIntervalEXT");
    }

    /*! Cleanup fake context
     */
    {
        wglMakeCurrent(prevHDC, prevHGLRC);

        wglDeleteContext(fakeHGLRC);

        ReleaseDC(fakeHWND, fakeHDC);

        DestroyWindow(fakeHWND);

        UnregisterClassA(FAKE_CLASS_NAME, NULL);
    }

    return PIXY_TRUE;
}

HGLRC _pixyNewContextWGL(HDC hdc, const int* pixelAttribs, const int* ctxAttribs) {
    if (!hdc) {
        return NULL;
    }

    int pf;
    UINT npf;

    wglChoosePixelFormatARB(hdc, pixelAttribs, NULL, 1, &pf, &npf);
    SetPixelFormat(hdc, pf, &_pixy_wgl_pfd);

    return wglCreateContextAttribsARB(hdc, NULL, ctxAttribs);
}

void _pixySwapIntervalWGL(int interval) {
    wglSwapIntervalEXT(interval);
}

void _pixyDeleteContextWGL(HGLRC ctx) {
    if (!ctx) {
        return;
    }

    if (wglGetCurrentContext() == ctx)
    {
        wglMakeCurrent(NULL, NULL);
    }

    wglDeleteContext(ctx);
}

void _pixyTerminateWGL()
{
    /* er? */
}
 
const PIXELFORMATDESCRIPTOR _pixy_wgl_pfd = {
    sizeof(_pixy_wgl_pfd),
    1,
    PFD_DOUBLEBUFFER | PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL,
    PFD_TYPE_RGBA,
    32,
    0, 0, 0, 0, 0, 0,
    0,
    0,
    0,
    0, 0, 0, 0,
    24,
    8,
    0,
    PFD_MAIN_PLANE,
    0,
    0, 0, 0,
};

PFNWGLCHOOSEPIXELFORMATARBPROC          _pixy_wglChoosePixelFormatARB;
PFNWGLCREATECONTEXTATTRIBSARBPROC       _pixy_wglCreateContextAttribsARB;
PFNWGLSWAPINTERVALEXTPROC               _pixy_wglSwapIntervalEXT;
