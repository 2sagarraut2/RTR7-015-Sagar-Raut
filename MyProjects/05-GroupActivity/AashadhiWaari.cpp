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

void dhwajGhetlelaWarkari(float SR_XPosition, float SR_YPosition, float SR_Height, float SR_Width);

bool bIsFullScreen = false;
float SR_XPosition = -0.5f;
float SR_YPosition = 0.3f;
float SR_Height = 1.5f;
float SR_Width = 0.2f;

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

    // float xPosition, float yPosition, float height, float width
    dhwajGhetlelaWarkari(SR_XPosition, SR_YPosition, SR_Height, SR_Width);

    glutSwapBuffers();
}

void dhwajGhetlelaWarkari(float SR_XPosition, float SR_YPosition, float SR_Height, float SR_Width)
{
    glColor3f(0.933f, 0.937f, 0.945f);

    glBegin(GL_QUADS);

    glVertex3f(SR_XPosition, SR_YPosition, 0.0f);
    glVertex3f(SR_XPosition + SR_Width, SR_YPosition, 0.0f);
    glVertex3f(SR_XPosition + SR_Width, SR_YPosition - SR_Height, 0.0f);
    glVertex3f(SR_XPosition, SR_YPosition - SR_Height, 0.0f);

    glEnd();

    // Warkari starts here
    // gandhitopi
    // topi top
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLES);

    glVertex3f(SR_XPosition + (SR_Width / 2), SR_YPosition, 0.0f);
    glVertex3f(SR_XPosition + (SR_Width - 0.051f), SR_YPosition - 0.045f, 0.0f);
    glVertex3f(SR_XPosition + 0.051f, SR_YPosition - 0.045f, 0.0f);

    glEnd();

    // topi main quad
    glBegin(GL_QUADS);

    glVertex3f(SR_XPosition + (SR_Width - 0.051f), SR_YPosition - 0.045f, 0.0f);
    glVertex3f(SR_XPosition + 0.051f, SR_YPosition - 0.045f, 0.0f);
    glVertex3f(SR_XPosition + (SR_Width / 5), SR_YPosition - 0.13f, 0.0f);
    glVertex3f(SR_XPosition + (SR_Width - 0.04f), SR_YPosition - 0.13f, 0.0f);

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
    glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.575f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.575f);

    glEnd();

    // hand top part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.575f);
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.575f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.81f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.93f);

    glEnd();

    // hand top line
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.575f);
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.81f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_XPosition - 0.008f, SR_YPosition - 0.81f);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_XPosition + 0.13f, SR_YPosition - 0.81f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_XPosition + 0.13f, SR_YPosition - 0.81f);
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition + 0.07f, SR_YPosition - 0.93f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_XPosition + 0.07f, SR_YPosition - 0.93f);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_XPosition - 0.075f, SR_YPosition - 0.93f);

    glEnd();

    // hand horizontal part -- here we will add animation
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
