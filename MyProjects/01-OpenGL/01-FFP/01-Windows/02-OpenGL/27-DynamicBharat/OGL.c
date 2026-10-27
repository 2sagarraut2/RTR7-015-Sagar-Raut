// header files
#include <windows.h>
#include <stdio.h>	// For file I/O
#include <stdlib.h> // For exit(0)
#include <math.h>

// OpenGL related header files
#include <gl\GL.h>	// inside include path gl directory inside which GL.h file
#include <gl\GLU.h> // Graphic library utility functions header file

#include "OGL.h"

// link with openGL import library
#pragma comment(lib, "OPENGL32.lib")
#pragma comment(lib, "GLU32.lib")

// macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

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

static GLint animationComplete = 0;
int planeAnimationStarted = 0;
#define MAX_POINTS 9500

typedef struct
{
	float x[MAX_POINTS];
	float y[MAX_POINTS];
	int numPoints;
} Path;

typedef struct
{
	int pathIndex;
	int currentPoint;
	float posX;
	float posY;
	int speed;
} MovingObject;

Path paths[3];
MovingObject objects[3];
int frameCounter = 0;

// variables for letters
// #define INCREMENT_FACTOR 0.01f
// #define INCREMENT_FACTOR 0.0001f
#define INCREMENT_FACTOR 0.001f

GLfloat xPositionForB = -8.0f;

GLfloat xPositionForH = -7.0f;
GLfloat yPositionForH = 4.3f;

GLfloat xPositionForA = -7.0f;
GLfloat yPositionForA = -5.55f;

GLfloat xPositionForR = 5.3f;
GLfloat yPositionForR = 5.5f;

GLfloat xPositionForSecondA = 7.0f;
GLfloat yPositionForSecondA = -5.95f;

GLfloat xPositionForT = 6.0f;

BOOL isReachedAtEndForB = FALSE;
BOOL isReachedAtEndForH = FALSE;
BOOL isReachedAtEndForA = FALSE;
BOOL isReachedAtEndForR = FALSE;
BOOL isReachedAtEndForSecondA = FALSE;
BOOL isReachedAtEndForT = FALSE;

// GLfloat blendFactor = 0.0f;

GLfloat blendFactorB = 0.0f;
GLfloat blendFactorH = 0.0f;
GLfloat blendFactorA = 0.0f;
GLfloat blendFactorR = 0.0f;
GLfloat blendFactorForSecondA = 0.0f;
GLfloat blendFactorT = 0.0f;

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
							 TEXT("RTR7-015-Sagar-Raut:") TEXT(__FILE__),
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
	void printGLInfo(void);
	void initializePaths();
	void initializeObjects();

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
	SR_pfd.cDepthBits = 32;

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

	// printGLInfo
	printGLInfo();

	// enable depth
	glShadeModel(GL_SMOOTH);			   // shading smooth
	glClearDepth(1.0f);					   // reset all depth values to 1
	glEnable(GL_DEPTH_TEST);			   // depth test
	glDepthFunc(GL_LEQUAL);				   // less than equal
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, // remove all the artifacts like distortion
		   GL_NICEST);					   // do it nicest

	// choose screen clearing color as blue
	// red green blue alpha
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // here we selected color to clear screen color

	initializePaths();
	initializeObjects();

	// warmup resize
	resize(WIN_WIDTH, WIN_HEIGHT);

	return 0;
}

void printGLInfo(void)
{
	// code
	fprintf(SR_gpFile, "OpenGL Vendor: %s\n", glGetString(GL_VENDOR));
	fprintf(SR_gpFile, "OpenGL Renderer: %s\n", glGetString(GL_RENDERER));
	fprintf(SR_gpFile, "OpenGL Version: %s\n\n", glGetString(GL_VERSION));
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

	// perspective projection
	gluPerspective(45.0f,							 // angle
				   (GLfloat)width / (GLfloat)height, // ratio of width and height
				   0.1f,							 // near
				   100.0f);							 // far
													 // this internally calls frustum
}

