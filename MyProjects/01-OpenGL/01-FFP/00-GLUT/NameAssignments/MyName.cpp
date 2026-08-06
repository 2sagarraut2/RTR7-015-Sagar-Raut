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

#define SR_VALUE_FROM_PERCENT(complete_value, SR_percent) (((complete_value) * (SR_percent)) / 100.0f)

bool bIsFullScreen = false;
float startingPointX = -0.9f; // -0.9
float startingPointY = 0.5f;
float width = 0.32f;
float thickness = 0.10f;
float SR_namePercent = 50.0;

// function declarations
void drawCoverBox(float startingPointX, float startingPointY, float width, float SR_percent);
void letterS(float startingPoint, float startingPointY, float width, float thickness, float SR_namePercent);
void letterA(float startingPointX, float startingPointY, float width, float thickness, float SR_namePercent);
void letterG(float startingPointX, float startingPointY, float width, float thickness, float SR_namePercent);
void letterR(float startingPointX, float startingPointY, float width, float thickness, float SR_namePercent);

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

    drawCoverBox(startingPointX, startingPointY, width, SR_namePercent);

    // TODO: ADD WAIT TO ADD ANIMATIONS

    // float startingPoint, float startingPointY, float width, float thickness
    // sagar name code
    letterS(startingPointX, startingPointY, width, thickness, SR_namePercent);
    startingPointX = startingPointX + width;
    letterA(startingPointX, startingPointY, width, thickness, SR_namePercent);
    startingPointX = startingPointX + width + thickness / 1.3f;
    letterG(startingPointX, startingPointY, width, thickness, SR_namePercent);
    startingPointX = startingPointX + width;
    letterA(startingPointX, startingPointY, width, thickness, SR_namePercent);
    startingPointX = startingPointX + width + thickness / 1.3f;
    letterR(startingPointX, startingPointY, width, thickness, SR_namePercent);

    glutSwapBuffers();
}

void drawCoverBox(float startingPointX, float startingPointY, float width, float SR_percent)
{
    glColor3f(1.0f, 0.0f, 1.0f);
    glLineWidth(10.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX - 0.04f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY + 0.04f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + (width * 5.5f) + 0.04f), SR_percent), SR_VALUE_FROM_PERCENT(startingPointY + 0.04f, SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + (width * 5.5f) + 0.04f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - width * 1.4f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX - 0.04f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - width * 1.4f), SR_percent));
    glEnd();

    glLineWidth(1.0f);
}

void letterS(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 2.5f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 2.5), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - 0.06f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - 0.06f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 2.5f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 2.5f), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width / 1.4f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - 0.06f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - 0.06), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4.0f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width / 1.4f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4.0f), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - (thickness * 3)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - (thickness * 3)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - (thickness * 3)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - (thickness * 3)), SR_percent));

    glEnd();
}

void letterA(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width / 2), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width / 2 + thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX - width / 2 + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX - width / 2 + width + thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width + thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + 0.16f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - 0.09f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX - 0.082f + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - 0.09f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX - 0.045f + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 2.8f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + 0.125f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 2.8f), SR_percent));

    // printf("Top-Left - %f, %f\t", startingPointX + width / 2, startingPointY);
    // printf("Top-Right - %f, %f\t", startingPointX + width / 2 + thickness / 1.3f, startingPointY);
    // printf("Bottom-Right - %f, %f\t", startingPointX + thickness / 1.3f, startingPointY - thickness * 4);
    // printf("Bottom-Left - %f, %f\n", startingPointX, startingPointY - thickness * 4);

    // printf("Top-Left - %f, %f\t", startingPointX - width / 2 + width, startingPointY);
    // printf("Top-Right - %f, %f\t", startingPointX - width / 2 + width + thickness / 1.3f, startingPointY);
    // printf("Bottom-Right - %f, %f\t", startingPointX + width + thickness / 1.3f, startingPointY - thickness * 4);
    // printf("Bottom-Left - %f, %f\n", startingPointX + width, startingPointY - thickness * 4);

    glEnd();
}

void letterG(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + (thickness + 0.05f)), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - width / 2.0f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - width / 2.0f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 2.5), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + (thickness + 0.05f)), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 2.5), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - width / 1.8f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - width / 1.8f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width - thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - (thickness * 3)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - (thickness * 3)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - (thickness * 3)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - (thickness * 3)), SR_percent));

    glEnd();
}

void letterR(float startingPointX, float startingPointY, float width, float thickness, float SR_percent)
{
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + thickness / 1.3f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 4), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width / 0.98f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width / 0.98f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width - thickness + 0.02f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width + 0.006f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width + 0.006f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 2), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width - thickness + 0.02f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness * 2), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - (width / 2)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width / 0.98f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - (width / 2)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width / 0.98f), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - (width / 2)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - (width / 2)), SR_percent));

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - (width / 2)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - (width)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX + width), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - thickness - (width)), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((startingPointX), SR_percent), SR_VALUE_FROM_PERCENT((startingPointY - (width - 0.05f)), SR_percent));

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
