#pragma once

// Header Files
#include <stdio.h>
#include <stdarg.h> //for glPrint() variable arguments
#include <string.h>
#include <windows.h>
#include <gl/GL.h>

// link with opengl import library
// #pragma comment(lib, "opengl32.lib")

#include "fontfile.h"

// display lists for the font
static GLuint base;

GLvoid BuildFont(HDC hdc, int fontWeight)
{
	HFONT font;
	HFONT oldfont;
	base = glGenLists(96);
	font = CreateFont(fontWeight,
					  0,
					  0,
					  0,
					  FW_BOLD,
					  FALSE,
					  FALSE,
					  FALSE,
					  ANSI_CHARSET,
					  OUT_TT_PRECIS,
					  CLIP_DEFAULT_PRECIS,
					  ANTIALIASED_QUALITY,
					  FF_DONTCARE | DEFAULT_PITCH,
					  "Algerian");

	oldfont = (HFONT)SelectObject(hdc, font);
	wglUseFontBitmaps(hdc, 32, 96, base);
	SelectObject(hdc, oldfont);
	DeleteObject(font);
}

GLvoid KillFont(GLvoid)
{
	glDeleteLists(base, 96);
}

GLvoid glPrint(const char *fmt, ...) // Custom GL "Print" Routine
{
	char text[256];
	va_list ap;

	if (fmt == NULL)
		return;

	va_start(ap, fmt);
	vsprintf(text, fmt, ap);
	va_end(ap);

	glPushAttrib(GL_LIST_BIT);
	glListBase(base - 32);

	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);
	glPopAttrib();
}

// draws text at screen position x, y (z is fixed at -1)
GLvoid RenderText(const char *text, float x, float y)
{
	glRasterPos3f(x, y, -1.0f);
	glPrint("%s", text);
}
