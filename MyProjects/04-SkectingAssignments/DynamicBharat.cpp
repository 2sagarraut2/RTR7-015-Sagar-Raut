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
#include "DynamicBharat.h"

bool bIsFullScreen = false;

static float radius = 0.5f;

float innerX = 0.0f;
float innerY = 0.0f;
float currentAngle = -180.0f;

void circularPath(float, float, float);
void linearPath(float startingX, float startingY, float endingX, float endingY);
void planeMove();
void renderMyPlane();

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

    glColor3f(1.0f, 0.0f, 0.0f);

    // glVertex2f(centerX, centerY);

    // static float centerX = -0.6f;
    // static float centerY = 0.5f;

    planeMove();
    renderMyPlane();

    // renderFighterJet(outerX, outerY, 100.0f);

    // circularPath(0.0f, 0.0f, 0.4f);
    // circularPath(0.6f, 1.0f, 0.4f);

    // circularPath(-0.6f, -1.0f, 0.4f);
    // circularPath(0.6f, -1.0f, 0.4f);

    // linearPath(-0.6, 0.32f, 0.6f, 0.32f);
    // linearPath(-0.6, -0.32f, 0.6f, -0.32f);

    // renderFighterJet(0.0f, 0.0f, 50.0f);

    glutSwapBuffers();
    glutPostRedisplay();
}

void renderMyPlane()
{
    printf("%f, %f\n", innerX, innerY);
    renderFighterJet(innerX, innerY, 70.0f);
}

void planeMove()
{
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POINTS);

    float angle = currentAngle * 3.14159f / 180.0f;

    innerX = -0.8f + (cos(angle) * (radius + 0.1f));
    innerY = 1.5f + (sin(angle) * (radius + 0.1f) * 1.7f);

    glVertex2f(innerX, innerY);

    if (currentAngle <= -100.0f)
    {
        currentAngle += 0.2f;
    }
    else
    {
        currentAngle = -180.0f;
    }

    glEnd();
}

void circularPath(float centerX, float centerY, float radius)
{
    glBegin(GL_TRIANGLE_FAN);
    // 1. Establish the center anchor point
    glVertex2f(centerX, centerY);

    // 2. Wrap around 360 degrees to plot the outer edge
    for (float i = 0; i <= 361; i = i + 0.09f)
    {
        // Convert degrees to radians for cos() and sin()
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius);
        float y = centerY + (sin(angle) * radius * 1.7f);

        glVertex2f(x, y);
        // renderFighterJet(x, y, 100.0f);
    }
    glEnd();
}

void linearPath(float startingX, float startingY, float endingX, float endingY)
{
    glBegin(GL_LINES);

    glVertex2f(startingX, startingY);
    glVertex2f(endingX, endingY);

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