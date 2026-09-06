// header files
#include <windows.h>
#include <stdio.h>	// For file I/O
#include <stdlib.h> // For exit(0)

// OpenGL related header files
#include <gl\GL.h> // inside include path gl directory inside which GL.h file

#include "OGL.h"

// link with openGL import library
#pragma comment(lib, "opengl32.lib")

// macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

GLfloat moveTriangleVariable = 0.0f;

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
HWND SR_ghwnd = NULL;
HDC SR_ghdc = NULL;	  // graphic card specialist device context handle
HGLRC SR_ghrc = NULL; // rendering conext of opengl graphic library rendering context
BOOL SR_bFullscreen = FALSE;
DWORD SR_dwStyle;
WINDOWPLACEMENT SR_wpPrev;
FILE *SR_gpFile = NULL; // global pointer to file

BOOL SR_bActiveWindow = FALSE;		 // to check whether window is active or in focus
BOOL SR_bEscapeKeyIsPressed = FALSE; // check if escape key is pressed

// Entery point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// function declarations
	int initialise(void); // to initialise things required for rendering
	void render(void);	  // here starts rendering
	void update(void);	  // continues rendering
	void uninitialise(void);

	// variable declarations
	WNDCLASSEX SR_wndclass;
	HWND SR_hwnd = NULL;
	MSG SR_msg;
	TCHAR SR_lpszAppName[] = TEXT("RTR7_SSR"); // TEXT -> MACRO
	BOOL SR_bDone = FALSE;					   // to use in gameloop

	// code
	// create log file
	SR_gpFile = fopen("Log.txt", "w"); // file open -> if does not exists then create | w - write & clean it
	if (SR_gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log file creation failed"), TEXT("Error"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(SR_gpFile, "SSR: Program successfully started.\n\n");
	}

	// WNDCLASSEX structure initialisation
	SR_wndclass.cbSize = sizeof(WNDCLASSEX);
	SR_wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // Class Style, CS_OWNDC - fixed non discardable/purgeable device context
	SR_wndclass.cbClsExtra = 0;
	SR_wndclass.cbWndExtra = 0;
	SR_wndclass.lpfnWndProc = WndProc; // long pointer function
	SR_wndclass.hInstance = hInstance;
	SR_wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);   // handle background
	SR_wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON)); // IDI_APPLICATION MACRO - Identifier Icon application -> LPCTSTR - long pointer to constantly NULL terminated string
	// MAKEINTRESOURCE - make my resource integer equivalent
	// To provide user defined icon we will give hInstance that we created as first parameter

	SR_wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // IDC_ARROW - Indetifier cursor
	// To provide user defined icon we will give hInstance that we created as first parameter

	SR_wndclass.lpszClassName = SR_lpszAppName;
	SR_wndclass.lpszMenuName = NULL;
	SR_wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));

	// Register above WNDCLASS structure
	RegisterClassEx(&SR_wndclass); // return value is atom - immutable string goes to into mater table

	// Centering
	int SR_screenWidth = GetSystemMetrics(SM_CXSCREEN);	 // x of screen - SM - SystemMetrics CX - count of x
	int SR_screenHeight = GetSystemMetrics(SM_CYSCREEN); // y of screen - CY - count of y

	// create the window
	// CreateWindowEX is also there to use when we want give extra styles
	SR_hwnd = CreateWindowEx(WS_EX_APPWINDOW, // Extended window style -> App window -> having top most order of z
							 SR_lpszAppName,
							 TEXT("RTR7-015-Sagar-Raut-MyProjects-01-OpenGL-01-FFP-01-Windows-02-OpenGL-02-GLTriangleWithoutGLUT"),
							 WS_OVERLAPPEDWINDOW   // top window
								 | WS_CLIPCHILDREN // cut all children window
								 | WS_CLIPSIBLINGS // cut all siblings
								 | WS_VISIBLE,
							 SR_screenWidth / 2 - WIN_WIDTH / 2,   // x
							 SR_screenHeight / 2 - WIN_HEIGHT / 2, // y
							 WIN_WIDTH,							   // width
							 WIN_HEIGHT,						   // height
							 NULL,								   // parent process
							 NULL,								   // menu name
							 hInstance,							   // compulsory
							 NULL);								   // creation parameter long ptr void *

	// set global window handle
	SR_ghwnd = SR_hwnd;

	int SR_iResult = initialise();
	if (SR_iResult != 0)
	{
		fprintf(SR_gpFile, "SSR: WinMain(): initialise() failed\n");
		DestroyWindow(SR_hwnd);
		SR_hwnd = NULL;
	}
	else if (SR_iResult == -1)
	{
		fprintf(SR_gpFile, "SSR: initialise(): failed to get device context\n");
		DestroyWindow(SR_hwnd);
		SR_hwnd = NULL;
	}
	else if (SR_iResult == -2)
	{
		fprintf(SR_gpFile, "SSR: initialise(): failed to get pixel format\n");
		DestroyWindow(SR_hwnd);
		SR_hwnd = NULL;
	}
	else if (SR_iResult == -3)
	{
		fprintf(SR_gpFile, "SSR: initialise(): failed to set pixel format\n");
		DestroyWindow(SR_hwnd);
		SR_hwnd = NULL;
	}
	else if (SR_iResult == -4)
	{
		fprintf(SR_gpFile, "SSR: initialise() failed to get rendering context\n");
		DestroyWindow(SR_hwnd);
		SR_hwnd = NULL;
	}
	else if (SR_iResult == -5)
	{
		fprintf(SR_gpFile, "SSR: initialise() failed to switch current context to rendering context\n");
		DestroyWindow(SR_hwnd);
		SR_hwnd = NULL;
	}
	else
	{
		fprintf(SR_gpFile, "SSR: WinMain(): initialise() succeeded\n");
	}

	// show window
	ShowWindow(SR_hwnd, iCmdShow);

	// update the window to paint its background
	UpdateWindow(SR_hwnd);

	SetForegroundWindow(SR_hwnd); // brings window to foreground
	SetFocus(SR_hwnd);			  // set focuns to our window

	// game loop
	while (SR_bDone == FALSE)
	{
		// PM_REMOVE - peek message remove
		if (PeekMessage(&SR_msg, NULL, 0, 0, PM_REMOVE))
		{
			if (SR_msg.message == WM_QUIT)
			{
				SR_bDone = TRUE;
			}
			else
			{
				TranslateMessage(&SR_msg);
				DispatchMessage(&SR_msg);
			}
		}
		else
		{
			if (SR_bActiveWindow == TRUE)
			{
				if (SR_bEscapeKeyIsPressed == TRUE)
				{
					SR_bDone = TRUE;
				}

				// render
				render();
				// update
				update();
			}
		}
	}

	// uninitialise
	uninitialise();

	return ((int)SR_msg.wParam);
}

