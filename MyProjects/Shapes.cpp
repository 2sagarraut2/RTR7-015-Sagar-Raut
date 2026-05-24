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

bool bIsFullScreen = false;

// function declarations
void drawTriangle(float startingX, float startingY, float height, float width);
void drawSquare(float startingX, float startingY, float height, float width);
void drawLine(float startingX, float startingY, float height, float width);

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
    glutCreateWindow("Sagar Raut");

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
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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

    // tirangle
    // float startingX, float startingY, float height, float width
    drawTriangle(-0.8f, 0.8f, 0.4f, 0.4f);

    // square
    // float startingX, float startingY, float height, float width
    drawSquare(-0.1f, 0.8f, 0.4f, 0.25f);

    // rectangle
    // float startingX, float startingY, float height, float width
    drawSquare(0.5f, 0.8f, 0.4f, 0.4f);

    // line
    drawLine(-0.8f, 0.1f, 0.4f, 0.4f);

    glutSwapBuffers();
}

void drawTriangle(float startingX, float startingY, float height, float width)
{
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(startingX, startingY, 0.0f);
    glVertex3f(startingX + (width / 2), startingY - height, 0.0f);
    glVertex3f(startingX - (width / 2), startingY - height, 0.0f);

    glEnd();
}

void drawSquare(float startingX, float startingY, float height, float width)
{
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 1.0f); // Blue

    glVertex2f(startingX, startingY);
    glVertex2f(startingX - width, startingY);
    glVertex2f(startingX - width, startingY - height);
    glVertex2f(startingX, startingY - height);

    glEnd();
}

void drawLine(float startingX, float startingY, float height, float width)
{
    glLineWidth(5.0f);

    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_LINES);

    glVertex2f(startingX, startingY);         // Line 1 Start
    glVertex2f(startingX + width, startingY); // Line 1 End

    glEnd();

    glLineWidth(1.0f);
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
