// header files
#include <windows.h>
#include <stdio.h>	// For file I/O
#include <stdlib.h> // For exit(0)
#include "Window.h"
// macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
HWND SR_ghwnd = NULL;
BOOL SR_bFullscreen = FALSE;
DWORD SR_dwStyle;
WINDOWPLACEMENT SR_wpPrev;
FILE *SR_gpFile = NULL; // global pointer to file

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
						  TEXT("RTR7-015-Sagar-Raut-MyProjects-01-OpenGL-01-FFP-01-Windows-01-Windowing-GameLoop"),
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
	SR_ghwnd = hwnd;

	int iResult = initialise();
	if (iResult != 0)
	{
		fprintf(SR_gpFile, "SSR: WinMain(): initialise() failed\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(SR_gpFile, "SSR: WinMain(): initialise() succeded\n");
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

LRESULT CALLBACK WndProc(HWND hwnd, UINT SR_iMsg, WPARAM wParam, LPARAM lParam)
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
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return (DefWindowProc(hwnd, SR_iMsg, wParam, lParam));
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
	// code
	return 0;
}

void resize(int width, int height)
{
	// code
}

void render(void)
{
	// code
}

void update(void)
{
	// code
}

void uninitialise(void)
{
	// code
	// destroy window
	if (SR_ghwnd)
	{
		DestroyWindow(SR_ghwnd);
		SR_ghwnd = NULL;
	}

	// close log file
	if (SR_gpFile)
	{
		fprintf(SR_gpFile, "SSR: Program successfully terminated.\n");
		fclose(SR_gpFile);
		SR_gpFile = NULL;
	}
}
