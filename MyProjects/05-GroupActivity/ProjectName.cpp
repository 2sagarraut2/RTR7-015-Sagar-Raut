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

#define SR_VALUE_FROM_PERCENT(complete_value, SR_percent) (((complete_value) * (SR_percent)) / 100.0f)
#define SCALE_RADIUS(radius, SR_percent) ((radius) * (SR_percent) / 100)
#define VALUE_FROM_PERCENT(complete_value, percent) ((complete_value * percent) / 100)
#define PSH_X(xCordinate) (VALUE_FROM_PERCENT(xCordinate, psh_width_percentage) + psh_x_pos)
#define PSH_Y(yCordinate) (VALUE_FROM_PERCENT(yCordinate, psh_height_percentage) + psh_y_pos)

// function declaration
void SR_mukut(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);
void projectName(float SR_xPosition, float SR_yPosition, float SR_width, float SR_height, float SR_thickness, float SR_percent);
void drawTree(float SR_tree_xPosition, float SR_tree_yPosition, float SR_tree_width, float SR_tree_height, float SR_tree_thickness, float SR_tree_percent);

void letterA(float x_pos, float y_pos);
void letterS(float x_pos, float y_pos);
void letterT(float x_pos, float y_pos);
void letterR(float x_pos, float y_pos);
void LetterM(float x_pos, float y_pos);
void letterE(float x_pos, float y_pos);
void letterD(float x_pos, float y_pos);
void letterI(float x_pos, float y_pos);
void letterC(float x_pos, float y_pos);
void letterO(float x_pos, float y_pos);
void letterM(float x_pos, float y_pos);
void letterP(float x_pos, float y_pos);
void letterV(float x_pos, float y_pos);
void letterJ(float x_pos, float y_pos);
void letterY(float x_pos, float y_pos);
void letterG(float x_pos, float y_pos);
void letterK(float x_pos, float y_pos);
void letterL(float x_pos, float y_pos);
void letterH(float x_pos, float y_pos);
void letterN(float x_pos, float y_pos);
void letterU(float x_pos, float y_pos);

// global variables
bool bIsFullScreen = false;
float SR_xPosition = -0.6f;
float SR_yPosition = 0.151f;
float SR_width = 1.2f;
float SR_height = 1.0f;
float SR_thickness = 0.11f;
float SR_percent = 50.0f;
float percent = 100.0f;

float SR_tree_xPosition = -0.4f;
float SR_tree_yPosition = 0.0f;
float SR_tree_width = 0.8f;
float SR_tree_height = 1.2f;
float SR_tree_thickness = 0.11f;
float SR_tree_percent = 100.0f;

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

    // function call
    // projectName(SR_xPosition, SR_yPosition, SR_width, SR_height, SR_thickness, 100.0);

    // drawTree(SR_tree_xPosition, SR_tree_yPosition, SR_tree_width, SR_tree_height, SR_tree_thickness, SR_tree_percent);

    letterA(0.02f, -0.4f);
    letterS(0.02f, -0.4f);
    letterT(0.02f, -0.4f);
    letterR(0.02f, -0.4f);
    letterO(-0.87f, -0.4f);
    letterM(0.02f, -0.4f);
    letterE(0.02f, -0.4f);
    letterD(0.02f, -0.4f);
    letterI(0.02f, -0.4f);
    letterC(0.02f, -0.4f);
    letterO(0.02f, -0.4f);
    letterM(0.905f, -0.4f);
    letterP(0.02f, -0.4f);

    printf("Inside V1\n");
    letterD(-1.08f, -0.9f);
    letterR(-0.28f, -0.9f);
    letterV(0.1f, -0.9f);
    letterI(-0.70f, -0.9f);
    letterJ(0.35f, -0.9f);
    letterA(0.77f, -0.9f);
    letterY(0.65f, -0.9f);
    letterG(-0.4f, 0.0f);
    letterK(-0.2f, 0.0f);
    letterL(0.0f, 0.0f);
    letterH(0.2f, 0.0f);
    letterN(0.4f, 0.0f);
    letterU(0.1f, -0.5f);

    glutSwapBuffers();
}

void SR_mukut(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage)
{
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
}

