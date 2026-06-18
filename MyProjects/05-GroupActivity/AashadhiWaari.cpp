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
void drawFlower(float flowerRadius, float xPosition, float yPosition);

#define VALUE_FROM_PERCENT(complete_value, SR_percent) (complete_value * SR_percent / 100)
#define SCALE_RADIUS(radius, SR_percent) ((radius) * (SR_percent) / 100)

bool bIsFullScreen = false;
float SR_XPosition = 0.0f;
float SR_YPosition = 0.9f;
float SR_Height = 1.5f;
float SR_Width = 0.2f;
float SR_currentSwayOffset = 0.0f;
bool SR_bodyGoingUp = true;
bool SR_flagSwayingLeft = true;

float SR_yForFlower = 0.95f;
float SR_xForFlower = 0.5f;

int SR_percent = 60.0f;

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

    float waveSpeed = 0.0012f;
    float maxWaveHeight = 0.035f;

    if (SR_flagSwayingLeft)
    {
        SR_currentSwayOffset = SR_currentSwayOffset - waveSpeed;
        if (SR_currentSwayOffset <= -maxWaveHeight)
        {
            SR_flagSwayingLeft = false;
        }
    }
    else
    {
        SR_currentSwayOffset = SR_currentSwayOffset + waveSpeed;
        if (SR_currentSwayOffset >= maxWaveHeight)
        {
            SR_flagSwayingLeft = true;
        }
    }

    float bounceRange = 0.015f;
    float upperYLimit = 0.9f + bounceRange;
    float lowerYLimit = 0.9f - bounceRange;

    if (SR_bodyGoingUp)
    {
        SR_YPosition = SR_YPosition + 0.0004f;
        if (SR_YPosition >= upperYLimit)
        {
            SR_bodyGoingUp = false;
        }
    }
    else
    {
        SR_YPosition = SR_YPosition - 0.0004f;
        if (SR_YPosition <= lowerYLimit)
        {
            SR_bodyGoingUp = true;
        }
    }

    dhwajGhetlelaWarkari(SR_XPosition, SR_YPosition, SR_Height, SR_Width, SR_currentSwayOffset);

    SR_yForFlower = SR_yForFlower - 0.0006f;
    if (SR_yForFlower < -1.5f) // Allow deep clipping before reset
    {
        SR_yForFlower = 1.0f; // Wrap back to the sky
    }

    // 2. GENERATE A DENSE, FULL-SCREEN FLOWER SHOWER
    int flowerCount = 0;

    // Loop from the left edge (-0.95f) to the right edge (+0.95f) with a tighter spacing step (0.08f)
    for (float xPos = -0.95f; xPos <= 0.95f; xPos += 0.08f)
    {
        // A. Create a vertical stagger based on the column index so they don't fall in a flat row
        // This creates an organic, staggered rain effect using basic math
        float staggerOffset = (float)(flowerCount % 4) * 0.35f;
        float currentY = SR_yForFlower + staggerOffset;

        // If a staggered flower falls past the bottom, wrap its individual position back to the top
        if (currentY < -1.0f)
        {
            currentY += 2.0f; // Shift it back into the sky viewing box range
        }

        // B. CYCLE DENSE PALETTE COLORS
        switch (flowerCount % 6)
        {
        case 0:
            glColor3f(0.928f, 0.438f, 0.266f);
            break; // Saffron Orange
        case 1:
            glColor3f(1.000f, 0.843f, 0.000f);
            break; // Marigold Yellow
        case 2:
            glColor3f(0.961f, 0.502f, 0.627f);
            break; // Rose Pink
        case 3:
            glColor3f(1.000f, 1.000f, 1.000f);
            break; // Jasmine White
        case 4:
            glColor3f(1.000f, 0.647f, 0.000f);
            break; // Bright Orange
        case 5:
            glColor3f(0.95f, 0.90f, 0.30f);
            break; // Soft Yellow
        }

        // C. RENDER INDIVIDUAL FLOWER
        // Alternates small size variations (0.012f and 0.016f) for added depth
        float sizeVar = (flowerCount % 2 == 0) ? 0.012f : 0.016f;

        drawFlower(sizeVar, xPos, currentY);

        flowerCount++;
    }

    glutSwapBuffers();
    glutPostRedisplay();
}

