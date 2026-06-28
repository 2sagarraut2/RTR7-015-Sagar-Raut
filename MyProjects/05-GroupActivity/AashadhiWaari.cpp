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

// function declarations
// sagar functions
void dhwajGhetlelaWarkari(float SR_XPosition, float SR_YPosition, float SR_Height, float SR_Width, float flagSway);
void drawFlower(float flowerRadius, float xPosition, float yPosition);

// pranali functions
void psh_drawVitthal(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);

// Hemant functions
void hbPalakhi(float hb_x, float hb_y, float hb_h, float hb_w);
void hbZumbar(float offset_x, float offset_y, float radius_x, float radius_y, float r, float g, float b, bool drawLines = false);

// ground function
void drawGroundQuad();

// sagar's macros
#define VALUE_FROM_PERCENT(complete_value, SR_percent) (((complete_value) * (SR_percent)) / 100.0f)
#define SCALE_RADIUS(radius, SR_percent) ((radius) * (SR_percent) / 100)

// Pranalis macros
#define PSH_X(xCordinate) (VALUE_FROM_PERCENT(xCordinate, psh_width_percentage) + psh_x_pos)
#define PSH_Y(yCordinate) (VALUE_FROM_PERCENT(yCordinate, psh_height_percentage) + psh_y_pos)

// Hemant macros
#define percent_vaule(complete_value, hb_percent) (complete_value * hb_percent / 100)
#define redius(redius, hb_percent) ((redius) * (hb_percent) / 100)

bool bIsFullScreen = false;

// Global variables
// Warkari variable declarations - sagar
float SR_XPosition = -1.4f;
float SR_YPosition = 0.290f;
float SR_Height = 1.5f;
float SR_Width = 0.2f;
float SR_currentSwayOffset = 0.0f;
bool SR_bodyGoingUp = true;
bool SR_flagSwayingLeft = true;

// flower variable declarations - sagar
float SR_yForFlower = 0.95f;
float SR_xForFlower = 0.5f;

// sagar percentage
int SR_percent = 60.0f;

