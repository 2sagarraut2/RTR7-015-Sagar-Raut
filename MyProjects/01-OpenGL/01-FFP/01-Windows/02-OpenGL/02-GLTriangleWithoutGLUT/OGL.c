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

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
HWND ghwnd = NULL;
HDC ghdc = NULL;   // graphic card specialist device context handle
HGLRC ghrc = NULL; // rendering conext of opengl graphic library rendering context
BOOL bFullscreen = FALSE;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;
FILE *gpFile = NULL; // global pointer to file

BOOL bActiveWindow = FALSE;		  // to check whether window is active or in focus
BOOL bEscapeKeyIsPressed = FALSE; // check if escape key is pressed

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
	HWND hwnd = NULL;
	MSG msg;
	TCHAR lpszAppName[] = TEXT("RTR7_SSR"); // TEXT -> MACRO
	BOOL bDone = FALSE;						// to use in gameloop

	// code
	// create log file
	gpFile = fopen("Log.txt", "w"); // file open -> if does not exists then create | w - write & clean it
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log file creation failed"), TEXT("Error"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "SSR: Program successfully started.\n\n");
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

	SR_wndclass.lpszClassName = lpszAppName;
	SR_wndclass.lpszMenuName = NULL;
	SR_wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));

	// Register above WNDCLASS structure
	RegisterClassEx(&SR_wndclass); // return value is atom - immutable string goes to into mater table

	// Centering
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);  // x of screen - SM - SystemMetrics CX - count of x
	int screenHeight = GetSystemMetrics(SM_CYSCREEN); // y of screen - CY - count of y

	// create the window
	// CreateWindowEX is also there to use when we want give extra styles
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, // Extended window style -> App window -> having top most order of z
						  lpszAppName,
						  TEXT("RTR7-015-Sagar-Raut-MyProjects-01-OpenGL-01-FFP-01-Windows-02-BlueScreen"),
						  WS_OVERLAPPEDWINDOW	// top window
							  | WS_CLIPCHILDREN // cut all children window
							  | WS_CLIPSIBLINGS // cut all siblings
							  | WS_VISIBLE,
						  screenWidth / 2 - WIN_WIDTH / 2,	 // x
						  screenHeight / 2 - WIN_HEIGHT / 2, // y
						  WIN_WIDTH,						 // width
						  WIN_HEIGHT,						 // height
						  NULL,								 // parent process
						  NULL,								 // menu name
						  hInstance,						 // compulsory
						  NULL);							 // creation parameter long ptr void *

	// set global window handle
	ghwnd = hwnd;

	int iResult = initialise();
	if (iResult != 0)
	{
		fprintf(gpFile, "SSR: WinMain(): initialise() failed\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else if (iResult == -1)
	{
		fprintf(gpFile, "SSR: initialise(): failed to get device context\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else if (iResult == -2)
	{
		fprintf(gpFile, "SSR: initialise(): failed to get pixel format\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else if (iResult == -3)
	{
		fprintf(gpFile, "SSR: initialise(): failed to set pixel format\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else if (iResult == -4)
	{
		fprintf(gpFile, "SSR: initialise() failed to get rendering context\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else if (iResult == -5)
	{
		fprintf(gpFile, "SSR: initialise() failed to switch current context to rendering context\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gpFile, "SSR: WinMain(): initialise() succeeded\n");
	}

	// show window
	ShowWindow(hwnd, iCmdShow);

	// update the window to paint its background
	UpdateWindow(hwnd);

	SetForegroundWindow(hwnd); // brings window to foreground
	SetFocus(hwnd);			   // set focuns to our window

	// game loop
	while (bDone == FALSE)
	{
		// PM_REMOVE - peek message remove
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				bDone = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (bActiveWindow == TRUE)
			{
				if (bEscapeKeyIsPressed == TRUE)
				{
					bDone = TRUE;
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

	return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// local function declarations
	void resize(int, int); // width and height
	void toggleFullscreen(void);
	void uninitialise(void);

	// code
	switch (iMsg)
	{
	case WM_CREATE:
		memset(&wpPrev, 0, sizeof(WINDOWPLACEMENT));
		wpPrev.length = sizeof(WINDOWPLACEMENT);
		break;
	case WM_SETFOCUS:
		bActiveWindow = TRUE;
		break;
	case WM_KILLFOCUS:
		bActiveWindow = FALSE;
		break;
	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			bEscapeKeyIsPressed = TRUE;
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
			if (bFullscreen == FALSE)
			{
				toggleFullscreen();
				bFullscreen = TRUE;
			}
			else
			{
				toggleFullscreen();
				bFullscreen = FALSE;
			}

			break;
		}
		break;
	case WM_CLOSE:
		uninitialise();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void toggleFullscreen(void)
{
	// variable declarations
	MONITORINFO mi;

	// code
	if (bFullscreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE); // get style of window from long parameter

		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			memset(&mi, 0, sizeof(MONITORINFO));
			mi.cbSize = sizeof(MONITORINFO);

			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd,
							 HWND_TOP,								 // set to top
							 mi.rcMonitor.left,						 // RECT rc left point
							 mi.rcMonitor.top,						 // top point
							 mi.rcMonitor.right - mi.rcMonitor.left, // width
							 mi.rcMonitor.bottom - mi.rcMonitor.top, // height
							 SWP_NOZORDER |							 // set window position no z order
								 SWP_FRAMECHANGED					 // set window position WM_NCCALCSIZE

				);
			}
		}

		ShowCursor(FALSE); // to hide cursor
	}
	else
	{
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0,
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
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex;

	// code
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1; // conventional
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	// PFD_DRAW_TO_WINDOW want to draw on window
	// PFD_DOUBLEBUFFER to use double for rendering fast and realistic to avoid lag (un-noticable) between two buffer rendering
	pfd.iPixelType = PFD_TYPE_RGBA; // reg green blue alpha - transperancy
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;

	// ask for specialist
	ghdc = GetDC(ghwnd);

	if (ghdc == NULL)
	{
		return -1;
	}

	// index of select pixel format is onebased
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);

	if (iPixelFormatIndex == 0)
	{
		return -2;
	}

	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		return -3;
	}

	// use wgl to get rendering context of my set index
	ghrc = wglCreateContext(ghdc);

	if (ghrc == NULL)
	{
		return -4;
	}

	// make ghrc as current rendering context
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		return -5;
	}

	// choose screen clearing color as blue
	// red green blue alpha
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// warmup resize
	resize(WIN_WIDTH, WIN_HEIGHT);

	return 0;
}

void resize(int width, int height)
{
	// code
	if (height <= 0)
	{
		height = 1; // in future while calculating perspective we will devide by height so to avoid divide by zero infinity
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// to match left top of viewport to window
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	// width and height are of size_t type varibales so we typecasted to GLsizei
}

void render(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT); // here we clear screen for which blue color was previously selected

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.8f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.8f, -0.4f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.8f, -0.4f, 0.0f);

	glEnd();

	// do double buffering
	SwapBuffers(ghdc);
}

void update(void)
{
	// code
}

void uninitialise(void)
{
	// code
	// if exiting in fullscreen first restore and then proceed
	if (bFullscreen == TRUE)
	{
		toggleFullscreen();
		bFullscreen = FALSE;
	}

	// first check the current context and if it is then unmake it
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);

		// now destroy the rendering context
		if (ghrc)
		{
			wglDeleteContext(ghrc);
			ghrc = NULL;
		}

		// release the device context
		if (ghdc)
		{
			ReleaseDC(ghwnd, ghdc);
			ghdc = NULL;
		}
	}

	// destroy window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// close log file
	if (gpFile)
	{
		fprintf(gpFile, "\nSSR: Program successfully terminated.\n");
		fclose(gpFile);
		gpFile = NULL;
	}
}
