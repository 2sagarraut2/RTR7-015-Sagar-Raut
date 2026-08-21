// header files
#include <windows.h>

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
	SR_wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); // handle background
	SR_wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);			 // IDI_APPLICATION MACRO - Identifier Icon application -> LPCTSTR - long pointer to constantly NULL terminated string
	// To provide user defined icon we will give hInstance that we created as first parameter

	SR_wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // IDC_ARROW - Indetifier cursor
	// To provide user defined icon we will give hInstance that we created as first parameter

	SR_wndclass.lpszClassName = lpszAppName;
	SR_wndclass.lpszMenuName = NULL;
	SR_wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// Register above WNDCLASS structure
	RegisterClassEx(&SR_wndclass); // return value is atom - immutable string goes to into mater table

	// create the window
	// CreateWindowEX is also there to use when we want give extra styles
	hwnd = CreateWindow(lpszAppName,
						TEXT("My First RTR7 Program : Sagar Sambhaji Raut"),
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, // x
						CW_USEDEFAULT, // y
						CW_USEDEFAULT, // width
						CW_USEDEFAULT, // height
						NULL,		   // parent process
						NULL,		   // menu name
						hInstance,	   // compulsory
						NULL);		   // creation parameter long ptr void *

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
