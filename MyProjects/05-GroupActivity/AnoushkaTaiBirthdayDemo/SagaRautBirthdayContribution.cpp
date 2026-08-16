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
	void RenderTrianle();
	void renderLightHouse(float, float, float);
	void renderCake(float, float, float, float);
	void renderCandle(float, float, float);
	void renderBalloon(float xPoint, float yPoint, float size, float colorR, float colorG, float colorB);

	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// RenderTrianle();

	// renderLightHouse(0.5f, 0.0f, 100.0f);

	renderCake(0.0f, 0.0f, 100.0f, 0.1f);

	// render candle calls
	// DO NOT CHANGE SIZE OF THE CANDLE
	renderCandle(-0.01f, 0.5, 100.0f);

	renderCandle(-0.09f, 0.32f, 80.0f);
	renderCandle(0.07f, 0.32f, 80.0f);

	renderCandle(-0.13f, 0.12f, 80.0f);
	renderCandle(0.11f, 0.12f, 80.0f);

	renderBalloon(-0.5f, 0.0f, 30.0f, 0.192f, 0.302f, 0.615f);

	renderBalloon(0.5f, 0.0f, 30.0f, 0.92f, 0.102f, 0.315f);

	glutSwapBuffers();
}

void renderLightHouse(float xPoint, float yPoint, float size)
{
	// top verticle line
	glColor3f(0.380f, 0.341f, 0.333f);

	glBegin(GL_LINES);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0f), size), VALUE_FROM_PERCENT((yPoint + 0.55f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0f), size), VALUE_FROM_PERCENT((yPoint + 0.43f), size));

	glEnd();

	// top triangle
	glBegin(GL_TRIANGLES);

	glColor3f(0.788f, 0.845f, 0.741f);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0f), size), VALUE_FROM_PERCENT((yPoint + 0.45f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.069f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.049f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));

	glColor3f(0.788f, 0.745f, 0.741f);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0f), size), VALUE_FROM_PERCENT((yPoint + 0.45f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.049f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.009f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));

	glColor3f(0.600f, 0.549f, 0.561f);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0f), size), VALUE_FROM_PERCENT((yPoint + 0.45f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.009f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.029f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));

	glColor3f(0.369f, 0.329f, 0.322f);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0f), size), VALUE_FROM_PERCENT((yPoint + 0.45f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.029f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.059f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));

	glColor3f(0.380f, 0.341f, 0.333f);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0f), size), VALUE_FROM_PERCENT((yPoint + 0.45f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.059f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.069f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));

	glEnd();

	// light cover top line
	glColor3f(0.447f, 0.396f, 0.371f);

	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.069f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.069f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.069f), size), VALUE_FROM_PERCENT((yPoint + 0.3f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.069f), size), VALUE_FROM_PERCENT((yPoint + 0.3f), size));

	glEnd();

	// light cover glass
	glColor3f(1.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.065f), size), VALUE_FROM_PERCENT((yPoint + 0.3f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.065f), size), VALUE_FROM_PERCENT((yPoint + 0.3f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.065f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.065f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));

	glEnd();

	// observatory
	glColor3f(0.447f, 0.396f, 0.371f);

	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.07f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.07f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.07f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.07f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));

	glEnd();

	// light cover middle line
	glColor3f(0.447f, 0.396f, 0.371f);

	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.065f), size), VALUE_FROM_PERCENT((yPoint + 0.21f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.065f), size), VALUE_FROM_PERCENT((yPoint + 0.21f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.065f), size), VALUE_FROM_PERCENT((yPoint + 0.205f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.065f), size), VALUE_FROM_PERCENT((yPoint + 0.205f), size));

	glEnd();

	// light cover verticle lines

	glLineWidth(2.0f);

	glBegin(GL_LINES);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.060f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.060f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.040f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.040f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.020f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.020f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.020f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.020f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.040f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.040f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.060f), size), VALUE_FROM_PERCENT((yPoint + 0.31f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.060f), size), VALUE_FROM_PERCENT((yPoint + 0.175f), size));

	// glVertex2f(VALUE_FROM_PERCENT((xPoint +0.060f), size), VALUE_FROM_PERCENT((xPoint +0.31f), size));
	// glVertex2f(VALUE_FROM_PERCENT((xPoint +0.060f), size), VALUE_FROM_PERCENT((xPoint +0.175f), size));

	glEnd();

	glLineWidth(1.0f);

	// railing
	glColor3f(0.447f, 0.496f, 0.471f);

	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.09f), size), VALUE_FROM_PERCENT((yPoint + 0.145f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.09f), size), VALUE_FROM_PERCENT((yPoint + 0.145f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.09f), size), VALUE_FROM_PERCENT((yPoint + 0.135f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.09f), size), VALUE_FROM_PERCENT((yPoint + 0.135f), size));

	glEnd();

	// railing verticle lines
	glColor3f(0.447f, 0.496f, 0.471f);

	glLineWidth(2.0f);

	glBegin(GL_LINES);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.0875f), size), VALUE_FROM_PERCENT((yPoint + 0.145f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.0875f), size), VALUE_FROM_PERCENT((yPoint + 0.05f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.0575f), size), VALUE_FROM_PERCENT((yPoint + 0.145f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.0575f), size), VALUE_FROM_PERCENT((yPoint + 0.05f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.0275f), size), VALUE_FROM_PERCENT((yPoint + 0.145f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.0275f), size), VALUE_FROM_PERCENT((yPoint + 0.05f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0075f), size), VALUE_FROM_PERCENT((yPoint + 0.145f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0075f), size), VALUE_FROM_PERCENT((yPoint + 0.05f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0375f), size), VALUE_FROM_PERCENT((yPoint + 0.145f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0375f), size), VALUE_FROM_PERCENT((yPoint + 0.05f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0575f), size), VALUE_FROM_PERCENT((yPoint + 0.145f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0575f), size), VALUE_FROM_PERCENT((yPoint + 0.05f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0875f), size), VALUE_FROM_PERCENT((yPoint + 0.145f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0875f), size), VALUE_FROM_PERCENT((yPoint + 0.05f), size));

	glEnd();

	glLineWidth(2.0f);

	// railing base
	glColor3f(0.447f, 0.496f, 0.371f);

	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.09f), size), VALUE_FROM_PERCENT((yPoint + 0.05f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.09f), size), VALUE_FROM_PERCENT((yPoint + 0.05f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.09f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.09f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));

	glEnd();

	// centre pillar
	glColor3f(0.973, 0.953, 0.925);

	glBegin(GL_QUADS);

	// glVertex2f(VALUE_FROM_PERCENT((xPoint +-0.08f), size), VALUE_FROM_PERCENT((xPoint +0.0f), size));
	// glVertex2f(VALUE_FROM_PERCENT((xPoint +0.08f), size), VALUE_FROM_PERCENT((xPoint +0.0f), size));
	// glVertex2f(VALUE_FROM_PERCENT((xPoint +0.10f), size), VALUE_FROM_PERCENT((xPoint +-0.8f), size));
	// glVertex2f(VALUE_FROM_PERCENT((xPoint +-0.10f), size), VALUE_FROM_PERCENT((xPoint +-0.8f), size));

	glColor3f(0.984, 0.965, 0.965);
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.08f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.04f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.05f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.10f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));

	glColor3f(0.969, 0.939, 0.921);
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.04f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.00f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.00f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.05f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));

	glColor3f(0.925, 0.878, 0.843);
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.00f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.04f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.05f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.00f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));

	glColor3f(0.839, 0.784, 0.733);
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.04f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.08f), size), VALUE_FROM_PERCENT((yPoint + 0.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.10f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.05f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));

	glEnd();

	// railing below line

	glBegin(GL_QUADS);

	glColor3f(0.843f, 0.463f, 0.427f);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.084f), size), VALUE_FROM_PERCENT((yPoint + -0.16f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.042f), size), VALUE_FROM_PERCENT((yPoint + -0.16f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.044f), size), VALUE_FROM_PERCENT((yPoint + -0.24f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.086f), size), VALUE_FROM_PERCENT((yPoint + -0.24f), size));

	glColor3f(0.447f, 0.476f, 0.371f);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.042f), size), VALUE_FROM_PERCENT((yPoint + -0.16f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.000f), size), VALUE_FROM_PERCENT((yPoint + -0.16f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.000f), size), VALUE_FROM_PERCENT((yPoint + -0.24f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.044f), size), VALUE_FROM_PERCENT((yPoint + -0.24f), size));

	glColor3f(0.447f, 0.456f, 0.371f);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.0f), size), VALUE_FROM_PERCENT((yPoint + -0.16f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.044f), size), VALUE_FROM_PERCENT((yPoint + -0.16f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.045f), size), VALUE_FROM_PERCENT((yPoint + -0.24f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.000f), size), VALUE_FROM_PERCENT((yPoint + -0.24f), size));

	glColor3f(0.447f, 0.466f, 0.371f);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.044f), size), VALUE_FROM_PERCENT((yPoint + -0.16f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.084f), size), VALUE_FROM_PERCENT((yPoint + -0.16f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.086f), size), VALUE_FROM_PERCENT((yPoint + -0.24f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.045f), size), VALUE_FROM_PERCENT((yPoint + -0.24f), size));

	glEnd();

	// // railing verticle support
	// glLineWidth(4.0f);

	// glBegin(GL_LINES);

	// glVertex2f(VALUE_FROM_PERCENT((xPoint +0.00f), size), VALUE_FROM_PERCENT((xPoint +0.0f), size));
	// glVertex2f(VALUE_FROM_PERCENT((xPoint +0.00f), size), VALUE_FROM_PERCENT((xPoint +-0.06f), size));

	// glEnd();

	// glLineWidth(1.0f);

	// foundation
	glColor3f(0.447f, 0.396f, 0.371f);

	glBegin(GL_QUADS);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.11f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.11f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.11f), size), VALUE_FROM_PERCENT((yPoint + -1.0f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.11f), size), VALUE_FROM_PERCENT((yPoint + -1.0f), size));

	glEnd();

	glColor3f(0.184, 0.125, 0.090f);
	glBegin(GL_LINES);

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.09f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.09f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.05f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.05f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.01f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.01f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.03f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.03f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.07f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.07f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.11f), size), VALUE_FROM_PERCENT((yPoint + -0.8f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.11f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.11f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.11f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.07f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.07f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.03f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.03f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.01f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.01f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.05f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.05f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.09f), size), VALUE_FROM_PERCENT((yPoint + -0.85f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.09f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.11f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.11f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.09f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.09f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.04f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.04f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.00f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.00f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.04f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.04f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.08f), size), VALUE_FROM_PERCENT((yPoint + -0.90f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.08f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.11f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.11f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.07f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.07f), size), VALUE_FROM_PERCENT((yPoint + -1.0f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.03f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + -0.03f), size), VALUE_FROM_PERCENT((yPoint + -1.0f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.01f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.01f), size), VALUE_FROM_PERCENT((yPoint + -1.0f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.05f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.05f), size), VALUE_FROM_PERCENT((yPoint + -1.0f), size));

	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.10f), size), VALUE_FROM_PERCENT((yPoint + -0.95f), size));
	glVertex2f(VALUE_FROM_PERCENT((xPoint + 0.10f), size), VALUE_FROM_PERCENT((yPoint + -1.0f), size));

	glEnd();
}

