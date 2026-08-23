// header files
#include <windows.h>
#include "Window.h"
// macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Entery point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// variable declarations
	WNDCLASSEX SR_wndclass;
	HWND hwnd = NULL;
	MSG msg;
	TCHAR lpszAppName[] = TEXT("RTR7_SSR"); // TEXT -> MACRO

	// code
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
	hwnd = CreateWindow(lpszAppName,
						TEXT("RTR7-015-Sagar-Raut-MyProjects-01-OpenGL-01-FFP-01-Windows-01-Windowing-03-Icon"),
						WS_OVERLAPPEDWINDOW,
						screenWidth / 2 - WIN_WIDTH / 2,   // x
						screenHeight / 2 - WIN_HEIGHT / 2, // y
						WIN_WIDTH,						   // width
						WIN_HEIGHT,						   // height
						NULL,							   // parent process
						NULL,							   // menu name
						hInstance,						   // compulsory
						NULL);							   // creation parameter long ptr void *

	// show window
	ShowWindow(hwnd, iCmdShow);

	// update the window to paint its background
	UpdateWindow(hwnd);

	// message loop
	while (GetMessage(&msg, // interrupt message coming from OS
					  NULL, // to handle instance of all window
					  0,	// min message range
					  0		// max message range
					  ))
	{
		TranslateMessage(&msg); // translates virtual-key messages into character messages
		DispatchMessage(&msg);	// message sent to WndProc
	}

	return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// code
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	// case WM_KEYDOWN:
	// 	PostQuitMessage(0);
	// 	break;
	case WM_RBUTTONDOWN:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}