void render(void)
{
	void staticBharat();
	void renderFighterJet(float, float);

	// code
	glClear(GL_COLOR_BUFFER_BIT | // here we clear screen for which blue color was previously selected
			GL_DEPTH_BUFFER_BIT); // clear depth buffer using previous value specified for depth buffer

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -6.0f);

	// GLfloat centerX = -2.6f;
	// GLfloat centerY = 2.475f;
	// GLfloat radius = 1.8f;

	// // PATH 0: Top path

	// glPointSize(2.0f);
	// glBegin(GL_POINTS);

	// // Top-left arc
	// for (float i = 160; i <= 270; i = i + 0.05f)
	// {

	// 	float angle = i * 3.14159f / 180.0f;
	// 	float x = centerX + (cos(angle) * radius);
	// 	float y = centerY + (sin(angle) * radius);
	// 	glVertex2f(x, y);
	// }

	// // Top horizontal line
	// for (float i = -2.6f; i <= 2.6f; i = i + 0.001f)
	// {

	// 	float x = i;
	// 	float y = 0.675f;
	// 	glVertex2f(x, y);
	// }

	// // Top-right arc
	// centerX = 2.6f;
	// for (float i = 270; i <= 380; i = i + 0.05f)
	// {

	// 	float angle = i * 3.14159f / 180.0f;
	// 	float x = centerX + (cos(angle) * radius);
	// 	float y = centerY + (sin(angle) * radius);
	// 	glVertex2f(x, y);
	// }

	// // PATH 1: Center line
	// for (float i = -4.8f; i <= 4.6f; i = i + 0.001f)
	// {

	// 	float x = i;
	// 	float y = 0.0f;
	// 	glVertex2f(x, y);
	// }

	// // PATH 2: Bottom path

	// // Bottom-left arc
	// centerX = -2.6f;
	// centerY = -2.475f;
	// for (float i = 200; i >= 90; i = i - 0.05f)
	// {

	// 	float angle = i * 3.14159f / 180.0f;
	// 	float x = centerX + (cos(angle) * radius);
	// 	float y = centerY + (sin(angle) * radius);
	// 	glVertex2f(x, y);
	// }

	// // Bottom horizontal line
	// for (float i = -2.6f; i <= 2.6f; i = i + 0.001f)
	// {

	// 	float x = i;
	// 	float y = -0.675f;
	// 	glVertex2f(x, y);
	// }

	// // Bottom-right arc
	// centerX = 2.6f;
	// centerY = -2.475f;
	// for (float i = 90; i >= -20; i = i - 0.05f)
	// {

	// 	float angle = i * 3.14159f / 180.0f;
	// 	float x = centerX + (cos(angle) * radius);
	// 	float y = centerY + (sin(angle) * radius);
	// 	glVertex2f(x, y);
	// }
	// glEnd();

	glPushMatrix();
	glScalef(0.75f, 0.75f, 0.75f);
	staticBharat();
	glPopMatrix();

	// Draw moving objects
	for (int i = 0; i < 3; i++)
	{
		renderFighterJet(objects[i].posX, objects[i].posY);
		// fprintf(SR_gpFile, "x = %f\n", objects[1].posX);
	}

	// do double buffering
	SwapBuffers(SR_ghdc);
}

void staticBharat()
{
	void letterB();
	void letterH();
	void letterA(GLfloat, BOOL);
	void letterR();
	void letterT();

	glTranslatef(0.30f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(xPositionForB, 0.0f, 0.0f);
	letterB();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xPositionForH, yPositionForH, 0.0f);
	letterH();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xPositionForA, yPositionForA, 0.0f);
	letterA(blendFactorA, isReachedAtEndForA);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xPositionForR, yPositionForR, 0.0f);
	letterR();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xPositionForSecondA, yPositionForSecondA, 0.0f);
	letterA(blendFactorForSecondA, isReachedAtEndForSecondA);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xPositionForT, 0.0f, 0.0f);
	letterT();
	glPopMatrix();
}

