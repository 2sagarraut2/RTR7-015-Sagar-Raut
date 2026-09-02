// header files
#include <windows.h>
#include "Window.h"

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// entry point functions
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // varibale declarations
    WNDCLASSEX wndclass;
    HWND hwnd = NULL;
    MSG msg;
    TCHAR lpszAppName[] = TEXT("My Practice Window");

    // code
    // WNSCLASSEX structure initialisation
    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hInstance = hInstance;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));
    wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = lpszAppName;
    wndclass.lpszMenuName = NULL;

    RegisterClassEx(&wndclass);

    hwnd = CreateWindow(lpszAppName,
                        TEXT("My First Practice Window"),
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, iCmdShow);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // variable declaration
    TCHAR str[255];
    int num1 = 100, num2 = 200;

    // code
    switch (iMsg)
    {
    case WM_CREATE:
        MessageBox(hwnd, "Hello", "information", MB_OK);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            MessageBox(hwnd, "Escape Key is pressed will close this later here", "inforamtion", MB_OK);
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
            // MessageBeep(1);
            MessageBox(hwnd, "F/f key pressed", "information", MB_OK);
            break;

        case 'A':
        case 'a':
            wsprintf(str, TEXT("Addtion of %d and %d is %d"), num1, num2, (num1 + num2));
            MessageBox(NULL, str, "Addition", MB_OK);
            break;

        default:

            break;
        }
        break;

    case WM_CLOSE:
        MessageBox(hwnd, "This will come before WM_QUIT", "information", MB_OK);
        break;

    case WM_DESTROY:
        MessageBox(hwnd, "I am dead already", "Information", MB_OK);
        PostQuitMessage(0);
        break;

    default:
        break;
    }

    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}