void projectName(float SR_xPosition, float SR_yPosition, float SR_width, float SR_height, float SR_thickness, float SR_percent)
{

    SR_mukut(0.25f, -0.980f, 172, 207);

    // glBegin(GL_LINES);

    // glVertex2f(SR_xPosition, SR_yPosition);
    // glVertex2f(SR_xPosition + SR_width, SR_yPosition);
    // glVertex2f(SR_xPosition + SR_width, SR_yPosition - SR_height);
    // glVertex2f(SR_xPosition, SR_yPosition - SR_height);

    // glEnd();

    // glBegin(GL_LINES);

    // glVertex2f(SR_xPosition + SR_width, SR_yPosition - (SR_height / 2));
    // glVertex2f(SR_xPosition, SR_yPosition - (SR_height / 2));

    // glEnd();

    // actual text
    glColor3f(0.924f, 0.438f, 0.180f);

    glBegin(GL_TRIANGLE_FAN);

    float centerX = SR_xPosition + 0.18f;
    float centerY = SR_yPosition - (SR_height / 2);
    float radius = SR_thickness * 2.5f;
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {

        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius * 0.7f);
        float y = centerY + (sin(angle) * radius * 1.0f);

        glVertex2f(x, y);
    }
    glEnd();

    // Inner circle color needs to chages according to background
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    // 1. Establish the center anchor point
    centerX = SR_xPosition + 0.18f;
    centerY = SR_yPosition - (SR_height / 2);
    radius = SR_thickness;
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

    glColor3f(0.924f, 0.438f, 0.180f);

    glBegin(GL_QUADS);

    glVertex2f(SR_xPosition - 0.05f, SR_yPosition);
    glVertex2f(SR_xPosition + (SR_width - 0.1f), SR_yPosition);
    glVertex2f(SR_xPosition + (SR_width - 0.1f), SR_yPosition + SR_thickness);
    glVertex2f(SR_xPosition - 0.05f, SR_yPosition + SR_thickness);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(SR_xPosition + 0.27f, SR_yPosition);
    glVertex2f((SR_xPosition + SR_thickness) + 0.27f, SR_yPosition);
    glVertex2f((SR_xPosition + SR_thickness) + 0.27f, SR_yPosition - SR_height);
    glVertex2f(SR_xPosition + 0.27f, SR_yPosition - SR_height);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(SR_xPosition + 0.45f, SR_yPosition);
    glVertex2f((SR_xPosition + SR_thickness) + 0.45f, SR_yPosition);
    glVertex2f((SR_xPosition + SR_thickness) + 0.45f, SR_yPosition - SR_height);
    glVertex2f(SR_xPosition + 0.45f, SR_yPosition - SR_height);

    glEnd();

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_xPosition + 0.90f, SR_yPosition);
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f((SR_xPosition + SR_thickness) + 0.90f, SR_yPosition);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f((SR_xPosition + SR_thickness) + 0.90f, SR_yPosition - SR_height);
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_xPosition + 0.90f, SR_yPosition - SR_height);

    glEnd();

    glColor3f(0.924f, 0.438f, 0.180f);

    glBegin(GL_QUADS);
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_xPosition + 0.70f, SR_yPosition);
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f((SR_xPosition + SR_thickness) + 0.70f, SR_yPosition);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f((SR_xPosition + SR_thickness) + 0.70f, SR_yPosition - (SR_height / 2 + 0.025f));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_xPosition + 0.70f, SR_yPosition - (SR_height / 2 - 0.1f));

    glEnd();

    glBegin(GL_QUADS);
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f((SR_xPosition + SR_thickness) + 0.70f, SR_yPosition - (SR_height / 2 + 0.025f));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_xPosition + 0.70f, SR_yPosition - (SR_height / 2 - 0.1f));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f((SR_xPosition + 0.60f), SR_yPosition - (SR_height / 2 + 0.030f));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f((SR_xPosition + SR_thickness) + 0.60f, SR_yPosition - (SR_height / 2 + 0.10f));

    glEnd();

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f((SR_xPosition + SR_thickness) + 0.55f, SR_yPosition - (SR_height / 2 - 0.1f));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_xPosition + 0.58f, SR_yPosition - (SR_height / 2 + 0.0005f));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_xPosition + 0.80f, SR_yPosition - (SR_height + 0.08f));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f((SR_xPosition + SR_thickness) + 0.77f, SR_yPosition - (SR_height));

    glEnd();
}

