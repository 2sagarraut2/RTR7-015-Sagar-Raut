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

#define VALUE_FROM_PERCENT(complete_value, percent) ((complete_value * percent) / 100)
#define SCALE_RADIUS(radius, SR_percent) ((radius) * (SR_percent) / 100)

bool bIsFullScreen = false;

static float circleRadius = 0.0f;
static float triangleSize = 0.0f;

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
	// function declarations
	void letterT(float startingPointX, float startingPointY, float width, float thickness, float SR_percent);
	void letterH(float startingPointX, float startingPointY, float width, float thickness, float SR_percent);
	void letterA(float startingPointX, float startingPointY, float width, float thickness, float SR_percent);
	void letterN(float startingPointX, float startingPointY, float width, float thickness, float SR_percent);
	void letterK(float startingPointX, float startingPointY, float width, float thickness, float SR_percent);
	void letterO(float startingPointX, float startingPointY, float width, float thickness, float SR_percent);
	void letterU(float startingPointX, float startingPointY, float width, float thickness, float SR_percent);
	void letterY(float startingPointX, float startingPointY, float width, float thickness, float SR_percent);

	void renderCircle(float radiusSize, float myX, float myY, float colorRValue, float colorGValue, float colorBValue);
	void renderTriangle(float startingPointX, float startingPointY, float triangleSize, float SR_percent);
	void renderRectangle(float startingPointX, float startingPointY, float triangleSize, float SR_percent);
	void renderSquare(float startingPointX, float startingPointY, float triangleSize, float SR_percent);

	void drawFlower(float radiusSize, float customX, float customY, float SR_percent);

	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// glBegin(GL_TRIANGLES);

	// // 1st triangle
	// glColor3f(1.0f, 0.0f, 0.0f); // Red
	// glVertex3f(0.0f, 0.8f, 0.0f);

	// glColor3f(0.0f, 0.0f, 0.5f); // Blue
	// glVertex3f(0.8f, -0.4f, 0.0f);

	// glColor3f(0.0f, 1.0f, 0.0f); // Green
	// glVertex3f(-0.8f, -0.4f, 0.0f);

	// glEnd();

	glColor3f(1.0f, 0.5f, 0.5f);

	letterT(-0.9f, 0.4f, 0.32f, 0.10f, 100.0f);
	letterH(-0.55f, 0.4f, 0.32f, 0.10f, 100.0f);
	letterA(-0.2f, 0.4f, 0.32f, 0.10f, 100.0f);
	letterN(0.225f, 0.4f, 0.32f, 0.10f, 100.0f);
	letterK(0.575f, 0.4f, 0.32f, 0.10f, 100.0f);

	letterY(-0.520f, -0.1f, 0.32f, 0.10f, 100.0f);
	letterO(-0.16f, -0.1f, 0.32f, 0.10f, 100.0f);
	letterU(0.2f, -0.1f, 0.32f, 0.10f, 100.0f);

	if (circleRadius < 0.2f)
	{
		circleRadius = circleRadius + 0.002f;

		if (circleRadius > 0.2f)
		{
			circleRadius = 0.0f;
		}
	}

	// printf("%f\n", circleRadius);

	// renderCircle(circleRadius, -0.15f, 0.7f, 1.5f, 0.5f, 0.05f);

	if (triangleSize < 0.3f)
	{
		triangleSize = triangleSize + 0.0007f;

		if (triangleSize > 0.3f)
		{
			triangleSize = 0.0f;
		}
	}

	glColor3f(0.5f, 0.5f, 0.5f);
	drawFlower(circleRadius, 0.0f, 0.0f, 20.0f);
	glColor3f(1.5f, 0.5f, 1.5f);
	drawFlower(circleRadius, 0.0f, 4.2f, 22.0f);
	glColor3f(0.5f, 1.5f, 0.5f);
	drawFlower(circleRadius, -1.8f, 2.5f, 23.0f);
	glColor3f(1.5f, 1.5f, 1.5f);
	drawFlower(circleRadius, 1.8f, 2.5f, 24.0f);
	glColor3f(2.5f, 2.5f, 0.5f);
	drawFlower(circleRadius, 3.8f, 3.8f, 25.0f);
	glColor3f(3.5f, 2.5f, 0.5f);
	drawFlower(circleRadius, -3.2f, 3.0f, 26.0f);
	glColor3f(2.5f, 4.5f, 1.5f);
	drawFlower(circleRadius, -1.2f, -2.0f, 27.0f);
	glColor3f(2.5f, 2.5f, 0.5f);
	drawFlower(circleRadius, -3.0f, -1.4f, 28.0f);
	glColor3f(2.5f, 3.5f, 1.5f);
	drawFlower(circleRadius, -4.0f, -3.6f, 22.0f);
	glColor3f(2.5f, 1.5f, 0.5f);
	drawFlower(circleRadius, 3.8f, -2.4f, 21.0f);
	glColor3f(2.5f, 2.5f, 3.5f);
	drawFlower(circleRadius, 2.0f, -3.8f, 19.0f);

	// renderTriangle(-0.7f, -0.5f, triangleSize, 100.0f);
	// renderRectangle(0.6f, 0.7f, triangleSize, 100.0f);
	// renderSquare(0.7f, -0.6f, triangleSize, 100.0f);

	glutSwapBuffers();
	glutPostRedisplay();
}

void letterT(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width / 2.0f - (thickness / 2.6f)), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width / 2.0f + (thickness / 2.6f)), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width / 2.0f + (thickness / 2.6f)), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width / 2.0f - (thickness / 2.6f)), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glEnd();
}

void letterH(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 1.5f), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 1.5f), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 2.5f), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 2.5f), SR_percent));

	glEnd();
}

