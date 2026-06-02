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

void drawParachute(float centerX, float centerY, float radius);
void drawClouds(float xPoint, float yPoint, float radius);
void drawMountains(float xPoint, float yPoint, float width, float height);

bool bIsFullScreen = false;
float xPosition = -1.0f;
float yPosition = -1.0f;

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

	if (yPosition <= 1.0f)
	{
		yPosition = yPosition + 0.0005f;
	}

	if (xPosition <= 0.0f)
	{
		xPosition = xPosition + 0.0005f;
	}

	drawClouds(xPosition + 0.2f, 0.8f, 0.1f);
	drawClouds(xPosition + 0.3f, 0.9f, 0.1f);
	drawClouds(xPosition + 0.4f, 0.8f, 0.1f);
	drawClouds(xPosition + 0.3f, 0.7f, 0.1f);

	drawClouds(-0.4f, 0.6f, 0.15f);
	drawClouds(-0.3f, 0.7f, 0.15f);
	drawClouds(-0.2f, 0.6f, 0.15f);
	drawClouds(-0.3f, 0.5f, 0.15f);

	drawClouds(0.8f, 0.8f, 0.2f);
	drawClouds(0.7f, 0.9f, 0.2f);
	drawClouds(0.6f, 0.8f, 0.2f);
	drawClouds(0.7f, 0.7f, 0.2f);

	// float xPoint, float yPoint, float width, float height
	drawMountains(-1.2f, -1.0f, 1.0f, 0.8f);

	drawMountains(0.1f, -1.0f, 1.2f, 1.0f);

	drawMountains(-0.6f, -1.0f, 0.9f, 0.6f);

	// float centerX, float centerY, float radius
	drawParachute(-0.5f, yPosition + 0.2f, 0.3f);

	drawParachute(0.2f, yPosition, 0.3f);

	glutSwapBuffers();
	glutPostRedisplay();
}

void drawClouds(float xPoint, float yPoint, float radius)
{
	glColor3f(0.961f, 0.961f, 0.961f);

	glBegin(GL_TRIANGLE_FAN);
	// 1. Establish the center anchor point
	glVertex2f(xPoint, yPoint);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 360; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = xPoint + (cos(angle) * radius);
		float y = yPoint + (sin(angle) * radius);

		glVertex2f(x, y);
	}
	glEnd();
}

void drawParachute(float centerX, float centerY, float radius)
{

	glBegin(GL_TRIANGLE_FAN);

	float x, y;

	// actual ballon
	glColor3f(0.192f, 0.302f, 0.615f);
	glVertex2f(centerX, centerY);

	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.14159f / 180.0f;
		x = centerX + (cos(angle) * radius * 0.6f); // x-axis
		y = centerY + (sin(angle) * radius + 0.5f); // y-axis
		glVertex2f(x, y);
	}
	glEnd();

	// glColor3f(0.0f, 0.0f, 1.0f); // Blue
	// // FIXED: Shrunk the height down to just 0.04 units total (from 0.20f down to 0.16f)
	// glVertex2f(centerX - (radius / 4), centerY + 0.20f);
	// glVertex2f(centerX + (radius / 4), centerY + 0.20f);
	// glVertex2f(centerX + (radius / 4), centerY + 0.16f);
	// glVertex2f(centerX - (radius / 4), centerY + 0.16f);

	glBegin(GL_QUADS);

	glColor3f(0.502f, 0.353f, 0.235f); // White box
	glVertex2f(centerX - (radius / 4), centerY + 0.16f);
	glVertex2f(centerX + (radius / 4), centerY + 0.16f);
	glVertex2f(centerX + (radius / 4), centerY + 0.001f);
	glVertex2f(centerX - (radius / 4), centerY + 0.001f);

	glColor3f(0.502f, 0.353f, 0.235f); // White box side

	glVertex2f(centerX + (radius / 4), centerY + 0.16f);
	glVertex2f(centerX + (radius / 4), centerY + 0.001f);
	glVertex2f(centerX + (radius / 3.5f), centerY + 0.02f);
	glVertex2f(centerX + (radius / 3.5f), centerY + 0.18f);

	glEnd();

	glLineWidth(4.0f);

	glColor3f(0.804f, 0.733f, 0.592f);
	glBegin(GL_LINE_LOOP);

	glVertex2f(centerX - (radius / 4), centerY + 0.16f);  // 1. Bottom-Left
	glVertex2f(centerX + (radius / 4), centerY + 0.16f);  // 2. Bottom-Right
	glVertex2f(centerX + (radius / 4), centerY + 0.001f); // 3. Top-Right
	glVertex2f(centerX - (radius / 4), centerY + 0.001f); // 4. Top-Left
	glEnd();

	glColor3f(0.804f, 0.733f, 0.592f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(centerX + (radius / 4), centerY + 0.16f);
	glVertex2f(centerX + (radius / 4), centerY + 0.001f);
	glVertex2f(centerX + (radius / 3.5f), centerY + 0.02f);
	glVertex2f(centerX + (radius / 3.5f), centerY + 0.18f);
	glEnd();

	// --- 3. Hanging Ropes (UPDATED TO ATTACH TO SHORTER BLUE BOX) ---

	glBegin(GL_LINES);
	glColor3f(0.804f, 0.733f, 0.592f);

	// Left Rope
	glVertex2f(centerX - (radius / 2), centerY + 0.665f);
	glVertex2f(centerX - (radius / 4), centerY + 0.14f);

	// Right Rope
	glVertex2f(centerX + (radius / 2), centerY + 0.665f);
	glVertex2f(centerX + (radius / 4), centerY + 0.14f);

	// Middle Rope
	glVertex2f(centerX, centerY + 0.80f);
	glVertex2f(centerX, centerY + 0.14f);

	// horizontal rope
	glVertex2f(centerX - (radius / 4), centerY + 0.14f);
	glVertex2f(centerX + (radius / 4), centerY + 0.14f);
	glLineWidth(1.0f);
	glEnd();
}

void drawMountains(float xPoint, float yPoint, float width, float height)
{
	glBegin(GL_TRIANGLES);

	glColor3f(0.137f, 0.298f, 0.184f);
	glVertex3f(xPoint, yPoint, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(xPoint + (width / 2), yPoint + height, 0.0f);

	glColor3f(0.137f, 0.298f, 0.184f);
	glVertex3f(xPoint + 0.4f, yPoint, 0.0f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.137f, 0.398f, 0.184f);

	glVertex3f(xPoint + (width / 4), yPoint, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(xPoint + (width / 2), yPoint + height, 0.0f);

	glColor3f(0.137f, 0.298f, 0.184f);
	glVertex3f(xPoint + width, yPoint, 0.0f);

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