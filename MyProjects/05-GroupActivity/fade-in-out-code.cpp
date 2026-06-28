#ifdef __APPLE__

// macOS Headers
#define GL_SILENCE_DEPRECATION

// Use FreeGLUT installed via Homebrew if available
#include <GLUT/glut.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// Compatibility for macOS GLUT missing FreeGLUT functions

#ifndef glutCloseFunc
#define glutCloseFunc(func) atexit(func)
#endif

#ifndef glutLeaveMainLoop
#define glutLeaveMainLoop() exit(0)
#endif

#ifndef glutLeaveFullScreen
#define glutLeaveFullScreen()         \
	do                                \
	{                                 \
		glutReshapeWindow(800, 600);  \
		glutPositionWindow(100, 100); \
	} while (0)
#endif

#elif defined(_WIN32) || defined(_WIN64)

// Windows Headers
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#endif

// Standard C headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define VALUE_FROM_PERCENT(complete_value, percent) ((complete_value * percent) / 100)

#define PSH_X(xCordinate) (VALUE_FROM_PERCENT(xCordinate, psh_width_percentage) + psh_x_pos)
#define PSH_Y(yCordinate) (VALUE_FROM_PERCENT(yCordinate, psh_height_percentage) + psh_y_pos)

void VitthalTimer(int value);
void psh_drawVitthal(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);
void Tila(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);
void renderGroupPresents(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);

// Global variable declerations
bool bIsFullScreen = false;
float xPosition = 0.0f;

float ScreenFadeFactor = 1.0f; // Start fully black (faded in)
bool ScreenFade = true;
bool FadeIn = true, FadeOut = false;

int scence = 0;
bool bRenderGroupPresentsFIn = false;
bool bRenderGroupPresentsFOut = false;

bool bProjectNameFIn = false;
bool bProjectNameFOut = false;

bool bVitthalFIn = false;
bool bVitthalFout = false;

int main(int argc, char *argv[])
{
	// function declarations
	void initialize(void);
	void uninitialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);

	// code
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First RTR7 Program : Sagar Sambhaji Raut");

	initialize();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	// flow should not come here
	return (0);
}

void initialize(void)
{
	// code
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void resize(int width, int height)
{
	// code
	if (height <= 0)
		height = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void)
{
	void rectMove(float xPosition);

	void ScreenQuad(void);
	void ScreenFadeIn(int value);
	void ScreenFadeOut(int value);

	// code
	glClear(GL_COLOR_BUFFER_BIT);

	switch (scence)
	{
	case 0: // sence 1 atromedicomp
		if (bRenderGroupPresentsFIn != true)
		{

			if (FadeIn)
			{
				ScreenFadeIn(ScreenFadeFactor);
				renderGroupPresents(0.0f, 0.0f, 100, 100);
			}
			if (ScreenFadeFactor <= 0.0f)
			{
				bRenderGroupPresentsFIn = true;
				FadeIn = false;
				FadeOut = true;
			}
		}
		else
		{
			if (FadeOut)
			{
				ScreenFadeOut(ScreenFadeFactor);
				renderGroupPresents(0.0f, 0.0f, 100, 100);
			}
			if (ScreenFadeFactor >= 1.0f)
			{
				bRenderGroupPresentsFOut = true;
				// Reset for next scene
				FadeIn = true;
				FadeOut = false;
				ScreenFadeFactor = 1.0f;
				scence++;
			}
		}
		break;

	case 1:
		if (bProjectNameFIn != true)
		{
			if (FadeIn)
			{
				ScreenFadeIn(ScreenFadeFactor);
				Tila(0.0f, -1.0f, 400, 200);
			}
			if (ScreenFadeFactor <= 0.0f)
			{
				bProjectNameFIn = true;
				FadeIn = false;
				FadeOut = true;
			}
		}
		else
		{
			if (FadeOut)
			{
				ScreenFadeOut(ScreenFadeFactor);
				Tila(0.0f, -1.0f, 400, 200);
			}
			if (ScreenFadeFactor >= 1.0f)
			{
				bProjectNameFOut = true;
				// Reset for next scene
				FadeIn = true;
				FadeOut = false;
				ScreenFadeFactor = 1.0f;
				scence++;
			}
		}
		break;

	case 2:
		if (bVitthalFIn != true)
		{
			if (FadeIn)
			{
				ScreenFadeIn(ScreenFadeFactor);
				psh_drawVitthal(0.0f, 0.0f, 60, 95);
			}
			if (ScreenFadeFactor <= 0.0f)
			{
				bVitthalFIn = true;
				FadeIn = false;
				FadeOut = true;
			}
		}

		else
		{
			if (FadeOut)
			{
				ScreenFadeOut(ScreenFadeFactor);
				psh_drawVitthal(0.0f, 0.0f, 60, 95);
			}

			if (ScreenFadeFactor >= 1.0f)
			{
				bVitthalFout = true;
				scence++;
				FadeIn = true;
				FadeOut = false;
			}
		}
		break;
	}

	ScreenQuad();
	glutSwapBuffers();
	glutPostRedisplay();
}

void rectMove(float xPosition)
{
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.2f, 0.2f + xPosition, 0.0f);

	// glColor3f(0.0f,1.0f,0.0f);
	glVertex3f(-0.2f, 0.2f + xPosition, 0.0f);

	// glColor3f(0.0f),PSH_Y(0.0f),PSH_Y(1.0f));
	glVertex3f(-0.2f, -0.2f + xPosition, 0.0f);

	// glColor3f(0.0f),PSH_Y(0.0f),PSH_Y(1.0f));
	glVertex3f(0.2f, -0.2f + xPosition, 0.0f);

	glEnd();
}

void keyboard(unsigned char key, int x, int y)
{
	// code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if (bIsFullScreen == false)
		{
			glutFullScreen();
			bIsFullScreen = true;
		}
		else
		{
			glutLeaveFullScreen();
			bIsFullScreen = false;
		}
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	// code
	switch (button)
	{
	case GLUT_RIGHT_BUTTON:
		glutLeaveMainLoop();
		break;
	default:
		break;
	}
}

