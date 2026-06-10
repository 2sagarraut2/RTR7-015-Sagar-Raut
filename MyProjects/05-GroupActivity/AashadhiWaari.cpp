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

void dhwajGhetlelaWarkari(float SR_XPosition, float SR_YPosition, float SR_Height, float SR_Width, float flagSway);

#define VALUE_FROM_PERCENT(complete_value, percent) (complete_value * percent / 100)

bool bIsFullScreen = false;
float SR_XPosition = 0.0f;
float SR_YPosition = 0.6f;
float SR_Height = 1.5f;
float SR_Width = 0.2f;
float currentSwayOffset = 0.0f;
bool bodyGoingUp = true;
bool flagSwayingLeft = true;

int percent = 100.0f;

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
    glutCreateWindow("Aashadhi Waari: Sagar Sambhaji Raut");

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

    glEnable(GL_POLYGON_OFFSET_FILL);

    glPolygonOffset(1.0f, 1.0f);
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

    float startX = 0.0f;
    if (SR_XPosition <= startX + 0.2f)
    {
        SR_XPosition = SR_XPosition + 0.0005f;
        if (SR_XPosition >= startX + 0.199f)
        {
            SR_XPosition = startX;
        }
    }

    float bounceRange = 0.015f;
    float upperYLimit = 0.4f + bounceRange;
    float lowerYLimit = 0.4f - bounceRange;

    if (bodyGoingUp)
    {
        SR_YPosition = SR_YPosition + 0.0004f;
        if (SR_YPosition >= upperYLimit)
        {
            bodyGoingUp = false;
        }
    }
    else
    {
        SR_YPosition = SR_YPosition - 0.0004f;
        if (SR_YPosition <= lowerYLimit)
        {
            bodyGoingUp = true;
        }
    }

    if (flagSwayingLeft)
    {
        currentSwayOffset = currentSwayOffset - 0.0006f;
        if (currentSwayOffset <= -0.02f)
        {
            flagSwayingLeft = false;
        }
    }
    else
    {
        currentSwayOffset = currentSwayOffset + 0.0006f;
        if (currentSwayOffset >= 0.02f)
        {
            flagSwayingLeft = true;
        }

        // printf("Offset, %f\n", currentSwayOffset);
    }

    dhwajGhetlelaWarkari(SR_XPosition, SR_YPosition, SR_Height, SR_Width, currentSwayOffset);

    glutSwapBuffers();
    glutPostRedisplay();
}