void letterB()
{
	// top horizontal line
	glBegin(GL_QUADS);

	if (isReachedAtEndForB)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorB);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(-0.2f, 0.9f, 0.0f);
	glVertex3f(1.2f, 0.9f, 0.0f);
	glVertex3f(1.2f, 0.6f, 0.0f);
	glVertex3f(-0.2f, 0.6f, 0.0f);

	glEnd();

	// top left vertical line
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.6f, 0.0f);
	glVertex3f(0.3f, 0.6f, 0.0f);

	if (isReachedAtEndForB)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorB);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.3f, 0.15f, 0.0f);
	glVertex3f(0.0f, 0.15f, 0.0f);

	glEnd();

	// top right vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEndForB)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorB);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.86f, 0.6f, 0.0f);
	glVertex3f(1.2f, 0.6f, 0.0f);

	if (isReachedAtEndForB)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorB);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(1.2f, 0.15f, 0.0f);
	glVertex3f(0.86f, 0.15f, 0.0f);

	glEnd();

	// central line
	glBegin(GL_QUADS);

	if (isReachedAtEndForB)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorB);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(1.2f, 0.15f, 0.0f);
	glVertex3f(1.2f, -0.15f, 0.0f);
	glVertex3f(0.0f, -0.15f, 0.0f);

	glEnd();

	// bottom left vertical line
	glBegin(GL_QUADS);

	glVertex3f(0.0f, -0.15f, 0.0f);
	glVertex3f(0.3f, -0.15f, 0.0f);

	if (isReachedAtEndForB)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorB);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.3f, -0.6f, 0.0f);
	glVertex3f(0.0f, -0.6f, 0.0f);

	glEnd();

	// bottom right vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEndForB)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorB);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.86f, -0.6f, 0.0f);
	glVertex3f(1.2f, -0.6f, 0.0f);

	if (isReachedAtEndForB)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorB);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(1.2f, -0.15f, 0.0f);
	glVertex3f(0.86f, -0.15f, 0.0f);

	glEnd();

	// bottom horizontal line
	glBegin(GL_QUADS);

	if (isReachedAtEndForB)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorB);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(-0.2f, -0.9f, 0.0f);
	glVertex3f(1.2f, -0.9f, 0.0f);
	glVertex3f(1.2f, -0.6f, 0.0f);
	glVertex3f(-0.2f, -0.6f, 0.0f);

	glEnd();
}

void letterH()
{
	// top horizontal line
	glBegin(GL_QUADS);

	if (isReachedAtEndForH)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorH);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.9f, 0.0f);
	glVertex3f(0.3f, 0.9f, 0.0f);
	glVertex3f(0.3f, 0.6f, 0.0f);
	glVertex3f(0.0f, 0.6f, 0.0f);

	glVertex3f(0.86f, 0.9f, 0.0f);
	glVertex3f(1.2f, 0.9f, 0.0f);
	glVertex3f(1.2f, 0.6f, 0.0f);
	glVertex3f(0.86f, 0.6f, 0.0f);

	glEnd();

	// top left vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEndForH)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorH);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.6f, 0.0f);
	glVertex3f(0.3f, 0.6f, 0.0f);

	if (isReachedAtEndForH)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorH);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.3f, 0.15f, 0.0f);
	glVertex3f(0.0f, 0.15f, 0.0f);

	glEnd();

	// top right vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEndForH)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorH);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.86f, 0.6f, 0.0f);
	glVertex3f(1.2f, 0.6f, 0.0f);

	if (isReachedAtEndForH)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorH);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(1.2f, 0.15f, 0.0f);
	glVertex3f(0.86f, 0.15f, 0.0f);

	glEnd();

	// central line
	glBegin(GL_QUADS);

	if (isReachedAtEndForH)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorH);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(1.2f, 0.15f, 0.0f);
	glVertex3f(1.2f, -0.15f, 0.0f);
	glVertex3f(0.0f, -0.15f, 0.0f);

	glEnd();

	// bottom left vertical line
	glBegin(GL_QUADS);

	glVertex3f(0.0f, -0.15f, 0.0f);
	glVertex3f(0.3f, -0.15f, 0.0f);

	if (isReachedAtEndForH)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorH);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.3f, -0.6f, 0.0f);
	glVertex3f(0.0f, -0.6f, 0.0f);

	glEnd();

	// bottom right vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEndForH)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorH);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.86f, -0.6f, 0.0f);
	glVertex3f(1.2f, -0.6f, 0.0f);

	if (isReachedAtEndForH)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorH);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(1.2f, -0.15f, 0.0f);
	glVertex3f(0.86f, -0.15f, 0.0f);

	glEnd();

	// bottom horizontal line
	glBegin(GL_QUADS);

	if (isReachedAtEndForH)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorH);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, -0.9f, 0.0f);
	glVertex3f(0.3f, -0.9f, 0.0f);
	glVertex3f(0.3f, -0.6f, 0.0f);
	glVertex3f(0.0f, -0.6f, 0.0f);

	glVertex3f(0.86f, -0.9f, 0.0f);
	glVertex3f(1.2f, -0.9f, 0.0f);
	glVertex3f(1.2f, -0.6f, 0.0f);
	glVertex3f(0.86f, -0.6f, 0.0f);

	glEnd();
}

