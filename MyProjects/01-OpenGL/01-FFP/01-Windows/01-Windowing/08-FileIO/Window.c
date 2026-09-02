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

// Entery point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{

	// variable declarations
	WNDCLASSEX SR_wndclass;
	HWND SR_hwnd = NULL;
	MSG SR_msg;
	TCHAR SR_lpszAppName[] = TEXT("RTR7_SSR"); // TEXT -> MACRO

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
	SR_wndclass.style = CS_HREDRAW | CS_VREDRAW; // Class Style
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
							 TEXT("RTR7-015-Sagar-Raut-MyProjects-01-OpenGL-01-FFP-01-Windows-01-Windowing-LogFile"),
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

	// show window
	ShowWindow(SR_hwnd, iCmdShow);

	// update the window to paint its background
	UpdateWindow(SR_hwnd);

	// message loop
	while (GetMessage(&SR_msg, // interrupt message coming from OS
					  NULL,	   // to handle instance of all window
					  0,	   // min message range
					  0		   // max message range
					  ))
	{
		TranslateMessage(&SR_msg); // translates virtual-key messages into character messages
		DispatchMessage(&SR_msg);  // message sent to WndProc
	}

	// close  log file
	if (SR_gpFile)
	{
		fprintf(SR_gpFile, "SSR: Program successfully terminated.\n");
		fclose(SR_gpFile);
		SR_gpFile = NULL;
	}

	return ((int)SR_msg.wParam);
}

LRESULT CALLBACK WndProc(HWND SR_hwnd, UINT SR_iMsg, WPARAM wParam, LPARAM lParam)
{
	// local function declarations
	void toggleFullscreen(void);

	// code
	switch (SR_iMsg)
	{
	case WM_CREATE:
		memset(&SR_wpPrev, 0, sizeof(WINDOWPLACEMENT));
		SR_wpPrev.length = sizeof(WINDOWPLACEMENT);
		break;
	case WM_SETFOCUS:
		break;
	case WM_KILLFOCUS:
		break;
	case WM_SIZE:
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
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
