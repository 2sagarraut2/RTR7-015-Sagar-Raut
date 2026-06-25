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

// func declarations
void drawMySquare(float xPosition, float yPosition, float height, float width);

bool bIsFullScreen = false;
float xPosition = -0.6f;
float yPosition = -0.6f;

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
	glutCreateWindow("Hot Air ballon: Sagar Sambhaji Raut");

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
	glClearColor(0.400f, 0.761f, 0.949f, 1.0f);
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

	if (xPosition <= 1.0f)
	{
		xPosition = xPosition + 0.0005f;
	}

	if (yPosition <= 1.0f)
	{
		yPosition = yPosition + 0.0005f;
	}

	// code starts here
	// float xPosition, float yPosition, float height, float width
	drawMySquare(xPosition, yPosition, 0.5f, 0.3f);

	glutSwapBuffers();
	glutPostRedisplay();
}

void drawMySquare(float xPosition, float yPosition, float height, float width)
{
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	// top left
	glVertex3f(xPosition, yPosition, 0.0f);

	// top right
	glVertex3f(xPosition + width, yPosition, 0.0f);

	// bottom right
	glVertex3f(xPosition + width, yPosition - height, 0.0f);

	// left
	glVertex3f(xPosition, yPosition - height, 0.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(xPosition + width, yPosition - 0.02f, 0.0f);

	glVertex3f(xPosition + (width + 0.02f), yPosition - 0.02f, 0.0f);
	glVertex3f(xPosition + (width + 0.08f), yPosition - 0.08f, 0.0f);
	glVertex3f(xPosition + (width + 0.06f), yPosition - 0.12f, 0.0f);
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