void uninitialize(void)
{
	// code
}

void ScreenQuad(void)
{
	glColor4f(0.0f, 0.0f, 0.0f, ScreenFadeFactor);
	glBegin(GL_QUADS);
	{
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
	}
	glEnd();
}

void ScreenFadeIn(int value)
{
	if (FadeIn == true)
	{
		ScreenFadeFactor = ScreenFadeFactor - 0.000006f;
		if (ScreenFadeFactor <= 0.0f)
		{
			// ScreenFade = false;
			FadeIn = false;
			FadeOut = true;
		}

		glutPostRedisplay();
		glutTimerFunc(60, ScreenFadeIn, 0);
	}
}

void ScreenFadeOut(int value)
{
	if (FadeOut == true)
	{
		ScreenFadeFactor = ScreenFadeFactor + 0.000006f;
		if (ScreenFadeFactor >= 1.0f)
		{
			// ScreenFade = true;
			FadeIn = true;
			FadeOut = false;
		}
		glutPostRedisplay();
		glutTimerFunc(60, ScreenFadeOut, 0);
	}
}

void VitthalTimer(int value)
{
	// Start fade out after 300 seconds
	FadeIn = false;
	FadeOut = true;
}

void renderGroupPresents(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage)
{

	// R
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.50f, 0.0f);
	glVertex2f(PSH_X(-0.42f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.39f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.39f), PSH_Y(0.50f));
	glVertex2f(PSH_X(-0.42f), PSH_Y(0.50f));

	glVertex2f(PSH_X(-0.42f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(0.80f));
	glVertex2f(PSH_X(-0.42f), PSH_Y(0.80f));
	glVertex2f(PSH_X(-0.42f), PSH_Y(0.70f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(0.70f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(0.65f));
	glVertex2f(PSH_X(-0.42f), PSH_Y(0.65f));
	glVertex2f(PSH_X(-0.33f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(0.65f));
	glVertex2f(PSH_X(-0.33f), PSH_Y(0.65f));
	glVertex2f(PSH_X(-0.39f), PSH_Y(0.65f));
	glVertex2f(PSH_X(-0.36f), PSH_Y(0.65f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(0.50f));
	glVertex2f(PSH_X(-0.33f), PSH_Y(0.50f));
	glEnd();

	// E
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.60f, 0.0f);
	glVertex2f(PSH_X(-0.28f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.25f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.25f), PSH_Y(0.50f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(0.50f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.16f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.16f), PSH_Y(0.80f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(0.80f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(0.70f));
	glVertex2f(PSH_X(-0.18f), PSH_Y(0.70f));
	glVertex2f(PSH_X(-0.18f), PSH_Y(0.65f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(0.65f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(0.55f));
	glVertex2f(PSH_X(-0.16f), PSH_Y(0.55f));
	glVertex2f(PSH_X(-0.16f), PSH_Y(0.50f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(0.50f));
	glEnd();

	// N
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.40f, 0.0f);
	glVertex2f(PSH_X(-0.14f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.11f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.11f), PSH_Y(0.50f));
	glVertex2f(PSH_X(-0.14f), PSH_Y(0.50f));
	glVertex2f(PSH_X(-0.05f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.02f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.02f), PSH_Y(0.50f));
	glVertex2f(PSH_X(-0.05f), PSH_Y(0.50f));
	glVertex2f(PSH_X(-0.11f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.08f), PSH_Y(0.85f));
	glVertex2f(PSH_X(-0.05f), PSH_Y(0.50f));
	glVertex2f(PSH_X(-0.08f), PSH_Y(0.50f));
	glEnd();

	// D
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.70f, 0.0f);
	glVertex2f(PSH_X(0.00f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.03f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.03f), PSH_Y(0.50f));
	glVertex2f(PSH_X(0.00f), PSH_Y(0.50f));
	glVertex2f(PSH_X(0.00f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.09f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.09f), PSH_Y(0.80f));
	glVertex2f(PSH_X(0.00f), PSH_Y(0.80f));
	glVertex2f(PSH_X(0.00f), PSH_Y(0.55f));
	glVertex2f(PSH_X(0.09f), PSH_Y(0.55f));
	glVertex2f(PSH_X(0.09f), PSH_Y(0.50f));
	glVertex2f(PSH_X(0.00f), PSH_Y(0.50f));
	glVertex2f(PSH_X(0.09f), PSH_Y(0.80f));
	glVertex2f(PSH_X(0.12f), PSH_Y(0.80f));
	glVertex2f(PSH_X(0.12f), PSH_Y(0.55f));
	glVertex2f(PSH_X(0.09f), PSH_Y(0.55f));
	glEnd();

	// E
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.30f, 0.0f);
	glVertex2f(PSH_X(0.14f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.17f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.17f), PSH_Y(0.50f));
	glVertex2f(PSH_X(0.14f), PSH_Y(0.50f));
	glVertex2f(PSH_X(0.14f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.26f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.26f), PSH_Y(0.80f));
	glVertex2f(PSH_X(0.14f), PSH_Y(0.80f));
	glVertex2f(PSH_X(0.14f), PSH_Y(0.70f));
	glVertex2f(PSH_X(0.24f), PSH_Y(0.70f));
	glVertex2f(PSH_X(0.24f), PSH_Y(0.65f));
	glVertex2f(PSH_X(0.14f), PSH_Y(0.65f));
	glVertex2f(PSH_X(0.14f), PSH_Y(0.55f));
	glVertex2f(PSH_X(0.26f), PSH_Y(0.55f));
	glVertex2f(PSH_X(0.26f), PSH_Y(0.50f));
	glVertex2f(PSH_X(0.14f), PSH_Y(0.50f));
	glEnd();

	// R
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.80f, 0.0f);
	glVertex2f(PSH_X(0.28f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.31f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.31f), PSH_Y(0.50f));
	glVertex2f(PSH_X(0.28f), PSH_Y(0.50f));
	glVertex2f(PSH_X(0.28f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.40f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.40f), PSH_Y(0.80f));
	glVertex2f(PSH_X(0.28f), PSH_Y(0.80f));
	glVertex2f(PSH_X(0.28f), PSH_Y(0.70f));
	glVertex2f(PSH_X(0.40f), PSH_Y(0.70f));
	glVertex2f(PSH_X(0.40f), PSH_Y(0.65f));
	glVertex2f(PSH_X(0.28f), PSH_Y(0.65f));
	glVertex2f(PSH_X(0.37f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.40f), PSH_Y(0.85f));
	glVertex2f(PSH_X(0.40f), PSH_Y(0.65f));
	glVertex2f(PSH_X(0.37f), PSH_Y(0.65f));
	glVertex2f(PSH_X(0.31f), PSH_Y(0.65f));
	glVertex2f(PSH_X(0.34f), PSH_Y(0.65f));
	glVertex2f(PSH_X(0.40f), PSH_Y(0.50f));
	glVertex2f(PSH_X(0.37f), PSH_Y(0.50f));
	glEnd();

	// G
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.55f, 0.0f);
	glVertex2f(PSH_X(-0.35f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.23f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.23f), PSH_Y(0.30f));
	glVertex2f(PSH_X(-0.35f), PSH_Y(0.30f));
	glVertex2f(PSH_X(-0.35f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.32f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.32f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.35f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.35f), PSH_Y(0.05f));
	glVertex2f(PSH_X(-0.23f), PSH_Y(0.05f));
	glVertex2f(PSH_X(-0.23f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.35f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.26f), PSH_Y(0.20f));
	glVertex2f(PSH_X(-0.23f), PSH_Y(0.20f));
	glVertex2f(PSH_X(-0.23f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.26f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.32f), PSH_Y(0.20f));
	glVertex2f(PSH_X(-0.23f), PSH_Y(0.20f));
	glVertex2f(PSH_X(-0.23f), PSH_Y(0.15f));
	glVertex2f(PSH_X(-0.32f), PSH_Y(0.15f));
	glEnd();

	// R
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.45f, 0.0f);
	glVertex2f(PSH_X(-0.21f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.18f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.18f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.21f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.21f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.09f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.09f), PSH_Y(0.30f));
	glVertex2f(PSH_X(-0.21f), PSH_Y(0.30f));
	glVertex2f(PSH_X(-0.21f), PSH_Y(0.20f));
	glVertex2f(PSH_X(-0.09f), PSH_Y(0.20f));
	glVertex2f(PSH_X(-0.09f), PSH_Y(0.15f));
	glVertex2f(PSH_X(-0.21f), PSH_Y(0.15f));
	glVertex2f(PSH_X(-0.12f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.09f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.09f), PSH_Y(0.15f));
	glVertex2f(PSH_X(-0.12f), PSH_Y(0.15f));
	glVertex2f(PSH_X(-0.18f), PSH_Y(0.15f));
	glVertex2f(PSH_X(-0.15f), PSH_Y(0.15f));
	glVertex2f(PSH_X(-0.09f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.12f), PSH_Y(0.00f));
	glEnd();

	// O
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.65f, 0.0f);
	glVertex2f(PSH_X(-0.07f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.04f), PSH_Y(0.35f));
	glVertex2f(PSH_X(-0.04f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.07f), PSH_Y(0.00f));
	glVertex2f(PSH_X(0.02f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.05f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.05f), PSH_Y(0.00f));
	glVertex2f(PSH_X(0.02f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.07f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.05f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.05f), PSH_Y(0.30f));
	glVertex2f(PSH_X(-0.07f), PSH_Y(0.30f));
	glVertex2f(PSH_X(-0.07f), PSH_Y(0.05f));
	glVertex2f(PSH_X(0.05f), PSH_Y(0.05f));
	glVertex2f(PSH_X(0.05f), PSH_Y(0.00f));
	glVertex2f(PSH_X(-0.07f), PSH_Y(0.00f));
	glEnd();

	// U
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.35f, 0.0f);
	glVertex2f(PSH_X(0.07f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.10f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.10f), PSH_Y(0.00f));
	glVertex2f(PSH_X(0.07f), PSH_Y(0.00f));
	glVertex2f(PSH_X(0.16f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.19f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.19f), PSH_Y(0.00f));
	glVertex2f(PSH_X(0.16f), PSH_Y(0.00f));
	glVertex2f(PSH_X(0.07f), PSH_Y(0.05f));
	glVertex2f(PSH_X(0.19f), PSH_Y(0.05f));
	glVertex2f(PSH_X(0.19f), PSH_Y(0.00f));
	glVertex2f(PSH_X(0.07f), PSH_Y(0.00f));
	glEnd();

	// P
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.75f, 0.0f);
	glVertex2f(PSH_X(0.21f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.24f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.24f), PSH_Y(0.00f));
	glVertex2f(PSH_X(0.21f), PSH_Y(0.00f));
	glVertex2f(PSH_X(0.21f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.33f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.33f), PSH_Y(0.30f));
	glVertex2f(PSH_X(0.21f), PSH_Y(0.30f));
	glVertex2f(PSH_X(0.21f), PSH_Y(0.20f));
	glVertex2f(PSH_X(0.33f), PSH_Y(0.20f));
	glVertex2f(PSH_X(0.33f), PSH_Y(0.15f));
	glVertex2f(PSH_X(0.21f), PSH_Y(0.15f));
	glVertex2f(PSH_X(0.30f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.33f), PSH_Y(0.35f));
	glVertex2f(PSH_X(0.33f), PSH_Y(0.15f));
	glVertex2f(PSH_X(0.30f), PSH_Y(0.15f));
	glEnd();

	// P
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.25f, 0.0f);
	glVertex2f(PSH_X(-0.56f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.53f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.53f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.56f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.56f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.44f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.44f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(-0.56f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(-0.56f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(-0.44f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(-0.44f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.56f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.47f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.44f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.44f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.47f), PSH_Y(-0.35f));
	glEnd();

	// R
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.85f, 0.0f);
	glVertex2f(PSH_X(-0.42f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.39f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.39f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.42f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.42f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(-0.42f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(-0.42f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.42f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.33f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.33f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.39f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.36f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.30f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.33f), PSH_Y(-0.50f));
	glEnd();

	// E
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.50f, 0.0f);
	glVertex2f(PSH_X(-0.28f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.25f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.25f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.16f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.16f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(-0.18f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(-0.18f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(-0.45f));
	glVertex2f(PSH_X(-0.16f), PSH_Y(-0.45f));
	glVertex2f(PSH_X(-0.16f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.28f), PSH_Y(-0.50f));
	glEnd();

	// S
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.62f, 0.0f);
	glVertex2f(PSH_X(-0.14f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.02f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.02f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(-0.14f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(-0.14f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.11f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(-0.11f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.14f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.14f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(-0.02f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(-0.02f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.14f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.05f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.02f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(-0.02f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.05f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.14f), PSH_Y(-0.45f));
	glVertex2f(PSH_X(-0.02f), PSH_Y(-0.45f));
	glVertex2f(PSH_X(-0.02f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(-0.14f), PSH_Y(-0.50f));
	glEnd();

	// E
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.42f, 0.0f);
	glVertex2f(PSH_X(0.00f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.03f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.03f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.00f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.00f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.12f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.12f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(0.00f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(0.00f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(0.10f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(0.10f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(0.00f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(0.00f), PSH_Y(-0.45f));
	glVertex2f(PSH_X(0.12f), PSH_Y(-0.45f));
	glVertex2f(PSH_X(0.12f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.00f), PSH_Y(-0.50f));
	glEnd();

	// N
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.72f, 0.0f);
	glVertex2f(PSH_X(0.14f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.17f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.17f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.14f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.23f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.26f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.26f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.23f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.17f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.20f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.23f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.20f), PSH_Y(-0.50f));
	glEnd();

	// T
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.32f, 0.0f);
	glVertex2f(PSH_X(0.28f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.40f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.40f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(0.28f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(0.325f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.355f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.355f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.325f), PSH_Y(-0.50f));
	glEnd();

	// S
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.82f, 0.0f);
	glVertex2f(PSH_X(0.42f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.54f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.54f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(0.42f), PSH_Y(-0.20f));
	glVertex2f(PSH_X(0.42f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.45f), PSH_Y(-0.15f));
	glVertex2f(PSH_X(0.45f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(0.42f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(0.42f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(0.54f), PSH_Y(-0.30f));
	glVertex2f(PSH_X(0.54f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(0.42f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(0.51f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(0.54f), PSH_Y(-0.35f));
	glVertex2f(PSH_X(0.54f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.51f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.42f), PSH_Y(-0.45f));
	glVertex2f(PSH_X(0.54f), PSH_Y(-0.45f));
	glVertex2f(PSH_X(0.54f), PSH_Y(-0.50f));
	glVertex2f(PSH_X(0.42f), PSH_Y(-0.50f));
	glEnd();
}

void psh_drawVitthal(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage)
{

	// Mukut
	glColor3f(1.0f, 0.90f, 0.35f);
	glBegin(GL_POLYGON);

	glVertex3f(PSH_X(0.0f), PSH_Y(0.95f), 0.0f);
	glVertex3f(PSH_X(0.03f), PSH_Y(0.9f), 0.0f);
	glVertex3f(PSH_X(0.02f), PSH_Y(0.88f), 0.0f);
	glVertex3f(PSH_X(-0.02f), PSH_Y(0.88f), 0.0f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(0.9f), 0.0f);

	glEnd();

	glColor3f(0.95f, 0.80f, 0.20f);

	glBegin(GL_POLYGON);

	glVertex3f(PSH_X(0.03f), PSH_Y(0.88f), 0.0f);
	glVertex3f(PSH_X(0.04f), PSH_Y(0.87f), 0.0f);
	glVertex3f(PSH_X(0.03f), PSH_Y(0.86f), 0.0f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(0.86f), 0.0f);
	glVertex3f(PSH_X(-0.04f), PSH_Y(0.87f), 0.0f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(0.88f), 0.0f);

	glEnd();

	glColor3f(0.85f, 0.65f, 0.13f);

	glBegin(GL_POLYGON);

	glVertex3f(PSH_X(0.03f), PSH_Y(0.86f), 0.0f);
	glVertex3f(PSH_X(0.08f), PSH_Y(0.8f), 0.0f);
	glVertex3f(PSH_X(0.08f), PSH_Y(0.65f), 0.0f);
	glVertex3f(PSH_X(-0.08f), PSH_Y(0.65f), 0.0f);
	glVertex3f(PSH_X(-0.08f), PSH_Y(0.8f), 0.0f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(0.86f), 0.0f);

	glEnd();

	glColor3f(0.65f, 0.50f, 0.10f);

	glBegin(GL_POLYGON);

	glVertex3f(PSH_X(0.08f), PSH_Y(0.65f), 0.0f);
	glVertex3f(PSH_X(0.1f), PSH_Y(0.63f), 0.0f);
	glVertex3f(PSH_X(0.08f), PSH_Y(0.6f), 0.0f);
	glVertex3f(PSH_X(-0.08f), PSH_Y(0.6f), 0.0f);
	glVertex3f(PSH_X(-0.1f), PSH_Y(0.63f), 0.0f);
	glVertex3f(PSH_X(-0.08f), PSH_Y(0.65f), 0.0f);

	glEnd();

	// Stomach
	glColor3f(0.44f, 0.50f, 0.57f);

	glBegin(GL_QUADS);

	glVertex3f(PSH_X(0.2f), PSH_Y(0.4f), 0.0f);
	glVertex3f(PSH_X(0.2f), PSH_Y(0.22f), 0.0f);
	glVertex3f(PSH_X(-0.2f), PSH_Y(0.22f), 0.0f);
	glVertex3f(PSH_X(-0.2f), PSH_Y(0.4f), 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(PSH_X(0.2f), PSH_Y(0.22f), 0.0f);
	glVertex3f(PSH_X(0.15f), PSH_Y(0.18f), 0.0f);
	glVertex3f(PSH_X(-0.15f), PSH_Y(0.18f), 0.0f);
	glVertex3f(PSH_X(-0.2f), PSH_Y(0.22f), 0.0f);

	glEnd();

	glColor3f(0.27f, 0.30f, 0.34f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(PSH_X(0.0f), PSH_Y(0.33f));

	for (int i = 0; i <= 180; i++)
	{
		float a = (180.0f + i) * 3.1415926f / 180.0f;

		float x = VALUE_FROM_PERCENT(0.08f * cos(a), psh_width_percentage);
		float y = VALUE_FROM_PERCENT(0.08f * sin(a), psh_height_percentage);

		glVertex2f(PSH_X(0.0f) + x, PSH_Y(0.33f) + y);
	}
	glEnd();

	// Neck

	glColor3f(0.27f, 0.30f, 0.34f);

	glBegin(GL_QUADS);

	glVertex3f(PSH_X(0.08f), PSH_Y(0.45f), 0.0f);
	glVertex3f(PSH_X(0.08f), PSH_Y(0.33f), 0.0f);
	glVertex3f(PSH_X(-0.08f), PSH_Y(0.33f), 0.0f);
	glVertex3f(PSH_X(-0.08f), PSH_Y(0.45f), 0.0f);

	glEnd();

	// Face
	glColor3f(0.44f, 0.50f, 0.57f);
	glBegin(GL_QUADS);

	glVertex3f(PSH_X(0.08f), PSH_Y(0.6f), 0.0f);
	glVertex3f(PSH_X(0.08f), PSH_Y(0.45f), 0.0f);
	glVertex3f(PSH_X(-0.08f), PSH_Y(0.45f), 0.0f);
	glVertex3f(PSH_X(-0.08f), PSH_Y(0.6f), 0.0f);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(PSH_X(0.0f), PSH_Y(0.45f));

	for (int i = 0; i <= 180; i++)
	{
		float a = (180.0f + i) * 3.1415926f / 180.0f;

		float x = VALUE_FROM_PERCENT(0.08f * cos(a), psh_width_percentage);
		float y = VALUE_FROM_PERCENT(0.08f * sin(a), psh_height_percentage);

		glVertex2f(PSH_X(0.0f) + x, PSH_Y(0.45f) + y);
	}

	glEnd();
	// Face End

	// Ears
	glColor3f(0.44f, 0.50f, 0.57f);

	glBegin(GL_QUADS);

	glVertex3f(PSH_X(0.08f), PSH_Y(0.59f), 0.0f);
	glVertex3f(PSH_X(0.1f), PSH_Y(0.59f), 0.0f);
	glVertex3f(PSH_X(0.1f), PSH_Y(0.45f), 0.0f);
	glVertex3f(PSH_X(0.08f), PSH_Y(0.45f), 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(PSH_X(-0.08f), PSH_Y(0.59f), 0.0f);
	glVertex3f(PSH_X(-0.1f), PSH_Y(0.59f), 0.0f);
	glVertex3f(PSH_X(-0.1f), PSH_Y(0.45f), 0.0f);
	glVertex3f(PSH_X(-0.08f), PSH_Y(0.45f), 0.0f);

	glEnd();

	glColor3f(0.92f, 0.79f, 0.20f);

	glBegin(GL_TRIANGLES);

	glVertex3f(PSH_X(0.1f), PSH_Y(0.5f), 0.0f);
	glVertex3f(PSH_X(0.25f), PSH_Y(0.4f), 0.0f);
	glVertex3f(PSH_X(0.1f), PSH_Y(0.4f), 0.0f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glVertex3f(PSH_X(0.2f), PSH_Y(0.43f), 0.0f);
	glVertex3f(PSH_X(0.25f), PSH_Y(0.46f), 0.0f);
	glVertex3f(PSH_X(0.25f), PSH_Y(0.4f), 0.0f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glVertex3f(PSH_X(-0.1f), PSH_Y(0.5f), 0.0f);
	glVertex3f(PSH_X(-0.25f), PSH_Y(0.4f), 0.0f);
	glVertex3f(PSH_X(-0.1f), PSH_Y(0.4f), 0.0f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glVertex3f(PSH_X(-0.2f), PSH_Y(0.43f), 0.0f);
	glVertex3f(PSH_X(-0.25f), PSH_Y(0.46f), 0.0f);
	glVertex3f(PSH_X(-0.25f), PSH_Y(0.4f), 0.0f);

	glEnd();
	// End of Ear

	// Dhotar
	glColor3f(0.486f, 0.631f, 0.373f);

	glBegin(GL_POLYGON);

	glColor3f(0.65f, 0.80f, 0.50f);
	glVertex3f(PSH_X(0.15f), PSH_Y(-0.03f), 0.0f);

	glColor3f(0.60f, 0.75f, 0.45f);
	glVertex3f(PSH_X(0.2f), PSH_Y(-0.07f), 0.0f);

	glColor3f(0.30f, 0.45f, 0.22f);
	glVertex3f(PSH_X(0.2f), PSH_Y(-0.2f), 0.0f);

	glColor3f(0.25f, 0.38f, 0.18f);
	glVertex3f(PSH_X(0.18f), PSH_Y(-0.22f), 0.0f);

	glColor3f(0.30f, 0.45f, 0.22f);
	glVertex3f(PSH_X(0.13f), PSH_Y(-0.22f), 0.0f);

	glColor3f(0.50f, 0.68f, 0.38f);
	glVertex3f(PSH_X(0.03f), PSH_Y(-0.15f), 0.0f);

	glColor3f(0.60f, 0.75f, 0.45f);
	glVertex3f(PSH_X(0.03f), PSH_Y(-0.1f), 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.65f, 0.80f, 0.50f);
	glVertex3f(PSH_X(-0.15f), PSH_Y(-0.03f), 0.0f);

	glColor3f(0.60f, 0.75f, 0.45f);
	glVertex3f(PSH_X(-0.2f), PSH_Y(-0.07f), 0.0f);

	glColor3f(0.30f, 0.45f, 0.22f);
	glVertex3f(PSH_X(-0.2f), PSH_Y(-0.2f), 0.0f);

	glColor3f(0.25f, 0.38f, 0.18f);
	glVertex3f(PSH_X(-0.18f), PSH_Y(-0.22f), 0.0f);

	glColor3f(0.30f, 0.45f, 0.22f);
	glVertex3f(PSH_X(-0.13f), PSH_Y(-0.22f), 0.0f);

	glColor3f(0.50f, 0.68f, 0.38f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(-0.15f), 0.0f);

	glColor3f(0.60f, 0.75f, 0.45f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(-0.1f), 0.0f);

	glEnd();

	// Stomach last part
	glColor3f(0.44f, 0.50f, 0.57f);

	glBegin(GL_QUADS);

	glVertex3f(PSH_X(0.15f), PSH_Y(0.18f), 0.0f);
	glVertex3f(PSH_X(0.15f), PSH_Y(-0.05f), 0.0f);
	glVertex3f(PSH_X(-0.15f), PSH_Y(-0.05f), 0.0f);
	glVertex3f(PSH_X(-0.15f), PSH_Y(0.18f), 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(PSH_X(0.15f), PSH_Y(-0.05f), 0.0f);
	glVertex3f(PSH_X(0.1f), PSH_Y(-0.1f), 0.0f);
	glVertex3f(PSH_X(-0.1f), PSH_Y(-0.1f), 0.0f);
	glVertex3f(PSH_X(-0.15f), PSH_Y(-0.05f), 0.0f);

	glEnd();
	// End of Stomach

	// broach
	glColor3f(0.92f, 0.79f, 0.20f);
	glBegin(GL_POLYGON);

	glVertex3f(PSH_X(0.03f), PSH_Y(-0.08f), 0.0f);
	glVertex3f(PSH_X(0.05f), PSH_Y(-0.1f), 0.0f);
	glVertex3f(PSH_X(0.05f), PSH_Y(-0.13f), 0.0f);
	glVertex3f(PSH_X(0.03f), PSH_Y(-0.15f), 0.0f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(-0.15f), 0.0f);
	glVertex3f(PSH_X(-0.05f), PSH_Y(-0.13f), 0.0f);
	glVertex3f(PSH_X(-0.05f), PSH_Y(-0.1f), 0.0f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(-0.08f), 0.0f);

	glEnd();
	// End of Broach

	// Vit
	glColor3f(0.24f, 0.13f, 0.02f);
	glBegin(GL_QUADS);

	glVertex3f(PSH_X(0.15f), PSH_Y(-0.75f), 0.0f);
	glVertex3f(PSH_X(0.15f), PSH_Y(-0.85f), 0.0f);
	glVertex3f(PSH_X(-0.15f), PSH_Y(-0.85f), 0.0f);
	glVertex3f(PSH_X(-0.15f), PSH_Y(-0.75f), 0.0f);

	glEnd();
	// End of Vit

	// Dhotar

	glBegin(GL_POLYGON);

	glColor3f(0.98f, 0.90f, 0.40f);
	glVertex3f(PSH_X(0.03f), PSH_Y(-0.15f), 0.0f);
	glColor3f(0.95f, 0.85f, 0.30f);
	glVertex3f(PSH_X(0.13f), PSH_Y(-0.22f), 0.0f);

	glColor3f(0.85f, 0.70f, 0.15f);
	glVertex3f(PSH_X(0.19f), PSH_Y(-0.21f), 0.0f);
	glVertex3f(PSH_X(0.19f), PSH_Y(-0.5f), 0.0f);

	glColor3f(0.55f, 0.45f, 0.08f);
	glVertex3f(PSH_X(0.15f), PSH_Y(-0.55f), 0.0f);

	glColor3f(0.98f, 0.90f, 0.40f);
	glVertex3f(PSH_X(0.15f), PSH_Y(-0.7f), 0.0f);
	glColor3f(0.85f, 0.70f, 0.15f);
	glVertex3f(PSH_X(0.1f), PSH_Y(-0.75f), 0.0f);
	glColor3f(0.45f, 0.35f, 0.06f);
	glVertex3f(PSH_X(0.1f), PSH_Y(-0.8f), 0.0f);
	glColor3f(0.95f, 0.85f, 0.30f);
	glVertex3f(PSH_X(0.05f), PSH_Y(-0.8f), 0.0f);
	glVertex3f(PSH_X(0.05f), PSH_Y(-0.75f), 0.0f);
	glColor3f(0.95f, 0.85f, 0.30f);
	glVertex3f(PSH_X(0.0f), PSH_Y(-0.7f), 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.98f, 0.90f, 0.40f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(-0.15f), 0.0f);
	glColor3f(0.95f, 0.85f, 0.30f);
	glVertex3f(PSH_X(-0.13f), PSH_Y(-0.22f), 0.0f);

	glColor3f(0.85f, 0.70f, 0.15f);
	glVertex3f(PSH_X(-0.19f), PSH_Y(-0.21f), 0.0f);
	glVertex3f(PSH_X(-0.19f), PSH_Y(-0.5f), 0.0f);

	glColor3f(0.55f, 0.45f, 0.08f);
	glVertex3f(PSH_X(-0.15f), PSH_Y(-0.55f), 0.0f);

	glColor3f(0.98f, 0.90f, 0.40f);
	glVertex3f(PSH_X(-0.15f), PSH_Y(-0.7f), 0.0f);
	glColor3f(0.85f, 0.70f, 0.15f);
	glVertex3f(PSH_X(-0.1f), PSH_Y(-0.75f), 0.0f);
	glColor3f(0.45f, 0.35f, 0.06f);
	glVertex3f(PSH_X(-0.1f), PSH_Y(-0.8f), 0.0f);
	glColor3f(0.95f, 0.85f, 0.30f);
	glVertex3f(PSH_X(-0.05f), PSH_Y(-0.8f), 0.0f);
	glVertex3f(PSH_X(-0.05f), PSH_Y(-0.75f), 0.0f);
	glColor3f(0.95f, 0.85f, 0.30f);
	glVertex3f(PSH_X(-0.0f), PSH_Y(-0.7f), 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.70f, 0.85f, 0.50f);
	glVertex3f(PSH_X(0.03f), PSH_Y(-0.15f), 0.0f);

	glColor3f(0.45f, 0.60f, 0.30f);
	glVertex3f(PSH_X(0.03f), PSH_Y(-0.6f), 0.0f);

	glColor3f(0.25f, 0.35f, 0.15f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(-0.6f), 0.0f);

	glColor3f(0.55f, 0.70f, 0.35f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(-0.15f), 0.0f);

	glEnd();

	// End of Dhotar

	// Shela
	glBegin(GL_POLYGON);

	glColor3f(0.85f, 0.25f, 0.20f);
	glVertex3f(PSH_X(0.15f), PSH_Y(0.05f), 0.0f);

	glColor3f(0.85f, 0.25f, 0.20f);
	glVertex3f(PSH_X(0.25f), PSH_Y(0.05f), 0.0f);

	glColor3f(0.75f, 0.20f, 0.16f);
	glVertex3f(PSH_X(0.4f), PSH_Y(-0.1f), 0.0f);

	glColor3f(0.45f, 0.10f, 0.08f);
	glVertex3f(PSH_X(0.4f), PSH_Y(-0.35f), 0.0f);

	glColor3f(0.35f, 0.08f, 0.06f);
	glVertex3f(PSH_X(0.35f), PSH_Y(-0.4f), 0.0f);

	glColor3f(0.30f, 0.06f, 0.05f);
	glVertex3f(PSH_X(0.35f), PSH_Y(-0.55f), 0.0f);

	glColor3f(0.45f, 0.10f, 0.08f);
	glVertex3f(PSH_X(0.24f), PSH_Y(-0.42f), 0.0f);

	glColor3f(0.55f, 0.14f, 0.10f);
	glVertex3f(PSH_X(0.24f), PSH_Y(-0.35f), 0.0f);

	glColor3f(0.65f, 0.18f, 0.12f);
	glVertex3f(PSH_X(0.2f), PSH_Y(-0.4f), 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.85f, 0.25f, 0.20f);
	glVertex3f(PSH_X(-0.15f), PSH_Y(0.05f), 0.0f);

	glColor3f(0.85f, 0.25f, 0.20f);
	glVertex3f(PSH_X(-0.25f), PSH_Y(0.05f), 0.0f);

	glColor3f(0.75f, 0.20f, 0.16f);
	glVertex3f(PSH_X(-0.4f), PSH_Y(-0.1f), 0.0f);

	glColor3f(0.45f, 0.10f, 0.08f);
	glVertex3f(PSH_X(-0.4f), PSH_Y(-0.35f), 0.0f);

	glColor3f(0.35f, 0.08f, 0.06f);
	glVertex3f(PSH_X(-0.35f), PSH_Y(-0.4f), 0.0f);

	glColor3f(0.30f, 0.06f, 0.05f);
	glVertex3f(PSH_X(-0.35f), PSH_Y(-0.55f), 0.0f);

	glColor3f(0.45f, 0.10f, 0.08f);
	glVertex3f(PSH_X(-0.24f), PSH_Y(-0.42f), 0.0f);

	glColor3f(0.55f, 0.14f, 0.10f);
	glVertex3f(PSH_X(-0.24f), PSH_Y(-0.35f), 0.0f);

	glColor3f(0.65f, 0.18f, 0.12f);
	glVertex3f(PSH_X(-0.2f), PSH_Y(-0.4f), 0.0f);

	glEnd();
	// End of Shela

	// Right Hand
	glColor3f(0.44f, 0.50f, 0.57f);
	glBegin(GL_QUADS);

	glVertex3f(PSH_X(0.2f), PSH_Y(0.4f), 0.0f);
	glVertex3f(PSH_X(0.43f), PSH_Y(0.25f), 0.0f);
	glVertex3f(PSH_X(0.32f), PSH_Y(0.21f), 0.0f);
	glVertex3f(PSH_X(0.2f), PSH_Y(0.28f), 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(PSH_X(0.43f), PSH_Y(0.25f), 0.0f);
	glVertex3f(PSH_X(0.32f), PSH_Y(-0.02f), 0.0f);
	glVertex3f(PSH_X(0.25f), PSH_Y(0.05f), 0.0f);
	glVertex3f(PSH_X(0.32f), PSH_Y(0.21f), 0.0f);

	glEnd();
	// End of Right Hand

	// Left Hands
	glColor3f(0.44f, 0.50f, 0.57f);
	glBegin(GL_QUADS);

	glVertex3f(PSH_X(-0.2f), PSH_Y(0.4f), 0.0f);
	glVertex3f(PSH_X(-0.43f), PSH_Y(0.25f), 0.0f);
	glVertex3f(PSH_X(-0.32f), PSH_Y(0.21f), 0.0f);
	glVertex3f(PSH_X(-0.2f), PSH_Y(0.28f), 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(PSH_X(-0.43f), PSH_Y(0.25f), 0.0f);
	glVertex3f(PSH_X(-0.32f), PSH_Y(-0.02f), 0.0f);
	glVertex3f(PSH_X(-0.25f), PSH_Y(0.05f), 0.0f);
	glVertex3f(PSH_X(-0.32f), PSH_Y(0.21f), 0.0f);

	glEnd();
	// End of Left Hand

	// Hand Jwellery
	glColor3f(0.95f, 0.80f, 0.20f);
	glBegin(GL_POLYGON);

	glVertex3f(PSH_X(0.29f), PSH_Y(0.34f), 0.0f);
	glVertex3f(PSH_X(0.28f), PSH_Y(0.31f), 0.0f);
	glVertex3f(PSH_X(0.29f), PSH_Y(0.28f), 0.0f);
	glVertex3f(PSH_X(0.33f), PSH_Y(0.28f), 0.0f);
	glVertex3f(PSH_X(0.35f), PSH_Y(0.3f), 0.0f);

	glEnd();

	glLineWidth(5.0f);
	glBegin(GL_LINES);

	glVertex2f(PSH_X(0.295f), PSH_Y(0.28f));
	glVertex2f(PSH_X(0.27f), PSH_Y(0.24f));

	glEnd();

	glColor3f(0.95f, 0.80f, 0.20f);
	glBegin(GL_POLYGON);

	glVertex3f(PSH_X(-0.29f), PSH_Y(0.34f), 0.0f);
	glVertex3f(PSH_X(-0.28f), PSH_Y(0.31f), 0.0f);
	glVertex3f(PSH_X(-0.29f), PSH_Y(0.28f), 0.0f);
	glVertex3f(PSH_X(-0.33f), PSH_Y(0.28f), 0.0f);
	glVertex3f(PSH_X(-0.35f), PSH_Y(0.3f), 0.0f);

	glEnd();

	glLineWidth(5.0f);
	glBegin(GL_LINES);

	glVertex2f(PSH_X(-0.295f), PSH_Y(0.28f));
	glVertex2f(PSH_X(-0.27f), PSH_Y(0.24f));

	glEnd();

	// Neckless
	glColor3f(0.95f, 0.80f, 0.20f);
	glBegin(GL_POLYGON);

	glVertex3f(PSH_X(0.02f), PSH_Y(0.25f), 0.0f);
	glVertex3f(PSH_X(0.03f), PSH_Y(0.23f), 0.0f);
	glVertex3f(PSH_X(0.03f), PSH_Y(0.22f), 0.0f);
	glVertex3f(PSH_X(0.02f), PSH_Y(0.20f), 0.0f);
	glVertex3f(PSH_X(-0.02f), PSH_Y(0.20f), 0.0f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(0.22f), 0.0f);
	glVertex3f(PSH_X(-0.03f), PSH_Y(0.23f), 0.0f);
	glVertex3f(PSH_X(-0.02f), PSH_Y(0.25f), 0.0f);

	glEnd();

	glLineWidth(6.0f);
	glBegin(GL_LINES);

	glVertex2f(PSH_X(0.1f), PSH_Y(0.4f));
	glVertex2f(PSH_X(0.1f), PSH_Y(0.32f));

	glEnd();

	glLineWidth(6.0f);
	glBegin(GL_LINES);

	glVertex2f(PSH_X(0.1f), PSH_Y(0.32f));
	glVertex2f(PSH_X(0.03f), PSH_Y(0.215f));

	glEnd();

	glLineWidth(6.0f);
	glBegin(GL_LINES);
	glVertex2f(PSH_X(-0.1f), PSH_Y(0.4f));
	glVertex2f(PSH_X(-0.1f), PSH_Y(0.32f));
	glEnd();

	glBegin(GL_LINES);

	glVertex2f(PSH_X(-0.1f), PSH_Y(0.32f));
	glVertex2f(PSH_X(-0.03f), PSH_Y(0.215f));

	glEnd();

	glLineWidth(6.0f);
	glBegin(GL_LINES);

	glVertex2f(PSH_X(0.1f), PSH_Y(0.32f));
	glVertex2f(PSH_X(0.1f), PSH_Y(0.18f));

	glEnd();

	glBegin(GL_LINES);

	glVertex2f(PSH_X(0.1f), PSH_Y(0.18f));
	glVertex2f(PSH_X(0.0f), PSH_Y(0.11f));

	glEnd();

	glBegin(GL_LINES);

	glVertex2f(PSH_X(-0.1f), PSH_Y(0.32f));
	glVertex2f(PSH_X(-0.1f), PSH_Y(0.18f));

	glEnd();

	glBegin(GL_LINES);

	glVertex2f(PSH_X(-0.1f), PSH_Y(0.18f));
	glVertex2f(PSH_X(-0.0f), PSH_Y(0.11f));

	glEnd();

	glPointSize(8.0f);
	glColor3f(0.85f, 0.25f, 0.20f);
	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.21f);
	glEnd();

	// Tila
	glColor3f(0.95f, 0.80f, 0.20f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(PSH_X(0.0f), PSH_Y(0.50f));

	for (int i = 0; i <= 360; i++)
	{
		float a = (360.0f + i) * 3.1415926f / 180.0f;

		float x = VALUE_FROM_PERCENT(0.03f * cos(a), psh_width_percentage);
		float y = VALUE_FROM_PERCENT(0.035f * sin(a), psh_height_percentage);

		glVertex2f(PSH_X(0.0f) + x, PSH_Y(0.56f) + y);
	}
	glEnd();

	glPointSize(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.53f);
	glEnd();
}

void Tila(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage)
{
	// Tila
	glColor3f(0.95f, 0.80f, 0.20f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(PSH_X(0.0f), PSH_Y(0.50f));

	for (int i = 0; i <= 360; i++)
	{
		float a = (360.0f + i) * 3.1415926f / 180.0f;

		float x = VALUE_FROM_PERCENT(0.03f * cos(a), psh_width_percentage);
		float y = VALUE_FROM_PERCENT(0.035f * sin(a), psh_height_percentage);

		glVertex2f(PSH_X(0.0f) + x, PSH_Y(0.56f) + y);
	}
	glEnd();

	glPointSize(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex2f(PSH_X(0.0f), PSH_Y(0.53f));
	glEnd();
}