void letterA(GLfloat blendFactor, BOOL isReachedAtEnd)
{
	// top horizontal line
	glBegin(GL_QUADS);

	if (isReachedAtEnd)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorA);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.9f, 0.0f);
	glVertex3f(1.2f, 0.9f, 0.0f);
	glVertex3f(1.2f, 0.6f, 0.0f);
	glVertex3f(0.0f, 0.6f, 0.0f);

	glEnd();

	// top left vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEnd)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorA);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.6f, 0.0f);
	glVertex3f(0.3f, 0.6f, 0.0f);

	if (isReachedAtEnd)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorA);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.3f, 0.15f, 0.0f);
	glVertex3f(0.0f, 0.15f, 0.0f);

	glEnd();

	// top right vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEnd)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorA);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.86f, 0.6f, 0.0f);
	glVertex3f(1.2f, 0.6f, 0.0f);

	if (isReachedAtEnd)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorA);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(1.2f, 0.15f, 0.0f);
	glVertex3f(0.86f, 0.15f, 0.0f);

	glEnd();

	// central line
	glBegin(GL_QUADS);

	if (isReachedAtEnd)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorA);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(1.2f, 0.15f, 0.0f);
	glVertex3f(1.2f, -0.15f, 0.0f);
	glVertex3f(0.0f, -0.15f, 0.0f);

	glEnd();

	// bottom left vertical line
	glBegin(GL_QUADS);

	glVertex3f(0.0f, -0.15f, 0.0f);
	glVertex3f(0.3f, -0.15f, 0.0f);

	if (isReachedAtEnd)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorA);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.3f, -0.6f, 0.0f);
	glVertex3f(0.0f, -0.6f, 0.0f);

	glEnd();

	// bottom right vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEnd)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorA);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.86f, -0.6f, 0.0f);
	glVertex3f(1.2f, -0.6f, 0.0f);

	if (isReachedAtEnd)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorA);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(1.2f, -0.15f, 0.0f);
	glVertex3f(0.86f, -0.15f, 0.0f);

	glEnd();

	// bottom horizontal line
	glBegin(GL_QUADS);

	if (isReachedAtEnd)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorA);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, -0.9f, 0.0f);
	glVertex3f(0.3f, -0.9f, 0.0f);
	glVertex3f(0.3f, -0.6f, 0.0f);
	glVertex3f(0.0f, -0.6f, 0.0f);

	glVertex3f(0.86f, -0.9f, 0.0f);
	glVertex3f(1.2f, -0.9f, 0.0f);
	glVertex3f(1.2f, -0.6f, 0.0f);
	glVertex3f(0.86f, -0.6f, 0.0f);

	glEnd();
}