void drawTree(float SR_tree_xPosition, float SR_tree_yPosition, float SR_tree_width, float SR_tree_height, float SR_tree_thickness, float SR_tree_percent)
{
    glColor3f(1.1f, 0.1f, 0.1f);

    glBegin(GL_LINES);

    glVertex2f(SR_VALUE_FROM_PERCENT(SR_tree_xPosition + 0.08f, SR_percent), SR_VALUE_FROM_PERCENT(SR_tree_yPosition - 0.6f, SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT(SR_tree_xPosition - 0.08f, SR_percent), SR_VALUE_FROM_PERCENT(SR_tree_yPosition - 0.6f, SR_percent));

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_tree_xPosition - 0.03f), SR_percent), SR_VALUE_FROM_PERCENT((SR_tree_yPosition), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_tree_xPosition + 0.03f), SR_percent), SR_VALUE_FROM_PERCENT((SR_tree_yPosition), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_tree_xPosition + 0.05f), SR_percent), SR_VALUE_FROM_PERCENT((SR_tree_yPosition - 0.6f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_tree_xPosition - 0.05f), SR_percent), SR_VALUE_FROM_PERCENT((SR_tree_yPosition - 0.6f), SR_percent));

    glEnd();

    // tree leaves
    glColor3f(0.0f, 1.0f, 0.0f);

    // 1
    glBegin(GL_TRIANGLE_FAN);

    float centerX = SR_VALUE_FROM_PERCENT(SR_tree_xPosition, SR_percent);
    float centerY = SR_VALUE_FROM_PERCENT(SR_tree_yPosition + 0.1f, SR_percent);
    float radius = SCALE_RADIUS(SR_thickness * 3.0f, SR_percent);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius * 0.7f);
        float y = centerY + (sin(angle) * radius * 1.0f);

        glVertex2f(x, y);
    }
    glEnd();

    // 2
    glBegin(GL_TRIANGLE_FAN);

    centerX = SR_VALUE_FROM_PERCENT(SR_tree_xPosition + 0.13f, SR_percent);
    centerY = SR_VALUE_FROM_PERCENT(SR_tree_yPosition - 0.05f, SR_percent);
    radius = SCALE_RADIUS(SR_thickness * 2.0f, SR_percent);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius * 0.8f);
        float y = centerY + (sin(angle) * radius * 1.0f);

        glVertex2f(x, y);
    }
    glEnd();

    // 3
    glBegin(GL_TRIANGLE_FAN);

    centerX = SR_VALUE_FROM_PERCENT(SR_tree_xPosition + 0.2f, SR_percent);
    centerY = SR_VALUE_FROM_PERCENT(SR_tree_yPosition + 0.2f, SR_percent);
    radius = SCALE_RADIUS(SR_thickness * 1.5f, SR_percent);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius * 0.7f);
        float y = centerY + (sin(angle) * radius * 1.0f);

        glVertex2f(x, y);
    }
    glEnd();

    // 4
    glBegin(GL_TRIANGLE_FAN);

    centerX = SR_VALUE_FROM_PERCENT(SR_tree_xPosition + 0.1f, SR_percent);
    centerY = SR_VALUE_FROM_PERCENT(SR_tree_yPosition + 0.4f, SR_percent);
    radius = SCALE_RADIUS(SR_thickness * 1.5f, SR_percent);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius * 0.7f);
        float y = centerY + (sin(angle) * radius * 1.0f);

        glVertex2f(x, y);
    }
    glEnd();

    // centre
    glBegin(GL_TRIANGLE_FAN);

    centerX = SR_VALUE_FROM_PERCENT(SR_tree_xPosition, SR_percent);
    centerY = SR_VALUE_FROM_PERCENT(SR_tree_yPosition + 0.5f, SR_percent);
    radius = SCALE_RADIUS(SR_thickness * 1.0f, SR_percent);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius * 0.7f);
        float y = centerY + (sin(angle) * radius * 1.0f);

        glVertex2f(x, y);
    }
    glEnd();

    // third last
    glBegin(GL_TRIANGLE_FAN);

    centerX = SR_VALUE_FROM_PERCENT(SR_tree_xPosition - 0.1f, SR_percent);
    centerY = SR_VALUE_FROM_PERCENT(SR_tree_yPosition + 0.4f, SR_percent);
    radius = SCALE_RADIUS(SR_thickness * 1.5f, SR_percent);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius * 0.7f);
        float y = centerY + (sin(angle) * radius * 1.0f);

        glVertex2f(x, y);
    }
    glEnd();

    // second last
    glBegin(GL_TRIANGLE_FAN);

    centerX = SR_VALUE_FROM_PERCENT(SR_tree_xPosition - 0.2f, SR_percent);
    centerY = SR_VALUE_FROM_PERCENT(SR_tree_yPosition + 0.2f, SR_percent);
    radius = SCALE_RADIUS(SR_thickness * 1.5f, SR_percent);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius * 0.7f);
        float y = centerY + (sin(angle) * radius * 1.0f);

        glVertex2f(x, y);
    }
    glEnd();

    // last
    glBegin(GL_TRIANGLE_FAN);

    centerX = SR_VALUE_FROM_PERCENT(SR_tree_xPosition - 0.13f, SR_percent);
    centerY = SR_VALUE_FROM_PERCENT(SR_tree_yPosition - 0.05f, SR_percent);
    radius = SCALE_RADIUS(SR_thickness * 2.0f, SR_percent);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        float x = centerX + (cos(angle) * radius * 0.8f);
        float y = centerY + (sin(angle) * radius * 1.0f);

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