void RenderTrianle()
{
	glBegin(GL_TRIANGLES);

	// 1st triangle
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex3f(0.0f, 0.8f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f); // Blue
	glVertex3f(0.8f, -0.4f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f); // Green
	glVertex3f(-0.8f, -0.4f, 0.0f);

	glEnd();
}

void renderCake(float xPoint, float yPoint, float size, float cakeBaseRadius)
{

	float scale = size / 100.0f;

	// base layer

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glVertex2f(xPoint + (-0.15f * scale), yPoint + (0.0f * scale));

	glVertex2f(xPoint + (0.15f * scale), yPoint + (0.0f * scale));

	glVertex2f(xPoint + (0.15f * scale), yPoint + (-0.3f * scale));

	glVertex2f(xPoint + (-0.15f * scale), yPoint + (-0.3f * scale));

	glEnd();

	// base top circle

	glColor3f(0.05f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(xPoint, yPoint);

	float radius = cakeBaseRadius * scale;

	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		float x = xPoint + cos(angle) * radius * 1.5f;

		float y = yPoint + sin(angle) * radius / 2.0f;

		glVertex2f(x, y);
	}

	glEnd();

	// base bottom circle

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	float baseBottomY = yPoint + (-0.3f * scale);

	glVertex2f(xPoint, baseBottomY);

	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		float x = xPoint + cos(angle) * radius * 1.5f;

		float y = baseBottomY + sin(angle) * radius / 2.0f;

		glVertex2f(x, y);
	}

	glEnd();

	// second layer bottom circle

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	float layer2BottomY = yPoint;
	float layer2BottomRadius = (cakeBaseRadius - 0.033f) * scale;

	glVertex2f(xPoint, layer2BottomY);

	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		float x = xPoint + cos(angle) * layer2BottomRadius * 1.5f;

		float y = layer2BottomY + sin(angle) * layer2BottomRadius / 2.0f;

		glVertex2f(x, y);
	}

	glEnd();

	// second layer

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glVertex2f(xPoint + (-0.1f * scale), yPoint + (0.0f * scale));

	glVertex2f(xPoint + (0.1f * scale), yPoint + (0.0f * scale));

	glVertex2f(xPoint + (0.1f * scale), yPoint + (0.2f * scale));

	glVertex2f(xPoint + (-0.1f * scale), yPoint + (0.2f * scale));

	glEnd();

	// second layer top circle

	glColor3f(0.05f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	float layer2Y = yPoint + (0.2f * scale);
	float layer2Radius = (cakeBaseRadius - 0.033f) * scale;

	glVertex2f(xPoint, layer2Y);

	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		float x = xPoint + cos(angle) * layer2Radius * 1.5f;

		float y = layer2Y + sin(angle) * layer2Radius / 2.0f;

		glVertex2f(x, y);
	}

	glEnd();

	// top layer bottom circle

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	float topBottomY = yPoint + (0.2f * scale);
	float topLayerRadius = (cakeBaseRadius - 0.058f) * scale;

	glVertex2f(xPoint, topBottomY);

	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		float x = xPoint + cos(angle) * topLayerRadius * 1.5f;

		float y = topBottomY + sin(angle) * topLayerRadius / 2.0f;

		glVertex2f(x, y);
	}

	glEnd();

	//  top layer

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glVertex2f(xPoint + (-0.063f * scale), yPoint + (0.2f * scale));

	glVertex2f(xPoint + (0.063f * scale), yPoint + (0.2f * scale));

	glVertex2f(xPoint + (0.063f * scale), yPoint + (0.35f * scale));

	glVertex2f(xPoint + (-0.063f * scale), yPoint + (0.35f * scale));

	glEnd();

	// top ellipsis

	glColor3f(0.05f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	float topY = yPoint + (0.35f * scale);
	float topRadius = (cakeBaseRadius - 0.058f) * scale;

	glVertex2f(xPoint, topY);

	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		float x = xPoint + cos(angle) * topRadius * 1.5f;

		float y = topY + sin(angle) * topRadius / 2.0f;

		glVertex2f(x, y);
	}

	glEnd();
}