void letterR()
{
	// top horizontal line
	glBegin(GL_QUADS);

	if (isReachedAtEndForR)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.9f, 0.0f);
	glVertex3f(1.2f, 0.9f, 0.0f);
	glVertex3f(1.2f, 0.6f, 0.0f);
	glVertex3f(0.0f, 0.6f, 0.0f);

	glEnd();

	// top left vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEndForR)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.6f, 0.0f);
	glVertex3f(0.3f, 0.6f, 0.0f);

	if (isReachedAtEndForR)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.3f, 0.15f, 0.0f);
	glVertex3f(0.0f, 0.15f, 0.0f);

	glEnd();

	// top right vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEndForR)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.86f, 0.6f, 0.0f);
	glVertex3f(1.2f, 0.6f, 0.0f);

	if (isReachedAtEndForR)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(1.2f, 0.15f, 0.0f);
	glVertex3f(0.86f, 0.15f, 0.0f);

	glEnd();

	// central line
	glBegin(GL_QUADS);

	if (isReachedAtEndForR)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(1.2f, 0.15f, 0.0f);
	glVertex3f(1.2f, -0.15f, 0.0f);
	glVertex3f(0.0f, -0.15f, 0.0f);

	glEnd();

	// bottom left vertical line
	glBegin(GL_QUADS);

	glVertex3f(0.0f, -0.15f, 0.0f);
	glVertex3f(0.3f, -0.15f, 0.0f);

	if (isReachedAtEndForR)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.3f, -0.6f, 0.0f);
	glVertex3f(0.0f, -0.6f, 0.0f);

	glEnd();

	// bottom right vertical line
	glBegin(GL_QUADS);
	glVertex3f(0.65f, -0.6f, 0.0f);

	if (isReachedAtEndForR)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.96f, -0.6f, 0.0f);

	if (isReachedAtEndForR)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.6f, -0.15f, 0.0f);

	glVertex3f(0.26f, -0.15f, 0.0f);

	glEnd();

	// bottom left vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEndForR)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, -0.9f, 0.0f);
	glVertex3f(0.3f, -0.9f, 0.0f);
	glVertex3f(0.3f, -0.6f, 0.0f);
	glVertex3f(0.0f, -0.6f, 0.0f);

	glEnd();

	// bottom horizontal line
	glBegin(GL_QUADS);

	if (isReachedAtEndForR)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorR);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.91f, -0.9f, 0.0f);
	glVertex3f(1.2f, -0.9f, 0.0f);
	glVertex3f(0.96f, -0.6f, 0.0f);
	glVertex3f(0.65f, -0.6f, 0.0f);

	glEnd();
}

void letterT()
{
	// top horizontal line
	glBegin(GL_QUADS);

	if (isReachedAtEndForT)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorT);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.0f, 0.9f, 0.0f);
	glVertex3f(1.2f, 0.9f, 0.0f);
	glVertex3f(1.2f, 0.6f, 0.0f);
	glVertex3f(0.0f, 0.6f, 0.0f);

	glEnd();

	// top vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEndForT)
	{
		glColor4f(1.000, 0.600, 0.200, blendFactorT);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.45, 0.6, 0.0f);
	glVertex3f(0.75, 0.6, 0.0f);

	if (isReachedAtEndForT)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorT);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.75, 0.15, 0.0f);
	glVertex3f(0.45, 0.15, 0.0f);

	glEnd();

	// central line
	glBegin(GL_QUADS);

	if (isReachedAtEndForT)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorT);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.45f, 0.15f, 0.0f);
	glVertex3f(0.75f, 0.15f, 0.0f);
	glVertex3f(0.75f, -0.15f, 0.0f);
	glVertex3f(0.45f, -0.15f, 0.0f);

	glEnd();

	// bottom vertical line
	glBegin(GL_QUADS);

	if (isReachedAtEndForT)
	{
		glColor4f(1.0f, 1.0f, 1.0f, blendFactorT);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.45f, -0.15f, 0.0f);
	glVertex3f(0.75f, -0.15f, 0.0f);

	if (isReachedAtEndForT)
	{
		glColor4f(0.0745f, 0.5333f, 0.0314f, blendFactorT);
	}
	else
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex3f(0.75f, -0.9f, 0.0f);
	glVertex3f(0.45f, -0.9f, 0.0f);

	glEnd();
}