void dhwajGhetlelaWarkari(float SR_XPosition, float SR_YPosition, float SR_Height, float SR_Width, float flagSway)
{
    glColor3f(0.933f, 0.937f, 0.945f);

    glBegin(GL_QUADS);

    glVertex3f(VALUE_FROM_PERCENT(SR_XPosition, percent), VALUE_FROM_PERCENT(SR_YPosition, percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT(SR_Width + SR_XPosition, percent), VALUE_FROM_PERCENT(SR_YPosition, percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT(SR_Width + SR_XPosition, percent), VALUE_FROM_PERCENT(SR_YPosition - SR_Height, percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT(SR_XPosition, percent), VALUE_FROM_PERCENT(SR_YPosition - SR_Height, percent), 0.0f);

    // glVertex3f(VALUE_FROM_PERSENT(-0.2f, persent) + xPosition, VALUE_FROM_PERSENT(-0.4f, persent) + YPosition, 0.0f);

    glEnd();

    // Warkari starts here
    // gandhitopi
    // topi top
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLES);

    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent), VALUE_FROM_PERCENT(SR_YPosition, percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent), 0.0f);

    glEnd();

    // topi main quad
    glBegin(GL_QUADS);

    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.051f)), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + (SR_Width / 5)), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.04f)), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent), 0.0f);

    glEnd();

    // glColor3f(0.917f, 0.816f, 0.726f);
    // glLineWidth(3.0f);

    // glBegin(GL_LINE_LOOP);

    // glVertex2f(SR_XPosition + (SR_Width / 2), SR_YPosition);
    // glVertex2f(SR_XPosition + (SR_Width - 0.051f), SR_YPosition - 0.045f);
    // glVertex3f(SR_XPosition + (SR_Width - 0.04f), SR_YPosition - 0.13f, 0.0f);
    // glVertex3f(SR_XPosition + (SR_Width / 2), SR_YPosition - 0.15f, 0.0f);
    // glVertex2f(SR_XPosition + (SR_Width / 2), SR_YPosition - 0.15f);
    // glVertex2f(SR_XPosition + (SR_Width / 5), SR_YPosition - 0.13f);
    // glVertex2f(SR_XPosition + 0.051f, SR_YPosition - 0.045f);
    // glVertex2f(SR_XPosition + (SR_Width / 2), SR_YPosition);

    // glEnd();

    // glLineWidth(1.0f);

    // neck rectangle
    glBegin(GL_QUADS);

    glColor3f(0.890f, 0.757f, 0.624f);
    glVertex2f(SR_XPosition + (SR_Width - 0.057f), SR_YPosition - 0.37f);
    // glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(SR_XPosition + 0.057f, SR_YPosition - 0.37f);
    // glColor3f(0.890f, 0.757f, 0.624f);
    glVertex2f(SR_XPosition + 0.057f, SR_YPosition - 0.49f);
    glVertex2f(SR_XPosition + (SR_Width - 0.057f), SR_YPosition - 0.49f);

    glEnd();

    // face quad
    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    glVertex2f(SR_XPosition + (SR_Width - 0.051f), SR_YPosition - 0.13f);
    glVertex2f(SR_XPosition + 0.051f, SR_YPosition - 0.13f);
    glVertex2f(SR_XPosition + 0.051f, SR_YPosition - 0.35f);
    glVertex2f(SR_XPosition + (SR_Width - 0.051f), SR_YPosition - 0.35f);

    glEnd();

    // hat bottom tip
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(SR_XPosition + (SR_Width / 5), SR_YPosition - 0.13f, 0.0f);
    glVertex3f(SR_XPosition + (SR_Width - 0.04f), SR_YPosition - 0.13f, 0.0f);
    glVertex3f(SR_XPosition + (SR_Width / 2), SR_YPosition - 0.15f, 0.0f);

    glEnd();

    // chin semicircle
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.917f, 0.816f, 0.726f);
    // 1. Establish the center anchor point
    float centerX = SR_XPosition + (SR_Width / 2);
    float centerY = SR_YPosition - 0.35f;
    float radius = 0.048f;
    glVertex2f(centerX, centerY);

    // 2. Wrap around 360 degrees to plot the outer edge
    for (int i = 0; i <= 360; i++)
    {
        // Convert degrees to radians for cos() and sin()
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius);
        float y = centerY + (sin(angle) * radius);

        glVertex2f(x, y);
    }
    glEnd();

    // bukka on chin
    glColor3f(0.1f, 0.1f, 0.1f);

    glBegin(GL_TRIANGLE_FAN);
    // 1. Establish the center anchor point
    centerY = SR_YPosition - 0.37f;
    radius = 0.015f;
    glVertex2f(centerX, centerY);

    // 2. Wrap around 360 degrees to plot the outer edge
    for (int i = 0; i <= 360; i++)
    {
        // Convert degrees to radians for cos() and sin()
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius);
        float y = centerY + (sin(angle) * (radius + 0.011f));

        glVertex2f(x, y);
    }
    glEnd();

    // left hair
    glBegin(GL_QUADS);

    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(SR_XPosition + 0.040f, SR_YPosition - 0.13f);
    glVertex2f(SR_XPosition + 0.040f, SR_YPosition - 0.18f);
    glVertex2f(SR_XPosition + 0.051f, SR_YPosition - 0.18f);
    glVertex2f(SR_XPosition + 0.051f, SR_YPosition - 0.135f);

    glEnd();

    // left ear
    glBegin(GL_QUADS);
    glColor3f(0.917f, 0.816f, 0.726f);

    glVertex2f(SR_XPosition + 0.040f, SR_YPosition - 0.18f);
    glVertex2f(SR_XPosition + 0.040f, SR_YPosition - 0.32f);
    glVertex2f(SR_XPosition + 0.051f, SR_YPosition - 0.32f);
    glVertex2f(SR_XPosition + 0.051f, SR_YPosition - 0.18f);

    glEnd();

    // glBegin(GL_LINE_LOOP);
    // glColor3f(0.05f, 0.05f, 0.05);

    // glVertex2f(SR_XPosition + 0.040f, SR_YPosition - 0.18f);
    // glVertex2f(SR_XPosition + 0.040f, SR_YPosition - 0.32f);
    // glVertex2f(SR_XPosition + 0.051f, SR_YPosition - 0.32f);
    // glVertex2f(SR_XPosition + 0.051f, SR_YPosition - 0.18f);

    // glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.1f, 0.1f);

    // 1. Establish the center anchor point
    centerX = SR_XPosition + 0.045f;
    centerY = SR_YPosition - 0.31f;
    radius = 0.006f;
    glVertex2f(centerX, centerY);

    // 2. Wrap around 360 degrees to plot the outer edge
    for (int i = 0; i <= 360; i++)
    {
        // Convert degrees to radians for cos() and sin()
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius);
        float y = centerY + (sin(angle) * (radius + 0.011f));

        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);

    // right hairs
    glBegin(GL_QUADS);

    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(SR_XPosition + (SR_Width - 0.051f), SR_YPosition - 0.135f);
    glVertex2f(SR_XPosition + (SR_Width - 0.051f), SR_YPosition - 0.18f);
    glVertex2f(SR_XPosition + (SR_Width - 0.040f), SR_YPosition - 0.18f);
    glVertex2f(SR_XPosition + (SR_Width - 0.040f), SR_YPosition - 0.13f);

    glEnd();

    // right ears
    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);
    glVertex2f(SR_XPosition + (SR_Width - 0.051f), SR_YPosition - 0.18f);
    glVertex2f(SR_XPosition + (SR_Width - 0.051f), SR_YPosition - 0.32f);
    glVertex2f(SR_XPosition + (SR_Width - 0.040f), SR_YPosition - 0.32f);
    glVertex2f(SR_XPosition + (SR_Width - 0.040f), SR_YPosition - 0.18f);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.1f, 0.1f, 0.1f);

    // 1. Establish the center anchor point
    centerX = SR_XPosition + (SR_Width - 0.046f);
    centerY = SR_YPosition - 0.31f;
    radius = 0.006f;
    glVertex2f(centerX, centerY);

    // 2. Wrap around 360 degrees to plot the outer edge
    for (int i = 0; i <= 360; i++)
    {
        // Convert degrees to radians for cos() and sin()
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius);
        float y = centerY + (sin(angle) * (radius + 0.011f));

        glVertex2f(x, y);
    }

    glEnd();

    // shirt starts here

    // left collar
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_XPosition + 0.057f, SR_YPosition - 0.37f);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_XPosition + 0.097f, SR_YPosition - 0.49f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.49f);
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_XPosition - 0.028f, SR_YPosition - 0.37f);

    glEnd();

    // right collar
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_XPosition + (SR_Width - 0.057f), SR_YPosition - 0.37f);
    // glColor3f(0.917f, 0.816f, 0.726f); // skin
    glVertex2f(SR_XPosition + (SR_Width / 2), SR_YPosition - 0.49f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition + (SR_Width + 0.075f), SR_YPosition - 0.49f);
    // glColor3f(0.0f, 0.1f, 0.0f); // green
    glVertex2f(SR_XPosition + (SR_Width + 0.028f), SR_YPosition - 0.37f);

    glEnd();

    // below collar quad
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.49f);
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.49f);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 1.15f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 1.15f);

    glEnd();

    // below collar quad line loop
    // glBegin(GL_LINE_LOOP);

    // glColor3f(0.851f, 0.863f, 0.882f);

    // // glColor3f(0.0f, 1.0f, 0.0f); // green
    // glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.49f);
    // // glColor3f(1.0f, 1.0f, 1.0f); // white
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.49f);
    // // glColor3f(0.0f, 0.0f, 1.0f); // blue
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 1.15f);
    // // glColor3f(0.1f, 0.1f, 0.1f); // black
    // glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 1.15f);

    // glEnd();

    // left hand vertical part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.490f);
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.490f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.81f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.93f);

    glEnd();

    // left hand vertical part lines loop
    glBegin(GL_LINE_LOOP);

    // glColor3f(0.851f, 0.863f, 0.882f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.490f);
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.490f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.81f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.93f);

    glEnd();

    // left hand top line
    glBegin(GL_LINES);

    glLineWidth(8.0f);

    glColor3f(0.851f, 0.863f, 0.882f);

    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.575f);
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.81f);

    glColor3f(0.851f, 0.863f, 0.882f);

    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.81f);
    glVertex2f(SR_XPosition + 0.13f, SR_YPosition - 0.81f);

    glColor3f(0.851f, 0.863f, 0.882f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_XPosition + 0.13f, SR_YPosition - 0.81f);
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition + 0.07f, SR_YPosition - 0.93f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition + 0.07f, SR_YPosition - 0.93f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.93f);

    // right hand lines
    glColor3f(0.851f, 0.863f, 0.882f);
    glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.575f);
    glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);

    glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);
    glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.90f);

    // right hand slant lines
    // glVertex2f(SR_XPosition + 0.200f, SR_YPosition - 0.708f);
    // glVertex2f(SR_XPosition + 0.145f, SR_YPosition - 0.82f);

    // glVertex2f(SR_XPosition + 0.145f, SR_YPosition - 0.82f);
    // glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);

    // glVertex2f(SR_XPosition + 0.200f, SR_YPosition - 0.708f);
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.80f);

    glColor3f(0.851f, 0.863f, 0.882f);
    glVertex2f(SR_XPosition + 0.202f, SR_YPosition - 0.715f);
    glVertex2f(SR_XPosition + 0.145f, SR_YPosition - 0.82f);

    glVertex2f(SR_XPosition + 0.202f, SR_YPosition - 0.715f);
    glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.80f);

    // glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.80f);

    glVertex2f(SR_XPosition + 0.145f, SR_YPosition - 0.82f);
    glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);

    glLineWidth(1.0f);

    glEnd();

    // left hand horizontal part -- here we will add animation
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.81f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.93f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition + 0.07f, SR_YPosition - 0.93f);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_XPosition + 0.13f, SR_YPosition - 0.81f);

    glEnd();

    // left hand horizontal part lines -- here we will add animation
    glBegin(GL_LINE_LOOP);

    glColor3f(0.851f, 0.863f, 0.882f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.81f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.93f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition + 0.07f, SR_YPosition - 0.93f);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_XPosition + 0.13f, SR_YPosition - 0.81f);

    glEnd();

    // right hand vertical part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.490f);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.490f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.90f);

    glEnd();

    // // right hand vertical part line lopp
    // glBegin(GL_LINE_LOOP);

    // glColor3f(0.851f, 0.863f, 0.882f);

    // // glColor3f(1.0f, 0.0f, 0.0f); // red
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.490f);
    // // glColor3f(0.0f, 0.0f, 1.0f); // blue
    // glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.490f);

    // // glColor3f(0.0f, 1.0f, 0.0f); // green
    // glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);
    // // glColor3f(0.1f, 0.1f, 0.1f); // black
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.90f);

    // glEnd();

    // right hand cross part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition + 0.202f, SR_YPosition - 0.715f);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_XPosition + 0.145f, SR_YPosition - 0.82f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.80f);

    glEnd();

    // right hand cross part lines loop
    // glBegin(GL_LINE_LOOP);

    // glColor3f(0.851f, 0.863f, 0.882f);

    // // glColor3f(1.0f, 0.0f, 0.0f); // red
    // glVertex2f(SR_XPosition + 0.202f, SR_YPosition - 0.715f);
    // // glColor3f(0.0f, 0.0f, 1.0f); // blue
    // glVertex2f(SR_XPosition + 0.145f, SR_YPosition - 0.82f);

    // // glColor3f(0.0f, 1.0f, 0.0f); // green
    // glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);
    // // glColor3f(0.1f, 0.1f, 0.1f); // black
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.80f);

    // glEnd();

    // flag starts here
    // flag bamboo
    glBegin(GL_QUADS);

    glColor3f(0.439f, 0.310f, 0.184f);

    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), percent), 0.0f);

    glEnd();

    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);

    glColor3f(0.278f, 0.282f, 0.267f);

    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), percent), 0.0f);

    glEnd();

    glLineWidth(1.0f);

    // flag
    glBegin(GL_TRIANGLES);
    glColor3f(0.893f, 0.313f, 0.149f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.012f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.012f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.1f), percent), 0.0f);

    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.3f + flagSway), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.1f), percent), 0.0f);
    glEnd();

    // flag border

    glLineWidth(1.0f);

    glLineWidth(1.0f);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.013f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent), 0.0f);
    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.013f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.1f), percent), 0.0f);

    glVertex3f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.3f + flagSway), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.1f), percent), 0.0f);
    glEnd();

    glLineWidth(1.0f);

    // pant starts here
    glBegin(GL_QUADS);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 1.15f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 1.15f);
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