void letterA(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width / 2), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width / 2 + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX - width / 2 + width), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX - width / 2 + width + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX + 0.16f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness - 0.09f), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX - 0.082f + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness - 0.09f), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX - 0.045f + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 2.8f), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + 0.125f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 2.8f), SR_percent));

	glEnd();
}

void letterN(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glEnd();
}

void letterK(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
	glBegin(GL_QUADS);

	// glColor3f(1.0f, 0.0f, 0.0f); // red
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	// glColor3f(0.0f, 1.0f, 0.0f); // green
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	// glColor3f(0.0f, 0.0f, 1.0f); // blue
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	// glColor3f(0.1f, 0.1f, 0.1f); // black
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	// glColor3f(1.0f, 0.0f, 0.0f); // red
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 2.5f), SR_percent));
	// glColor3f(0.0f, 1.0f, 0.0f); // green
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 2.5f), SR_percent));
	// glColor3f(0.0f, 0.0f, 1.0f); // blue
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	// glColor3f(0.1f, 0.1f, 0.1f); // black
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));

	// glColor3f(1.0f, 0.0f, 0.0f); // red
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 1.5f), SR_percent));
	// glColor3f(0.0f, 1.0f, 0.0f); // green
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 1.5f), SR_percent));
	// glColor3f(0.0f, 0.0f, 1.0f); // blue
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	// glColor3f(0.1f, 0.1f, 0.1f); // black
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	// glColor3f(1.0f, 0.0f, 0.0f); // red

	glEnd();
}

void letterO(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - (thickness * 3)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - (thickness * 3)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness - (thickness * 3)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness - (thickness * 3)), SR_percent));

	glEnd();
}

void letterU(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - (thickness * 3)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - (thickness * 3)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness - (thickness * 3)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness - (thickness * 3)), SR_percent));

	glEnd();
}

void letterY(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + (width / 2)), SR_percent), VALUE_FROM_PERCENT((startingPointY - (width / 2)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + (width / 2)), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness - (width / 2)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX + (width / 2)), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness - (width / 2)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + (width / 2)), SR_percent), VALUE_FROM_PERCENT((startingPointY - (width / 2)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));

	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width / 2.0f - (thickness / 2.6f)), SR_percent), VALUE_FROM_PERCENT((startingPointY - (width / 2)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width / 2.0f + (thickness / 2.6f)), SR_percent), VALUE_FROM_PERCENT((startingPointY - (width / 2)), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width / 2.0f + (thickness / 2.6f)), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
	glVertex2f(VALUE_FROM_PERCENT((startingPointX + width / 2.0f - (thickness / 2.6f)), SR_percent), VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

	glEnd();
}

void renderCircle(float radiusSize, float myX, float myY, float colorRValue, float colorGValue, float colorBValue)
{
	glColor3f(colorRValue, colorGValue, colorBValue);

	glBegin(GL_TRIANGLE_FAN);

	float centerX = VALUE_FROM_PERCENT(myX, 100.0f);
	float centerY = VALUE_FROM_PERCENT(myY, 100.0f);
	glVertex2f(centerX, centerY);

	float baseRadius = SCALE_RADIUS(radiusSize, 100.0f);

	for (int i = 0; i <= 360; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * baseRadius);
		float y = centerY + (sin(angle) * baseRadius * 1.7f);

		glVertex2f(x, y);
	}

	glEnd();
}

void renderTriangle(float startingPointX, float startingPointY, float triangleSize, float SR_percent)
{
	glBegin(GL_TRIANGLES);

	glVertex2f(startingPointX, startingPointY + triangleSize);
	glVertex2f(startingPointX + triangleSize, startingPointY - triangleSize);
	glVertex2f(startingPointX - triangleSize, startingPointY - triangleSize);

	glEnd();
}

void renderRectangle(float startingPointX, float startingPointY, float triangleSize, float SR_percent)
{
	glColor3f(0.004f, 0.456f, 1.65);

	glBegin(GL_QUADS);

	glVertex2f(startingPointX - triangleSize, startingPointY + triangleSize);
	glVertex2f(startingPointX + triangleSize, startingPointY + triangleSize);
	glVertex2f(startingPointX + triangleSize, startingPointY - triangleSize);
	glVertex2f(startingPointX - triangleSize, startingPointY - triangleSize);

	glEnd();
}

void renderSquare(float startingPointX, float startingPointY, float triangleSize, float SR_percent)
{
	glColor3f(1.345f, 1.456f, 1.675);

	glBegin(GL_QUADS);

	glVertex2f(startingPointX - (triangleSize - 0.2f), startingPointY + triangleSize);
	glVertex2f(startingPointX + (triangleSize), startingPointY + triangleSize);
	glVertex2f(startingPointX + (triangleSize), startingPointY - triangleSize);
	glVertex2f(startingPointX - (triangleSize - 0.2f), startingPointY - triangleSize);

	glEnd();
}

void drawFlower(float radiusSize, float customX, float customY, float SR_percent)
{
	glBegin(GL_TRIANGLE_FAN);

	float centerX = VALUE_FROM_PERCENT(customX, SR_percent);
	float centerY = VALUE_FROM_PERCENT(customY, SR_percent);
	glVertex2f(centerX, centerY);

	float baseRadius = SCALE_RADIUS(radiusSize, SR_percent);

	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.14159f / 180.0f;
		float petalShapeModifier = 1.0f + 0.5f * cos(5.0f * angle);
		float x = centerX + (cos(angle) * baseRadius * petalShapeModifier);
		float y = centerY + (sin(angle) * baseRadius * petalShapeModifier);
		glVertex2f(x, y);
	}
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