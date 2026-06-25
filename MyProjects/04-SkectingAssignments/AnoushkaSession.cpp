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

void drawTriangle();
void drawSquare(float xPoint, float yPoint, float height, float width);

bool bIsFullScreen = false;

int percentage = 50.0;

#define VALUE_FROM_PERCENT(complete_value, percent) (complete_value * percent / 100)

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
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawTriangle(); // drawTriangle call kela

	float xPoint = 0.0f;
	float yPoint = -0.4;
	float height = 0.4f;
	float width = 0.2f;

	drawSquare(xPoint, yPoint, height, width); // drawSquare call kela

	glLineWidth(5.0f);

	glBegin(GL_LINES);

	// x,y first point
	glVertex2f(-0.8f, -0.4f);
	// x,y second point
	glVertex2f(-0.4f, -0.4f);

	glEnd();

	glutSwapBuffers();
}

// drawTriangle func
void drawTriangle()
{
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);

	// x, y - first point
	glVertex2f(0.0f, 0.8f);
	glColor3f(0.0f, 1.0f, 0.0f);
	// xy - second point
	glVertex2f(0.8f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	// xy - third point
	glVertex2f(-0.8f, 0.0f);

	glEnd();
}

// draw square func
void drawSquare(float xPoint, float yPoint, float height, float width)
{
	// square
	glBegin(GL_QUADS);

	// x,y - first point
	glVertex2f(VALUE_FROM_PERCENT(xPoint, percentage), VALUE_FROM_PERCENT(yPoint, percentage));
	// x,y - second point
	glVertex2f(VALUE_FROM_PERCENT((xPoint + (width * 2)), percentage), VALUE_FROM_PERCENT(yPoint, percentage));
	// x,y - third point
	glVertex2f(VALUE_FROM_PERCENT((xPoint + (width * 2)), percentage), VALUE_FROM_PERCENT((yPoint - height), percentage)); // -0.4 - 0.4 = -0.8
	// x,y - fourth point
	glVertex2f(VALUE_FROM_PERCENT(xPoint, percentage), VALUE_FROM_PERCENT((yPoint - height), percentage));

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