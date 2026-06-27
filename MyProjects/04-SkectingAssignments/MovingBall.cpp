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
float yPosition = 1.0f;

void drawBall(float centerX, float centerY);

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

    if (yPosition >= -0.5)
    {
        yPosition = yPosition - 0.009;
    }

    drawBall(0.0f, yPosition);

    glutSwapBuffers();
    glutPostRedisplay();
}

void drawBall(float centerX, float centerY)
{
    centerX = centerX - 0.05f;
    centerY = centerY + 0.05f;

    glColor3f(0.913f, 0.344f, 0.290f);

    glBegin(GL_TRIANGLE_FAN);

    centerX = centerX - 0.01f;
    // 1. Establish the center anchor point
    glVertex2f(centerX, centerY);

    // 2. Wrap around 360 degrees to plot the outer edge
    for (int i = 0; i <= 361; i++)
    {
        // Convert degrees to radians for cos() and sin()
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * 0.1f);
        float y = centerY + (sin(angle) * 0.17f);

        glVertex2f(x, y);
    }
    glEnd();

    centerX = centerX - 0.05f;
    centerY = centerY + 0.05f;

    glColor3f(0.983f, 0.930f, 0.795f);

    glBegin(GL_TRIANGLE_FAN);

    centerX = centerX - 0.01f;
    // 1. Establish the center anchor point
    glVertex2f(centerX, centerY);

    // 2. Wrap around 360 degrees to plot the outer edge
    for (int i = 0; i <= 361; i++)
    {
        // Convert degrees to radians for cos() and sin()
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * 0.02f);
        float y = centerY + (sin(angle) * 0.04f);

        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    centerX = centerX - 0.01f;
    centerY = centerY - 0.1f;
    // 1. Establish the center anchor point
    glVertex2f(centerX, centerY);

    // 2. Wrap around 360 degrees to plot the outer edge
    for (int i = 0; i <= 361; i++)
    {
        // Convert degrees to radians for cos() and sin()
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * 0.02f);
        float y = centerY + (sin(angle) * 0.04f);

        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    centerX = centerX + 0.1f;
    // 1. Establish the center anchor point
    glVertex2f(centerX, centerY);

    // 2. Wrap around 360 degrees to plot the outer edge
    for (int i = 0; i <= 361; i++)
    {
        // Convert degrees to radians for cos() and sin()
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * 0.02f);
        float y = centerY + (sin(angle) * 0.04f);

        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_LINES);

    glVertex2f(-1.0f, -0.62f);
    glVertex2f(1.0f, -0.62f);

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