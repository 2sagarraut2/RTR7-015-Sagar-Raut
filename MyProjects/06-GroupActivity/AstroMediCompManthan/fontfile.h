#pragma once

// Header Files
#include <windows.h>
#include <gl/GL.h>

// Font rendering function declarations
GLvoid BuildFont(HDC hdc, int fontWeight);
GLvoid KillFont(GLvoid);
GLvoid glPrint(const char *fmt, ...);
GLvoid RenderText(const char *text, float x, float y);