void dhwajGhetlelaWarkari(float SR_XPosition, float SR_YPosition, float SR_Height, float SR_Width, float flagSway)
{
    // glColor3f(0.933f, 0.937f, 0.945f);

    // glBegin(GL_QUADS);

    // glVertex3f(VALUE_FROM_PERCENT(SR_XPosition, SR_percent), VALUE_FROM_PERCENT(SR_YPosition, SR_percent), 0.0f);
    // glVertex3f(VALUE_FROM_PERCENT(SR_Width + SR_XPosition, SR_percent), VALUE_FROM_PERCENT(SR_YPosition, SR_percent), 0.0f);
    // glVertex3f(VALUE_FROM_PERCENT(SR_Width + SR_XPosition, SR_percent), VALUE_FROM_PERCENT(SR_YPosition - SR_Height, SR_percent), 0.0f);
    // glVertex3f(VALUE_FROM_PERCENT(SR_XPosition, SR_percent), VALUE_FROM_PERCENT(SR_YPosition - SR_Height, SR_percent), 0.0f);

    // // glVertex3f(VALUE_FROM_PERSENT(-0.2f, persent) + xPosition, VALUE_FROM_PERSENT(-0.4f, persent) + YPosition, 0.0f);

    // glEnd();

    // Warkari starts here
    // gandhitopi
    // topi top
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLES);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), VALUE_FROM_PERCENT(SR_YPosition, SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));

    glEnd();

    // topi main quad
    glBegin(GL_QUADS);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.051f)), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + (SR_Width / 5)), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.04f)), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));

    glEnd();

    // neck rectangle
    glBegin(GL_QUADS);

    glColor3f(0.890f, 0.757f, 0.624f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.057f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    // glColor3f(0.890f, 0.757f, 0.624f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.057f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));

    glEnd();

    // face quad
    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.35f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.35f), SR_percent));

    glEnd();

    // hat bottom tip
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 5), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.04f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.15f), SR_percent));

    glEnd();

    // chin semicircle
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.917f, 0.816f, 0.726f);
    // 1. Establish the center anchor point
    float centerX = VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent);
    float centerY = VALUE_FROM_PERCENT((SR_YPosition - 0.35f), SR_percent);
    float radius = SCALE_RADIUS(0.048f, SR_percent);
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

    float bukkaX = VALUE_FROM_PERCENT((SR_XPosition + (SR_Width / 2)), SR_percent);
    float bukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent);

    float radiusX = SCALE_RADIUS(0.015f, SR_percent);

    float radiusY = SCALE_RADIUS(0.015f + 0.011f, SR_percent);

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
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.040f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.040f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.135f), SR_percent));

    glEnd();

    // left ear
    glBegin(GL_QUADS);
    glColor3f(0.917f, 0.816f, 0.726f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.040f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.040f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.32f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.32f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));

    glEnd();

    // --- BUKKA ON EAR (FULLY FIXED & SCALABLE) ---
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.1f, 0.1f); // Charcoal black

    // 1. Calculate positions safely from your global baseline variables
    float earBukkaX = VALUE_FROM_PERCENT((SR_XPosition + 0.045f), SR_percent);
    float earBukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.31f), SR_percent);

    // 2. Scale horizontal radius
    radiusX = SCALE_RADIUS(0.006f, SR_percent);

    // FIXED: Wrap the entire vertical height extension inside your macro
    radiusY = SCALE_RADIUS(0.006f + 0.011f, SR_percent);

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
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.135f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));

    glEnd();

    // right ears
    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.32f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.32f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));

    glEnd();

    // --- BUKKA ON EARS
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.1f, 0.1f); // Charcoal black

    // 1. FIXED: Wrap the center coordinates in your position percentage macro
    earBukkaX = VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.046f)), SR_percent);
    earBukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.31f), SR_percent);

    // 2. FIXED: Scale the horizontal radius
    radiusX = SCALE_RADIUS(0.006f, SR_percent);

    // 3. FIXED: Combine and scale the vertical radius together to prevent stretching
    radiusY = SCALE_RADIUS(0.006f + 0.011f, SR_percent);

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
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), VALUE_FROM_PERCENT(SR_YPosition, SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.04f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), VALUE_FROM_PERCENT(SR_YPosition, SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 5), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.15f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 5), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.04f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.15f), SR_percent));

    // RIGHT COLLAR TOP LINE
    // glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.028f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    glEnd();

    glLineWidth(1.0f);

    // FACE LINES END HERE //

    // shirt starts here

    // left collar
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.057f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.097f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.028f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    glEnd();

    // right collar
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.028f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    glEnd();

    // below collar quad
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    glEnd();

    // FLAG STARTS HERE //
    // flag bamboo
    glBegin(GL_QUADS);

    glColor3f(0.439f, 0.310f, 0.184f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), SR_percent));

    glEnd();

    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);

    glColor3f(0.278f, 0.282f, 0.267f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.0f), SR_percent));

    glEnd();

    glLineWidth(1.0f);

    // flag
    glBegin(GL_TRIANGLES);
    glColor3f(0.928f, 0.438f, 0.266f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.012f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.012f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.1f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.3f + flagSway), SR_percent), VALUE_FROM_PERCENT((SR_YPosition + 0.1f), SR_percent));
    glEnd();

    // flag border

    glLineWidth(1.0f);

    glLineWidth(1.0f);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.013f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.013f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.1f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.3f + flagSway), SR_percent), VALUE_FROM_PERCENT((SR_YPosition + 0.1f), SR_percent));
    glEnd();

    glLineWidth(1.0f);

    // FLAG ENDS HERE //

    // left hand vertical part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));

    glEnd();

    // left hand vertical part lines loop
    glBegin(GL_LINE_LOOP);

    // glColor3f(0.001f, 0.001f, 0.001f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));

    glEnd();

    // LINES START

    glLineWidth(2.0f);
    // left hand top line
    glBegin(GL_LINES);

    glColor3f(0.001f, 0.001f, 0.001f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.575f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));

    glColor3f(0.001f, 0.001f, 0.001f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.13f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));

    glColor3f(0.001f, 0.001f, 0.001f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.13f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.07f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.07f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));

    // right hand lines
    glColor3f(0.001f, 0.001f, 0.001f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.575f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

    // right hand slant lines
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.200f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.712f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.145f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.82f), SR_percent));

    // glVertex2f(SR_XPosition + 0.145f, SR_YPosition - 0.82f);
    // glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);

    // glVertex2f(SR_XPosition + 0.200f, SR_YPosition - 0.708f);
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.80f);

    glColor3f(0.001f, 0.001f, 0.001f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.202f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.715f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.145f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.82f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.202f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.715f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.80f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.80f), SR_percent));

    // RIGHT Hand cross line
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.165f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.82f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

    // shirt ending lines
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    // Shirt left side lines
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    // shirt right side lines
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

    // right collar border

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.028f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    glColor3f(0.001f, 0.001f, 0.001f);
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));

    // left collar border
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.028f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.057f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.057f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.097f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.028f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    // Pant lines left leg
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.087f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.087f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    // Pant lines right leg
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.117f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.117f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glEnd();

    glLineWidth(1.0f);

    // LINES END

    // HANDS STARTS HERE //

    // left hand horizontal part -- here we will add animation
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.07f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.13f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));

    glEnd();

    // left hand horizontal part lines -- here we will add animation
    glBegin(GL_LINE_LOOP);

    glColor3f(0.001f, 0.001f, 0.001f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.07f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.13f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));

    glEnd();

    // LEFT HAND START

    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.141f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.79f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.161f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.79f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.181f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.75f), SR_percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // White
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.161f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.75f), SR_percent));

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.141f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.79f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.23f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.79f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.18f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.085f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

    // glVertex2f();

    glEnd();

    // LEFT HAND END

    // right hand vertical part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

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

    // RIGHT HAND //
    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.212f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.815f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.212f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.695f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.190f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.655f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.190f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.815f), SR_percent));

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.190f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.825f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.190f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.695f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.150f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.635f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.145f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.765f), SR_percent));

    glEnd();

    // right hand cross part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.222f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.715f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.165f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.82f), SR_percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.80f), SR_percent));

    glEnd();

    // HANDS ENDS HERE //

    // PANT STARTS HERE //
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // LEFT PANT
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.087f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glEnd();

    glBegin(GL_QUADS);

    // RIGHT PANT
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.117f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glEnd();

    // PANT ENDS HERE //

    // GANDH ON FOREHEAD STARTS HERE //

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2.25), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.15f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 1.8f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.15f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 1.8f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.19f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2.25), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 0.19f), SR_percent));

    glEnd();

    // GANDHA BOTTOM CIRCLES
    glBegin(GL_TRIANGLE_FAN);

    bukkaX = VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent);
    bukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.19f), SR_percent);

    radiusX = SCALE_RADIUS(0.011f, SR_percent);

    radiusY = SCALE_RADIUS(0.015f + 0.011f, SR_percent);

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

    bukkaX = VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent);
    bukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.19f), SR_percent);

    radiusX = SCALE_RADIUS(0.006f, SR_percent);

    radiusY = SCALE_RADIUS(0.011f, SR_percent);

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

    bukkaX = VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent);
    bukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.167f), SR_percent);

    radiusX = SCALE_RADIUS(0.006f, SR_percent);

    radiusY = SCALE_RADIUS(0.011f, SR_percent);

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

    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.03f, SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.803f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.04f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.803f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.04f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.03f, SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));

    glEnd();

    // glColor3f(0.917f, 0.816f, 0.726f);

    glBegin(GL_QUADS);

    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.03f, SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.04f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.02f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.05f, SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));

    glEnd();

    glColor3f(0.917f, 0.816f, 0.726f);

    // RIGHT LEG
    glBegin(GL_QUADS);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.227f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.803f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.16f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.803f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.16f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.227f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.227f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.16f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.18f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.247f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));

    glEnd();

    // glBegin(GL_QUADS);

    // glColor3f(0.1f, 0.1f, 0.1f);

    // // glColor3f(1.0f, 1.0f, 1.0f);
    // glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.17f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.860f), SR_percent));
    // // glColor3f(1.0f, 0.0f, 0.0f);
    // glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.237f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.860f), SR_percent));
    // // glColor3f(0.0f, 1.0f, 0.0f);
    // glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.247f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));
    // // glColor3f(0.0f, 0.0f, 1.0f);
    // glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.18f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));

    // glEnd();

    // LEGS ENDS HERE //
}

void drawFlower(float radiusSize, float customX, float customY)
{
    glBegin(GL_TRIANGLE_FAN);

    // Dynamic coordinates calculated using your SR_percent macro
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