LRESULT CALLBACK WndProc(HWND SR_hwnd, UINT SR_iMsg, WPARAM wParam, LPARAM lParam)
{
	// local function declarations
	void resize(int, int); // width and height
	void toggleFullscreen(void);
	void uninitialise(void);

	// code
	switch (SR_iMsg)
	{
	case WM_CREATE:
		memset(&SR_wpPrev, 0, sizeof(WINDOWPLACEMENT));
		SR_wpPrev.length = sizeof(WINDOWPLACEMENT);
		break;
	case WM_SETFOCUS:
		SR_bActiveWindow = TRUE;
		break;
	case WM_KILLFOCUS:
		SR_bActiveWindow = FALSE;
		break;
	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			SR_bEscapeKeyIsPressed = TRUE;
			break;
		default:
			break;
		}
		break;
	case WM_CHAR:
		switch (wParam)
		{
		case 'F':
		case 'f':
			if (SR_bFullscreen == FALSE)
			{
				toggleFullscreen();
				SR_bFullscreen = TRUE;
			}
			else
			{
				toggleFullscreen();
				SR_bFullscreen = FALSE;
			}

			break;
		}
		break;
	case WM_CLOSE:
		uninitialise();
		break;
	case WM_TIMER:
		KillTimer(SR_hwnd, 1234);

		// code to move rectangle
		if (moveTriangleVariable <= 2.0f)
		{
			moveTriangleVariable = moveTriangleVariable + 0.02f;
		}
		else if (moveTriangleVariable > 2.0f)
		{
			moveTriangleVariable = -2.0f;
		}
		SetTimer(SR_hwnd, 1234, 5, NULL);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return (DefWindowProc(SR_hwnd, SR_iMsg, wParam, lParam));
}

