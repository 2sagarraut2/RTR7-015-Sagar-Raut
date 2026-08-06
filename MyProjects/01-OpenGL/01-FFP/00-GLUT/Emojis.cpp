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
void drawOuterCircle(float centerX, float centerY, float radius);
void angrySmiley(float centerX, float centerY);
void happySmiley(float centerX, float centerY);
void excitedSmiley(float centerX, float centerY);
void hmmSmiley(float centerX, float centerY);
void attitudeSmiley(float centerX, float centerY);
void confusedSmiley(float centerX, float centerY);
void crySmiley(float centerX, float centerY);
void sadSmiley(float centerX, float centerY);
void coolEmoji(float centerX, float centerY);
void lastEmoji(float centerX, float centerY);

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
	glutCreateWindow("Emojis : Sagar Sambhaji Raut");

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
	glColor3f(0.231f, 0.428f, 0.693f);
	drawOuterCircle(-0.75f, 0.65f, 0.2f);
	happySmiley(-0.75f, 0.65f);

	glColor3f(0.649f, 0.297f, 0.191f);
	drawOuterCircle(-0.25f, 0.65f, 0.2f);
	angrySmiley(-0.25f, 0.65f);

	glColor3f(0.834f, 0.775f, 0.588f);
	drawOuterCircle(0.25f, 0.65f, 0.2f);
	excitedSmiley(0.25f, 0.65f);

	glColor3f(0.205f, 0.360f, 0.661f);
	drawOuterCircle(0.75f, 0.65f, 0.2f);
	hmmSmiley(0.75f, 0.65f);

	glColor3f(0.991f, 0.951f, 0.848f);
	drawOuterCircle(-0.75f, -0.05f, 0.2f);
	attitudeSmiley(-0.75f, -0.05f);

	glColor3f(0.640f, 0.848f, 0.937f);
	drawOuterCircle(-0.25f, -0.05f, 0.2f);
	confusedSmiley(-0.25f, -0.05f);

	glColor3f(1.640f, 0.0f, 0.937f);
	drawOuterCircle(0.25f, -0.05f, 0.2f);
	crySmiley(0.25f, -0.05f);

	glColor3f(1.640f, 1.848f, 1.937f);
	drawOuterCircle(0.75f, -0.05f, 0.2f);
	sadSmiley(0.75f, -0.05f);

	glColor3f(1.0f, 0.0f, 0.5f);
	drawOuterCircle(-0.50f, -0.65f, 0.2f);
	coolEmoji(-0.50f, -0.65f);

	glColor3f(0.05f, 0.7f, 0.2f);
	drawOuterCircle(0.50f, -0.65f, 0.2f);
	lastEmoji(0.50f, -0.65f);

	glutSwapBuffers();
}

void drawOuterCircle(float centerX, float centerY, float radius)
{

	// inner circle
	// glColor3f(0.471f, 0.784f, 0.310f);

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

	// // outer circle
	// glColor3f(0.1f, 0.1f, 0.1f);

	// float ringInnerRadius = radius;

	// float ringOuterRadius = radius + 0.01f;

	// glBegin(GL_QUAD_STRIP);
	// for (int i = 0; i <= 360; i++)
	// {
	// 	float angle = i * 3.14159f / 180.0f;

	// 	// Inner edge points (Matches the green circle exactly)
	// 	float innerX = centerX + (cos(angle) * ringInnerRadius);
	// 	float innerY = centerY + (sin(angle) * ringInnerRadius * 1.7f);

	// 	// Outer edge points (Forms the sharp 1.0f width outline)
	// 	float outerX = centerX + (cos(angle) * ringOuterRadius);
	// 	float outerY = centerY + (sin(angle) * ringOuterRadius * 1.7f);

	// 	glVertex2f(innerX, innerY);
	// 	glVertex2f(outerX, outerY);
	// }
	// glEnd();
}