void letterA(float x_pos, float y_pos)
{
    // A
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(VALUE_FROM_PERCENT(-0.99f, percent) + x_pos, VALUE_FROM_PERCENT(0.6f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.96f, percent) + x_pos, VALUE_FROM_PERCENT(0.6f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.96f, percent) + x_pos, VALUE_FROM_PERCENT(0.2f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.99f, percent) + x_pos, VALUE_FROM_PERCENT(0.2f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.99f, percent) + x_pos, VALUE_FROM_PERCENT(0.6f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.87f, percent) + x_pos, VALUE_FROM_PERCENT(0.6f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.87f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.99f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.87f, percent) + x_pos, VALUE_FROM_PERCENT(0.6f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.90f, percent) + x_pos, VALUE_FROM_PERCENT(0.6f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.90f, percent) + x_pos, VALUE_FROM_PERCENT(0.2f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.87f, percent) + x_pos, VALUE_FROM_PERCENT(0.2f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.99f, percent) + x_pos, VALUE_FROM_PERCENT(0.42f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.87f, percent) + x_pos, VALUE_FROM_PERCENT(0.42f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.87f, percent) + x_pos, VALUE_FROM_PERCENT(0.38f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.99f, percent) + x_pos, VALUE_FROM_PERCENT(0.38f, percent) + y_pos);

    glEnd();
}