void toggleFullscreen(void)
{
	// variable declarations
	MONITORINFO SR_mi;

	// code
	if (SR_bFullscreen == FALSE)
	{
		SR_dwStyle = GetWindowLong(SR_ghwnd, GWL_STYLE); // get style of window from long parameter

		if (SR_dwStyle & WS_OVERLAPPEDWINDOW)
		{
			memset(&SR_mi, 0, sizeof(MONITORINFO));
			SR_mi.cbSize = sizeof(MONITORINFO);

			if (GetWindowPlacement(SR_ghwnd, &SR_wpPrev) && GetMonitorInfo(MonitorFromWindow(SR_ghwnd, MONITORINFOF_PRIMARY), &SR_mi))
			{
				SetWindowLong(SR_ghwnd, GWL_STYLE, SR_dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(SR_ghwnd,
							 HWND_TOP,									   // set to top
							 SR_mi.rcMonitor.left,						   // RECT rc left point
							 SR_mi.rcMonitor.top,						   // top point
							 SR_mi.rcMonitor.right - SR_mi.rcMonitor.left, // width
							 SR_mi.rcMonitor.bottom - SR_mi.rcMonitor.top, // height
							 SWP_NOZORDER |								   // set window position no z order
								 SWP_FRAMECHANGED						   // set window position WM_NCCALCSIZE

				);
			}
		}

		ShowCursor(FALSE); // to hide cursor
	}
	else
	{
		SetWindowLong(SR_ghwnd, GWL_STYLE, SR_dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(SR_ghwnd, &SR_wpPrev);
		SetWindowPos(SR_ghwnd, HWND_TOP, 0, 0, 0, 0,
					 SWP_NOMOVE |			 // Use window placement set by WindowPlacement
						 SWP_NOSIZE |		 // Use window size set by WindowPlacement
						 SWP_NOOWNERZORDER | // dont change order even if tooltip or dialg box changes
						 SWP_NOZORDER |		 // dont change order
						 SWP_FRAMECHANGED);

		ShowCursor(TRUE);
	}
}

int initialise(void)
{
	// function declarations
	void resize(int, int);

	// variable declarations
	PIXELFORMATDESCRIPTOR SR_pfd;
	int SR_iPixelFormatIndex;

	// code
	memset(&SR_pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

	SR_pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	SR_pfd.nVersion = 1; // conventional
	SR_pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	// PFD_DRAW_TO_WINDOW want to draw on window
	// PFD_DOUBLEBUFFER to use double for rendering fast and realistic to avoid lag (un-noticable) between two buffer rendering
	SR_pfd.iPixelType = PFD_TYPE_RGBA; // reg green blue alpha - transperancy
	SR_pfd.cRedBits = 8;
	SR_pfd.cGreenBits = 8;
	SR_pfd.cBlueBits = 8;
	SR_pfd.cAlphaBits = 8;

	// ask for specialist
	SR_ghdc = GetDC(SR_ghwnd);

	if (SR_ghdc == NULL)
	{
		return -1;
	}

	// index of select pixel format is onebased
	SR_iPixelFormatIndex = ChoosePixelFormat(SR_ghdc, &SR_pfd);

	if (SR_iPixelFormatIndex == 0)
	{
		return -2;
	}

	if (SetPixelFormat(SR_ghdc, SR_iPixelFormatIndex, &SR_pfd) == FALSE)
	{
		return -3;
	}

	// use wgl to get rendering context of my set index
	SR_ghrc = wglCreateContext(SR_ghdc);

	if (SR_ghrc == NULL)
	{
		return -4;
	}

	// make SR_ghrc as current rendering context
	if (wglMakeCurrent(SR_ghdc, SR_ghrc) == FALSE)
	{
		return -5;
	}

	// choose screen clearing color as blue
	// red green blue alpha
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // here we selected color to clear screen color

	// warmup resize
	resize(WIN_WIDTH, WIN_HEIGHT);

	// we will set timer here
	SetTimer(SR_ghwnd, 1234, 0, NULL);

	return 0;
}

void resize(int width, int height)
{
	// code
	if (height <= 0)
	{
		height = 1; // in future while calculating perspective we will devide by height so to avoid divide by zero infinity
	}

	// to match left top of viewport to window
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	// width and height are of size_t type varibales so we typecasted to GLsizei

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void render(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT); // here we clear screen for which blue color was previously selected

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f + moveTriangleVariable, 0.8f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.8f + moveTriangleVariable, -0.4f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.8f + moveTriangleVariable, -0.4f, 0.0f);

	glEnd();

	// do double buffering
	SwapBuffers(SR_ghdc);
}

void update(void)
{
	// code
}

void uninitialise(void)
{
	// code
	// if exiting in fullscreen first restore and then proceed
	if (SR_bFullscreen == TRUE)
	{
		toggleFullscreen();
		SR_bFullscreen = FALSE;
	}

	// first check the current context and if it is then unmake it
	if (wglGetCurrentContext() == SR_ghrc)
	{
		wglMakeCurrent(NULL, NULL);

		// now destroy the rendering context
		if (SR_ghrc)
		{
			wglDeleteContext(SR_ghrc);
			SR_ghrc = NULL;
		}

		// release the device context
		if (SR_ghdc)
		{
			ReleaseDC(SR_ghwnd, SR_ghdc);
			SR_ghdc = NULL;
		}
	}

	// destroy window
	if (SR_ghwnd)
	{
		DestroyWindow(SR_ghwnd);
		SR_ghwnd = NULL;
	}

	// close log file
	if (SR_gpFile)
	{
		fprintf(SR_gpFile, "\nSSR: Program successfully terminated.\n");
		fclose(SR_gpFile);
		SR_gpFile = NULL;
	}
}
