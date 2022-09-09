
#ifndef __wgl_context_h__
#define __wgl_context_h__

#include "wgl_ext.h"

int _pixyInitWGL();

HGLRC _pixyNewContextWGL(HDC hdc, const int* pixelAttribs, const int* ctxAttribs);

void _pixyDeleteContextWGL(HGLRC ctx);

void _pixySwapIntervalWGL(int interval);

void _pixyTerminateWGL();

extern const PIXELFORMATDESCRIPTOR          _pixy_wgl_pfd;

extern PFNWGLCHOOSEPIXELFORMATARBPROC       _pixy_wglChoosePixelFormatARB;
extern PFNWGLCREATECONTEXTATTRIBSARBPROC    _pixy_wglCreateContextAttribsARB;
extern PFNWGLSWAPINTERVALEXTPROC            _pixy_wglSwapIntervalEXT;

#define wglChoosePixelFormatARB             _pixy_wglChoosePixelFormatARB
#define wglCreateContextAttribsARB          _pixy_wglCreateContextAttribsARB
#define wglSwapIntervalEXT                  _pixy_wglSwapIntervalEXT

#endif