void happySmiley(float centerX, float centerY)
{
	glColor3f(0.1f, 0.1f, 0.1f);

	// eyebrows
	glLineWidth(4.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.08f, centerY + 0.13f);
	glVertex2f(centerX - 0.06f, centerY + 0.15f);

	glVertex2f(centerX + 0.08f, centerY + 0.13f);
	glVertex2f(centerX + 0.06f, centerY + 0.15f);

	glEnd();

	glLineWidth(1.0f);

	// left eye
	centerX = centerX - 0.05f;
	centerY = centerY + 0.05f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX + 0.005f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	centerY = centerY + 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye
	centerX = centerX + 0.14f;
	centerY = centerY - 0.01f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.005f;
	centerY = centerY;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	centerX = centerX - 0.01f;
	centerY = centerY + 0.01f;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.05f;
	centerY = centerY - 0.05f;

	float radius = 0.1f;

	float ringInnerRadius = radius;

	float ringOuterRadius = radius + 0.01f;

	glBegin(GL_QUAD_STRIP);
	for (int i = 200; i <= 340; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		// Inner edge points (Matches the green circle exactly)
		float innerX = centerX + (cos(angle) * ringInnerRadius);
		float innerY = centerY + (sin(angle) * ringInnerRadius * 1.7f);

		// Outer edge points (Forms the sharp 1.0f width outline)
		float outerX = centerX + (cos(angle) * ringOuterRadius);
		float outerY = centerY + (sin(angle) * ringOuterRadius * 1.7f);

		glVertex2f(innerX, innerY);
		glVertex2f(outerX, outerY);
	}
	glEnd();
}

void angrySmiley(float centerX, float centerY)
{
	// drawOuterCircle(-0.75f, 0.65f, 0.2f);

	glColor3f(0.1f, 0.1f, 0.1f);

	// left eyebroes
	glLineWidth(4.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.08f, centerY + 0.15f);
	glVertex2f(centerX - 0.06f, centerY + 0.13f);

	glVertex2f(centerX + 0.08f, centerY + 0.15f);
	glVertex2f(centerX + 0.06f, centerY + 0.13f);

	glEnd();

	glLineWidth(1.0f);

	// right eyebrow

	// left eye
	centerX = centerX - 0.05f;
	centerY = centerY + 0.05f;

	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye
	centerX = centerX + 0.14f;
	centerY = centerY - 0.01f;

	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.07f;
	centerY = centerY - 0.5f;

	float radius = 0.2f;

	float ringInnerRadius = radius;

	float ringOuterRadius = radius + 0.01f;

	glBegin(GL_QUAD_STRIP);
	for (int i = 68; i <= 111; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		// Inner edge points (Matches the green circle exactly)
		float innerX = centerX + (cos(angle) * ringInnerRadius);
		float innerY = centerY + (sin(angle) * ringInnerRadius * 1.7f);

		// Outer edge points (Forms the sharp 1.0f width outline)
		float outerX = centerX + (cos(angle) * ringOuterRadius);
		float outerY = centerY + (sin(angle) * ringOuterRadius * 1.7f);

		glVertex2f(innerX, innerY);
		glVertex2f(outerX, outerY);
	}
	glEnd();
}