void renderCandle(float xPoint, float yPoint, float size)
{
	float scale = size / 100.0f;

	// candle flame

	glColor3f(1.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);

	float flameX = xPoint + (0.01f * scale);
	float flameY = yPoint + (0.0f * scale);

	glVertex2f(flameX, flameY);

	float flameRadius = 0.005f * scale;

	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		float x = flameX + cos(angle) * flameRadius;

		float y = flameY + sin(angle) * flameRadius * 8.0f;

		glVertex2f(x, y);
	}

	glEnd();

	// candle body

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glVertex2f(xPoint + (0.0f * scale), yPoint + (0.0f * scale));

	glVertex2f(xPoint + (0.02f * scale), yPoint + (0.0f * scale));

	glVertex2f(xPoint + (0.02f * scale), yPoint + (-0.15f * scale));

	glVertex2f(xPoint + (0.0f * scale), yPoint + (-0.15f * scale));

	glEnd();
}

void renderBalloon(float xPoint, float yPoint, float size, float colorR, float colorG, float colorB)
{
	float scale = size / 100.0f;

	float radiusX = 0.30f * scale;
	float radiusY = 0.50f * scale;

	// string
	glColor3f(1.0f, 1.0f, 1.0f);

	glLineWidth(2.0f);

	glBegin(GL_LINES);

	glVertex2f(xPoint, yPoint - (radiusY * 1.5f));

	glVertex2f(xPoint, yPoint - radiusY - (0.8f * scale));

	glEnd();

	glLineWidth(1.0f);

	// ballonn

	glColor3f(colorR, colorG, colorB);

	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(xPoint, yPoint);

	for (int i = 0; i <= 360; i++)
	{
		float angle = i * 3.14159265f / 180.0f;

		float x = xPoint + cosf(angle) * (radiusX);
		float y = yPoint + sinf(angle) * (radiusY * 1.5f);

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