void initializePaths(void)
{
	GLfloat centerX = -2.6f;
	GLfloat centerY = 2.475f;
	GLfloat radius = 1.8f;

	// PATH 0: Top path
	paths[0].numPoints = 0;

	// Top-left arc
	for (float i = 160; i <= 270; i = i + 0.05f)
	{
		if (paths[0].numPoints >= MAX_POINTS - 1)
			break;

		float angle = i * 3.14159f / 180.0f;
		paths[0].x[paths[0].numPoints] = centerX + (cos(angle) * radius);
		paths[0].y[paths[0].numPoints] = centerY + (sin(angle) * radius);
		paths[0].numPoints++;
	}

	// Top horizontal line
	for (float x = -2.6f; x <= 2.6f; x = x + 0.001f)
	{
		if (paths[0].numPoints >= MAX_POINTS - 1)
			break;

		paths[0].x[paths[0].numPoints] = x;
		paths[0].y[paths[0].numPoints] = 0.675f;
		paths[0].numPoints++;
	}

	// Top-right arc
	centerX = 2.6f;
	for (float i = 270; i <= 380; i = i + 0.05f)
	{
		if (paths[0].numPoints >= MAX_POINTS - 1)
			break;

		float angle = i * 3.14159f / 180.0f;
		paths[0].x[paths[0].numPoints] = centerX + (cos(angle) * radius);
		paths[0].y[paths[0].numPoints] = centerY + (sin(angle) * radius);
		paths[0].numPoints++;
	}

	// PATH 1: Center line
	paths[1].numPoints = 0;
	for (float i = -4.8f; i <= 4.6f; i = i + 0.001f)
	{
		if (paths[1].numPoints >= MAX_POINTS - 1)
			break;

		paths[1].x[paths[1].numPoints] = i;
		paths[1].y[paths[1].numPoints] = 0.0f;
		paths[1].numPoints++;
	}

	// PATH 2: Bottom path
	paths[2].numPoints = 0;

	// Bottom-left arc
	centerX = -2.6f;
	centerY = -2.475f;
	for (float i = 200; i >= 90; i = i - 0.05f)
	{
		if (paths[2].numPoints >= MAX_POINTS - 1)
			break;

		float angle = i * 3.14159f / 180.0f;
		paths[2].x[paths[2].numPoints] = centerX + (cos(angle) * radius);
		paths[2].y[paths[2].numPoints] = centerY + (sin(angle) * radius);
		paths[2].numPoints++;
	}

	// Bottom horizontal line
	for (float x = -2.6f; x <= 2.6f; x = x + 0.001f)
	{
		if (paths[2].numPoints >= MAX_POINTS - 1)
			break;

		paths[2].x[paths[2].numPoints] = x;
		paths[2].y[paths[2].numPoints] = -0.675f;
		paths[2].numPoints++;
	}

	// Bottom-right arc
	centerX = 2.6f;
	centerY = -2.475f;
	for (float i = 90; i >= -20; i = i - 0.05f)
	{
		if (paths[2].numPoints >= MAX_POINTS - 1)
			break;

		float angle = i * 3.14159f / 180.0f;
		paths[2].x[paths[2].numPoints] = centerX + (cos(angle) * radius);
		paths[2].y[paths[2].numPoints] = centerY + (sin(angle) * radius);
		paths[2].numPoints++;
	}
}

void initializeObjects(void)
{
	objects[0].pathIndex = 0;
	objects[0].currentPoint = 0;
	objects[0].posX = paths[0].x[0];
	objects[0].posY = paths[0].y[0];
	objects[0].speed = 10;
	// objects[0].speed = 1;

	objects[1].pathIndex = 1;
	objects[1].currentPoint = 0;
	objects[1].posX = paths[1].x[0];
	objects[1].posY = paths[1].y[0];
	objects[1].speed = 10;
	// objects[1].speed = 1;

	objects[2].pathIndex = 2;
	objects[2].currentPoint = 0;
	objects[2].posX = paths[2].x[0];
	objects[2].posY = paths[2].y[0];
	objects[2].speed = 10;
	// objects[2].speed = 1;
}