void letterS(float x_pos, float y_pos)
{

    // S

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.96f, 0.90f);

    glVertex2f(VALUE_FROM_PERCENT(-0.85f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.85f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.85f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.82f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.82f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.85f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.85f, percent) + x_pos, VALUE_FROM_PERCENT(0.425f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, percent) + x_pos, VALUE_FROM_PERCENT(0.425f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.85f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.76f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.76f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.85f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.85f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterT(float x_pos, float y_pos)
{

    // T

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.92f, 0.80f);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(-0.71f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.59f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.59f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.71f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(-0.665f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.635f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.635f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.666f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterR(float x_pos, float y_pos)
{

    // R

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.88f, 0.70f);

    glVertex2f(VALUE_FROM_PERCENT(-0.57f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.54f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.54f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.57f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.57f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.57f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.57f, percent) + x_pos, VALUE_FROM_PERCENT(0.425f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.425f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.57f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.48f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.48f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.54f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.50f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.44f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.48f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

// void letterO(float x_pos, float y_pos)
// {

//     // O

//     glBegin(GL_QUADS);

//     glColor3f(1.0f, 0.84f, 0.60f);

//     glVertex2f(VALUE_FROM_PERCENT(-0.43f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.40f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.40f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.43f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

//     glVertex2f(VALUE_FROM_PERCENT(-0.31f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.28f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.28f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.31f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

//     glVertex2f(VALUE_FROM_PERCENT(-0.43f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.28f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.28f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.43f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

//     glVertex2f(VALUE_FROM_PERCENT(-0.43f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.28f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.28f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(-0.43f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

//     glEnd();
// }

void letterM(float x_pos, float y_pos)
{

    // M

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.80f, 0.50f);

    glVertex2f(VALUE_FROM_PERCENT(-0.26f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.23f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.23f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.26f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.26f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.09f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.09f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.26f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.09f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.06f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.06f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.09f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.17f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.14f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.14f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.17f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterE(float x_pos, float y_pos)
{

    // E

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.76f, 0.40f);

    glVertex2f(VALUE_FROM_PERCENT(-0.04f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.01f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.01f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.04f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.04f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.08f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.08f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.04f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.04f, percent) + x_pos, VALUE_FROM_PERCENT(0.425f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.06f, percent) + x_pos, VALUE_FROM_PERCENT(0.425f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.06f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.04f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.04f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.08f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.08f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.04f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterD(float x_pos, float y_pos)
{
    // D

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.72f, 0.30f);

    glVertex2f(VALUE_FROM_PERCENT(0.09f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.12f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.12f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.09f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.09f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.09f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.18f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.18f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.09f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.09f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterI(float x_pos, float y_pos)
{

    // I

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.68f, 0.20f);

    glVertex2f(VALUE_FROM_PERCENT(0.22f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.32f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.32f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.22f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.255f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.285f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.285f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.255f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.22f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.32f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.32f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.22f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterC(float x_pos, float y_pos)
{

    // C

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.64f, 0.10f);

    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}
void letterO(float x_pos, float y_pos)
{
    // O

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.62f, 0.05f);

    glVertex2f(VALUE_FROM_PERCENT(0.46f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.49f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.49f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.46f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.58f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.58f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.46f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.46f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.46f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.46f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

// void letterM(float x_pos, float y_pos)
// {
//     // M

//     glBegin(GL_QUADS);

//     glColor3f(1.0f, 0.60f, 0.02f);

//     glVertex2f(VALUE_FROM_PERCENT(0.62f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.65f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.65f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.62f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

//     glVertex2f(VALUE_FROM_PERCENT(0.62f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.80f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.80f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.62f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

//     glVertex2f(VALUE_FROM_PERCENT(0.80f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.83f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.83f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.80f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

//     glVertex2f(VALUE_FROM_PERCENT(0.71f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.74f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.74f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
//     glVertex2f(VALUE_FROM_PERCENT(0.71f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

//     glEnd();
// }

void letterP(float x_pos, float y_pos)
{
    // P

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.60f, 0.00f);

    glVertex2f(VALUE_FROM_PERCENT(0.84f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.87f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.87f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.84f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.84f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.84f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.93f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.93f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.84f, percent) + x_pos, VALUE_FROM_PERCENT(0.425f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, percent) + x_pos, VALUE_FROM_PERCENT(0.425f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.84f, percent) + x_pos, VALUE_FROM_PERCENT(0.375f, percent) + y_pos);

    glEnd();
}

void letterV(float x_pos, float y_pos)
{

    printf("Inside V\n");
    glColor3f(1.0f, 0.60f, 0.00f);
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(-0.71f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(-0.74f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.666f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.636f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.59f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.62f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.666f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.635f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterJ(float x_pos, float y_pos)
{

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.92f, 0.80f);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(-0.71f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.59f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.59f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.71f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(-0.665f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.635f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.635f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.664f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.92f, 0.80f);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(-0.71f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.65f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.65f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.71f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterY(float x_pos, float y_pos)
{
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(-0.71f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(-0.74f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.666f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.636f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.59f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.62f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.666f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.635f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(-0.665f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.635f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.635f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.665f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterG(float x_pos, float y_pos)
{

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.64f, 0.10f);

    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.55f, percent) + y_pos);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.42f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.42f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);

    glEnd();
}

void letterK(float x_pos, float y_pos)
{

    glColor3f(1.0f, 0.64f, 0.10f);
    glBegin(GL_QUADS);

    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.55f, percent) + x_pos + 1.0f, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.58f, percent) + x_pos + 1.0f, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.670f, percent) + x_pos + 1.0f, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.639f, percent) + x_pos + 1.0f, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.670f, percent) + x_pos + 1.0f, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(-0.639f, percent) + x_pos + 1.0f, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(-0.55f, percent) + x_pos + 1.0f, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(-0.58f, percent) + x_pos + 1.0f, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterL(float x_pos, float y_pos)
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterH(float x_pos, float y_pos)
{
    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.45f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.45f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.40f, percent) + y_pos);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(0.48f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.48f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterN(float x_pos, float y_pos)
{
    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.48f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(0.48f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.48f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}

void letterU(float x_pos, float y_pos)
{

    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.36f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.25f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.33f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(VALUE_FROM_PERCENT(0.48f, percent) + x_pos, VALUE_FROM_PERCENT(0.60f, percent) + y_pos);
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(VALUE_FROM_PERCENT(0.48f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);
    glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(VALUE_FROM_PERCENT(0.45f, percent) + x_pos, VALUE_FROM_PERCENT(0.20f, percent) + y_pos);

    glEnd();
}