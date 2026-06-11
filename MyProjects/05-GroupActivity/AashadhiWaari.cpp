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
#define SCALE_RADIUS(radius, percent) ((radius) * (percent) / 100.0f)

bool bIsFullScreen = false;
float SR_XPosition = 0.0f;
float SR_YPosition = 0.9f;
float SR_Height = 1.5f;
float SR_Width = 0.2f;
float currentSwayOffset = 0.0f;
bool bodyGoingUp = true;
bool flagSwayingLeft = true;

int percent = 80.0f;

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

    // float startX = 0.0f;
    // if (SR_XPosition <= startX + 0.2f)
    // {
    //     SR_XPosition = SR_XPosition + 0.0005f;
    //     if (SR_XPosition >= startX + 0.199f)
    //     {
    //         SR_XPosition = startX;
    //     }
    // }

    // float bounceRange = 0.015f;
    // float upperYLimit = 0.4f + bounceRange;
    // float lowerYLimit = 0.4f - bounceRange;

    // if (bodyGoingUp)
    // {
    //     SR_YPosition = SR_YPosition + 0.0004f;
    //     if (SR_YPosition >= upperYLimit)
    //     {
    //         bodyGoingUp = false;
    //     }
    // }
    // else
    // {
    //     SR_YPosition = SR_YPosition - 0.0004f;
    //     if (SR_YPosition <= lowerYLimit)
    //     {
    //         bodyGoingUp = true;
    //     }
    // }

    // if (flagSwayingLeft)
    // {
    //     currentSwayOffset = currentSwayOffset - 0.0006f;
    //     if (currentSwayOffset <= -0.02f)
    //     {
    //         flagSwayingLeft = false;
    //     }
    // }
    // else
    // {
    //     currentSwayOffset = currentSwayOffset + 0.0006f;
    //     if (currentSwayOffset >= 0.02f)
    //     {
    //         flagSwayingLeft = true;
    //     }

    //     // printf("Offset, %f\n", currentSwayOffset);
    // }

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

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent), VALUE_FROM_PERCENT(SR_YPosition, percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent));

    glEnd();

    // topi main quad
    glBegin(GL_QUADS);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.051f)), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + (SR_Width / 5)), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.04f)), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));

    glEnd();

    // neck rectangle
    glBegin(GL_QUADS);

    glColor3f(0.890f, 0.757f, 0.624f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.057f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));
    // glColor3f(0.890f, 0.757f, 0.624f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.057f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));

    glEnd();

    // face quad
    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.35f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.35f), percent));

    glEnd();

    // hat bottom tip
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 5), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.04f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.15f), percent));

    glEnd();

    // chin semicircle
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.917f, 0.816f, 0.726f);
    // 1. Establish the center anchor point
    float centerX = VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent);
    float centerY = VALUE_FROM_PERCENT((SR_YPosition - 0.35f), percent);
    float radius = SCALE_RADIUS(0.048f, percent);
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

    // BUKKA ON CHIN
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLE_FAN);

    float bukkaX = VALUE_FROM_PERCENT((SR_XPosition + (SR_Width / 2)), percent);
    float bukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent);

    float radiusX = SCALE_RADIUS(0.015f, percent);

    float radiusY = SCALE_RADIUS(0.015f + 0.011f, percent);

    glVertex2f(bukkaX, bukkaY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = bukkaX + (cos(angle) * radiusX);
        float y = bukkaY + (sin(angle) * radiusY);

        glVertex2f(x, y);
    }
    glEnd();

    // left hair
    glBegin(GL_QUADS);

    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.040f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.040f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.135f), percent));

    glEnd();

    // left ear
    glBegin(GL_QUADS);
    glColor3f(0.917f, 0.816f, 0.726f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.040f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.040f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.32f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.32f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), percent));

    glEnd();

    // --- BUKKA ON EAR (FULLY FIXED & SCALABLE) ---
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.1f, 0.1f); // Charcoal black

    // 1. Calculate positions safely from your global baseline variables
    float earBukkaX = VALUE_FROM_PERCENT((SR_XPosition + 0.045f), percent);
    float earBukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.31f), percent);

    // 2. Scale horizontal radius
    radiusX = SCALE_RADIUS(0.006f, percent);

    // FIXED: Wrap the entire vertical height extension inside your macro
    radiusY = SCALE_RADIUS(0.006f + 0.011f, percent);

    // Submit the clean, anchored center point to the GPU
    glVertex2f(earBukkaX, earBukkaY);

    // 3. Loop to plot the outer edge
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        // Math uses the cleanly scaled horizontal and vertical dimensions
        float x = earBukkaX + (cos(angle) * radiusX);
        float y = earBukkaY + (sin(angle) * radiusY);

        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);

    // right hairs
    glBegin(GL_QUADS);

    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.135f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));

    glEnd();

    // right ears
    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.32f), percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.32f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), percent));

    glEnd();

    // --- BUKKA ON EARS
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.1f, 0.1f); // Charcoal black

    // 1. FIXED: Wrap the center coordinates in your position percentage macro
    earBukkaX = VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.046f)), percent);
    earBukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.31f), percent);

    // 2. FIXED: Scale the horizontal radius
    radiusX = SCALE_RADIUS(0.006f, percent);

    // 3. FIXED: Combine and scale the vertical radius together to prevent stretching
    radiusY = SCALE_RADIUS(0.006f + 0.011f, percent);

    // Submit the clean, scaled center anchor to the GPU
    glVertex2f(earBukkaX, earBukkaY);

    // 4. Loop to plot the outer edge
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        // Math applies the cleanly scaled horizontal and vertical dimensions relative to the center
        float x = earBukkaX + (cos(angle) * radiusX);
        float y = earBukkaY + (sin(angle) * radiusY);

        glVertex2f(x, y);
    }
    glEnd();

    // BUKKA ON EARS ENDS HERE //

    // FACE LINES
    glLineWidth(2.0f);

    glBegin(GL_LINES);

    glColor3f(0.001f, 0.001f, 0.001f);

    // TOPI LINES
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent), VALUE_FROM_PERCENT(SR_YPosition, percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.04f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent), VALUE_FROM_PERCENT(SR_YPosition, percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 5), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.15f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 5), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.04f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.15f), percent));

    // RIGHT COLLAR TOP LINE
    // glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.028f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));

    glEnd();

    glLineWidth(1.0f);

    // FACE LINES END HERE //

    // shirt starts here

    // left collar
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.057f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.097f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.028f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));

    glEnd();

    // right collar
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.028f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));

    glEnd();

    // below collar quad
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));

    glEnd();

    // FLAG STARTS HERE //
    // flag bamboo
    glBegin(GL_QUADS);

    glColor3f(0.439f, 0.310f, 0.184f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), percent));

    glEnd();

    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);

    glColor3f(0.278f, 0.282f, 0.267f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), percent));

    glEnd();

    glLineWidth(1.0f);

    // flag
    glBegin(GL_TRIANGLES);
    glColor3f(0.928f, 0.438f, 0.266f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.012f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.012f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.1f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.3f + flagSway), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.1f), percent));
    glEnd();

    // flag border

    glLineWidth(1.0f);

    glLineWidth(1.0f);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.013f), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.013f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.1f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.3f + flagSway), percent), VALUE_FROM_PERCENT((SR_YPosition + 0.1f), percent));
    glEnd();

    glLineWidth(1.0f);

    // FLAG ENDS HERE //

    // left hand vertical part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), percent));

    glEnd();

    // left hand vertical part lines loop
    glBegin(GL_LINE_LOOP);

    // glColor3f(0.001f, 0.001f, 0.001f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), percent));

    glEnd();

    // LINES START

    glLineWidth(2.0f);
    // left hand top line
    glBegin(GL_LINES);

    glColor3f(0.001f, 0.001f, 0.001f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.575f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), percent));

    glColor3f(0.001f, 0.001f, 0.001f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.13f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), percent));

    glColor3f(0.001f, 0.001f, 0.001f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.13f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.07f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), percent));

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.07f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), percent));

    // right hand lines
    glColor3f(0.001f, 0.001f, 0.001f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.575f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));

    // right hand slant lines
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.200f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.712f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.145f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.82f), percent));

    // glVertex2f(SR_XPosition + 0.145f, SR_YPosition - 0.82f);
    // glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);

    // glVertex2f(SR_XPosition + 0.200f, SR_YPosition - 0.708f);
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.80f);

    glColor3f(0.001f, 0.001f, 0.001f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.202f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.715f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.145f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.82f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.202f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.715f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.80f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.80f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.145f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.82f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));

    // shirt ending lines
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));

    // Shirt left side lines
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));

    // shirt right side lines
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));

    // right collar border

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.028f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));

    glColor3f(0.001f, 0.001f, 0.001f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));

    // left collar border
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.028f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.057f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.057f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.097f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.028f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), percent));

    // Pant lines left leg
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.087f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.087f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));

    // Pant lines right leg
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.117f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.117f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));

    glEnd();

    glLineWidth(1.0f);

    // LINES END

    // HANDS STARTS HERE //

    // left hand horizontal part -- here we will add animation
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.07f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.13f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), percent));

    glEnd();

    // left hand horizontal part lines -- here we will add animation
    glBegin(GL_LINE_LOOP);

    glColor3f(0.001f, 0.001f, 0.001f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), percent));

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.07f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.13f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), percent));

    glEnd();

    // LEFT HAND START

    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.141f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.79f), percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.161f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.79f), percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.181f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.75f), percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // White
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.161f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.75f), percent));

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.141f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.79f), percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.23f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.79f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.18f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.085f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));

    // glVertex2f();

    glEnd();

    // LEFT HAND END

    // right hand vertical part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));

    glEnd();

    // // right hand vertical part line lopp
    // glBegin(GL_LINE_LOOP);

    // glColor3f(0.001f, 0.001f, 0.001f);

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
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.202f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.715f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.145f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.82f), percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.80f), percent));

    glEnd();

    // right hand cross part lines loop
    // glBegin(GL_LINE_LOOP);

    // glColor3f(0.001f, 0.001f, 0.001f);

    // // glColor3f(1.0f, 0.0f, 0.0f); // red
    // glVertex2f(SR_XPosition + 0.202f, SR_YPosition - 0.715f);
    // // glColor3f(0.0f, 0.0f, 1.0f); // blue
    // glVertex2f(SR_XPosition + 0.145f, SR_YPosition - 0.82f);

    // // glColor3f(0.0f, 1.0f, 0.0f); // green
    // glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);
    // // glColor3f(0.1f, 0.1f, 0.1f); // black
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.80f);

    // glEnd();

    // HANDS ENDS HERE //

    // PANT STARTS HERE //
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // LEFT PANT
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.087f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));

    glEnd();

    glBegin(GL_QUADS);

    // RIGHT PANT
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.117f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), percent));

    glEnd();

    // PANT ENDS HERE //

    // GANDH ON FOREHEAD STARTS HERE //

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2.25), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.15f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 1.8f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.15f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 1.8f), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.19f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2.25), percent), VALUE_FROM_PERCENT((SR_YPosition - 0.19f), percent));

    glEnd();

    // GANDHA BOTTOM CIRCLES
    glBegin(GL_TRIANGLE_FAN);

    bukkaX = VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent);
    bukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.19f), percent);

    radiusX = SCALE_RADIUS(0.011f, percent);

    radiusY = SCALE_RADIUS(0.015f + 0.011f, percent);

    glVertex2f(bukkaX, bukkaY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = bukkaX + (cos(angle) * radiusX);
        float y = bukkaY + (sin(angle) * radiusY);

        glVertex2f(x, y);
    }
    glEnd();

    // GANDH INSIDE CIRCLE BOTTOM
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1.0f, 0.0f, 0.0f);

    bukkaX = VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent);
    bukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.19f), percent);

    radiusX = SCALE_RADIUS(0.006f, percent);

    radiusY = SCALE_RADIUS(0.011f, percent);

    glVertex2f(bukkaX, bukkaY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = bukkaX + (cos(angle) * radiusX);
        float y = bukkaY + (sin(angle) * radiusY);

        glVertex2f(x, y);
    }
    glEnd();

    // GANDH INSIDE CIRCLE TOP
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.1f, 0.1f, 0.1f);

    bukkaX = VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), percent);
    bukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.167f), percent);

    radiusX = SCALE_RADIUS(0.006f, percent);

    radiusY = SCALE_RADIUS(0.011f, percent);

    glVertex2f(bukkaX, bukkaY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = bukkaX + (cos(angle) * radiusX);
        float y = bukkaY + (sin(angle) * radiusY);

        glVertex2f(x, y);
    }
    glEnd();

    // GANDH ENDS HERE //

    // LEGS STARTS HERE //

    glColor3f(0.917f, 0.816f, 0.726f);

    // LEFT LEG
    glBegin(GL_QUADS);

    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.03f, percent), VALUE_FROM_PERCENT((SR_YPosition - 1.803f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.04f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.803f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.04f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), percent));
    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.03f, percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), percent));

    glEnd();

    // glColor3f(0.917f, 0.816f, 0.726f);

    glBegin(GL_QUADS);

    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.03f, percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.04f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.02f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), percent));
    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.05f, percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), percent));

    glEnd();

    glColor3f(0.917f, 0.816f, 0.726f);

    // RIGHT LEG
    glBegin(GL_QUADS);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.227f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.803f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.16f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.803f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.16f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.227f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), percent));

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.227f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.16f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.18f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.247f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), percent));

    glEnd();

    // glBegin(GL_QUADS);

    // glColor3f(0.1f, 0.1f, 0.1f);

    // // glColor3f(1.0f, 1.0f, 1.0f);
    // glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.17f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.860f), percent));
    // // glColor3f(1.0f, 0.0f, 0.0f);
    // glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.237f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.860f), percent));
    // // glColor3f(0.0f, 1.0f, 0.0f);
    // glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.247f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), percent));
    // // glColor3f(0.0f, 0.0f, 1.0f);
    // glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.18f), percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), percent));

    // glEnd();

    // LEGS ENDS HERE //
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
