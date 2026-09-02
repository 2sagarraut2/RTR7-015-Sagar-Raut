// header files
#include <windows.h>

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
	SR_wndclass.style = CS_HREDRAW | CS_VREDRAW; // Class Style
	SR_wndclass.cbClsExtra = 0;
	SR_wndclass.cbWndExtra = 0;
	SR_wndclass.lpfnWndProc = WndProc; // long pointer function
	SR_wndclass.hInstance = hInstance;
	SR_wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); // handle background
	SR_wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);			 // IDI_APPLICATION MACRO - Identifier Icon application -> LPCTSTR - long pointer to constantly NULL terminated string
	// To provide user defined icon we will give hInstance that we created as first parameter

	SR_wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // IDC_ARROW - Indetifier cursor
	// To provide user defined icon we will give hInstance that we created as first parameter

	SR_wndclass.lpszClassName = SR_lpszAppName;
	SR_wndclass.lpszMenuName = NULL;
	SR_wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// Register above WNDCLASS structure
	RegisterClassEx(&SR_wndclass); // return value is atom - immutable string goes to into mater table

	// create the window
	// CreateWindowEX is also there to use when we want give extra styles
	SR_hwnd = CreateWindow(SR_lpszAppName,
						   TEXT("RTR7-015-Sagar-Raut-MyProjects-01-OpenGL-01-FFP-01-Windows-01-Windowing-01-Window"),
						   WS_OVERLAPPEDWINDOW,
						   CW_USEDEFAULT, // x
						   CW_USEDEFAULT, // y
						   CW_USEDEFAULT, // width
						   CW_USEDEFAULT, // height
						   NULL,		  // parent process
						   NULL,		  // menu name
						   hInstance,	  // compulsory
						   NULL);		  // creation parameter long ptr void *

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
	// code
	switch (SR_iMsg)
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

	return (DefWindowProc(SR_hwnd, SR_iMsg, wParam, lParam));
}