// Hemant variable declarations
// Variables declaration
float hb_x = 0.0f;
float hb_y = -0.55f;
float hb_h = 0.1f;
float hb_w = 0.1f;
float hb_percent = 50.0f;
// Colours
// Wood light colour
float woodlR = 0.58f;
float woodlG = 0.27f;
float woodlB = 0.13f;
// Wood dark colour
float wooddR = 0.86f;
float wooddG = 0.32f;
float wooddB = 0.2f;
// Golden colour
float goldR = 0.95f;
float goldG = 0.72f;
float goldB = 0.25f;
// lines colour
float lineR = 0.001f;
float lineG = 0.001f;
float lineB = 0.001f;

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

    // ground func call
    drawGroundQuad();

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

    dhwajGhetlelaWarkari(SR_XPosition, SR_YPosition, SR_Height, SR_Width, SR_currentSwayOffset);

    // Pranalis code

    psh_drawVitthal(0.2f, 0.0f, 60, 95);

    // Pranalis code

    SR_yForFlower -= 0.003f;
    if (SR_yForFlower < -1.5f)
    {
        SR_yForFlower = 1.0f;
    }

    int flowerCount = 0;

    for (float xPos = -0.6f; xPos <= 0.6f; xPos += 0.08f)
    {
        float heightOffset = (float)(flowerCount * 7 % 13) * 0.15f;
        float currentY = SR_yForFlower + heightOffset;

        for (int row = 0; row < 12; row++)
        {
            float individualY = currentY + (row * 0.2f);

            if (individualY < -1.0f)
            {
                individualY = 1.0f + (individualY + 1.0f);
            }

            float sway = cos(individualY * 4.0f + (float)flowerCount) * 0.02f;
            float finalX = xPos + sway;

            switch ((flowerCount + row) % 6)
            {
            case 0:
                glColor3f(0.928f, 0.438f, 0.266f);
                break;
            case 1:
                glColor3f(1.000f, 0.843f, 0.000f);
                break;
            case 2:
                glColor3f(0.961f, 0.502f, 0.627f);
                break;
            case 3:
                glColor3f(1.000f, 1.000f, 1.000f);
                break;
            case 4:
                glColor3f(1.000f, 0.647f, 0.000f);
                break;
            case 5:
                glColor3f(0.950f, 0.900f, 0.300f);
                break;
            }

            float sizeVar = (row % 2 == 0) ? 0.012f : 0.016f;

            drawFlower(sizeVar, finalX, individualY);
        }

        flowerCount++;
    }

    // Hemant code
    hbPalakhi(hb_x, hb_y, hb_h, hb_w);

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

    float centerX = VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent);
    float centerY = VALUE_FROM_PERCENT((SR_YPosition - 0.35f), SR_percent);
    float radius = SCALE_RADIUS(0.048f, SR_percent);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {

        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius);
        float y = centerY + (sin(angle) * radius);

        glVertex2f(x, y);
    }
    glEnd();

    // BUKKA ON CHIN
    // glColor3f(0.1f, 0.1f, 0.1f);
    // glBegin(GL_TRIANGLE_FAN);

    float bukkaX = VALUE_FROM_PERCENT((SR_XPosition + (SR_Width / 2)), SR_percent);
    float bukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent);

    float radiusX = SCALE_RADIUS(0.015f, SR_percent);

    float radiusY = SCALE_RADIUS(0.015f + 0.011f, SR_percent);

    // glVertex2f(bukkaX, bukkaY);

    // for (int i = 0; i <= 360; i++)
    // {
    //     float angle = i * 3.14159f / 180.0f;

    //     float x = bukkaX + (cos(angle) * radiusX);
    //     float y = bukkaY + (sin(angle) * radiusY);

    //     glVertex2f(x, y);
    // }
    // glEnd();

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

    // --- BUKKA ON EAR
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.1f, 0.1f);

    float earBukkaX = VALUE_FROM_PERCENT((SR_XPosition + 0.045f), SR_percent);
    float earBukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.31f), SR_percent);

    radiusX = SCALE_RADIUS(0.006f, SR_percent);

    radiusY = SCALE_RADIUS(0.006f + 0.011f, SR_percent);

    glVertex2f(earBukkaX, earBukkaY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

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
    glColor3f(0.1f, 0.1f, 0.1f);

    earBukkaX = VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.046f)), SR_percent);
    earBukkaY = VALUE_FROM_PERCENT((SR_YPosition - 0.31f), SR_percent);

    radiusX = SCALE_RADIUS(0.006f, SR_percent);

    radiusY = SCALE_RADIUS(0.006f + 0.011f, SR_percent);

    glVertex2f(earBukkaX, earBukkaY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

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

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.03f, SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.803f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.04f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.803f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.04f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.03f, SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));

    glEnd();

    // glColor3f(0.917f, 0.816f, 0.726f);

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(SR_XPosition - 0.03f, SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.04f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT((SR_XPosition + 0.02f), SR_percent), VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
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

// Pranalis code

void psh_drawVitthal(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage)
{

    // Mukut
    glColor3f(1.0f, 0.90f, 0.35f);
    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(0.0f), PSH_Y(0.95f), 0.0f);
    glVertex3f(PSH_X(0.03f), PSH_Y(0.9f), 0.0f);
    glVertex3f(PSH_X(0.02f), PSH_Y(0.88f), 0.0f);
    glVertex3f(PSH_X(-0.02f), PSH_Y(0.88f), 0.0f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(0.9f), 0.0f);

    glEnd();

    glColor3f(0.95f, 0.80f, 0.20f);

    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(0.03f), PSH_Y(0.88f), 0.0f);
    glVertex3f(PSH_X(0.04f), PSH_Y(0.87f), 0.0f);
    glVertex3f(PSH_X(0.03f), PSH_Y(0.86f), 0.0f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(0.86f), 0.0f);
    glVertex3f(PSH_X(-0.04f), PSH_Y(0.87f), 0.0f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(0.88f), 0.0f);

    glEnd();

    glColor3f(0.85f, 0.65f, 0.13f);

    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(0.03f), PSH_Y(0.86f), 0.0f);
    glVertex3f(PSH_X(0.08f), PSH_Y(0.8f), 0.0f);
    glVertex3f(PSH_X(0.08f), PSH_Y(0.65f), 0.0f);
    glVertex3f(PSH_X(-0.08f), PSH_Y(0.65f), 0.0f);
    glVertex3f(PSH_X(-0.08f), PSH_Y(0.8f), 0.0f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(0.86f), 0.0f);

    glEnd();

    glColor3f(0.65f, 0.50f, 0.10f);

    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(0.08f), PSH_Y(0.65f), 0.0f);
    glVertex3f(PSH_X(0.1f), PSH_Y(0.63f), 0.0f);
    glVertex3f(PSH_X(0.08f), PSH_Y(0.6f), 0.0f);
    glVertex3f(PSH_X(-0.08f), PSH_Y(0.6f), 0.0f);
    glVertex3f(PSH_X(-0.1f), PSH_Y(0.63f), 0.0f);
    glVertex3f(PSH_X(-0.08f), PSH_Y(0.65f), 0.0f);

    glEnd();

    // Stomach
    glColor3f(0.44f, 0.50f, 0.57f);

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.2f), PSH_Y(0.4f), 0.0f);
    glVertex3f(PSH_X(0.2f), PSH_Y(0.22f), 0.0f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(0.22f), 0.0f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(0.4f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.2f), PSH_Y(0.22f), 0.0f);
    glVertex3f(PSH_X(0.15f), PSH_Y(0.18f), 0.0f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(0.18f), 0.0f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(0.22f), 0.0f);

    glEnd();

    glColor3f(0.27f, 0.30f, 0.34f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(PSH_X(0.0f), PSH_Y(0.33f));

    for (int i = 0; i <= 180; i++)
    {
        float a = (180.0f + i) * 3.1415926f / 180.0f;

        float x = VALUE_FROM_PERCENT(0.08f * cos(a), psh_width_percentage);
        float y = VALUE_FROM_PERCENT(0.08f * sin(a), psh_height_percentage);

        glVertex2f(PSH_X(0.0f) + x, PSH_Y(0.33f) + y);
    }
    glEnd();

    // Neck

    glColor3f(0.27f, 0.30f, 0.34f);

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.08f), PSH_Y(0.45f), 0.0f);
    glVertex3f(PSH_X(0.08f), PSH_Y(0.33f), 0.0f);
    glVertex3f(PSH_X(-0.08f), PSH_Y(0.33f), 0.0f);
    glVertex3f(PSH_X(-0.08f), PSH_Y(0.45f), 0.0f);

    glEnd();

    // Face
    glColor3f(0.44f, 0.50f, 0.57f);
    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.08f), PSH_Y(0.6f), 0.0f);
    glVertex3f(PSH_X(0.08f), PSH_Y(0.45f), 0.0f);
    glVertex3f(PSH_X(-0.08f), PSH_Y(0.45f), 0.0f);
    glVertex3f(PSH_X(-0.08f), PSH_Y(0.6f), 0.0f);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(PSH_X(0.0f), PSH_Y(0.45f));

    for (int i = 0; i <= 180; i++)
    {
        float a = (180.0f + i) * 3.1415926f / 180.0f;

        float x = VALUE_FROM_PERCENT(0.08f * cos(a), psh_width_percentage);
        float y = VALUE_FROM_PERCENT(0.08f * sin(a), psh_height_percentage);

        glVertex2f(PSH_X(0.0f) + x, PSH_Y(0.45f) + y);
    }

    glEnd();
    // Face End

    // Ears
    glColor3f(0.44f, 0.50f, 0.57f);

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.08f), PSH_Y(0.59f), 0.0f);
    glVertex3f(PSH_X(0.1f), PSH_Y(0.59f), 0.0f);
    glVertex3f(PSH_X(0.1f), PSH_Y(0.45f), 0.0f);
    glVertex3f(PSH_X(0.08f), PSH_Y(0.45f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.08f), PSH_Y(0.59f), 0.0f);
    glVertex3f(PSH_X(-0.1f), PSH_Y(0.59f), 0.0f);
    glVertex3f(PSH_X(-0.1f), PSH_Y(0.45f), 0.0f);
    glVertex3f(PSH_X(-0.08f), PSH_Y(0.45f), 0.0f);

    glEnd();

    glColor3f(0.92f, 0.79f, 0.20f);

    glBegin(GL_TRIANGLES);

    glVertex3f(PSH_X(0.1f), PSH_Y(0.5f), 0.0f);
    glVertex3f(PSH_X(0.25f), PSH_Y(0.4f), 0.0f);
    glVertex3f(PSH_X(0.1f), PSH_Y(0.4f), 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glVertex3f(PSH_X(0.2f), PSH_Y(0.43f), 0.0f);
    glVertex3f(PSH_X(0.25f), PSH_Y(0.46f), 0.0f);
    glVertex3f(PSH_X(0.25f), PSH_Y(0.4f), 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glVertex3f(PSH_X(-0.1f), PSH_Y(0.5f), 0.0f);
    glVertex3f(PSH_X(-0.25f), PSH_Y(0.4f), 0.0f);
    glVertex3f(PSH_X(-0.1f), PSH_Y(0.4f), 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glVertex3f(PSH_X(-0.2f), PSH_Y(0.43f), 0.0f);
    glVertex3f(PSH_X(-0.25f), PSH_Y(0.46f), 0.0f);
    glVertex3f(PSH_X(-0.25f), PSH_Y(0.4f), 0.0f);

    glEnd();
    // End of Ear

    // Dhotar
    glColor3f(0.486f, 0.631f, 0.373f);

    glBegin(GL_POLYGON);

    glColor3f(0.65f, 0.80f, 0.50f);
    glVertex3f(PSH_X(0.15f), PSH_Y(-0.03f), 0.0f);

    glColor3f(0.60f, 0.75f, 0.45f);
    glVertex3f(PSH_X(0.2f), PSH_Y(-0.07f), 0.0f);

    glColor3f(0.30f, 0.45f, 0.22f);
    glVertex3f(PSH_X(0.2f), PSH_Y(-0.2f), 0.0f);

    glColor3f(0.25f, 0.38f, 0.18f);
    glVertex3f(PSH_X(0.18f), PSH_Y(-0.22f), 0.0f);

    glColor3f(0.30f, 0.45f, 0.22f);
    glVertex3f(PSH_X(0.13f), PSH_Y(-0.22f), 0.0f);

    glColor3f(0.50f, 0.68f, 0.38f);
    glVertex3f(PSH_X(0.03f), PSH_Y(-0.15f), 0.0f);

    glColor3f(0.60f, 0.75f, 0.45f);
    glVertex3f(PSH_X(0.03f), PSH_Y(-0.1f), 0.0f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.65f, 0.80f, 0.50f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(-0.03f), 0.0f);

    glColor3f(0.60f, 0.75f, 0.45f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(-0.07f), 0.0f);

    glColor3f(0.30f, 0.45f, 0.22f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(-0.2f), 0.0f);

    glColor3f(0.25f, 0.38f, 0.18f);
    glVertex3f(PSH_X(-0.18f), PSH_Y(-0.22f), 0.0f);

    glColor3f(0.30f, 0.45f, 0.22f);
    glVertex3f(PSH_X(-0.13f), PSH_Y(-0.22f), 0.0f);

    glColor3f(0.50f, 0.68f, 0.38f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(-0.15f), 0.0f);

    glColor3f(0.60f, 0.75f, 0.45f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(-0.1f), 0.0f);

    glEnd();

    // Stomach last part
    glColor3f(0.44f, 0.50f, 0.57f);

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.15f), PSH_Y(0.18f), 0.0f);
    glVertex3f(PSH_X(0.15f), PSH_Y(-0.05f), 0.0f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(-0.05f), 0.0f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(0.18f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.15f), PSH_Y(-0.05f), 0.0f);
    glVertex3f(PSH_X(0.1f), PSH_Y(-0.1f), 0.0f);
    glVertex3f(PSH_X(-0.1f), PSH_Y(-0.1f), 0.0f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(-0.05f), 0.0f);

    glEnd();
    // End of Stomach

    // broach
    glColor3f(0.92f, 0.79f, 0.20f);
    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(0.03f), PSH_Y(-0.08f), 0.0f);
    glVertex3f(PSH_X(0.05f), PSH_Y(-0.1f), 0.0f);
    glVertex3f(PSH_X(0.05f), PSH_Y(-0.13f), 0.0f);
    glVertex3f(PSH_X(0.03f), PSH_Y(-0.15f), 0.0f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(-0.15f), 0.0f);
    glVertex3f(PSH_X(-0.05f), PSH_Y(-0.13f), 0.0f);
    glVertex3f(PSH_X(-0.05f), PSH_Y(-0.1f), 0.0f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(-0.08f), 0.0f);

    glEnd();
    // End of Broach

    // Vit
    glColor3f(0.24f, 0.13f, 0.02f);
    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.15f), PSH_Y(-0.75f), 0.0f);
    glVertex3f(PSH_X(0.15f), PSH_Y(-0.85f), 0.0f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(-0.85f), 0.0f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(-0.75f), 0.0f);

    glEnd();
    // End of Vit

    // Dhotar

    glBegin(GL_POLYGON);

    glColor3f(0.98f, 0.90f, 0.40f);
    glVertex3f(PSH_X(0.03f), PSH_Y(-0.15f), 0.0f);
    glColor3f(0.95f, 0.85f, 0.30f);
    glVertex3f(PSH_X(0.13f), PSH_Y(-0.22f), 0.0f);

    glColor3f(0.85f, 0.70f, 0.15f);
    glVertex3f(PSH_X(0.19f), PSH_Y(-0.21f), 0.0f);
    glVertex3f(PSH_X(0.19f), PSH_Y(-0.5f), 0.0f);

    glColor3f(0.55f, 0.45f, 0.08f);
    glVertex3f(PSH_X(0.15f), PSH_Y(-0.55f), 0.0f);

    glColor3f(0.98f, 0.90f, 0.40f);
    glVertex3f(PSH_X(0.15f), PSH_Y(-0.7f), 0.0f);
    glColor3f(0.85f, 0.70f, 0.15f);
    glVertex3f(PSH_X(0.1f), PSH_Y(-0.75f), 0.0f);
    glColor3f(0.45f, 0.35f, 0.06f);
    glVertex3f(PSH_X(0.1f), PSH_Y(-0.8f), 0.0f);
    glColor3f(0.95f, 0.85f, 0.30f);
    glVertex3f(PSH_X(0.05f), PSH_Y(-0.8f), 0.0f);
    glVertex3f(PSH_X(0.05f), PSH_Y(-0.75f), 0.0f);
    glColor3f(0.95f, 0.85f, 0.30f);
    glVertex3f(PSH_X(0.0f), PSH_Y(-0.7f), 0.0f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.98f, 0.90f, 0.40f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(-0.15f), 0.0f);
    glColor3f(0.95f, 0.85f, 0.30f);
    glVertex3f(PSH_X(-0.13f), PSH_Y(-0.22f), 0.0f);

    glColor3f(0.85f, 0.70f, 0.15f);
    glVertex3f(PSH_X(-0.19f), PSH_Y(-0.21f), 0.0f);
    glVertex3f(PSH_X(-0.19f), PSH_Y(-0.5f), 0.0f);

    glColor3f(0.55f, 0.45f, 0.08f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(-0.55f), 0.0f);

    glColor3f(0.98f, 0.90f, 0.40f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(-0.7f), 0.0f);
    glColor3f(0.85f, 0.70f, 0.15f);
    glVertex3f(PSH_X(-0.1f), PSH_Y(-0.75f), 0.0f);
    glColor3f(0.45f, 0.35f, 0.06f);
    glVertex3f(PSH_X(-0.1f), PSH_Y(-0.8f), 0.0f);
    glColor3f(0.95f, 0.85f, 0.30f);
    glVertex3f(PSH_X(-0.05f), PSH_Y(-0.8f), 0.0f);
    glVertex3f(PSH_X(-0.05f), PSH_Y(-0.75f), 0.0f);
    glColor3f(0.95f, 0.85f, 0.30f);
    glVertex3f(PSH_X(-0.0f), PSH_Y(-0.7f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.70f, 0.85f, 0.50f);
    glVertex3f(PSH_X(0.03f), PSH_Y(-0.15f), 0.0f);

    glColor3f(0.45f, 0.60f, 0.30f);
    glVertex3f(PSH_X(0.03f), PSH_Y(-0.6f), 0.0f);

    glColor3f(0.25f, 0.35f, 0.15f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(-0.6f), 0.0f);

    glColor3f(0.55f, 0.70f, 0.35f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(-0.15f), 0.0f);

    glEnd();

    // End of Dhotar

    // Shela
    glBegin(GL_POLYGON);

    glColor3f(0.85f, 0.25f, 0.20f);
    glVertex3f(PSH_X(0.15f), PSH_Y(0.05f), 0.0f);

    glColor3f(0.85f, 0.25f, 0.20f);
    glVertex3f(PSH_X(0.25f), PSH_Y(0.05f), 0.0f);

    glColor3f(0.75f, 0.20f, 0.16f);
    glVertex3f(PSH_X(0.4f), PSH_Y(-0.1f), 0.0f);

    glColor3f(0.45f, 0.10f, 0.08f);
    glVertex3f(PSH_X(0.4f), PSH_Y(-0.35f), 0.0f);

    glColor3f(0.35f, 0.08f, 0.06f);
    glVertex3f(PSH_X(0.35f), PSH_Y(-0.4f), 0.0f);

    glColor3f(0.30f, 0.06f, 0.05f);
    glVertex3f(PSH_X(0.35f), PSH_Y(-0.55f), 0.0f);

    glColor3f(0.45f, 0.10f, 0.08f);
    glVertex3f(PSH_X(0.24f), PSH_Y(-0.42f), 0.0f);

    glColor3f(0.55f, 0.14f, 0.10f);
    glVertex3f(PSH_X(0.24f), PSH_Y(-0.35f), 0.0f);

    glColor3f(0.65f, 0.18f, 0.12f);
    glVertex3f(PSH_X(0.2f), PSH_Y(-0.4f), 0.0f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.85f, 0.25f, 0.20f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(0.05f), 0.0f);

    glColor3f(0.85f, 0.25f, 0.20f);
    glVertex3f(PSH_X(-0.25f), PSH_Y(0.05f), 0.0f);

    glColor3f(0.75f, 0.20f, 0.16f);
    glVertex3f(PSH_X(-0.4f), PSH_Y(-0.1f), 0.0f);

    glColor3f(0.45f, 0.10f, 0.08f);
    glVertex3f(PSH_X(-0.4f), PSH_Y(-0.35f), 0.0f);

    glColor3f(0.35f, 0.08f, 0.06f);
    glVertex3f(PSH_X(-0.35f), PSH_Y(-0.4f), 0.0f);

    glColor3f(0.30f, 0.06f, 0.05f);
    glVertex3f(PSH_X(-0.35f), PSH_Y(-0.55f), 0.0f);

    glColor3f(0.45f, 0.10f, 0.08f);
    glVertex3f(PSH_X(-0.24f), PSH_Y(-0.42f), 0.0f);

    glColor3f(0.55f, 0.14f, 0.10f);
    glVertex3f(PSH_X(-0.24f), PSH_Y(-0.35f), 0.0f);

    glColor3f(0.65f, 0.18f, 0.12f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(-0.4f), 0.0f);

    glEnd();
    // End of Shela

    // Right Hand
    glColor3f(0.44f, 0.50f, 0.57f);
    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.2f), PSH_Y(0.4f), 0.0f);
    glVertex3f(PSH_X(0.43f), PSH_Y(0.25f), 0.0f);
    glVertex3f(PSH_X(0.32f), PSH_Y(0.21f), 0.0f);
    glVertex3f(PSH_X(0.2f), PSH_Y(0.28f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.43f), PSH_Y(0.25f), 0.0f);
    glVertex3f(PSH_X(0.32f), PSH_Y(-0.02f), 0.0f);
    glVertex3f(PSH_X(0.25f), PSH_Y(0.05f), 0.0f);
    glVertex3f(PSH_X(0.32f), PSH_Y(0.21f), 0.0f);

    glEnd();
    // End of Right Hand

    // Left Hands
    glColor3f(0.44f, 0.50f, 0.57f);
    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.2f), PSH_Y(0.4f), 0.0f);
    glVertex3f(PSH_X(-0.43f), PSH_Y(0.25f), 0.0f);
    glVertex3f(PSH_X(-0.32f), PSH_Y(0.21f), 0.0f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(0.28f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.43f), PSH_Y(0.25f), 0.0f);
    glVertex3f(PSH_X(-0.32f), PSH_Y(-0.02f), 0.0f);
    glVertex3f(PSH_X(-0.25f), PSH_Y(0.05f), 0.0f);
    glVertex3f(PSH_X(-0.32f), PSH_Y(0.21f), 0.0f);

    glEnd();
    // End of Left Hand

    // Hand Jwellery
    glColor3f(0.95f, 0.80f, 0.20f);
    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(0.29f), PSH_Y(0.34f), 0.0f);
    glVertex3f(PSH_X(0.28f), PSH_Y(0.31f), 0.0f);
    glVertex3f(PSH_X(0.29f), PSH_Y(0.28f), 0.0f);
    glVertex3f(PSH_X(0.33f), PSH_Y(0.28f), 0.0f);
    glVertex3f(PSH_X(0.35f), PSH_Y(0.3f), 0.0f);

    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);

    glVertex2f(PSH_X(0.295f), PSH_Y(0.28f));
    glVertex2f(PSH_X(0.27f), PSH_Y(0.24f));

    glEnd();

    glColor3f(0.95f, 0.80f, 0.20f);
    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(-0.29f), PSH_Y(0.34f), 0.0f);
    glVertex3f(PSH_X(-0.28f), PSH_Y(0.31f), 0.0f);
    glVertex3f(PSH_X(-0.29f), PSH_Y(0.28f), 0.0f);
    glVertex3f(PSH_X(-0.33f), PSH_Y(0.28f), 0.0f);
    glVertex3f(PSH_X(-0.35f), PSH_Y(0.3f), 0.0f);

    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);

    glVertex2f(PSH_X(-0.295f), PSH_Y(0.28f));
    glVertex2f(PSH_X(-0.27f), PSH_Y(0.24f));

    glEnd();

    // Neckless
    glColor3f(0.95f, 0.80f, 0.20f);
    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(0.02f), PSH_Y(0.25f), 0.0f);
    glVertex3f(PSH_X(0.03f), PSH_Y(0.23f), 0.0f);
    glVertex3f(PSH_X(0.03f), PSH_Y(0.22f), 0.0f);
    glVertex3f(PSH_X(0.02f), PSH_Y(0.20f), 0.0f);
    glVertex3f(PSH_X(-0.02f), PSH_Y(0.20f), 0.0f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(0.22f), 0.0f);
    glVertex3f(PSH_X(-0.03f), PSH_Y(0.23f), 0.0f);
    glVertex3f(PSH_X(-0.02f), PSH_Y(0.25f), 0.0f);

    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);

    glVertex2f(PSH_X(0.1f), PSH_Y(0.4f));
    glVertex2f(PSH_X(0.1f), PSH_Y(0.32f));

    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);

    glVertex2f(PSH_X(0.1f), PSH_Y(0.32f));
    glVertex2f(PSH_X(0.03f), PSH_Y(0.215f));

    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(PSH_X(-0.1f), PSH_Y(0.4f));
    glVertex2f(PSH_X(-0.1f), PSH_Y(0.32f));
    glEnd();

    glBegin(GL_LINES);

    glVertex2f(PSH_X(-0.1f), PSH_Y(0.32f));
    glVertex2f(PSH_X(-0.03f), PSH_Y(0.215f));

    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_LINES);

    glVertex2f(PSH_X(0.1f), PSH_Y(0.32f));
    glVertex2f(PSH_X(0.1f), PSH_Y(0.18f));

    glEnd();

    glBegin(GL_LINES);

    glVertex2f(PSH_X(0.1f), PSH_Y(0.18f));
    glVertex2f(PSH_X(0.0f), PSH_Y(0.11f));

    glEnd();

    glBegin(GL_LINES);

    glVertex2f(PSH_X(-0.1f), PSH_Y(0.32f));
    glVertex2f(PSH_X(-0.1f), PSH_Y(0.18f));

    glEnd();

    glBegin(GL_LINES);

    glVertex2f(PSH_X(-0.1f), PSH_Y(0.18f));
    glVertex2f(PSH_X(-0.0f), PSH_Y(0.11f));

    glEnd();

    glEnable(GL_POINT_SMOOTH);
    glPointSize(8.0f);
    glColor3f(0.85f, 0.25f, 0.20f);
    glBegin(GL_POINTS);

    glVertex2f(PSH_X(0.0f), PSH_Y(0.225f));
    glEnd();

    glDisable(GL_POINT_SMOOTH);

    // Tila
    glColor3f(0.95f, 0.80f, 0.20f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(PSH_X(0.0f), PSH_Y(0.50f));

    for (int i = 0; i <= 360; i++)
    {
        float a = (360.0f + i) * 3.1415926f / 180.0f;

        float x = VALUE_FROM_PERCENT(0.03f * cos(a), psh_width_percentage);
        float y = VALUE_FROM_PERCENT(0.035f * sin(a), psh_height_percentage);

        glVertex2f(PSH_X(0.0f) + x, PSH_Y(0.56f) + y);
    }
    glEnd();

    glEnable(GL_POINT_SMOOTH);

    glPointSize(6.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    glVertex2f(PSH_X(0.0f), PSH_Y(0.56f));
    glEnd();

    glDisable(GL_POINT_SMOOTH);
}

// Pranalis code

// Hemants code

void hbPalakhi(float hb_x, float hb_y, float hb_h, float hb_w)
{

    // Palakhi chauthara code

    glColor3f(0.63f, 0.63f, 0.58f);

    glBegin(GL_QUADS);
    // glColor3f(wooddR, wooddG, wooddB);

    glVertex2f(-0.2f, -0.5f);
    glVertex2f(0.2f, -0.5f);

    glColor3f(0.29f, 0.32f, 0.33f);
    glVertex2f(0.2f, -1.0f);
    glVertex2f(-0.2f, -1.0f);

    glEnd();

    // Palakhi chauthara code

    // Zumbar main 1
    // Zumbar main 1
    hbZumbar(0.0f, 0.3f, 0.06f, 0.06f, goldR, goldG, goldB, true);

    // Zumbar main 2
    hbZumbar(-0.8f, -0.1f, 0.06f, 0.06f, goldR, goldG, goldB, true);

    // Zumbar main 3
    hbZumbar(0.8f, -0.1f, 0.06f, 0.06f, goldR, goldG, goldB, true);

    // hbZumbar(0.3f, 0.695f, goldR, goldG, goldB, 50.0f);
    // hbZumbar(0.52f, 0.43f, goldR, goldG, goldB, 50.0f);
    // hbZumbar(0.7f, 0.21f, goldR, goldG, goldB, 50.0f);

    // hbZumbar(-0.3f, 0.695f, goldR, goldG, goldB, 50.0f);
    // hbZumbar(-0.52f, 0.43f, goldR, goldG, goldB, 50.0f);
    // hbZumbar(-0.7f, 0.21f, goldR, goldG, goldB, 50.0f);

    // danda 1
    glBegin(GL_QUADS);
    glColor3f(wooddR, wooddG, wooddB);
    glVertex2f(percent_vaule((hb_x - 0.9f), hb_percent), percent_vaule((hb_y), hb_percent));
    glColor3f(woodlR, woodlG, woodlB);
    glVertex2f(percent_vaule((hb_x - 0.9f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));
    glColor3f(woodlR, woodlG, woodlB);
    glVertex2f(percent_vaule((hb_x - 0.4f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));
    glColor3f(wooddR, wooddG, wooddB);
    glVertex2f(percent_vaule((hb_x - 0.4f), hb_percent), percent_vaule((hb_y), hb_percent));
    glEnd();

    // Lines
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(lineR, lineG, lineB);
    // Danda 1 design lines
    glVertex2f(percent_vaule((hb_x - 0.9f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.85f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.85f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.8f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.8f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.75f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.75f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.7f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.7f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.65f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.65f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.6f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.6f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.55f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.55f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.5f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.5f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.45f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.45f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.4f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    // Danda 1 Border lines
    glVertex2f(percent_vaule((hb_x - 0.9f), hb_percent), percent_vaule((hb_y), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.9f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.4f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.4f), hb_percent), percent_vaule((hb_y), hb_percent));
    glEnd();

    // danda 2
    glBegin(GL_QUADS);
    glColor3f(woodlR, woodlG, woodlB);
    glVertex2f(percent_vaule((hb_x - 0.5f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));
    glColor3f(woodlR, woodlG, woodlB);
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y + 0.5f), hb_percent));
    glColor3f(wooddR, wooddG, wooddB);
    glVertex2f(percent_vaule((hb_x - 0.15f), hb_percent), percent_vaule((hb_y + 0.4f), hb_percent));
    glColor3f(wooddR, wooddG, wooddB);
    glVertex2f(percent_vaule((hb_x - 0.4f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));
    glEnd();

    // danda 3
    glBegin(GL_QUADS);
    glColor3f(woodlR, woodlG, woodlB);
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y + 0.5f), hb_percent));
    glColor3f(woodlR, woodlG, woodlB);
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y + 0.5f), hb_percent));
    glColor3f(wooddR, wooddG, wooddB);
    glVertex2f(percent_vaule((hb_x + 0.15f), hb_percent), percent_vaule((hb_y + 0.4f), hb_percent));
    glColor3f(wooddR, wooddG, wooddB);
    glVertex2f(percent_vaule((hb_x - 0.15f), hb_percent), percent_vaule((hb_y + 0.4f), hb_percent));
    glEnd();

    // danda 4
    glBegin(GL_QUADS);
    glColor3f(woodlR, woodlG, woodlB);
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y + 0.5f), hb_percent));
    glColor3f(woodlR, woodlG, woodlB);
    glVertex2f(percent_vaule((hb_x + 0.5f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));
    glColor3f(wooddR, wooddG, wooddB);
    glVertex2f(percent_vaule((hb_x + 0.4f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));
    glColor3f(wooddR, wooddG, wooddB);
    glVertex2f(percent_vaule((hb_x + 0.15f), hb_percent), percent_vaule((hb_y + 0.4f), hb_percent));
    glEnd();

    // danda 5
    glBegin(GL_QUADS);
    glColor3f(wooddR, wooddG, wooddB);
    glVertex2f(percent_vaule((hb_x + 0.4f), hb_percent), percent_vaule((hb_y), hb_percent));
    glColor3f(woodlR, woodlG, woodlB);
    glVertex2f(percent_vaule((hb_x + 0.4f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));
    glColor3f(woodlR, woodlG, woodlB);
    glVertex2f(percent_vaule((hb_x + 0.9f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));
    glColor3f(wooddR, wooddG, wooddB);
    glVertex2f(percent_vaule((hb_x + 0.9f), hb_percent), percent_vaule((hb_y), hb_percent));
    glEnd();

    // Lines
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(lineR, lineG, lineB);
    // danda 5 design lines
    glVertex2f(percent_vaule((hb_x + 0.4f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.45f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.45f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.5f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.5f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.55f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.55f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.6f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.6f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.65f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.65f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.7f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.7f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.75f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.75f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.8f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.8f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.85f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.85f), hb_percent), percent_vaule((hb_y + 0.1f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.9f), hb_percent), percent_vaule((hb_y + 0.0f), hb_percent));

    // Danda 5 Border lines
    glVertex2f(percent_vaule((hb_x + 0.4f), hb_percent), percent_vaule((hb_y), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.4f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.9f), hb_percent), percent_vaule((hb_y + hb_h), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.9f), hb_percent), percent_vaule((hb_y), hb_percent));
    glEnd();

    // kalash 1 base
    glColor3f(goldR, goldG, goldB);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.05f), hb_percent), percent_vaule((hb_y + 0.55f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.05f), hb_percent), percent_vaule((hb_y + 0.55f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.07f), hb_percent), percent_vaule((hb_y + 0.5f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.07f), hb_percent), percent_vaule((hb_y + 0.5f), hb_percent));
    glEnd();

    // kalash 1 top
    glColor3f(goldR, goldG, goldB);
    glBegin(GL_TRIANGLES);
    glVertex2f(percent_vaule((hb_x - 0.03f), hb_percent), percent_vaule((hb_y + 0.55f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.00f), hb_percent), percent_vaule((hb_y + 0.62f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.03f), hb_percent), percent_vaule((hb_y + 0.55f), hb_percent));
    glEnd();

    // Lines
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3f(lineR, lineG, lineB);
    // kalash 1 border lines
    glVertex2f(percent_vaule((hb_x - 0.05f), hb_percent), percent_vaule((hb_y + 0.55f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.05f), hb_percent), percent_vaule((hb_y + 0.55f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.07f), hb_percent), percent_vaule((hb_y + 0.5f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.07f), hb_percent), percent_vaule((hb_y + 0.5f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.07f), hb_percent), percent_vaule((hb_y + 0.5f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.05f), hb_percent), percent_vaule((hb_y + 0.55f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.05f), hb_percent), percent_vaule((hb_y + 0.55f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.07f), hb_percent), percent_vaule((hb_y + 0.5f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.03f), hb_percent), percent_vaule((hb_y + 0.55f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.00f), hb_percent), percent_vaule((hb_y + 0.62f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.00f), hb_percent), percent_vaule((hb_y + 0.62f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.03f), hb_percent), percent_vaule((hb_y + 0.55f), hb_percent));
    glEnd();

    // chowki mount left
    glColor3f(0.37, 0.25, 0.22);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.45f), hb_percent), percent_vaule((hb_y), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.4f), hb_percent), percent_vaule((hb_y), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.4f), hb_percent), percent_vaule((hb_y - hb_h / 2), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.45f), hb_percent), percent_vaule((hb_y - hb_h / 2), hb_percent));
    glEnd();

    // chowki mount right
    glColor3f(0.37, 0.25, 0.22);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x + 0.4f), hb_percent), percent_vaule((hb_y), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.45f), hb_percent), percent_vaule((hb_y), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.45f), hb_percent), percent_vaule((hb_y - hb_h / 2), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.4f), hb_percent), percent_vaule((hb_y - hb_h / 2), hb_percent));
    glEnd();

    // chowki 1
    glColor3f(0.30, 0.15, 0.05);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.45f), hb_percent), percent_vaule((hb_y - 0.05f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.25f), hb_percent), percent_vaule((hb_y - 0.05f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.1f), hb_percent), percent_vaule((hb_y - 0.2f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.3f), hb_percent));
    glEnd();

    // chowki 2
    glColor3f(0.30, 0.15, 0.05);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.1f), hb_percent), percent_vaule((hb_y - 0.2f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.1f), hb_percent), percent_vaule((hb_y - 0.2f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.3f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.3f), hb_percent));
    glEnd();

    // chowki 3
    glColor3f(0.30, 0.15, 0.05);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x + 0.25f), hb_percent), percent_vaule((hb_y - 0.05f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.45f), hb_percent), percent_vaule((hb_y - 0.05f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.3f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.1f), hb_percent), percent_vaule((hb_y - 0.2f), hb_percent));
    glEnd();

    // chowki bottom 1
    glColor3f(woodlR, woodlG, woodlB);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.3f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.3f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.33f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.33f), hb_percent));
    glEnd();

    // chowki bottom 2
    glColor3f(goldR, goldG, goldB);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.18f), hb_percent), percent_vaule((hb_y - 0.33f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.18f), hb_percent), percent_vaule((hb_y - 0.33f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.18f), hb_percent), percent_vaule((hb_y - 0.36f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.18f), hb_percent), percent_vaule((hb_y - 0.36f), hb_percent));
    glEnd();

    // chowki bottom 3
    glColor3f(woodlR, woodlG, woodlB);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.36f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.36f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.39f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.39f), hb_percent));
    glEnd();

    // chowki leg left
    glColor3f(woodlR, woodlG, woodlB);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.39f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.15f), hb_percent), percent_vaule((hb_y - 0.39f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.15f), hb_percent), percent_vaule((hb_y - 0.45f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.45f), hb_percent));
    glEnd();

    // chowki leg right
    glColor3f(woodlR, woodlG, woodlB);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x + 0.15f), hb_percent), percent_vaule((hb_y - 0.39f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.39f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.45f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.15f), hb_percent), percent_vaule((hb_y - 0.45f), hb_percent));
    glEnd();

    // paduka 1
    glColor3f(0.94, 0.27, 0.22);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.1f), hb_percent), percent_vaule((hb_y - 0.17f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.1f), hb_percent), percent_vaule((hb_y - 0.17f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.1f), hb_percent), percent_vaule((hb_y - 0.2f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.1f), hb_percent), percent_vaule((hb_y - 0.2f), hb_percent));
    glEnd();

    // paduka 2
    glColor3f(0.75f, 0.75f, 0.75f);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.07f), hb_percent), percent_vaule((hb_y - 0.14f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.07f), hb_percent), percent_vaule((hb_y - 0.14f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.07f), hb_percent), percent_vaule((hb_y - 0.17f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.07f), hb_percent), percent_vaule((hb_y - 0.17f), hb_percent));
    glEnd();

    // paduka 3
    glColor3f(0.60f, 0.61f, 0.61f);
    glBegin(GL_QUADS);
    glVertex2f(percent_vaule((hb_x - 0.05f), hb_percent), percent_vaule((hb_y - 0.12f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.03f), hb_percent), percent_vaule((hb_y - 0.12f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.03f), hb_percent), percent_vaule((hb_y - 0.14f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.05f), hb_percent), percent_vaule((hb_y - 0.14f), hb_percent));
    glEnd();

    // Lines
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(lineR, lineG, lineB);

    // chowki bottom lines
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.3f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.3f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.33f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.33f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.36f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.36f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.39f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.39f), hb_percent));

    glVertex2f(percent_vaule((hb_x - 0.15f), hb_percent), percent_vaule((hb_y - 0.45f), hb_percent));
    glVertex2f(percent_vaule((hb_x - 0.2f), hb_percent), percent_vaule((hb_y - 0.45f), hb_percent));

    glVertex2f(percent_vaule((hb_x + 0.2f), hb_percent), percent_vaule((hb_y - 0.45f), hb_percent));
    glVertex2f(percent_vaule((hb_x + 0.15f), hb_percent), percent_vaule((hb_y - 0.45f), hb_percent));

    glEnd();
}