void excitedSmiley(float centerX, float centerY)
{
	// drawOuterCircle(-0.75f, 0.65f, 0.2f);

	glColor3f(0.1f, 0.1f, 0.1f);

	// eyebrows
	glLineWidth(4.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.08f, centerY + 0.13f);
	glVertex2f(centerX - 0.06f, centerY + 0.15f);

	glVertex2f(centerX + 0.08f, centerY + 0.13f);
	glVertex2f(centerX + 0.06f, centerY + 0.15f);

	glEnd();

	glLineWidth(1.0f);

	// left eye
	// left eye
	centerX = centerX - 0.05f;
	centerY = centerY + 0.05f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX + 0.005f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	centerY = centerY + 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye
	centerX = centerX + 0.14f;
	centerY = centerY - 0.01f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.005f;
	centerY = centerY;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	centerX = centerX - 0.01f;
	centerY = centerY + 0.01f;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.05f;
	centerY = centerY - 0.09f;

	float radius = 0.1f;

	float ringInnerRadius = radius;

	float ringOuterRadius = radius + 0.01f;

	glBegin(GL_QUAD_STRIP);
	for (int i = 195; i <= 346; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		// Inner edge points (Matches the green circle exactly)
		float innerX = centerX + (cos(angle) * ringInnerRadius);
		float innerY = centerY + (sin(angle) * ringInnerRadius * 1.7f);

		// Outer edge points (Forms the sharp 1.0f width outline)
		float outerX = centerX + (cos(angle) * ringOuterRadius);
		float outerY = centerY + (sin(angle) * ringOuterRadius * 1.7f);

		glVertex2f(innerX, innerY);
		glVertex2f(outerX, outerY);
	}
	glEnd();

	glLineWidth(6.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.15f, centerY - 0.05f);
	glVertex2f(centerX + 0.15f, centerY - 0.05f);

	glEnd();

	glLineWidth(1.0f);

	// Tooths

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glVertex2f(centerX - 0.005f, centerY - 0.057f);
	glVertex2f(centerX - 0.05f, centerY - 0.057f);
	glVertex2f(centerX - 0.05f, centerY - 0.11f);
	glVertex2f(centerX - 0.005f, centerY - 0.11f);

	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glVertex2f(centerX + 0.005f, centerY - 0.057f);
	glVertex2f(centerX + 0.05f, centerY - 0.057f);
	glVertex2f(centerX + 0.05f, centerY - 0.11f);
	glVertex2f(centerX + 0.005f, centerY - 0.11f);

	glEnd();
}

void hmmSmiley(float centerX, float centerY)
{
	glColor3f(0.1f, 0.1f, 0.1f);

	// eyebrows
	glLineWidth(4.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.08f, centerY + 0.15f);
	glVertex2f(centerX - 0.06f, centerY + 0.17f);

	glVertex2f(centerX + 0.08f, centerY + 0.15f);
	glVertex2f(centerX + 0.06f, centerY + 0.17f);

	glEnd();

	glLineWidth(1.0f);

	// left eye
	centerX = centerX - 0.05f;
	centerY = centerY + 0.05f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX + 0.005f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	centerY = centerY + 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye
	centerX = centerX + 0.14f;
	centerY = centerY - 0.01f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.005f;
	centerY = centerY;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	centerX = centerX - 0.01f;
	centerY = centerY + 0.01f;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.09f;
	centerY = centerY;

	float radius = 0.1f;

	float ringInnerRadius = radius;

	float ringOuterRadius = radius + 0.01f;

	glBegin(GL_QUAD_STRIP);
	for (int i = 290; i <= 321; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		// Inner edge points (Matches the green circle exactly)
		float innerX = centerX + (cos(angle) * ringInnerRadius);
		float innerY = centerY + (sin(angle) * ringInnerRadius * 1.7f);

		// Outer edge points (Forms the sharp 1.0f width outline)
		float outerX = centerX + (cos(angle) * ringOuterRadius);
		float outerY = centerY + (sin(angle) * ringOuterRadius * 1.7f);

		glVertex2f(innerX, innerY);
		glVertex2f(outerX, outerY);
	}
	glEnd();

	// mouth horizontal line

	glLineWidth(5.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX + 0.07f, centerY - 0.10f);
	glVertex2f(centerX + 0.09f, centerY - 0.13f);

	glEnd();

	glLineWidth(1.0f);
}

