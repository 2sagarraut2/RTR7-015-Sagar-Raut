// header files
#include <windows.h>
#include "Window.h"
// macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
int iPaintFlag = -1;

// Entery point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// variable declarations
	WNDCLASSEX SR_wndclass;
	HWND SR_hwnd = NULL;
	MSG SR_msg;
	TCHAR SR_lpszAppName[] = TEXT("RTR7_SSR"); // TEXT -> MACRO

	// code
	// WNDCLASSEX structure initialisation
	SR_wndclass.cbSize = sizeof(WNDCLASSEX);
	SR_wndclass.style = CS_HREDRAW | CS_VREDRAW; // Class Style - Painting window when resized
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
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);  // x of screen - SM - SystemMetrics CX - count of x
	int screenHeight = GetSystemMetrics(SM_CYSCREEN); // y of screen - CY - count of y

	// create the window
	// CreateWindowEX is also there to use when we want give extra styles
	SR_hwnd = CreateWindow(SR_lpszAppName,
						   TEXT("RTR7-015-Sagar-Raut-MyProjects-01-OpenGL-01-FFP-01-Windows-01-Windowing-MultiColoredHelloWorld"),
						   WS_OVERLAPPEDWINDOW,
						   screenWidth / 2 - WIN_WIDTH / 2,	  // x
						   screenHeight / 2 - WIN_HEIGHT / 2, // y
						   WIN_WIDTH,						  // width
						   WIN_HEIGHT,						  // height
						   NULL,							  // parent process
						   NULL,							  // menu name
						   hInstance,						  // compulsory
						   NULL);							  // creation parameter long ptr void *

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

	return ((int)SR_msg.wParam);
}

LRESULT CALLBACK WndProc(HWND SR_hwnd, UINT SR_iMsg, WPARAM wParam, LPARAM lParam)
{
	// variable declarations
	HDC hdc; // handle to DC - device context or Graphics specialist
	PAINTSTRUCT ps;
	RECT rc;
	TCHAR str[] = TEXT("Hello, World!!!");

	// code
	switch (SR_iMsg)
	{
	case WM_CREATE:
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
			break;
		case 'R':
		case 'r':
			iPaintFlag = 1;
			InvalidateRect(SR_hwnd, NULL, TRUE);
			break;
		case 'G':
		case 'g':
			iPaintFlag = 2;
			InvalidateRect(SR_hwnd, NULL, TRUE);
			break;
		case 'B':
		case 'b':
			iPaintFlag = 3;
			InvalidateRect(SR_hwnd, NULL, TRUE);
			break;
		case 'C':
		case 'c':
			iPaintFlag = 4;
			InvalidateRect(SR_hwnd, NULL, TRUE);
			break;
		case 'M':
		case 'm':
			iPaintFlag = 5;
			InvalidateRect(SR_hwnd, NULL, TRUE);
			break;
		case 'Y':
		case 'y':
			iPaintFlag = 6;
			InvalidateRect(SR_hwnd, NULL, TRUE);
			break;
		default:
			iPaintFlag = -1;
			InvalidateRect(SR_hwnd, NULL, TRUE);
			break;
		}
		break;
	case WM_PAINT:
		GetClientRect(SR_hwnd, &rc);	// Get Windows client rectangles dimentions - only client area and not the title bar
		hdc = BeginPaint(SR_hwnd, &ps); // Get Graphics context
		SetBkColor(hdc, RGB(0, 0, 0));	// Hello World texts Background color

		if (iPaintFlag == 1)
		{
			SetTextColor(hdc, RGB(255, 0, 0));
		}
		else if (iPaintFlag == 2)
		{
			SetTextColor(hdc, RGB(0, 255, 0));
		}
		else if (iPaintFlag == 3)
		{
			SetTextColor(hdc, RGB(0, 0, 255));
		}
		else if (iPaintFlag == 4)
		{
			SetTextColor(hdc, RGB(0, 255, 255));
		}
		else if (iPaintFlag == 5)
		{
			SetTextColor(hdc, RGB(255, 0, 255));
		}
		else if (iPaintFlag == 6)
		{
			SetTextColor(hdc, RGB(255, 255, 0));
		}
		else
		{
			SetTextColor(hdc, RGB(255, 255, 255));
		}

		// SetTextColor(hdc, RGB(0, 255, 0));				  // Color of Text
		DrawText(hdc,									  // specialist
				 str,									  // string
				 -1,									  // Whole string
				 &rc,									  // which rectangle
				 DT_SINGLELINE | DT_CENTER | DT_VCENTER); // Single line text (not multiline) | Horizontal center | verticle center
		EndPaint(SR_hwnd, &ps);							  // return specialist to window
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