void hbZumbar(float offset_x, float offset_y, float radius_x, float radius_y, float r, float g, float b, bool drawLines)
{
    float x_center = percent_vaule((hb_x + offset_x), hb_percent);
    float y_center = percent_vaule((hb_y + offset_y), hb_percent);

    float rad_x = redius(radius_x, hb_percent);
    float rad_y = redius(radius_y, hb_percent);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(r, g, b);

    glVertex2f(x_center, y_center);
    for (int i = 0; i <= 180; i++)
    {
        float angle = i * 3.14159f / 180.0f;
        float x = x_center + (cos(angle) * rad_x);
        float y = y_center + (sin(angle) * rad_y);
        glVertex2f(x, y);
    }
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    for (int i = 0; i <= 180; i++)
    {
        float angle = i * 3.14159f / 180.0f;
        float x = x_center + (cos(angle) * rad_x);
        float y = y_center + (sin(angle) * rad_y);
        glVertex2f(x, y);
    }
    glEnd();

    if (drawLines)
    {
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        glColor3f(lineR, lineG, lineB);

        // Center line
        glVertex2f(percent_vaule((hb_x + offset_x), hb_percent), percent_vaule((hb_y + offset_y + 0.1f), hb_percent));
        glVertex2f(percent_vaule((hb_x + offset_x), hb_percent), percent_vaule((hb_y + offset_y + 0.06f), hb_percent));

        // lines
        float line_offsets[] = {0.06f, 0.04f, 0.02f, 0.00f, -0.02f, -0.04f, -0.06f};
        for (int i = 0; i < 7; i++)
        {
            float line_x = percent_vaule((hb_x + offset_x + line_offsets[i]), hb_percent);
            float line_y_top = percent_vaule((hb_y + offset_y), hb_percent);
            float line_y_bottom = percent_vaule((hb_y + offset_y - 0.05f), hb_percent);
            glVertex2f(line_x, line_y_top);
            glVertex2f(line_x, line_y_bottom);
        }

        glEnd();
    }
}

// Hamants code

// Ground quad

void drawGroundQuad()
{

    glColor3f(0.991157f, 0.466667f, 0.329412f);

    glBegin(GL_QUADS);

    glVertex2f(1.0f, -0.95f);
    glVertex2f(-1.0f, -0.95f);

    glColor3f(0.498039, 0.333333, 0.278431);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);

    glEnd();
}

// ground quad

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
