#ifdef __APPLE__
// macOS Headers
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// Functional macros that absorb the empty parentheses ()
#ifndef glutCloseFunc
#define glutCloseFunc glutWMCloseFunc
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
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h> // Required for exit()
#include <math.h>

bool bIsFullScreen = false;
const float SSR_square_size = 0.25f;

// function declarations
void drawSmiley(float centerX, float centerY, float radius);

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
	glutCreateWindow("City Scene : Sagar Sambhaji Raut");

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
	glClearColor(0.184f, 0.310f, 0.533f, 1.0f);
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
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// float x, float y, float radius
	drawSmiley(0.0f, 0.0f, 0.5f);

	glutSwapBuffers();
}

void drawSmiley(float centerX, float centerY, float radius)
{
	glColor3f(0.471f, 0.784f, 0.310f);

	glBegin(GL_TRIANGLE_FAN);
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * radius);
		float y = centerY + (sin(angle) * radius * 1.7f);

		glVertex2f(x, y);
	}
	glEnd();

	// outer eye
	glColor3f(0.1f, 0.1f, 0.1f);

	radius = 0.1f;
	glBegin(GL_TRIANGLE_FAN);
	// 1. Establish the center anchor point
	glVertex2f(centerX - 0.2f, centerY + 0.2f);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = (centerX - 0.2f) + (cos(angle) * radius);
		float y = (centerY + 0.2f) + (sin(angle) * radius * 1.7f);

		glVertex2f(x, y);
	}
	glEnd();

	// inner eye
	glColor3f(1.0f, 1.0f, 1.0f);

	radius = 0.05f;
	glBegin(GL_TRIANGLE_FAN);
	// 1. Establish the center anchor point
	glVertex2f(centerX - 0.2f, centerY + 0.2f);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = (centerX - 0.2f) + (cos(angle) * radius);
		float y = (centerY + 0.2f) + (sin(angle) * radius * 1.7f);

		glVertex2f(x, y);
	}
	glEnd();

	// outer eye
	glColor3f(0.1f, 0.1f, 0.1f);

	radius = 0.1f;
	glBegin(GL_TRIANGLE_FAN);
	// 1. Establish the center anchor point
	glVertex2f(centerX + 0.2f, centerY + 0.2f);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = (centerX + 0.2f) + (cos(angle) * radius);
		float y = (centerY + 0.2f) + (sin(angle) * radius * 1.7f);

		glVertex2f(x, y);
	}
	glEnd();

	// inner eye
	glColor3f(1.0f, 1.0f, 1.0f);

	radius = 0.05f;
	glBegin(GL_TRIANGLE_FAN);
	// 1. Establish the center anchor point
	glVertex2f(centerX + 0.2f, centerY + 0.2f);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = (centerX + 0.2f) + (cos(angle) * radius);
		float y = (centerY + 0.2f) + (sin(angle) * radius * 1.7f);

		glVertex2f(x, y);
	}
	glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_QUADS);

	glVertex3f(centerX - 0.15f, centerY - 0.4f, 0.0f);
	glVertex3f(centerX + 0.15f, centerY - 0.4f, 0.0f);
	glVertex3f(centerX + 0.15f, centerY - 0.3f, 0.0f);
	glVertex3f(centerX - 0.15f, centerY - 0.3f, 0.0f);

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