void attitudeSmiley(float centerX, float centerY)
{
	// eyebrows

	glColor3f(0.1f, 0.1f, 0.1f);

	glLineWidth(4.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.09f, centerY + 0.15f);
	glVertex2f(centerX - 0.05f, centerY + 0.15f);

	glVertex2f(centerX + 0.10f, centerY + 0.15f);
	glVertex2f(centerX + 0.06f, centerY + 0.15f);

	glEnd();

	glLineWidth(1.0f);

	// left eye
	centerX = centerX - 0.05f;
	centerY = centerY + 0.05f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX + 0.005f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye half
	glColor3f(0.975f, 0.865f, 0.587f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.005f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 180; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye
	centerX = centerX + 0.14f;
	// centerY = centerY - 0.01f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.005f;
	centerY = centerY;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye half

	glColor3f(0.975f, 0.865f, 0.587f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX + 0.005f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 180; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	glLineWidth(5.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.12f, centerY - 0.15f);
	glVertex2f(centerX, centerY - 0.15f);

	glEnd();

	glLineWidth(1.0f);
}

void confusedSmiley(float centerX, float centerY)
{
	// eyebrows

	glColor3f(0.1f, 0.1f, 0.1f);

	glLineWidth(4.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.09f, centerY + 0.15f);
	glVertex2f(centerX - 0.05f, centerY + 0.15f);

	glVertex2f(centerX + 0.10f, centerY + 0.15f);
	glVertex2f(centerX + 0.06f, centerY + 0.15f);

	glEnd();

	glLineWidth(1.0f);

	// left eye
	centerX = centerX - 0.05f;
	centerY = centerY + 0.05f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX + 0.001f;
	centerY = centerY + 0.013;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX;
	centerY = centerY + 0.02f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye
	centerX = centerX + 0.14f;
	centerY = centerY - 0.035f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.001f;
	centerY = centerY + 0.013;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	centerX = centerX;
	centerY = centerY + 0.02f;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	glLineWidth(5.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.05f, centerY - 0.17f);
	glVertex2f(centerX - 0.07f, centerY - 0.17f);

	glEnd();

	glLineWidth(1.0f);
}

void crySmiley(float centerX, float centerY)
{

	glColor3f(0.1f, 0.1f, 0.1f);

	// eyebrows
	glLineWidth(4.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.08f, centerY + 0.13f);
	glVertex2f(centerX - 0.06f, centerY + 0.15f);

	glVertex2f(centerX + 0.08f, centerY + 0.13f);
	glVertex2f(centerX + 0.06f, centerY + 0.15f);

	glEnd();

	glLineWidth(1.0f);

	// left eye
	centerX = centerX - 0.05f;
	centerY = centerY + 0.05f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	// centerX = centerX + 0.005f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	// centerX = centerX - 0.01f;
	// centerY = centerY - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye
	centerX = centerX + 0.14f;
	centerY = centerY;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	// centerX = centerX + 0.005f;
	centerY = centerY;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	// centerX = centerX - 0.01f;
	// centerY = centerY + 0.01f;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.065f;
	centerY = centerY - 0.15f;

	float radius = 0.010f;

	float ringInnerRadius = radius;

	float ringOuterRadius = radius + 0.01f;

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= 361; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		// Inner edge points (Matches the green circle exactly)
		float innerX = centerX + (cos(angle) * ringInnerRadius);
		float innerY = centerY + (sin(angle) * ringInnerRadius * 1.7f);

		// Outer edge points (Forms the sharp 1.0f width outline)
		float outerX = centerX + (cos(angle) * ringOuterRadius);
		float outerY = centerY + (sin(angle) * ringOuterRadius * 1.7f);

		glVertex2f(innerX, innerY);
		glVertex2f(outerX, outerY);
	}
	glEnd();
}

void sadSmiley(float centerX, float centerY)
{

	glColor3f(0.1f, 0.1f, 0.1f);

	// eyebrows
	glLineWidth(4.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.08f, centerY + 0.13f);
	glVertex2f(centerX - 0.06f, centerY + 0.15f);

	glVertex2f(centerX + 0.08f, centerY + 0.13f);
	glVertex2f(centerX + 0.06f, centerY + 0.15f);

	glEnd();

	glLineWidth(1.0f);

	// left eye
	centerX = centerX - 0.05f;
	centerY = centerY + 0.05f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX + 0.005f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	// centerX = centerX - 0.01f;
	centerY = centerY - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye
	centerX = centerX + 0.14f;
	centerY = centerY + 0.01f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.005f;
	centerY = centerY;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	// centerX = centerX - 0.01f;
	centerY = centerY - 0.01f;

	glBegin(GL_TRIANGLE_FAN);

	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.06f;
	centerY = centerY - 0.3f;

	float radius = 0.1f;

	float ringInnerRadius = radius;

	float ringOuterRadius = radius + 0.01f;

	glBegin(GL_QUAD_STRIP);
	for (int i = 40; i <= 140; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		// Inner edge points (Matches the green circle exactly)
		float innerX = centerX + (cos(angle) * ringInnerRadius);
		float innerY = centerY + (sin(angle) * ringInnerRadius * 1.7f);

		// Outer edge points (Forms the sharp 1.0f width outline)
		float outerX = centerX + (cos(angle) * ringOuterRadius);
		float outerY = centerY + (sin(angle) * ringOuterRadius * 1.7f);

		glVertex2f(innerX, innerY);
		glVertex2f(outerX, outerY);
	}
	glEnd();
}

void coolEmoji(float centerX, float centerY)
{
	// specs
	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_QUADS);

	// glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(centerX - 0.11f, centerY + 0.14f);
	// glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(centerX - 0.11f, centerY + 0.10f);
	// glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(centerX - 0.169f, centerY + 0.18f);
	// glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(centerX - 0.162f, centerY + 0.20f);

	glEnd();

	// left eye

	centerX = centerX - 0.05f;
	centerY = centerY + 0.05f;

	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.05f);
		float y = centerY + (sin(angle) * 0.09f);

		glVertex2f(x, y);
	}
	glEnd();

	// specs
	glBegin(GL_QUADS);

	glVertex2f(centerX - 0.050f, centerY + 0.09f);
	glVertex2f(centerX + 0.180f, centerY + 0.09f);
	glVertex2f(centerX + 0.180f, centerY - 0.0000001f);
	glVertex2f(centerX - 0.050f, centerY - 0.0000001f);

	glEnd();

	glBegin(GL_QUADS);

	// glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(centerX + 0.180f, centerY + 0.09f);
	// glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(centerX + 0.180f, centerY + 0.05f);
	// glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(centerX + 0.235f, centerY + 0.12f);
	// glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(centerX + 0.230f, centerY + 0.14f);

	glEnd();

	// right eye

	centerX = centerX + 0.14f;
	// centerY = centerY - 0.01f;

	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.05f);
		float y = centerY + (sin(angle) * 0.09f);

		glVertex2f(x, y);
	}
	glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.065f;
	centerY = centerY - 0.05f;

	float radius = 0.1f;

	float ringInnerRadius = radius;

	float ringOuterRadius = radius + 0.01f;

	glBegin(GL_QUAD_STRIP);
	for (int i = 200; i <= 340; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		// Inner edge points (Matches the green circle exactly)
		float innerX = centerX + (cos(angle) * ringInnerRadius);
		float innerY = centerY + (sin(angle) * ringInnerRadius * 1.7f);

		// Outer edge points (Forms the sharp 1.0f width outline)
		float outerX = centerX + (cos(angle) * ringOuterRadius);
		float outerY = centerY + (sin(angle) * ringOuterRadius * 1.7f);

		glVertex2f(innerX, innerY);
		glVertex2f(outerX, outerY);
	}
	glEnd();
}