void update(void)
{
	// Plane animation code
	// Only update plane animation if not yet complete
	if (planeAnimationStarted && animationComplete == 0)
	{
		frameCounter++;

		int allObjectsFinished = 1;

		for (int i = 0; i < 3; i++)
		{
			if (objects[i].currentPoint < paths[objects[i].pathIndex].numPoints - 1)
			{
				allObjectsFinished = 0;

				if (frameCounter % objects[i].speed == 0)
				{
					objects[i].currentPoint++;

					int pathIdx = objects[i].pathIndex;
					int pointIdx = objects[i].currentPoint;
					objects[i].posX = paths[pathIdx].x[pointIdx];
					objects[i].posY = paths[pathIdx].y[pointIdx];
				}
			}
		}

		if (allObjectsFinished == 1)
		{
			animationComplete = 1;
		}
	}

	// LETTERS ANIMATION
	// B movement
	if (xPositionForB < -3.95f)
	{
		xPositionForB = xPositionForB + INCREMENT_FACTOR;
	}

	if (objects[0].posX >= -1.8f)
	{
		blendFactorB = 1.0f; // this should blend slowly and only when plane is reached at end of the letter
		isReachedAtEndForB = TRUE;
	}

	// H Movements
	if (xPositionForB > -3.95f)
	{
		// H movement on X-axis
		if (xPositionForH < -2.70f)
		{
			xPositionForH = xPositionForH + INCREMENT_FACTOR;
		}

		// H movement on Y-axis
		if (yPositionForH > 0.0f)
		{
			yPositionForH = yPositionForH - INCREMENT_FACTOR;
		}
	}

	if (objects[0].posX >= -0.8f)
	{
		blendFactorH = 1.0f; // this should blend slowly and only when plane is reached at end of the letter
		isReachedAtEndForH = TRUE;
	}

	// A movements
	if (xPositionForH > -2.70f)
	{

		// A movement on X-axis
		if (xPositionForA < -1.45f)
		{
			xPositionForA = xPositionForA + INCREMENT_FACTOR;
		}

		// A movement on Y-axis
		if (yPositionForA < 0.0f)
		{
			yPositionForA = yPositionForA + INCREMENT_FACTOR;
		}
	}

	if (objects[0].posX >= 0.1f)
	{
		blendFactorA = 1.0f; // this should blend slowly and only when plane is reached at end of the letter
		isReachedAtEndForA = TRUE;
	}

	// R movements
	if (xPositionForA > -1.45f)
	{

		// R movement on X-axis
		if (xPositionForR > -0.20f)
		{
			xPositionForR = xPositionForR - INCREMENT_FACTOR;
		}

		// R movement on Y-axis
		if (yPositionForR > 0.0f)
		{
			yPositionForR = yPositionForR - INCREMENT_FACTOR;
		}
	}

	if (objects[0].posX >= 1.1f)
	{
		blendFactorR = 1.0f; // this should blend slowly and only when plane is reached at end of the letter
		isReachedAtEndForR = TRUE;
	}

	// Second A Movements
	if (xPositionForR < -0.20f)
	{

		// A movement on X-axis
		if (xPositionForSecondA > 1.05f)
		{
			xPositionForSecondA = xPositionForSecondA - INCREMENT_FACTOR;
		}

		// A movement on Y-axis
		if (yPositionForSecondA < 0.0f)
		{
			yPositionForSecondA = yPositionForSecondA + INCREMENT_FACTOR;
		}
	}

	if (objects[0].posX >= 2.1f)
	{
		blendFactorForSecondA = 1.0f; // this should blend slowly and only when plane is reached at end of the letter
		isReachedAtEndForSecondA = TRUE;
	}

	// T Movements
	if (xPositionForSecondA < 1.05f)
	{

		if (xPositionForT > 2.30f)
		{
			xPositionForT = xPositionForT - INCREMENT_FACTOR;
		}
	}

	if (objects[0].posX >= 3.0f)
	{
		isReachedAtEndForT = TRUE;
		blendFactorT = 1.0f;
	}

	if ((xPositionForT < 2.30f) && !planeAnimationStarted)
	{
		planeAnimationStarted = 1; // Mark that planes should now animate
		frameCounter = 0;		   // Reset frame counter for clean start
	}
}