void lastEmoji(float centerX, float centerY)
{
	glColor3f(0.1f, 0.1f, 0.1f);

	// eyebrows
	glLineWidth(4.0f);

	glBegin(GL_LINES);

	glVertex2f(centerX - 0.08f, centerY + 0.13f);
	glVertex2f(centerX - 0.06f, centerY + 0.13f);

	glVertex2f(centerX + 0.08f, centerY + 0.13f);
	glVertex2f(centerX + 0.06f, centerY + 0.13f);

	glEnd();

	glLineWidth(1.0f);

	// left eye
	centerX = centerX - 0.05f;
	centerY = centerY + 0.05f;

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.05f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside
	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX + 0.005f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.02f);
		float y = centerY + (sin(angle) * 0.035f);

		glVertex2f(x, y);
	}
	glEnd();

	// left eye inside inside
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	centerY = centerY + 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.005f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// right eye
	centerX = centerX + 0.14f;
	centerY = centerY - 0.01f;

	glColor3f(0.1f, 0.1f, 0.1f);

	glBegin(GL_TRIANGLE_FAN);

	centerX = centerX - 0.01f;
	// 1. Establish the center anchor point
	glVertex2f(centerX, centerY);

	// 2. Wrap around 360 degrees to plot the outer edge
	for (int i = 0; i <= 361; i++)
	{
		// Convert degrees to radians for cos() and sin()
		float angle = i * 3.14159f / 180.0f;

		float x = centerX + (cos(angle) * 0.03f);
		float y = centerY + (sin(angle) * 0.01f);

		glVertex2f(x, y);
	}
	glEnd();

	// // right eye inside
	// glColor3f(0.1f, 0.1f, 0.1f);

	// centerX = centerX - 0.005f;
	// centerY = centerY;

	// glBegin(GL_TRIANGLE_FAN);

	// // 1. Establish the center anchor point
	// glVertex2f(centerX, centerY);

	// // 2. Wrap around 360 degrees to plot the outer edge
	// for (int i = 0; i <= 361; i++)
	// {
	// 	// Convert degrees to radians for cos() and sin()
	// 	float angle = i * 3.14159f / 180.0f;

	// 	float x = centerX + (cos(angle) * 0.02f);
	// 	float y = centerY + (sin(angle) * 0.035f);

	// 	glVertex2f(x, y);
	// }
	// glEnd();

	// // right eye inside inside
	// glColor3f(1.0f, 1.0f, 1.0f);

	// centerX = centerX - 0.01f;
	// centerY = centerY + 0.01f;

	// glBegin(GL_TRIANGLE_FAN);

	// // 1. Establish the center anchor point
	// glVertex2f(centerX, centerY);

	// // 2. Wrap around 360 degrees to plot the outer edge
	// for (int i = 0; i <= 361; i++)
	// {
	// 	// Convert degrees to radians for cos() and sin()
	// 	float angle = i * 3.14159f / 180.0f;

	// 	float x = centerX + (cos(angle) * 0.005f);
	// 	float y = centerY + (sin(angle) * 0.01f);

	// 	glVertex2f(x, y);
	// }
	// glEnd();

	// mouth
	glColor3f(0.1f, 0.1f, 0.1f);

	centerX = centerX - 0.05f;
	centerY = centerY - 0.05f;

	float radius = 0.1f;

	float ringInnerRadius = radius;

	float ringOuterRadius = radius + 0.01f;

	glBegin(GL_QUAD_STRIP);
	for (int i = 200; i <= 340; i++)
	{
		float angle = i * 3.14159f / 180.0f;

		// Inner edge points (Matches the green circle exactly)
		float innerX = centerX + (cos(angle) * ringInnerRadius);
		float innerY = centerY + (sin(angle) * ringInnerRadius * 1.7f);

		// Outer edge points (Forms the sharp 1.0f width outline)
		float outerX = centerX + (cos(angle) * ringOuterRadius);
		float outerY = centerY + (sin(angle) * ringOuterRadius * 1.7f);

		glVertex2f(innerX, innerY);
		glVertex2f(outerX, outerY);
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