void renderFighterJet(float xPosition, float yPosition)
{
	glBegin(GL_QUADS);

	glColor3f(0.35f, 0.38f, 0.42f);
	glVertex2f(xPosition - 0.075f, yPosition + 0.12f);
	glVertex2f(xPosition, yPosition + 0.12f);

	glColor3f(0.28f, 0.30f, 0.34f);
	glVertex2f(xPosition, yPosition + 0.07f);
	glVertex2f(xPosition - 0.075f, yPosition + 0.07f);

	glColor3f(0.35f, 0.38f, 0.42f);
	glVertex2f(xPosition - 0.075f, yPosition - 0.06f);
	glVertex2f(xPosition, yPosition - 0.06f);

	glColor3f(0.28f, 0.30f, 0.34f);
	glVertex2f(xPosition, yPosition - 0.11f);
	glVertex2f(xPosition - 0.075f, yPosition - 0.11f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.45f, 0.50f, 0.58f);
	glVertex2f(xPosition - 0.03f, yPosition + 0.2f);
	glVertex2f(xPosition, yPosition + 0.2f);

	glColor3f(0.32f, 0.38f, 0.45f);
	glVertex2f(xPosition, yPosition - 0.2f);
	glVertex2f(xPosition - 0.03f, yPosition - 0.2f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.38f, 0.42f, 0.48f);
	glVertex2f(xPosition, yPosition + 0.2f);

	glColor3f(0.25f, 0.28f, 0.32f);
	glVertex2f(xPosition + 0.05f, yPosition);

	glColor3f(0.38f, 0.42f, 0.48f);
	glVertex2f(xPosition, yPosition - 0.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.38f, 0.42f, 0.48f);
	glVertex2f(xPosition, yPosition + 0.07f);
	glVertex2f(xPosition + 0.20f, yPosition + 0.07f);

	glColor3f(0.38f, 0.42f, 0.48f);
	glVertex2f(xPosition + 0.25f, yPosition);
	glVertex2f(xPosition + 0.25f, yPosition);

	glColor3f(0.38f, 0.42f, 0.48f);
	glVertex2f(xPosition + 0.20f, yPosition - 0.07f);
	glVertex2f(xPosition, yPosition - 0.07f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.40f, 0.44f, 0.50f);
	glVertex2f(xPosition + 0.03f, yPosition + 0.3f);
	glVertex2f(xPosition + 0.07f, yPosition + 0.3f);

	glColor3f(0.32f, 0.36f, 0.42f);
	glVertex2f(xPosition + 0.20f, yPosition + 0.07f);
	glVertex2f(xPosition + 0.07f, yPosition + 0.07f);

	glColor3f(0.40f, 0.44f, 0.50f);
	glVertex2f(xPosition + 0.03f, yPosition - 0.3f);
	glVertex2f(xPosition + 0.07f, yPosition - 0.3f);

	glColor3f(0.32f, 0.36f, 0.42f);
	glVertex2f(xPosition + 0.20f, yPosition - 0.07f);
	glVertex2f(xPosition + 0.07f, yPosition - 0.07f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.30f, 0.32f, 0.36f);
	glVertex2f(xPosition + 0.225f, yPosition + 0.03f);
	glVertex2f(xPosition + 0.28f, yPosition + 0.03f);

	glColor3f(0.22f, 0.24f, 0.28f);
	glVertex2f(xPosition + 0.28f, yPosition - 0.03f);
	glVertex2f(xPosition + 0.225f, yPosition - 0.03f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.28f, 0.30f, 0.34f);
	glVertex2f(xPosition + 0.28f, yPosition + 0.03f);

	glColor3f(0.18f, 0.20f, 0.24f);
	glVertex2f(xPosition + 0.4f, yPosition);

	glColor3f(0.28f, 0.30f, 0.34f);
	glVertex2f(xPosition + 0.28f, yPosition - 0.03f);

	glEnd();
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
