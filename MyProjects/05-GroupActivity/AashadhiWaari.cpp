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

// MACRO DECLARATIONS
#define VALUE_FROM_PERCENT(complete_value, percent) ((complete_value * percent) / 100)
// sagar's macros
#define SR_VALUE_FROM_PERCENT(complete_value, SR_percent) (((complete_value) * (SR_percent)) / 100.0f)
#define SCALE_RADIUS(radius, SR_percent) ((radius) * (SR_percent) / 100)

// Pranalis macros
#define PSH_X(xCordinate) (VALUE_FROM_PERCENT(xCordinate, psh_width_percentage) + psh_x_pos)
#define PSH_Y(yCordinate) (VALUE_FROM_PERCENT(yCordinate, psh_height_percentage) + psh_y_pos)

// Hemant macros
#define percent_vaule(complete_value, hb_percent) (complete_value * hb_percent / 100)
#define redius(redius, hb_percent) ((redius) * (hb_percent) / 100)

// yogesh macros
#define PI 3.14159265359
#define VALUE_FROM_PERCENT(complete_value, percent) ((complete_value * percent) / 100) // SAME AS Sagar
#define YBG_SCALE_RADIUS(radius, YBG_percent) ((radius) * (YBG_percent) / 100)

float YBG_shift_X = -0.5f;
float YBG_shift_Y = -0.65f;

int YBG_percent = 75;

#define YBG_X(xValue) (VALUE_FROM_PERCENT(xValue, YBG_percent) + YBG_shift_X)
#define YBG_Y(yValue) (VALUE_FROM_PERCENT(yValue, YBG_percent) + YBG_shift_Y)

// Sriniwas macro
#define suj_VALUE_FROM_PERCENT(complete_value, suj_percent) (((complete_value) * (suj_percent)) / 100.0f)

// FUNCTION DECLARATIONS
// sagar functions
void dhwajGhetlelaWarkari(float SR_XPosition, float SR_YPosition, float SR_Height, float SR_Width, float flagSway, float SR_percent);
void callDhwajGhetlelWarkari();
void drawFlower(float flowerRadius, float xPosition, float yPosition);
void calldrawFlower();
void drawTree(float SR_tree_xPosition, float SR_tree_yPosition, float SR_tree_width, float SR_tree_height, float SR_tree_thickness, float SR_tree_percent);
// sagar name functions
void drawSagarName(float startingPointX, float startingPointY, float width, float thickness, float SR_namePercent);
void letterS(float startingPoint, float startingPointY, float width, float thickness, float SR_namePercent);
void letterA(float startingPointX, float startingPointY, float width, float thickness, float SR_namePercent);
void letterG(float startingPointX, float startingPointY, float width, float thickness, float SR_namePercent);
void letterR(float startingPointX, float startingPointY, float width, float thickness, float SR_namePercent);

// project name functions
void SR_mukut(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);
void projectName(float SR_xPosition, float SR_yPosition, float SR_width, float SR_height, float SR_thickness, float SR_percent);

// pranali functions
void VitthalTimer(int value);
void psh_drawVitthal(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);
void psh_draw_ghoda(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);

// Hemant functions
void hbPalakhi(float hb_x, float hb_y, float hb_h, float hb_w);
void hbZumbar(float offset_x, float offset_y, float radius_x, float radius_y, float r, float g, float b, bool drawLines = false);

// ground function
void drawGroundQuad();

// harshal functions
void Tila(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);
void renderGroupPresents(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);

// shriniwas's funcions
void SJ_Chopdar();
void suj_s(void);
void suj_h(void);
void suj_r(void);
void suj_i(void);
void suj_n(void);
void suj_i2(void);
void suj_v(void);
void suj_a(void);
void suj_s2(void);

// Yogesh's functions
void drawQuad(float xP, float yP, float width, float height);
void drawHalfCircle(float cx, float cy, float r, int segments);
void drawCirlce(float cx, float cy, float r, int segment);
void yg_Veena_Warkari();

// Prasad's function
void drawMandir();

// Astromedicomp functions
void AstroMediComp(float x_pos, float y_pos);

// fade in out functions
void ScreenFadeIn(int value);
void ScreenFadeOut(int value);
void ScreenQuad(void);

// GLOBAL VARIABLES
bool bIsFullScreen = false;
float xPosition = 0.0f;

// Warkari variable declarations - sagar
float SR_XPosition = -1.5f;
float SR_YPosition = 0.250f;
float SR_Height = 1.5f;
float SR_Width = 0.2f;
float SR_currentSwayOffset = 0.0f;
bool SR_bodyGoingUp = true;
bool SR_flagSwayingLeft = true;
// sagar name variables
float startingPointX = -0.9f; // -0.9
float startingPointY = 0.5f;
float width = 0.32f;
float thickness = 0.10f;
float SR_namePercent = 50.0;

// variables for project name
float SR_xPosition = -0.6f;
float SR_yPosition = 0.152f;
float SR_width = 1.2f;
float SR_height = 0.8f;
float SR_thickness = 0.11f;

// variables for tree
float SR_tree_xPosition = -1.1f;
float SR_tree_yPosition = 0.85f;
float SR_tree_width = 0.8f;
float SR_tree_height = 1.2f;
float SR_tree_thickness = 0.11f;
float SR_tree_percent = 50.0f;

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

// shriniwas variables
float suj_percent = 65.0f;
float suj_x = 0.6f;
float suj_y = -0.5f;

// prasad mandir variables
float PK_xPosition = -0.3f;
float PK_yPosition = -0.1f;
float PK_width;
float PK_height;
float percent = 120;

// Astromedicomp variables
float x_pos, y_pos;
float persent = 100.0f;

// fade in out code
float ScreenFadeFactor = 1.0f; // Start fully black (faded in)
bool ScreenFade = true;
bool FadeIn = true, FadeOut = false;

int scence = 0;
bool bRenderGroupPresentsFIn = false;
bool bRenderGroupPresentsFOut = false;

bool bProjectNameFIn = false;
bool bProjectNameFOut = false;

bool showMainSceneFIn = false;
bool showMainSceneFOut = false;

bool bVitthalFIn = false;
bool bVitthalFout = false;

bool endCreditSceneIn = false;
bool endCreditSceneOut = true;

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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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

    // Astromedicomp
    // AstroMediComp(0.02f, -0.4f);

    // ground func call
    // drawGroundQuad();

    // drawTree(SR_tree_xPosition, SR_tree_yPosition, SR_tree_width, SR_tree_height, SR_tree_thickness, SR_tree_percent);

    // ghoda
    // void psh_draw_ghoda(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage);
    // psh_draw_ghoda(-0.4f, 0.5f, 30, 35);

    // SJ_Chopdar();

    // yg_Veena_Warkari();

    // callDhwajGhetlelWarkari();

    // // // Pranalis code

    // // psh_drawVitthal(0.2f, 0.0f, 60, 95);

    // // // Pranalis code

    // Hemant code
    // hbPalakhi(hb_x, hb_y, hb_h, hb_w);

    // // drawflower call

    // calldrawFlower();

    // Mandir
    // drawMandir();

    // // drawFlower call

    // // Harshal's code
    // renderGroupPresents(0.0f, 0.0f, 100, 100);
    // Tila(0.0f, -1.0f, 400, 200);

    // projectName(SR_xPosition, SR_yPosition, SR_width, SR_height, SR_thickness, 100.0);

    // Pranalis code
    // psh_drawVitthal(0.0f, 0.0f, 60, 95);

    // Shriniwas name code
    // glColor3f(1.0f, 1.0f, 0.0f);
    // suj_s();
    // suj_h();
    // suj_r();
    // suj_i();
    // suj_n();
    // suj_i2();
    // suj_v();
    // suj_a();
    // suj_s2();

    // sagar name code
    // drawSagarName(startingPointX, startingPointY, width, thickness, SR_namePercent);

    // fade in out switch case
    switch (scence)
    {
        // case for Astromedicomp
    case 0:
        if (bRenderGroupPresentsFIn != true)
        {

            if (FadeIn)
            {
                ScreenFadeIn(ScreenFadeFactor);
                AstroMediComp(0.02f, -0.4f);
                printf("renderGroupPresents\n");
            }
            if (ScreenFadeFactor <= 0.0f)
            {
                bRenderGroupPresentsFIn = true;
                FadeIn = false;
                FadeOut = true;
            }
        }
        else
        {
            // printf("FadeOut %d", FadeOut);
            if (FadeOut)
            {
                ScreenFadeOut(ScreenFadeFactor);
                AstroMediComp(0.02f, -0.4f);
                printf("renderGroupPresents from else\n");
            }
            if (ScreenFadeFactor >= 1.0f)
            {
                bRenderGroupPresentsFOut = true;
                // Reset for next scene
                FadeIn = true;
                FadeOut = false;
                ScreenFadeFactor = 1.0f;
                scence++;
            }
        }
        break;

        // case for astromedicomp and render group presents
    case 1:
        if (bRenderGroupPresentsFIn != true)
        {

            if (FadeIn)
            {
                ScreenFadeIn(ScreenFadeFactor);
                renderGroupPresents(0.0f, 0.0f, 100, 100);
                printf("renderGroupPresents\n");
            }
            if (ScreenFadeFactor <= 0.0f)
            {
                bRenderGroupPresentsFIn = true;
                FadeIn = false;
                FadeOut = true;
            }
        }
        else
        {
            // printf("FadeOut %d", FadeOut);
            if (FadeOut)
            {
                ScreenFadeOut(ScreenFadeFactor);
                renderGroupPresents(0.0f, 0.0f, 100, 100);
                printf("renderGroupPresents from else\n");
            }
            if (ScreenFadeFactor >= 1.0f)
            {
                bRenderGroupPresentsFOut = true;
                // Reset for next scene
                FadeIn = true;
                FadeOut = false;
                ScreenFadeFactor = 1.0f;
                scence++;
            }
        }
        break;

    // case for showing project name
    case 2:
        if (bProjectNameFIn != true)
        {
            if (FadeIn)
            {
                ScreenFadeIn(ScreenFadeFactor);
                printf("Tila called\n");
                projectName(SR_xPosition, SR_yPosition, SR_width, SR_height, SR_thickness, 100.0);
            }
            if (ScreenFadeFactor <= 0.0f)
            {
                bProjectNameFIn = true;
                FadeIn = false;
                FadeOut = true;
            }
        }
        else
        {
            if (FadeOut)
            {
                ScreenFadeOut(ScreenFadeFactor);
                printf("Tila called from else\n");
                projectName(SR_xPosition, SR_yPosition, SR_width, SR_height, SR_thickness, 100.0);
            }
            if (ScreenFadeFactor >= 1.0f)
            {
                bProjectNameFOut = true;
                // Reset for next scene
                FadeIn = true;
                FadeOut = false;
                ScreenFadeFactor = 1.0f;
                scence++;
            }
        }
        break;

    // case for showing main scene
    case 3:
        if (showMainSceneFIn != true)
        {
            if (FadeIn)
            {
                ScreenFadeIn(ScreenFadeFactor);
                printf("ground called\n");
                drawGroundQuad();
                callDhwajGhetlelWarkari();
                hbPalakhi(hb_x, hb_y, hb_h, hb_w);
                SJ_Chopdar();
                yg_Veena_Warkari();
            }
            if (ScreenFadeFactor <= 0.0f)
            {
                showMainSceneFIn = true;
                FadeIn = false;
                FadeOut = true;
            }
        }

        else
        {
            if (FadeOut)
            {
                ScreenFadeOut(ScreenFadeFactor);
                printf("ground called from else\n");
                drawGroundQuad();
                callDhwajGhetlelWarkari();
                hbPalakhi(hb_x, hb_y, hb_h, hb_w);
                SJ_Chopdar();
                yg_Veena_Warkari();
            }

            if (ScreenFadeFactor >= 1.0f)
            {
                showMainSceneFOut = true;
                scence++;
                ScreenFadeFactor = 1.0f;
                FadeIn = true;
                FadeOut = false;
            }
        }
        break;

        // case for showing vitthal
    case 4:
        if (bVitthalFIn != true)
        {
            if (FadeIn)
            {
                ScreenFadeIn(ScreenFadeFactor);
                printf("vitthal called\n");
                psh_drawVitthal(0.0f, 0.0f, 60, 95);
                calldrawFlower();
            }
            if (ScreenFadeFactor <= 0.0f)
            {
                bVitthalFIn = true;
                FadeIn = false;
                FadeOut = true;
            }
        }

        else
        {
            if (FadeOut)
            {
                ScreenFadeOut(ScreenFadeFactor);
                printf("vitthal called from else\n");
                psh_drawVitthal(0.0f, 0.0f, 60, 95);
            }

            if (ScreenFadeFactor >= 1.0f)
            {
                bVitthalFout = true;
                scence++;
                ScreenFadeFactor = 1.0f;
                FadeIn = true;
                FadeOut = false;
            }
        }
        break;

        // case for end credit scene
    case 5:
        if (endCreditSceneIn != true)
        {
            if (FadeIn)
            {
                ScreenFadeIn(ScreenFadeFactor);
                printf("end credit scene called\n");
                drawSagarName(startingPointX, startingPointY, width, thickness, SR_namePercent);
            }
            if (ScreenFadeFactor <= 0.0f)
            {
                endCreditSceneIn = true;
                FadeIn = false;
                FadeOut = true;
            }
        }

        else
        {
            if (FadeOut)
            {
                ScreenFadeOut(ScreenFadeFactor);
                printf("end credit scene called from else\n");
                drawSagarName(startingPointX, startingPointY, width, thickness, SR_namePercent);
            }

            if (ScreenFadeFactor >= 1.0f)
            {
                endCreditSceneOut = true;
                scence++;
                ScreenFadeFactor = 1.0f;
                FadeIn = true;
                FadeOut = false;

                if (scence == 6)
                {
                    glutLeaveMainLoop();
                }
            }
        }
        break;
    }

    ScreenQuad();

    glutSwapBuffers();
    glutPostRedisplay();
}

void rectMove(float xPosition)
{
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(0.2f, 0.2f + xPosition, 0.0f);

    // glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-0.2f, 0.2f + xPosition, 0.0f);

    // glColor3f(0.0f),PSH_Y(0.0f),PSH_Y(1.0f));
    glVertex3f(-0.2f, -0.2f + xPosition, 0.0f);

    // glColor3f(0.0f),PSH_Y(0.0f),PSH_Y(1.0f));
    glVertex3f(0.2f, -0.2f + xPosition, 0.0f);

    glEnd();
}

void ScreenQuad(void)
{
    glColor4f(0.0f, 0.0f, 0.0f, ScreenFadeFactor);
    glBegin(GL_QUADS);
    {
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 0.0f);
    }
    glEnd();
}

void ScreenFadeIn(int value)
{
    // printf("ScreenFadeIn\n");
    if (FadeIn == true)
    {
        // THIS ALPHA FACTOR WILL CHANGE ON BASIS OF YOUR MACHINE
        ScreenFadeFactor = ScreenFadeFactor - 0.006f;
        if (ScreenFadeFactor <= 0.0f)
        {
            // ScreenFade = false;
            FadeIn = false;
            FadeOut = true;
        }

        glutPostRedisplay();
        glutTimerFunc(60, ScreenFadeIn, 0);
    }
}

void ScreenFadeOut(int value)
{
    if (FadeOut == true)
    {
        ScreenFadeFactor = ScreenFadeFactor + 0.006f;
        if (ScreenFadeFactor >= 1.0f)
        {
            // ScreenFade = true;
            FadeIn = true;
            FadeOut = false;
        }
        glutPostRedisplay();
        glutTimerFunc(60, ScreenFadeOut, 0);
    }
}

void calldrawFlower()
{
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
}

void dhwajGhetlelaWarkari(float SR_XPosition, float SR_YPosition, float SR_Height, float SR_Width, float flagSway, float SR_percent)
{

    // glColor3f(0.933f, 0.937f, 0.945f);

    // glBegin(GL_QUADS);

    // glVertex3f(SR_VALUE_FROM_PERCENT(SR_XPosition, SR_percent), SR_VALUE_FROM_PERCENT(SR_YPosition, SR_percent), 0.0f);
    // glVertex3f(SR_VALUE_FROM_PERCENT(SR_Width + SR_XPosition, SR_percent), SR_VALUE_FROM_PERCENT(SR_YPosition, SR_percent), 0.0f);
    // glVertex3f(SR_VALUE_FROM_PERCENT(SR_Width + SR_XPosition, SR_percent), SR_VALUE_FROM_PERCENT(SR_YPosition - SR_Height, SR_percent), 0.0f);
    // glVertex3f(SR_VALUE_FROM_PERCENT(SR_XPosition, SR_percent), SR_VALUE_FROM_PERCENT(SR_YPosition - SR_Height, SR_percent), 0.0f);

    // // glVertex3f(VALUE_FROM_PERCENT(-0.2f, persent) + xPosition, VALUE_FROM_PERCENT(-0.4f, persent) + YPosition, 0.0f);

    // glEnd();

    // Warkari starts here
    // gandhitopi
    // topi top
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLES);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), SR_VALUE_FROM_PERCENT(SR_YPosition, SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));

    glEnd();

    // topi main quad
    glBegin(GL_QUADS);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.051f)), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + (SR_Width / 5)), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.04f)), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));

    glEnd();

    // neck rectangle
    glBegin(GL_QUADS);

    glColor3f(0.890f, 0.757f, 0.624f);
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.057f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    // glColor3f(0.890f, 0.757f, 0.624f);
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.057f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));

    glEnd();

    // face quad
    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.35f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.35f), SR_percent));

    glEnd();

    // hat bottom tip
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 5), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.04f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.15f), SR_percent));

    glEnd();

    // chin semicircle
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.917f, 0.816f, 0.726f);

    float centerX = SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent);
    float centerY = SR_VALUE_FROM_PERCENT((SR_YPosition - 0.35f), SR_percent);
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

    float bukkaX = SR_VALUE_FROM_PERCENT((SR_XPosition + (SR_Width / 2)), SR_percent);
    float bukkaY = SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent);

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
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.040f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.040f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.135f), SR_percent));

    glEnd();

    // left ear
    glBegin(GL_QUADS);
    glColor3f(0.917f, 0.816f, 0.726f);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.040f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.040f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.32f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.32f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));

    glEnd();

    // --- BUKKA ON EAR
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.1f, 0.1f);

    float earBukkaX = SR_VALUE_FROM_PERCENT((SR_XPosition + 0.045f), SR_percent);
    float earBukkaY = SR_VALUE_FROM_PERCENT((SR_YPosition - 0.31f), SR_percent);

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
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.135f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));

    glEnd();

    // right ears
    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.32f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.32f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.040f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.18f), SR_percent));

    glEnd();

    // --- BUKKA ON EARS
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.1f, 0.1f);

    earBukkaX = SR_VALUE_FROM_PERCENT((SR_XPosition + (SR_Width - 0.046f)), SR_percent);
    earBukkaY = SR_VALUE_FROM_PERCENT((SR_YPosition - 0.31f), SR_percent);

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
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), SR_VALUE_FROM_PERCENT(SR_YPosition, SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.04f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), SR_VALUE_FROM_PERCENT(SR_YPosition, SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 5), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.15f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 5), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.051f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.045f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.04f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.13f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.15f), SR_percent));

    // RIGHT COLLAR TOP LINE
    // glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.028f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    glEnd();

    glLineWidth(1.0f);

    // FACE LINES END HERE //

    // shirt starts here

    // left collar
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.057f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.097f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.028f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    glEnd();

    // right collar
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.028f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    glEnd();

    // below collar quad
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    glEnd();

    // FLAG STARTS HERE //
    // flag bamboo
    glBegin(GL_QUADS);

    glColor3f(0.439f, 0.310f, 0.184f);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.0f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.0f), SR_percent));

    glEnd();

    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);

    glColor3f(0.278f, 0.282f, 0.267f);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.015f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.0f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.035f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.0f), SR_percent));

    glEnd();

    glLineWidth(1.0f);

    // flag
    glBegin(GL_TRIANGLES);
    glColor3f(0.924f, 0.438f, 0.180f);
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.012f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.012f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.1f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.3f + flagSway), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition + 0.1f), SR_percent));
    glEnd();

    // flag border

    glLineWidth(1.0f);

    glLineWidth(1.0f);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.013f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition + 0.3f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.013f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.1f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.3f + flagSway), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition + 0.1f), SR_percent));
    glEnd();

    glLineWidth(1.0f);

    // FLAG ENDS HERE //

    // left hand vertical part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));

    glEnd();

    // left hand vertical part lines loop
    glBegin(GL_LINE_LOOP);

    // glColor3f(0.001f, 0.001f, 0.001f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));

    glEnd();

    // LINES START

    glLineWidth(2.0f);
    // left hand top line
    glBegin(GL_LINES);

    glColor3f(0.001f, 0.001f, 0.001f);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.575f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));

    glColor3f(0.001f, 0.001f, 0.001f);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.13f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));

    glColor3f(0.001f, 0.001f, 0.001f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.13f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.07f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.07f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));

    // right hand lines
    glColor3f(0.001f, 0.001f, 0.001f);
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.575f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

    // right hand slant lines
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.200f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.712f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.145f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.82f), SR_percent));

    // glVertex2f(SR_XPosition + 0.145f, SR_YPosition - 0.82f);
    // glVertex2f(SR_XPosition + 0.210f, SR_YPosition - 0.90f);

    // glVertex2f(SR_XPosition + 0.200f, SR_YPosition - 0.708f);
    // glVertex2f(SR_XPosition + 0.275f, SR_YPosition - 0.80f);

    glColor3f(0.001f, 0.001f, 0.001f);
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.202f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.715f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.145f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.82f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.202f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.715f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.80f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.80f), SR_percent));

    // RIGHT Hand cross line
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.165f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.82f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

    // shirt ending lines
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    // Shirt left side lines
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    // shirt right side lines
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

    // right collar border

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width + 0.028f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    glColor3f(0.001f, 0.001f, 0.001f);
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width - 0.057f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));

    // left collar border
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.028f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.057f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.057f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.097f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.49f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.028f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.37f), SR_percent));

    // Pant lines left leg
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.087f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.087f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    // Pant lines right leg
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.117f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.117f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glEnd();

    glLineWidth(1.0f);

    // LINES END

    // HANDS STARTS HERE //

    // left hand horizontal part -- here we will add animation
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.07f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.13f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));

    glEnd();

    // left hand horizontal part lines -- here we will add animation
    glBegin(GL_LINE_LOOP);

    glColor3f(0.001f, 0.001f, 0.001f);

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.008f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.075f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.07f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.93f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.13f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.81f), SR_percent));

    glEnd();

    // LEFT HAND START

    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.141f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.79f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.161f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.79f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.181f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.75f), SR_percent));
    // glColor3f(1.0f, 1.0f, 1.0f); // White
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.161f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.75f), SR_percent));

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.141f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.79f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.23f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.79f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.18f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.085f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

    // glVertex2f();

    glEnd();

    // LEFT HAND END

    // right hand vertical part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.490f), SR_percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));

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
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.212f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.815f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.212f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.695f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.190f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.655f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.190f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.815f), SR_percent));

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.917f, 0.816f, 0.726f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.190f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.825f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.190f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.695f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.150f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.635f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.145f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.765f), SR_percent));

    glEnd();

    // right hand cross part
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.222f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.715f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.165f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.82f), SR_percent));

    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.210f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.90f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.275f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.80f), SR_percent));

    glEnd();

    // HANDS ENDS HERE //

    // PANT STARTS HERE //
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    // LEFT PANT
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.087f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition - 0.065f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glEnd();

    glBegin(GL_QUADS);

    // RIGHT PANT
    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.1f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.15f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.265f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.117f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.8f), SR_percent));

    glEnd();

    // PANT ENDS HERE //

    // GANDH ON FOREHEAD STARTS HERE //

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2.25), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.15f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 1.8f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.15f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 1.8f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.19f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2.25), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 0.19f), SR_percent));

    glEnd();

    // GANDHA BOTTOM CIRCLES
    glBegin(GL_TRIANGLE_FAN);

    bukkaX = SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent);
    bukkaY = SR_VALUE_FROM_PERCENT((SR_YPosition - 0.19f), SR_percent);

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

    bukkaX = SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent);
    bukkaY = SR_VALUE_FROM_PERCENT((SR_YPosition - 0.19f), SR_percent);

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

    bukkaX = SR_VALUE_FROM_PERCENT((SR_XPosition + SR_Width / 2), SR_percent);
    bukkaY = SR_VALUE_FROM_PERCENT((SR_YPosition - 0.167f), SR_percent);

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
    glVertex2f(SR_VALUE_FROM_PERCENT(SR_XPosition - 0.03f, SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.803f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.04f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.803f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.04f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT(SR_XPosition - 0.03f, SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));

    glEnd();

    // glColor3f(0.917f, 0.816f, 0.726f);

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f); // red
    glVertex2f(SR_VALUE_FROM_PERCENT(SR_XPosition - 0.03f, SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    // glColor3f(0.1f, 0.1f, 0.1f); // black
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.04f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    // glColor3f(0.0f, 1.0f, 0.0f); // green
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.02f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));
    // glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2f(SR_VALUE_FROM_PERCENT(SR_XPosition - 0.05f, SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));

    glEnd();

    glColor3f(0.917f, 0.816f, 0.726f);

    // RIGHT LEG
    glBegin(GL_QUADS);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.227f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.803f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.16f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.803f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.16f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.227f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.227f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.16f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.815f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.18f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));
    glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.247f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));

    glEnd();

    // glBegin(GL_QUADS);

    // glColor3f(0.1f, 0.1f, 0.1f);

    // // glColor3f(1.0f, 1.0f, 1.0f);
    // glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.17f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.860f), SR_percent));
    // // glColor3f(1.0f, 0.0f, 0.0f);
    // glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.237f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.860f), SR_percent));
    // // glColor3f(0.0f, 1.0f, 0.0f);
    // glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.247f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));
    // // glColor3f(0.0f, 0.0f, 1.0f);
    // glVertex2f(SR_VALUE_FROM_PERCENT((SR_XPosition + 0.18f), SR_percent), SR_VALUE_FROM_PERCENT((SR_YPosition - 1.900f), SR_percent));

    // glEnd();

    // LEGS ENDS HERE //
}

void callDhwajGhetlelWarkari()
{
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

    dhwajGhetlelaWarkari(SR_XPosition, SR_YPosition, SR_Height, SR_Width, SR_currentSwayOffset, SR_percent);
    dhwajGhetlelaWarkari(SR_XPosition + 1.8f, SR_YPosition - 0.16f, SR_Height, SR_Width, SR_currentSwayOffset, 55.0f);
}

void drawFlower(float radiusSize, float customX, float customY)
{
    glBegin(GL_TRIANGLE_FAN);

    float centerX = SR_VALUE_FROM_PERCENT(customX, SR_percent);
    float centerY = SR_VALUE_FROM_PERCENT(customY, SR_percent);
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

void VitthalTimer(int value)
{
    // Start fade out after 300 seconds
    FadeIn = false;
    FadeOut = true;
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

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1.0f, -0.985f);
    // glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-1.0f, -0.985f);

    glColor3f(0.498039, 0.333333, 0.278431);
    glVertex2f(-1.0f, -1.0f);
    // glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);

    glEnd();
}

// ground quad

// Harshal's code

void renderGroupPresents(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage)
{

    // R
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.50f, 0.0f);
    glVertex2f(PSH_X(-0.42f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.39f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.39f), PSH_Y(0.50f));
    glVertex2f(PSH_X(-0.42f), PSH_Y(0.50f));

    glVertex2f(PSH_X(-0.42f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(0.80f));
    glVertex2f(PSH_X(-0.42f), PSH_Y(0.80f));
    glVertex2f(PSH_X(-0.42f), PSH_Y(0.70f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(0.70f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(0.65f));
    glVertex2f(PSH_X(-0.42f), PSH_Y(0.65f));
    glVertex2f(PSH_X(-0.33f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(0.65f));
    glVertex2f(PSH_X(-0.33f), PSH_Y(0.65f));
    glVertex2f(PSH_X(-0.39f), PSH_Y(0.65f));
    glVertex2f(PSH_X(-0.36f), PSH_Y(0.65f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(0.50f));
    glVertex2f(PSH_X(-0.33f), PSH_Y(0.50f));
    glEnd();

    // E
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.60f, 0.0f);
    glVertex2f(PSH_X(-0.28f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.25f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.25f), PSH_Y(0.50f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(0.50f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.16f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.16f), PSH_Y(0.80f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(0.80f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(0.70f));
    glVertex2f(PSH_X(-0.18f), PSH_Y(0.70f));
    glVertex2f(PSH_X(-0.18f), PSH_Y(0.65f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(0.65f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(0.55f));
    glVertex2f(PSH_X(-0.16f), PSH_Y(0.55f));
    glVertex2f(PSH_X(-0.16f), PSH_Y(0.50f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(0.50f));
    glEnd();

    // N
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.40f, 0.0f);
    glVertex2f(PSH_X(-0.14f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.11f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.11f), PSH_Y(0.50f));
    glVertex2f(PSH_X(-0.14f), PSH_Y(0.50f));
    glVertex2f(PSH_X(-0.05f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.02f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.02f), PSH_Y(0.50f));
    glVertex2f(PSH_X(-0.05f), PSH_Y(0.50f));
    glVertex2f(PSH_X(-0.11f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.08f), PSH_Y(0.85f));
    glVertex2f(PSH_X(-0.05f), PSH_Y(0.50f));
    glVertex2f(PSH_X(-0.08f), PSH_Y(0.50f));
    glEnd();

    // D
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.70f, 0.0f);
    glVertex2f(PSH_X(0.00f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.03f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.03f), PSH_Y(0.50f));
    glVertex2f(PSH_X(0.00f), PSH_Y(0.50f));
    glVertex2f(PSH_X(0.00f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.09f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.09f), PSH_Y(0.80f));
    glVertex2f(PSH_X(0.00f), PSH_Y(0.80f));
    glVertex2f(PSH_X(0.00f), PSH_Y(0.55f));
    glVertex2f(PSH_X(0.09f), PSH_Y(0.55f));
    glVertex2f(PSH_X(0.09f), PSH_Y(0.50f));
    glVertex2f(PSH_X(0.00f), PSH_Y(0.50f));
    glVertex2f(PSH_X(0.09f), PSH_Y(0.80f));
    glVertex2f(PSH_X(0.12f), PSH_Y(0.80f));
    glVertex2f(PSH_X(0.12f), PSH_Y(0.55f));
    glVertex2f(PSH_X(0.09f), PSH_Y(0.55f));
    glEnd();

    // E
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.30f, 0.0f);
    glVertex2f(PSH_X(0.14f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.17f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.17f), PSH_Y(0.50f));
    glVertex2f(PSH_X(0.14f), PSH_Y(0.50f));
    glVertex2f(PSH_X(0.14f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.26f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.26f), PSH_Y(0.80f));
    glVertex2f(PSH_X(0.14f), PSH_Y(0.80f));
    glVertex2f(PSH_X(0.14f), PSH_Y(0.70f));
    glVertex2f(PSH_X(0.24f), PSH_Y(0.70f));
    glVertex2f(PSH_X(0.24f), PSH_Y(0.65f));
    glVertex2f(PSH_X(0.14f), PSH_Y(0.65f));
    glVertex2f(PSH_X(0.14f), PSH_Y(0.55f));
    glVertex2f(PSH_X(0.26f), PSH_Y(0.55f));
    glVertex2f(PSH_X(0.26f), PSH_Y(0.50f));
    glVertex2f(PSH_X(0.14f), PSH_Y(0.50f));
    glEnd();

    // R
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.80f, 0.0f);
    glVertex2f(PSH_X(0.28f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.31f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.31f), PSH_Y(0.50f));
    glVertex2f(PSH_X(0.28f), PSH_Y(0.50f));
    glVertex2f(PSH_X(0.28f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.40f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.40f), PSH_Y(0.80f));
    glVertex2f(PSH_X(0.28f), PSH_Y(0.80f));
    glVertex2f(PSH_X(0.28f), PSH_Y(0.70f));
    glVertex2f(PSH_X(0.40f), PSH_Y(0.70f));
    glVertex2f(PSH_X(0.40f), PSH_Y(0.65f));
    glVertex2f(PSH_X(0.28f), PSH_Y(0.65f));
    glVertex2f(PSH_X(0.37f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.40f), PSH_Y(0.85f));
    glVertex2f(PSH_X(0.40f), PSH_Y(0.65f));
    glVertex2f(PSH_X(0.37f), PSH_Y(0.65f));
    glVertex2f(PSH_X(0.31f), PSH_Y(0.65f));
    glVertex2f(PSH_X(0.34f), PSH_Y(0.65f));
    glVertex2f(PSH_X(0.40f), PSH_Y(0.50f));
    glVertex2f(PSH_X(0.37f), PSH_Y(0.50f));
    glEnd();

    // G
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.55f, 0.0f);
    glVertex2f(PSH_X(-0.35f), PSH_X(0.35f));
    glVertex2f(PSH_X(-0.23f), PSH_X(0.35f));
    glVertex2f(PSH_X(-0.23f), PSH_X(0.30f));
    glVertex2f(PSH_X(-0.35f), PSH_X(0.30f));
    glVertex2f(PSH_X(-0.35f), PSH_X(0.35f));
    glVertex2f(PSH_X(-0.32f), PSH_X(0.35f));
    glVertex2f(PSH_X(-0.32f), PSH_X(0.00f));
    glVertex2f(PSH_X(-0.35f), PSH_X(0.00f));
    glVertex2f(PSH_X(-0.35f), PSH_X(0.05f));
    glVertex2f(PSH_X(-0.23f), PSH_X(0.05f));
    glVertex2f(PSH_X(-0.23f), PSH_X(0.00f));
    glVertex2f(PSH_X(-0.35f), PSH_X(0.00f));
    glVertex2f(PSH_X(-0.26f), PSH_X(0.20f));
    glVertex2f(PSH_X(-0.23f), PSH_X(0.20f));
    glVertex2f(PSH_X(-0.23f), PSH_X(0.00f));
    glVertex2f(PSH_X(-0.26f), PSH_X(0.00f));
    glVertex2f(PSH_X(-0.27f), PSH_X(0.20f));
    glVertex2f(PSH_X(-0.23f), PSH_X(0.20f));
    glVertex2f(PSH_X(-0.23f), PSH_X(0.15f));
    glVertex2f(PSH_X(-0.27f), PSH_X(0.15f));
    glEnd();

    // R
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.45f, 0.0f);
    glVertex2f(PSH_X(-0.21f), PSH_Y(0.35f));
    glVertex2f(PSH_X(-0.18f), PSH_Y(0.35f));
    glVertex2f(PSH_X(-0.18f), PSH_Y(0.00f));
    glVertex2f(PSH_X(-0.21f), PSH_Y(0.00f));
    glVertex2f(PSH_X(-0.21f), PSH_Y(0.35f));
    glVertex2f(PSH_X(-0.09f), PSH_Y(0.35f));
    glVertex2f(PSH_X(-0.09f), PSH_Y(0.30f));
    glVertex2f(PSH_X(-0.21f), PSH_Y(0.30f));
    glVertex2f(PSH_X(-0.21f), PSH_Y(0.20f));
    glVertex2f(PSH_X(-0.09f), PSH_Y(0.20f));
    glVertex2f(PSH_X(-0.09f), PSH_Y(0.15f));
    glVertex2f(PSH_X(-0.21f), PSH_Y(0.15f));
    glVertex2f(PSH_X(-0.12f), PSH_Y(0.35f));
    glVertex2f(PSH_X(-0.09f), PSH_Y(0.35f));
    glVertex2f(PSH_X(-0.09f), PSH_Y(0.15f));
    glVertex2f(PSH_X(-0.12f), PSH_Y(0.15f));
    glVertex2f(PSH_X(-0.18f), PSH_Y(0.15f));
    glVertex2f(PSH_X(-0.15f), PSH_Y(0.15f));
    glVertex2f(PSH_X(-0.09f), PSH_Y(0.00f));
    glVertex2f(PSH_X(-0.12f), PSH_Y(0.00f));
    glEnd();

    // O
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.65f, 0.0f);
    glVertex2f(PSH_X(-0.07f), PSH_Y(0.35f));
    glVertex2f(PSH_X(-0.04f), PSH_Y(0.35f));
    glVertex2f(PSH_X(-0.04f), PSH_Y(0.00f));
    glVertex2f(PSH_X(-0.07f), PSH_Y(0.00f));
    glVertex2f(PSH_X(0.02f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.05f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.05f), PSH_Y(0.00f));
    glVertex2f(PSH_X(0.02f), PSH_Y(0.00f));
    glVertex2f(PSH_X(-0.07f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.05f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.05f), PSH_Y(0.30f));
    glVertex2f(PSH_X(-0.07f), PSH_Y(0.30f));
    glVertex2f(PSH_X(-0.07f), PSH_Y(0.05f));
    glVertex2f(PSH_X(0.05f), PSH_Y(0.05f));
    glVertex2f(PSH_X(0.05f), PSH_Y(0.00f));
    glVertex2f(PSH_X(-0.07f), PSH_Y(0.00f));
    glEnd();

    // U
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.35f, 0.0f);
    glVertex2f(PSH_X(0.07f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.10f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.10f), PSH_Y(0.00f));
    glVertex2f(PSH_X(0.07f), PSH_Y(0.00f));
    glVertex2f(PSH_X(0.16f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.19f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.19f), PSH_Y(0.00f));
    glVertex2f(PSH_X(0.16f), PSH_Y(0.00f));
    glVertex2f(PSH_X(0.07f), PSH_Y(0.05f));
    glVertex2f(PSH_X(0.19f), PSH_Y(0.05f));
    glVertex2f(PSH_X(0.19f), PSH_Y(0.00f));
    glVertex2f(PSH_X(0.07f), PSH_Y(0.00f));
    glEnd();

    // P
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.75f, 0.0f);
    glVertex2f(PSH_X(0.21f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.24f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.24f), PSH_Y(0.00f));
    glVertex2f(PSH_X(0.21f), PSH_Y(0.00f));
    glVertex2f(PSH_X(0.21f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.33f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.33f), PSH_Y(0.30f));
    glVertex2f(PSH_X(0.21f), PSH_Y(0.30f));
    glVertex2f(PSH_X(0.21f), PSH_Y(0.20f));
    glVertex2f(PSH_X(0.33f), PSH_Y(0.20f));
    glVertex2f(PSH_X(0.33f), PSH_Y(0.15f));
    glVertex2f(PSH_X(0.21f), PSH_Y(0.15f));
    glVertex2f(PSH_X(0.30f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.33f), PSH_Y(0.35f));
    glVertex2f(PSH_X(0.33f), PSH_Y(0.15f));
    glVertex2f(PSH_X(0.30f), PSH_Y(0.15f));
    glEnd();

    // P
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.25f, 0.0f);
    glVertex2f(PSH_X(-0.56f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.53f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.53f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.56f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.56f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.44f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.44f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(-0.56f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(-0.56f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(-0.44f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(-0.44f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.56f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.47f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.44f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.44f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.47f), PSH_Y(-0.35f));
    glEnd();

    // R
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.85f, 0.0f);
    glVertex2f(PSH_X(-0.42f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.39f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.39f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.42f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.42f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(-0.42f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(-0.42f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.42f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.33f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.33f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.39f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.36f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.30f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.33f), PSH_Y(-0.50f));
    glEnd();

    // E
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.50f, 0.0f);
    glVertex2f(PSH_X(-0.28f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.25f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.25f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.16f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.16f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(-0.18f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(-0.18f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(-0.45f));
    glVertex2f(PSH_X(-0.16f), PSH_Y(-0.45f));
    glVertex2f(PSH_X(-0.16f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.28f), PSH_Y(-0.50f));
    glEnd();

    // S
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.62f, 0.0f);
    glVertex2f(PSH_X(-0.14f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.02f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.02f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(-0.14f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(-0.14f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.11f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(-0.11f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.14f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.14f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(-0.02f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(-0.02f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.14f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.05f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.02f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(-0.02f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.05f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.14f), PSH_Y(-0.45f));
    glVertex2f(PSH_X(-0.02f), PSH_Y(-0.45f));
    glVertex2f(PSH_X(-0.02f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(-0.14f), PSH_Y(-0.50f));
    glEnd();

    // E
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.42f, 0.0f);
    glVertex2f(PSH_X(0.00f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.03f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.03f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.00f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.00f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.12f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.12f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(0.00f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(0.00f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(0.10f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(0.10f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(0.00f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(0.00f), PSH_Y(-0.45f));
    glVertex2f(PSH_X(0.12f), PSH_Y(-0.45f));
    glVertex2f(PSH_X(0.12f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.00f), PSH_Y(-0.50f));
    glEnd();

    // N
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.72f, 0.0f);
    glVertex2f(PSH_X(0.14f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.17f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.17f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.14f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.23f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.26f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.26f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.23f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.17f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.20f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.23f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.20f), PSH_Y(-0.50f));
    glEnd();

    // T
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.32f, 0.0f);
    glVertex2f(PSH_X(0.28f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.40f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.40f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(0.28f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(0.325f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.355f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.355f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.325f), PSH_Y(-0.50f));
    glEnd();

    // S
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.82f, 0.0f);
    glVertex2f(PSH_X(0.42f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.54f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.54f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(0.42f), PSH_Y(-0.20f));
    glVertex2f(PSH_X(0.42f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.45f), PSH_Y(-0.15f));
    glVertex2f(PSH_X(0.45f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(0.42f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(0.42f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(0.54f), PSH_Y(-0.30f));
    glVertex2f(PSH_X(0.54f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(0.42f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(0.51f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(0.54f), PSH_Y(-0.35f));
    glVertex2f(PSH_X(0.54f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.51f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.42f), PSH_Y(-0.45f));
    glVertex2f(PSH_X(0.54f), PSH_Y(-0.45f));
    glVertex2f(PSH_X(0.54f), PSH_Y(-0.50f));
    glVertex2f(PSH_X(0.42f), PSH_Y(-0.50f));
    glEnd();
}

void Tila(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage)
{
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

    glPointSize(5.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    glVertex2f(PSH_X(0.0f), PSH_Y(0.53f));
    glEnd();
}

// Harshal's code

// Shriniwas's code

void SJ_Chopdar()
{
    // Turban
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.8f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.8f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.7f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.7f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.85f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.8f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.7f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.85f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.8f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.7f, suj_percent), 0.0f);
    glEnd();

    // Face
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.70f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.70f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.50f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.03f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.45f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.03f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.45f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.50f, suj_percent), 0.0f);
    glEnd();

    // Ears
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.068f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.65f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.65f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.58f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.068f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.58f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.068f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.65f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.65f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.06f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.58f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.068f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.58f, suj_percent), 0.0f);
    glEnd();

    // Gandh
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.01f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.69f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.01f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.65f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.01f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.65f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.01f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.65f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.01f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.69f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.01f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.65f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.65f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.002f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.68f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.004f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.68f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.004f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.67f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.002f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.67f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.002f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.665f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.004f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.665f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.004f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.655f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.002f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.655f, suj_percent), 0.0f);
    glEnd();

    // Body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.1f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.45f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.1f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.45f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.35f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.35f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.1f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.45f, suj_percent), 0.0f);
    glEnd();

    // Neck
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.03f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.45f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.03f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.45f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.03f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.42f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.03f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.42f, suj_percent), 0.0f);
    glEnd();

    // collar
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.03f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.42f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.03f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.42f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.35f, suj_percent), 0.0f);
    glEnd();

    // Legs
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.14f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.02f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.7f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.14f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.7f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.14f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.14f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.7f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.02f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.7f, suj_percent), 0.0f);
    glEnd();

    // Foot
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.70f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.10f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.70f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.70f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.10f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.70f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), 0.0f);
    glEnd();

    // Dress Lines
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.84f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.45f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.35f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.35f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.75f, 0.75f, 0.75f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.35f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.09f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.09f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.09f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glEnd();

    // Left Hand
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.35f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.35f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), 0.0f);
    glEnd();

    // Right Hand
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.35f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.35f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.2f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), 0.0f);
    glEnd();

    // Right Hand Fingers
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.08f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.08f, suj_percent), 0.0f);
    glEnd();

    // Right Hand Thumb
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.01f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.01f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.22f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.21f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), 0.0f);
    glEnd();

    glLineWidth(0.05f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.17f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.17f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.08f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.08f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.19f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.19f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.08f, suj_percent), 0.0f);
    glEnd();

    // Arm Outlines
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.33f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.33f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glEnd();

    // Left Hand Thumb
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.01f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.03f, suj_percent), 0.0f);
    glEnd();

    // Stick
    glBegin(GL_QUADS);
    glColor3f(0.75f, 0.75f, 0.75f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.42f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.42f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.19f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.52f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.15f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.50f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.14f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.46f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.42f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.22f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.42f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.24f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.46f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.23f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.50f, suj_percent), 0.0f);
    glEnd();

    // Left Hand Fingers
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.85f, 0.70f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.206f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.0f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.206f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.08f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.08f, suj_percent), 0.0f);
    glEnd();

    glLineWidth(0.05f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.0f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.0f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.02f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.02f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.16f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.18f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.06f, suj_percent), 0.0f);
    glEnd();
}

// Shriniwas's code

// Yogesh's code

void drawQuad(float xP, float yP, float width, float height)
{
    float zP = 0.0f;
    glBegin(GL_QUADS);

    glVertex3f(YBG_X(xP), YBG_Y(yP), zP);
    glVertex3f(YBG_X((xP + width)), YBG_Y(yP), zP);
    glVertex3f(YBG_X((xP + width)), YBG_Y((yP - height)), zP);
    glVertex3f(YBG_X((xP)), YBG_Y((yP - height)), zP);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);

    glVertex3f(YBG_X(xP), YBG_Y(yP), zP);
    glVertex3f(YBG_X((xP + width)), YBG_Y(yP), zP);
    glVertex3f(YBG_X((xP + width)), YBG_Y((yP - height)), zP);
    glVertex3f(YBG_X((xP)), YBG_Y((yP - height)), zP);

    glEnd();
}

void drawHalfCircle(float cx, float cy, float r, int segments)
{
    float angle;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center point
    for (int i = 0; i <= segments; i++)
    {
        angle = PI + (PI * i / segments);
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();

    // Border (outline)
    glColor3f(0.0f, 0.0f, 0.0f); // Border color
    glLineWidth(3.0f);           // Border thickness
    glBegin(GL_LINE_STRIP);      // Outline mode
    for (int i = 0; i <= segments; i++)
    {
        angle = PI + (PI * i / segments);
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

void drawCirlce(float cx, float cy, float r, int segment)
{
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(cx, cy, 0.0f);
    for (int i = 0; i < segment; i++)
    {
        float theta = 2.0f * PI * i / segment;
        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex3f(cx + x, cy + y, 0.0f);
    }
    glEnd();
    glDisable(GL_POINT_SMOOTH);
}

void yg_Veena_Warkari()
{

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);

    glVertex3f(YBG_X(-0.10f), YBG_Y(0.40f), 0.0f); // top body
    glVertex3f(YBG_X(0.10f), YBG_Y(0.40f), 0.0f);

    glVertex3f(YBG_X(-0.10f), YBG_Y(0.40f), 0.0f); // left hand side
    glVertex3f(YBG_X(-0.17f), YBG_Y(0.32f), 0.0f);
    glVertex3f(YBG_X(-0.17f), YBG_Y(0.23f), 0.0f);
    glVertex3f(YBG_X(-0.13f), YBG_Y(0.27f), 0.0f);
    glVertex3f(YBG_X(-0.19f), YBG_Y(0.21f), 0.0f);
    glVertex3f(YBG_X(-0.19f), YBG_Y(0.15f), 0.0f);
    glVertex3f(YBG_X(-0.16f), YBG_Y(0.15f), 0.0f);
    glVertex3f(YBG_X(-0.13f), YBG_Y(0.19f), 0.0f);

    glVertex3f(YBG_X(-0.13f), YBG_Y(0.00f), 0.0f); // bottom body
    glVertex3f(YBG_X(0.15f), YBG_Y(0.00f), 0.0f);
    glVertex3f(YBG_X(0.15f), YBG_Y(0.11f), 0.0f);

    glVertex3f(YBG_X(0.10f), YBG_Y(0.40f), 0.0f); // right hand side
    glVertex3f(YBG_X(0.17f), YBG_Y(0.32f), 0.0f);
    glVertex3f(YBG_X(0.17f), YBG_Y(0.15f), 0.0f);
    glVertex3f(YBG_X(0.10f), YBG_Y(0.05f), 0.0f);
    glVertex3f(YBG_X(0.03f), YBG_Y(0.05f), 0.0f);
    glVertex3f(YBG_X(0.11f), YBG_Y(0.16f), 0.0f);
    glVertex3f(YBG_X(0.11f), YBG_Y(0.28f), 0.0f);

    glEnd();

    // Border (black)
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
    glVertex3f(YBG_X(-0.10f), YBG_Y(0.40f), 0.0f); // top body
    glVertex3f(YBG_X(0.10f), YBG_Y(0.40f), 0.0f);

    glVertex3f(YBG_X(-0.10f), YBG_Y(0.40f), 0.0f); // left hand side
    glVertex3f(YBG_X(-0.17f), YBG_Y(0.32f), 0.0f);
    glVertex3f(YBG_X(-0.17f), YBG_Y(0.23f), 0.0f);
    glVertex3f(YBG_X(-0.13f), YBG_Y(0.27f), 0.0f);
    glVertex3f(YBG_X(-0.19f), YBG_Y(0.21f), 0.0f);
    glVertex3f(YBG_X(-0.19f), YBG_Y(0.15f), 0.0f);
    glVertex3f(YBG_X(-0.16f), YBG_Y(0.15f), 0.0f);
    glVertex3f(YBG_X(-0.13f), YBG_Y(0.19f), 0.0f);

    glVertex3f(YBG_X(-0.13f), YBG_Y(0.00f), 0.0f); // bottom body
    glVertex3f(YBG_X(0.15f), YBG_Y(0.00f), 0.0f);
    glVertex3f(YBG_X(0.15f), YBG_Y(0.11f), 0.0f);

    glVertex3f(YBG_X(0.10f), YBG_Y(0.40f), 0.0f); // right hand side
    glVertex3f(YBG_X(0.17f), YBG_Y(0.32f), 0.0f);
    glVertex3f(YBG_X(0.17f), YBG_Y(0.15f), 0.0f);
    glVertex3f(YBG_X(0.10f), YBG_Y(0.05f), 0.0f);
    glVertex3f(YBG_X(0.03f), YBG_Y(0.05f), 0.0f);
    glVertex3f(YBG_X(0.11f), YBG_Y(0.16f), 0.0f);
    glVertex3f(YBG_X(0.11f), YBG_Y(0.28f), 0.0f);

    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // legs
    glBegin(GL_QUADS);

    glVertex3f(YBG_X(-0.14f), YBG_Y(0.0f), 0.0f); // left
    glVertex3f(YBG_X(-0.14f), YBG_Y(-0.40f), 0.0f);
    glVertex3f(YBG_X(-0.04f), YBG_Y(-0.40f), 0.0f);
    glVertex3f(YBG_X(0.0f), YBG_Y(0.0f), 0.0f);

    glVertex3f(YBG_X(0.00f), YBG_Y(0.0f), 0.0f); // right
    glVertex3f(YBG_X(0.04f), YBG_Y(-0.40f), 0.0f);
    glVertex3f(YBG_X(0.14f), YBG_Y(-0.40f), 0.0f);
    glVertex3f(YBG_X(0.14f), YBG_Y(0.0f), 0.0f);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // legs border
    glLineWidth(2.0f);
    glBegin(GL_LINES);

    glVertex3f(YBG_X(-0.14f), YBG_Y(0.0f), 0.0f);
    glVertex3f(YBG_X(-0.14f), YBG_Y(-0.40f), 0.0f);
    glVertex3f(YBG_X(-0.04f), YBG_Y(-0.40f), 0.0f);
    glVertex3f(YBG_X(0.0f), YBG_Y(0.0f), 0.0f);

    glVertex3f(YBG_X(0.00f), YBG_Y(0.0f), 0.0f);
    glVertex3f(YBG_X(0.04f), YBG_Y(-0.40f), 0.0f);
    glVertex3f(YBG_X(0.14f), YBG_Y(-0.40f), 0.0f);
    glVertex3f(YBG_X(0.14f), YBG_Y(0.0f), 0.0f);

    glEnd();

    glColor3f(0.878f, 0.674f, 0.411f); // left leg skin
    glBegin(GL_QUADS);
    glVertex3f(YBG_X(-0.11f), YBG_Y(-0.40f), 0.0f);
    glVertex3f(YBG_X(-0.15f), YBG_Y(-0.46f), 0.0f);
    glVertex3f(YBG_X(-0.06f), YBG_Y(-0.46f), 0.0f);
    glVertex3f(YBG_X(-0.06f), YBG_Y(-0.40f), 0.0f);

    glVertex3f(YBG_X(0.11f), YBG_Y(-0.40f), 0.0f); // Right leg skin
    glVertex3f(YBG_X(0.15f), YBG_Y(-0.46f), 0.0f);
    glVertex3f(YBG_X(0.06f), YBG_Y(-0.46f), 0.0f);
    glVertex3f(YBG_X(0.06f), YBG_Y(-0.40f), 0.0f);
    glEnd();

    glColor3f(0.878f, 0.674f, 0.411f); // Head
    drawQuad(-0.05f, 0.75f, 0.10f, 0.25f);

    glColor3f(1.0f, 0.55f, 0.0f); // Cap
    glBegin(GL_POLYGON);
    glVertex3f(YBG_X(-0.04f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(0.04f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(0.07f), YBG_Y(0.74f), 0.0f);
    glVertex3f(YBG_X(0.07f), YBG_Y(0.63f), 0.0f);
    glVertex3f(YBG_X(0.00f), YBG_Y(0.70f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.63f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.74f), 0.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // cap lines
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.72f), 0.0f);
    glVertex3f(YBG_X(-0.02f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.70f), 0.0f);
    glVertex3f(YBG_X(0.00f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.68f), 0.0f);
    glVertex3f(YBG_X(0.02f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.66f), 0.0f);
    glVertex3f(YBG_X(0.04f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(0.00f), YBG_Y(0.70f), 0.0f);
    glVertex3f(YBG_X(0.055f), YBG_Y(0.76f), 0.0f);

    glVertex3f(YBG_X(0.07f), YBG_Y(0.72f), 0.0f);
    glVertex3f(YBG_X(0.04f), YBG_Y(0.75f), 0.0f);
    glVertex3f(YBG_X(0.07f), YBG_Y(0.70f), 0.0f);
    glVertex3f(YBG_X(0.03f), YBG_Y(0.73f), 0.0f);
    glVertex3f(YBG_X(0.07f), YBG_Y(0.67f), 0.0f);
    glVertex3f(YBG_X(0.01f), YBG_Y(0.715f), 0.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // cap border
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(YBG_X(-0.04f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(0.04f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(0.07f), YBG_Y(0.74f), 0.0f);
    glVertex3f(YBG_X(0.07f), YBG_Y(0.63f), 0.0f);
    glVertex3f(YBG_X(0.00f), YBG_Y(0.70f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.63f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.74f), 0.0f);

    glEnd();

    glColor3f(0.878f, 0.674f, 0.411f); // Neck
    glLineWidth(2.0f);
    glBegin(GL_QUAD_STRIP);

    glVertex3f(YBG_X(-0.03f), YBG_Y(0.47f), 0.0f);
    glVertex3f(YBG_X(-0.03f), YBG_Y(0.405f), 0.0f);
    glVertex3f(YBG_X(0.03f), YBG_Y(0.47f), 0.0f);
    glVertex3f(YBG_X(0.03f), YBG_Y(0.405f), 0.0f);
    glVertex3f(YBG_X(-0.03f), YBG_Y(0.03f), 0.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // neck border
    glLineWidth(2.0f);
    glBegin(GL_LINES); // Line

    glVertex3f(YBG_X(-0.03f), YBG_Y(0.47f), 0.0f);
    glVertex3f(YBG_X(-0.03f), YBG_Y(0.405f), 0.0f);
    glVertex3f(YBG_X(0.03f), YBG_Y(0.47f), 0.0f);
    glVertex3f(YBG_X(0.03f), YBG_Y(0.405f), 0.0f);
    glEnd();

    glColor3f(0.878f, 0.674f, 0.411f); // Neck
    drawHalfCircle(YBG_X(0.0f), YBG_Y(0.51f), YBG_SCALE_RADIUS(0.05f, YBG_percent), 500);

    glColor3f(0.878f, 0.674f, 0.411f);
    drawHalfCircle(YBG_X(0.0f), YBG_Y(0.405f), YBG_SCALE_RADIUS(0.03f, YBG_percent), 500); // neck end

    glColor3f(0.5f, 0.25f, 0.0f); // Veena
    glBegin(GL_POLYGON);

    glVertex3f(YBG_X(-0.06f), YBG_Y(0.13f), 0.0f);
    glVertex3f(YBG_X(-0.01f), YBG_Y(0.08f), 0.0f);
    glVertex3f(YBG_X(-0.01f), YBG_Y(-0.02f), 0.0f);
    glVertex3f(YBG_X(-0.06f), YBG_Y(-0.07f), 0.0f);
    glVertex3f(YBG_X(-0.14f), YBG_Y(-0.07f), 0.0f);
    glVertex3f(YBG_X(-0.19f), YBG_Y(-0.02f), 0.0f);
    glVertex3f(YBG_X(-0.19f), YBG_Y(0.08f), 0.0f);
    glVertex3f(YBG_X(-0.14f), YBG_Y(0.13f), 0.0f);
    glVertex3f(YBG_X(-0.06f), YBG_Y(0.13f), 0.0f);
    glEnd();

    drawQuad(-0.13f, 0.78f, 0.06f, 0.65f);

    glColor3f(0.0f, 0.0f, 0.0f); // Veena Border
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);

    glVertex3f(YBG_X(-0.06f), YBG_Y(0.13f), 0.0f);
    glVertex3f(YBG_X(-0.01f), YBG_Y(0.08f), 0.0f);
    glVertex3f(YBG_X(-0.01f), YBG_Y(-0.02f), 0.0f);
    glVertex3f(YBG_X(-0.06f), YBG_Y(-0.07f), 0.0f);
    glVertex3f(YBG_X(-0.14f), YBG_Y(-0.07f), 0.0f);
    glVertex3f(YBG_X(-0.19f), YBG_Y(-0.02f), 0.0f);
    glVertex3f(YBG_X(-0.19f), YBG_Y(0.08f), 0.0f);
    glVertex3f(YBG_X(-0.14f), YBG_Y(0.13f), 0.0f);
    glVertex3f(YBG_X(-0.06f), YBG_Y(0.13f), 0.0f);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Veena vertical line
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(YBG_X(-0.11f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(-0.11f), YBG_Y(-0.07f), 0.0f);
    glVertex3f(YBG_X(-0.10f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(-0.10f), YBG_Y(-0.07f), 0.0f);
    glVertex3f(YBG_X(-0.09f), YBG_Y(0.78f), 0.0f);
    glVertex3f(YBG_X(-0.09f), YBG_Y(-0.07f), 0.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Veena Inner Border
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);

    glVertex3f(YBG_X(-0.07f), YBG_Y(0.12f), 0.0f);
    glVertex3f(YBG_X(-0.02f), YBG_Y(0.07f), 0.0f);
    glVertex3f(YBG_X(-0.02f), YBG_Y(-0.03f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(-0.06f), 0.0f);
    glVertex3f(YBG_X(-0.13f), YBG_Y(-0.06f), 0.0f);
    glVertex3f(YBG_X(-0.18f), YBG_Y(-0.01f), 0.0f);
    glVertex3f(YBG_X(-0.18f), YBG_Y(0.07f), 0.0f);
    glVertex3f(YBG_X(-0.13f), YBG_Y(0.12f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.12f), 0.0f);

    glEnd();

    glColor3f(0.878f, 0.674f, 0.411f); // Right hand  skin
    glBegin(GL_POLYGON);
    glVertex3f(YBG_X(0.03f), YBG_Y(0.05f), 0.0f);
    glVertex3f(YBG_X(-0.02f), YBG_Y(0.05f), 0.0f);
    glVertex3f(YBG_X(-0.04f), YBG_Y(0.02f), 0.0f);
    glVertex3f(YBG_X(-0.01f), YBG_Y(0.02f), 0.0f);
    glVertex3f(YBG_X(-0.05f), YBG_Y(-0.04f), 0.0f);
    glVertex3f(YBG_X(0.00f), YBG_Y(-0.04f), 0.0f);
    glVertex3f(YBG_X(0.08f), YBG_Y(0.05f), 0.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Right hand  skin border
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
    glVertex3f(YBG_X(0.03f), YBG_Y(0.05f), 0.0f);
    glVertex3f(YBG_X(-0.02f), YBG_Y(0.05f), 0.0f);
    glVertex3f(YBG_X(-0.04f), YBG_Y(0.02f), 0.0f);
    glVertex3f(YBG_X(-0.01f), YBG_Y(0.02f), 0.0f);
    glVertex3f(YBG_X(-0.05f), YBG_Y(-0.04f), 0.0f);
    glVertex3f(YBG_X(0.00f), YBG_Y(-0.04f), 0.0f);
    glVertex3f(YBG_X(0.08f), YBG_Y(0.05f), 0.0f);
    glEnd();

    glColor3f(0.878f, 0.674f, 0.411f); // left hand  skin
    glBegin(GL_POLYGON);

    glVertex3f(YBG_X(-0.14f), YBG_Y(0.19f), 0.0f);
    glVertex3f(YBG_X(-0.14f), YBG_Y(0.27f), 0.0f);
    glVertex3f(YBG_X(-0.13f), YBG_Y(0.29f), 0.0f);
    glVertex3f(YBG_X(-0.13f), YBG_Y(0.26f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.32f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.25f), 0.0f);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // left hand  skin border
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);

    glVertex3f(YBG_X(-0.14f), YBG_Y(0.19f), 0.0f);
    glVertex3f(YBG_X(-0.14f), YBG_Y(0.27f), 0.0f);
    glVertex3f(YBG_X(-0.13f), YBG_Y(0.29f), 0.0f);
    glVertex3f(YBG_X(-0.13f), YBG_Y(0.26f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.32f), 0.0f);
    glVertex3f(YBG_X(-0.07f), YBG_Y(0.25f), 0.0f);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Tila black
    drawCirlce(YBG_X(0.0f), YBG_Y(0.66f), YBG_SCALE_RADIUS(0.013f, YBG_percent), 500);

    glColor3f(1.0f, 0.0f, 0.0f); // Tila red
    drawCirlce(YBG_X(0.0f), YBG_Y(0.64f), YBG_SCALE_RADIUS(0.012f, YBG_percent), 500);
}

// Yogesh's code

// Project Name code

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

// Project Name code

// Pranalis ghoda code

void psh_draw_ghoda(float psh_x_pos, float psh_y_pos, int psh_width_percentage, int psh_height_percentage)
{

    // Head
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(-0.8f), PSH_Y(0.45f), 0.0f);
    glVertex3f(PSH_X(-0.8f), PSH_Y(0.1f), 0.0f);
    glVertex3f(PSH_X(-0.7f), PSH_Y(0.0f), 0.0f);
    glVertex3f(PSH_X(-0.63f), PSH_Y(0.07f), 0.0f);
    glVertex3f(PSH_X(-0.63f), PSH_Y(0.12f), 0.0f);
    glVertex3f(PSH_X(-0.61f), PSH_Y(0.135f), 0.0f);
    glVertex3f(PSH_X(-0.26f), PSH_Y(0.15f), 0.0f);
    glVertex3f(PSH_X(-0.52f), PSH_Y(0.05f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.05f), 0.0f);
    glVertex3f(PSH_X(-0.3f), PSH_Y(-0.05f), 0.0f);
    glVertex3f(PSH_X(-0.25f), PSH_Y(0.015f), 0.0f);
    glVertex3f(PSH_X(-0.25f), PSH_Y(0.25f), 0.0f);
    glVertex3f(PSH_X(-0.45f), PSH_Y(0.52f), 0.0f);
    glVertex3f(PSH_X(-0.72f), PSH_Y(0.52f), 0.0f);

    glEnd();

    // Face Design

    glColor3f(0.87f, 0.61f, 0.16f);
    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.8f), PSH_Y(0.45f), 0.0f);
    glVertex3f(PSH_X(-0.72f), PSH_Y(0.43f), 0.0f);
    glVertex3f(PSH_X(-0.72f), PSH_Y(0.2f), 0.0f);
    glVertex3f(PSH_X(-0.8f), PSH_Y(0.2f), 0.0f);

    glEnd();

    glColor3f(0.57f, 0.05f, 0.02f);
    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.8f), PSH_Y(0.45f), 0.0f);
    glVertex3f(PSH_X(-0.75f), PSH_Y(0.4f), 0.0f);
    glVertex3f(PSH_X(-0.75f), PSH_Y(0.23f), 0.0f);
    glVertex3f(PSH_X(-0.8f), PSH_Y(0.23f), 0.0f);

    glEnd();

    // Kaan
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(-0.7f), PSH_Y(0.52f), 0.0f);
    glVertex3f(PSH_X(-0.77f), PSH_Y(0.63f), 0.0f);
    glVertex3f(PSH_X(-0.77f), PSH_Y(0.75f), 0.0f);
    glVertex3f(PSH_X(-0.67f), PSH_Y(0.63f), 0.0f);
    glVertex3f(PSH_X(-0.67f), PSH_Y(0.52f), 0.0f);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(-0.77f), PSH_Y(0.53f), 0.0f);
    glVertex3f(PSH_X(-0.82f), PSH_Y(0.53f), 0.0f);
    glVertex3f(PSH_X(-0.92f), PSH_Y(0.62f), 0.0f);
    glVertex3f(PSH_X(-0.8f), PSH_Y(0.62f), 0.0f);
    glVertex3f(PSH_X(-0.75f), PSH_Y(0.55f), 0.0f);

    glEnd();

    // Above Head design
    glColor3f(0.64f, 0.63f, 0.61f);
    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(-0.85f), PSH_Y(0.41f), 0.0f);
    glVertex3f(PSH_X(-0.85f), PSH_Y(0.46f), 0.0f);
    glVertex3f(PSH_X(-0.73f), PSH_Y(0.57f), 0.0f);
    glVertex3f(PSH_X(-0.7f), PSH_Y(0.52f), 0.0f);
    glVertex3f(PSH_X(-0.72f), PSH_Y(0.52f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.67f), PSH_Y(0.52f), 0.0f);
    glVertex3f(PSH_X(-0.67f), PSH_Y(0.57f), 0.0f);
    glVertex3f(PSH_X(-0.43f), PSH_Y(0.57f), 0.0f);
    glVertex3f(PSH_X(-0.45f), PSH_Y(0.52f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.45f), PSH_Y(0.52f), 0.0f);
    glVertex3f(PSH_X(-0.43f), PSH_Y(0.57f), 0.0f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(0.27f), 0.0f);
    glVertex3f(PSH_X(-0.25f), PSH_Y(0.25f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.25f), PSH_Y(0.25f), 0.0f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(0.27f), 0.0f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(0.09f), 0.0f);
    glVertex3f(PSH_X(-0.25f), PSH_Y(0.01f), 0.0f);

    glEnd();

    // Tail
    glColor3f(0.64f, 0.63f, 0.61f);
    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(0.53f), PSH_Y(0.03f), 0.0f);
    glVertex3f(PSH_X(0.59f), PSH_Y(0.03f), 0.0f);
    glVertex3f(PSH_X(0.65f), PSH_Y(0.1f), 0.0f);
    glVertex3f(PSH_X(0.9f), PSH_Y(0.1f), 0.0f);
    glVertex3f(PSH_X(1.0f), PSH_Y(0.0f), 0.0f);
    glVertex3f(PSH_X(1.0f), PSH_Y(-0.2f), 0.0f);
    glVertex3f(PSH_X(0.9f), PSH_Y(-0.6f), 0.0f);
    glVertex3f(PSH_X(0.75f), PSH_Y(-0.3f), 0.0f);
    glVertex3f(PSH_X(0.85f), PSH_Y(-0.2f), 0.0f);
    glVertex3f(PSH_X(0.85f), PSH_Y(-0.1f), 0.0f);
    glVertex3f(PSH_X(0.8f), PSH_Y(-0.05f), 0.0f);
    glVertex3f(PSH_X(0.7f), PSH_Y(-0.05f), 0.0f);
    glVertex3f(PSH_X(0.65f), PSH_Y(-0.1f), 0.0f);

    glEnd();

    // Stomatch
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(-0.17f), PSH_Y(0.09f), 0.0f);
    glVertex3f(PSH_X(-0.14f), PSH_Y(0.065f), 0.0f);
    glVertex3f(PSH_X(0.5f), PSH_Y(0.065f), 0.0f);
    glVertex3f(PSH_X(0.7f), PSH_Y(-0.15f), 0.0f);
    glVertex3f(PSH_X(0.7f), PSH_Y(-0.4f), 0.0f);
    glVertex3f(PSH_X(0.59f), PSH_Y(-0.5f), 0.0f);
    glVertex3f(PSH_X(0.43f), PSH_Y(-0.6f), 0.0f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(-0.6f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.3f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.07f), 0.0f);

    glEnd();

    // Belts
    glColor3f(0.3f, 0.16f, 0.03f);
    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.2f), PSH_Y(0.17f), 0.0f);
    glVertex3f(PSH_X(-0.17f), PSH_Y(0.15f), 0.0f);
    glVertex3f(PSH_X(-0.17f), PSH_Y(0.09f), 0.0f);
    glVertex3f(PSH_X(-0.2f), PSH_Y(0.08f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.215f), PSH_Y(0.08f), 0.0f);
    glVertex3f(PSH_X(-0.17f), PSH_Y(0.09f), 0.0f);
    glVertex3f(PSH_X(-0.28f), PSH_Y(-0.07f), 0.0f);
    glVertex3f(PSH_X(-0.3f), PSH_Y(-0.05f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.3f), PSH_Y(-0.04f), 0.0f);
    glVertex3f(PSH_X(-0.28f), PSH_Y(-0.07f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.04f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.07f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.04f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.07f), 0.0f);
    glVertex3f(PSH_X(-0.7f), PSH_Y(0.07f), 0.0f);
    glVertex3f(PSH_X(-0.69f), PSH_Y(0.09f), 0.0f);

    glEnd();

    // Legs

    // First Leg

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.39f), PSH_Y(-0.41f), 0.0f);
    glVertex3f(PSH_X(-0.6f), PSH_Y(-0.65f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.65f), 0.0f);
    glVertex3f(PSH_X(-0.245f), PSH_Y(-0.53f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.6f), PSH_Y(-0.65f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.65f), 0.0f);
    glVertex3f(PSH_X(-0.4f), PSH_Y(-0.8f), 0.0f);
    glVertex3f(PSH_X(-0.45f), PSH_Y(-0.83f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.45f), PSH_Y(-0.83f), 0.0f);
    glVertex3f(PSH_X(-0.4f), PSH_Y(-0.8f), 0.0f);
    glVertex3f(PSH_X(-0.35f), PSH_Y(-0.8f), 0.0f);
    glVertex3f(PSH_X(-0.45f), PSH_Y(-0.88f), 0.0f);

    glEnd();

    // Second Leg

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.28f), PSH_Y(-0.51f), 0.0f);
    glVertex3f(PSH_X(-0.18f), PSH_Y(-0.6f), 0.0f);
    glVertex3f(PSH_X(-0.27f), PSH_Y(-0.93f), 0.0f);
    glVertex3f(PSH_X(-0.33f), PSH_Y(-0.9f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.33f), PSH_Y(-0.9f), 0.0f);
    glVertex3f(PSH_X(-0.27f), PSH_Y(-0.93f), 0.0f);
    glVertex3f(PSH_X(-0.26f), PSH_Y(-0.97f), 0.0f);
    glVertex3f(PSH_X(-0.37f), PSH_Y(-0.97f), 0.0f);

    glEnd();

    // Third Leg

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.41f), PSH_Y(-0.50f), 0.0f);
    glVertex3f(PSH_X(0.53f), PSH_Y(-0.59f), 0.0f);
    glVertex3f(PSH_X(0.5f), PSH_Y(-0.67f), 0.0f);
    glVertex3f(PSH_X(0.4f), PSH_Y(-0.65f), 0.0f);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(PSH_X(0.4f), PSH_Y(-0.65f), 0.0f);
    glVertex3f(PSH_X(0.33f), PSH_Y(-0.97f), 0.0f);
    glVertex3f(PSH_X(0.43f), PSH_Y(-0.97f), 0.0f);
    glVertex3f(PSH_X(0.41f), PSH_Y(-0.95f), 0.0f);
    glVertex3f(PSH_X(0.53f), PSH_Y(-0.59f), 0.0f);

    glEnd();

    // Fourth Leg

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.4f), PSH_Y(-0.5f), 0.0f);
    glVertex3f(PSH_X(0.59f), PSH_Y(-0.5f), 0.0f);
    glVertex3f(PSH_X(0.63f), PSH_Y(-0.55f), 0.0f);
    glVertex3f(PSH_X(0.55f), PSH_Y(-0.61f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.55f), PSH_Y(-0.61f), 0.0f);
    glVertex3f(PSH_X(0.63f), PSH_Y(-0.55f), 0.0f);
    glVertex3f(PSH_X(0.63f), PSH_Y(-0.93f), 0.0f);
    glVertex3f(PSH_X(0.55f), PSH_Y(-0.93f), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(0.55f), PSH_Y(-0.93f), 0.0f);
    glVertex3f(PSH_X(0.63f), PSH_Y(-0.93f), 0.0f);
    glVertex3f(PSH_X(0.65f), PSH_Y(-0.97f), 0.0f);
    glVertex3f(PSH_X(0.53f), PSH_Y(-0.97f), 0.0f);

    glEnd();

    // Neck Design

    glColor3f(0.87f, 0.61f, 0.16f);

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.4f), PSH_Y(-0.43f), 0.0f);
    glVertex3f(PSH_X(-0.48f), PSH_Y(-0.37f), 0.0f);
    glVertex3f(PSH_X(-0.17f), PSH_Y(0.12f), 0.0f);
    glVertex3f(PSH_X(-0.1f), PSH_Y(0.04f), 0.0f);

    glEnd();

    // Design Above Stomatch

    glColor3f(0.57f, 0.05f, 0.02f);

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.15f), PSH_Y(0.09f), 0.0f);
    glVertex3f(PSH_X(-0.15f), PSH_Y(-0.35f), 0.0f);
    glVertex3f(PSH_X(0.47f), PSH_Y(-0.35f), 0.0f);
    glVertex3f(PSH_X(0.47f), PSH_Y(0.08f), 0.0f);

    glEnd();

    glColor3f(0.87f, 0.61f, 0.16f);

    glBegin(GL_QUADS);

    glVertex3f(PSH_X(-0.05f), PSH_Y(0.09f), 0.0f);
    glVertex3f(PSH_X(-0.05f), PSH_Y(-0.25f), 0.0f);
    glVertex3f(PSH_X(0.37f), PSH_Y(-0.25f), 0.0f);
    glVertex3f(PSH_X(0.37f), PSH_Y(0.08f), 0.0f);

    glEnd();

    // Border
    glColor3f(0.28f, 0.28f, 0.28f);
    glLineWidth(1.0f);
    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.8f), PSH_Y(0.45f), 0.0f);
    glVertex3f(PSH_X(-0.8f), PSH_Y(0.1f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.8f), PSH_Y(0.1f), 0.0f);
    glVertex3f(PSH_X(-0.7f), PSH_Y(0.0f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.7f), PSH_Y(0.0f), 0.0f);
    glVertex3f(PSH_X(-0.7f), PSH_Y(0.08f), 0.0f);

    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.78f), PSH_Y(0.08f), 0.0f);
    glVertex3f(PSH_X(-0.74f), PSH_Y(0.13f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.74f), PSH_Y(0.13f), 0.0f);
    glVertex3f(PSH_X(-0.76f), PSH_Y(0.15f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.76f), PSH_Y(0.15f), 0.0f);
    glVertex3f(PSH_X(-0.77f), PSH_Y(0.12f), 0.0f);

    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.7f), PSH_Y(0.0f), 0.0f);
    glVertex3f(PSH_X(-0.63f), PSH_Y(0.07f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.63f), PSH_Y(0.07f), 0.0f);
    glVertex3f(PSH_X(-0.63f), PSH_Y(0.12f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.63f), PSH_Y(0.12f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(0.25f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.5f), PSH_Y(0.25f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(0.35f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.61f), PSH_Y(0.135f), 0.0f);
    glVertex3f(PSH_X(-0.52f), PSH_Y(-0.018f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.07f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.3f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.3f), 0.0f);
    glVertex3f(PSH_X(-0.46f), PSH_Y(-0.34f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.46f), PSH_Y(-0.34f), 0.0f);
    glVertex3f(PSH_X(-0.475f), PSH_Y(-0.37f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.475f), PSH_Y(-0.37f), 0.0f);
    glVertex3f(PSH_X(-0.385f), PSH_Y(-0.435f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.39f), PSH_Y(-0.42f), 0.0f);
    glVertex3f(PSH_X(-0.6f), PSH_Y(-0.65f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.6f), PSH_Y(-0.65f), 0.0f);
    glVertex3f(PSH_X(-0.45f), PSH_Y(-0.83f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.45f), PSH_Y(-0.83f), 0.0f);
    glVertex3f(PSH_X(-0.45f), PSH_Y(-0.88f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.45f), PSH_Y(-0.88f), 0.0f);
    glVertex3f(PSH_X(-0.35f), PSH_Y(-0.8f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.35f), PSH_Y(-0.8f), 0.0f);
    glVertex3f(PSH_X(-0.4f), PSH_Y(-0.8f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.4f), PSH_Y(-0.8f), 0.0f);
    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.65f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.5f), PSH_Y(-0.65f), 0.0f);
    glVertex3f(PSH_X(-0.29f), PSH_Y(-0.54f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.285f), PSH_Y(-0.51f), 0.0f);
    glVertex3f(PSH_X(-0.34f), PSH_Y(-0.92f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.33f), PSH_Y(-0.9f), 0.0f);
    glVertex3f(PSH_X(-0.37f), PSH_Y(-0.97f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.37f), PSH_Y(-0.97f), 0.0f);
    glVertex3f(PSH_X(-0.26f), PSH_Y(-0.97f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.26f), PSH_Y(-0.97f), 0.0f);
    glVertex3f(PSH_X(-0.27f), PSH_Y(-0.93f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.27f), PSH_Y(-0.93f), 0.0f);
    glVertex3f(PSH_X(-0.185f), PSH_Y(-0.6f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.185f), PSH_Y(-0.6f), 0.0f);
    glVertex3f(PSH_X(0.41f), PSH_Y(-0.6f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.43f), PSH_Y(-0.6f), 0.0f);
    glVertex3f(PSH_X(0.41f), PSH_Y(-0.50f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.415f), PSH_Y(-0.55f), 0.0f);
    glVertex3f(PSH_X(0.33f), PSH_Y(-0.97f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.33f), PSH_Y(-0.97f), 0.0f);
    glVertex3f(PSH_X(0.43f), PSH_Y(-0.97f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.43f), PSH_Y(-0.97f), 0.0f);
    glVertex3f(PSH_X(0.42f), PSH_Y(-0.93f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.42f), PSH_Y(-0.93f), 0.0f);
    glVertex3f(PSH_X(0.53f), PSH_Y(-0.59f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.4f), PSH_Y(-0.5f), 0.0f);
    glVertex3f(PSH_X(0.55f), PSH_Y(-0.61f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.55f), PSH_Y(-0.61f), 0.0f);
    glVertex3f(PSH_X(0.55f), PSH_Y(-0.93f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.55f), PSH_Y(-0.93f), 0.0f);
    glVertex3f(PSH_X(0.53f), PSH_Y(-0.97f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.53f), PSH_Y(-0.97f), 0.0f);
    glVertex3f(PSH_X(0.65f), PSH_Y(-0.97f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.65f), PSH_Y(-0.97f), 0.0f);
    glVertex3f(PSH_X(0.63f), PSH_Y(-0.93f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.63f), PSH_Y(-0.93f), 0.0f);
    glVertex3f(PSH_X(0.63f), PSH_Y(-0.55f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.63f), PSH_Y(-0.55f), 0.0f);
    glVertex3f(PSH_X(0.59f), PSH_Y(-0.5f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.59f), PSH_Y(-0.5f), 0.0f);
    glVertex3f(PSH_X(0.7f), PSH_Y(-0.4f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.7f), PSH_Y(-0.4f), 0.0f);
    glVertex3f(PSH_X(0.7f), PSH_Y(-0.15f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.7f), PSH_Y(-0.15f), 0.0f);
    glVertex3f(PSH_X(0.5f), PSH_Y(0.065f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.5f), PSH_Y(0.065f), 0.0f);
    glVertex3f(PSH_X(0.47f), PSH_Y(0.065f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.53f), PSH_Y(0.03f), 0.0f);
    glVertex3f(PSH_X(0.65f), PSH_Y(0.1f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.65f), PSH_Y(0.1f), 0.0f);
    glVertex3f(PSH_X(0.9f), PSH_Y(0.1f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.9f), PSH_Y(0.1f), 0.0f);
    glVertex3f(PSH_X(1.0f), PSH_Y(0.0f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(1.0f), PSH_Y(0.0f), 0.0f);
    glVertex3f(PSH_X(1.0f), PSH_Y(-0.2f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(1.0f), PSH_Y(-0.2f), 0.0f);
    glVertex3f(PSH_X(0.9f), PSH_Y(-0.6f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(0.9f), PSH_Y(-0.6f), 0.0f);
    glVertex3f(PSH_X(0.7f), PSH_Y(-0.245f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.7f), PSH_Y(0.52f), 0.0f);
    glVertex3f(PSH_X(-0.77f), PSH_Y(0.63f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.77f), PSH_Y(0.63f), 0.0f);
    glVertex3f(PSH_X(-0.77f), PSH_Y(0.75f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.77f), PSH_Y(0.75f), 0.0f);
    glVertex3f(PSH_X(-0.67f), PSH_Y(0.63f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.67f), PSH_Y(0.63f), 0.0f);
    glVertex3f(PSH_X(-0.67f), PSH_Y(0.50f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.77f), PSH_Y(0.53f), 0.0f);
    glVertex3f(PSH_X(-0.82f), PSH_Y(0.53f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.82f), PSH_Y(0.53f), 0.0f);
    glVertex3f(PSH_X(-0.92f), PSH_Y(0.62f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.92f), PSH_Y(0.62f), 0.0f);
    glVertex3f(PSH_X(-0.8f), PSH_Y(0.62f), 0.0f);

    glEnd();

    glBegin(GL_LINES);

    glVertex3f(PSH_X(-0.8f), PSH_Y(0.62f), 0.0f);
    glVertex3f(PSH_X(-0.75f), PSH_Y(0.55f), 0.0f);

    glEnd();
}

// Pranalis ghoda code

// Prasad mandir code

void drawMandir()
{
    glBegin(GL_QUADS); // E9,B9,C9,D9 MIDDLE SMALL MANDIR BACKGROUND 0.97, 0.69, 0

    glColor3f(1.0f, 0.79f, 0.05f);                                                                                      // YELLOW
    glVertex2f(VALUE_FROM_PERCENT(0.368f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.260f, persent) + PK_yPosition); // U12
    glVertex2f(VALUE_FROM_PERCENT(0.368f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.53f, persent) + PK_yPosition);  // E5
    glVertex2f(VALUE_FROM_PERCENT(0.678f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.53f, persent) + PK_yPosition);  // V8
    glVertex2f(VALUE_FROM_PERCENT(0.678f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.260f, persent) + PK_yPosition); // T12
    glEnd();

    glBegin(GL_QUADS); // C3,R12,I9,F9 background block for seventh middle stair

    glColor3f(0.5f, 0.17f, 0.11f);
    glVertex2f(VALUE_FROM_PERCENT(0.38f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.260f, persent) + PK_yPosition);  // C3
    glVertex2f(VALUE_FROM_PERCENT(0.38f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.288f, persent) + PK_yPosition);  // R12
    glVertex2f(VALUE_FROM_PERCENT(0.668f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.288f, persent) + PK_yPosition); // I9
    glVertex2f(VALUE_FROM_PERCENT(0.668f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.260f, persent) + PK_yPosition); // F9
    glEnd();

    glBegin(GL_QUADS); // C4,E5,F5,G3 MIDDLE SMALL MANDIR BACKGROUND RIGHT COMLUMN

    glColor3f(0.03f, 0.58f, 0.62f);                                                                                     // BLUE
    glVertex2f(VALUE_FROM_PERCENT(0.368f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // D4
    glVertex2f(VALUE_FROM_PERCENT(0.368f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.53f, persent) + PK_yPosition);  // E5
    glVertex2f(VALUE_FROM_PERCENT(0.378f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.53f, persent) + PK_yPosition);  // F5
    glVertex2f(VALUE_FROM_PERCENT(0.378f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // G3
    glEnd();

    glBegin(GL_QUADS); // C4,E5,F5,G3 MIDDLE SMALL MANDIR BACKGROUND LEFT COLUMN

    glColor3f(0.03f, 0.58f, 0.62f);                                                                                     // BLUE
    glVertex2f(VALUE_FROM_PERCENT(0.668f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // Z8
    glVertex2f(VALUE_FROM_PERCENT(0.668f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.53f, persent) + PK_yPosition);  // A9
    glVertex2f(VALUE_FROM_PERCENT(0.678f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.53f, persent) + PK_yPosition);  // V8
    glVertex2f(VALUE_FROM_PERCENT(0.678f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // W8
    glEnd();

    glBegin(GL_QUADS); // HGJK mandir left side first payri

    glColor3f(0.65f, 0.4f, 0.19f);
    glVertex2f(VALUE_FROM_PERCENT(0.16f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition);  // H
    glVertex2f(VALUE_FROM_PERCENT(0.16f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);    // G
    glVertex2f(VALUE_FROM_PERCENT(0.385f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);   // J
    glVertex2f(VALUE_FROM_PERCENT(0.385f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition); // K

    glEnd();

    glBegin(GL_QUADS); // KJZL
    glColor3f(1.0f, 0.71f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.385f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition); // K
    glVertex2f(VALUE_FROM_PERCENT(0.385f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);   // J
    glVertex2f(VALUE_FROM_PERCENT(0.44f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);    // Z
    glVertex2f(VALUE_FROM_PERCENT(0.44f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition);  // L

    glEnd();

    glBegin(GL_QUADS); // POQR mindir right side first payri

    glColor3f(0.65f, 0.4f, 0.19f);
    glVertex2f(VALUE_FROM_PERCENT(0.655f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition); // P
    glVertex2f(VALUE_FROM_PERCENT(0.655f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);   // O
    glVertex2f(VALUE_FROM_PERCENT(0.875f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);   // Q
    glVertex2f(VALUE_FROM_PERCENT(0.875f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition); // R

    glEnd();

    glBegin(GL_QUADS); // MNOP mindir right side first payri

    glColor3f(1.0f, 0.71f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.6f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition);   // M
    glVertex2f(VALUE_FROM_PERCENT(0.6f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);     // N
    glVertex2f(VALUE_FROM_PERCENT(0.655f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);   // O
    glVertex2f(VALUE_FROM_PERCENT(0.655f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition); // P

    glEnd();

    glBegin(GL_QUADS); // L,P12,Q12,M BOX IN BACKGROUND OF STAIRS FOR GIVING SHADOW TO THE STRAIRS

    glColor3f(0.29f, 0.18f, 0.13f);
    glVertex2f(VALUE_FROM_PERCENT(0.44f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition); // L
    glVertex2f(VALUE_FROM_PERCENT(0.44f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.266f, persent) + PK_yPosition); // P12

    glColor3f(0.56f, 0.38f, 0.31f);
    glVertex2f(VALUE_FROM_PERCENT(0.6f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.266f, persent) + PK_yPosition); // Q12
    glVertex2f(VALUE_FROM_PERCENT(0.6f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition); // M

    glEnd();

    glBegin(GL_QUADS); // UVWZ LEFT PAYRI CHYA SHEJARCHA COLUMN

    glColor3f(0.21f, 0.12f, 0.08f);                                                                                    // 0.21, 0.12, 0.08 brown color
    glVertex2f(VALUE_FROM_PERCENT(0.41f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);   // U
    glVertex2f(VALUE_FROM_PERCENT(0.43f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.266f, persent) + PK_yPosition); // V
    glVertex2f(VALUE_FROM_PERCENT(0.46f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.266f, persent) + PK_yPosition); // W
    glVertex2f(VALUE_FROM_PERCENT(0.44f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);   // Z
    glEnd();

    glBegin(GL_QUADS); // N,A1,B1,C1 RIGHT PAYRICHYA SHEJARCHA COLUMN

    glColor3f(0.21f, 0.12f, 0.08f);                                                                                     // 0.21, 0.12, 0.08 brown color
    glVertex2f(VALUE_FROM_PERCENT(0.6f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);     // N
    glVertex2f(VALUE_FROM_PERCENT(0.574f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.266f, persent) + PK_yPosition); // A1
    glVertex2f(VALUE_FROM_PERCENT(0.606f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.266f, persent) + PK_yPosition); // B1
    glVertex2f(VALUE_FROM_PERCENT(0.632f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition);   // C1
    glEnd();

    // from here we start middle stairs

    glBegin(GL_QUADS); // L,T1,U1,M middle first stair

    glColor3f(0.91f, 0.67f, 0.41f);
    glVertex2f(VALUE_FROM_PERCENT(0.44f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition); // L
    glVertex2f(VALUE_FROM_PERCENT(0.44f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.165f, persent) + PK_yPosition); // T1
    glVertex2f(VALUE_FROM_PERCENT(0.6f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.165f, persent) + PK_yPosition);  // U1
    glVertex2f(VALUE_FROM_PERCENT(0.6f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition);  // M
    glEnd();

    glBegin(GL_QUADS); // L,T1,U1,M middle first stair

    glColor3f(0.91f, 0.67f, 0.41f);
    glVertex2f(VALUE_FROM_PERCENT(0.44f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition); // L
    glVertex2f(VALUE_FROM_PERCENT(0.44f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.165f, persent) + PK_yPosition); // T1
    glVertex2f(VALUE_FROM_PERCENT(0.6f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.165f, persent) + PK_yPosition);  // U1
    glVertex2f(VALUE_FROM_PERCENT(0.6f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.155f, persent) + PK_yPosition);  // M
    glEnd();

    glBegin(GL_QUADS); // W1,V1,A2,Z1 middle SECOND stair

    glColor3f(0.91f, 0.67f, 0.41f);
    glVertex2f(VALUE_FROM_PERCENT(0.442f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.17f, persent) + PK_yPosition);  // W1
    glVertex2f(VALUE_FROM_PERCENT(0.442f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.185f, persent) + PK_yPosition); // V1
    glVertex2f(VALUE_FROM_PERCENT(0.59f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.185f, persent) + PK_yPosition);  // A2
    glVertex2f(VALUE_FROM_PERCENT(0.59f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.17f, persent) + PK_yPosition);   // Z1
    glEnd();

    glBegin(GL_QUADS); // C2,B2,D2,E2 middle THIRD stair

    glColor3f(0.91f, 0.67f, 0.41f);
    glVertex2f(VALUE_FROM_PERCENT(0.447f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.192f, persent) + PK_yPosition); // C2
    glVertex2f(VALUE_FROM_PERCENT(0.447f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.206f, persent) + PK_yPosition); // B2
    glVertex2f(VALUE_FROM_PERCENT(0.586f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.206, persent) + PK_yPosition);  // D2
    glVertex2f(VALUE_FROM_PERCENT(0.586f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.192f, persent) + PK_yPosition); // E2
    glEnd();

    glBegin(GL_QUADS); // I2,H2,F2,G2 middle FORTH stair

    glColor3f(0.91f, 0.67f, 0.41f);
    glVertex2f(VALUE_FROM_PERCENT(0.452f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.212f, persent) + PK_yPosition); // I2
    glVertex2f(VALUE_FROM_PERCENT(0.452f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.228f, persent) + PK_yPosition); // H2
    glVertex2f(VALUE_FROM_PERCENT(0.582f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.228f, persent) + PK_yPosition); // F2
    glVertex2f(VALUE_FROM_PERCENT(0.582f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.212f, persent) + PK_yPosition); // G2
    glEnd();

    glBegin(GL_QUADS); // K2,J2,L2,M2 middle FIFTH stair

    glColor3f(0.91f, 0.67f, 0.41f);
    glVertex2f(VALUE_FROM_PERCENT(0.456f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.234f, persent) + PK_yPosition); // K2
    glVertex2f(VALUE_FROM_PERCENT(0.456f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.248f, persent) + PK_yPosition); // J2
    glVertex2f(VALUE_FROM_PERCENT(0.575f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.248f, persent) + PK_yPosition); // L2
    glVertex2f(VALUE_FROM_PERCENT(0.575f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.234f, persent) + PK_yPosition); // M2
    glEnd();

    glBegin(GL_QUADS); // N2,W,A1,O2 middle SIXTH stair

    glColor3f(0.91f, 0.67f, 0.41f);
    glVertex2f(VALUE_FROM_PERCENT(0.46f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.253f, persent) + PK_yPosition);  // N2
    glVertex2f(VALUE_FROM_PERCENT(0.46f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.266f, persent) + PK_yPosition);  // W
    glVertex2f(VALUE_FROM_PERCENT(0.574, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.266f, persent) + PK_yPosition);  // A1
    glVertex2f(VALUE_FROM_PERCENT(0.574f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.253f, persent) + PK_yPosition); // O2
    glEnd();

    /*glBegin(GL_QUADS);//Q2,P2,R2,S2 middle SEVENTH stair

    glColor3f(0.91f, 0.67f, 0.41f);
          glVertex2f(0.466f, 0.266f);//Q2
          glVertex2f(0.466f, 0.285f);//P2
          glVertex2f(0.568f, 0.285f);//R2
          glVertex2f(0.568f, 0.266f);//S2
          glEnd();*/

    // FROM HERE WE START THE LEFT SIDE STRAI FROM MIDDLE

    glBegin(GL_QUADS); // stair1 S,T,G1,U

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.19f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition); // S

    glColor3f(0.98f, 0.65f, 0.06f);
    glVertex2f(VALUE_FROM_PERCENT(0.19f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.22f, persent) + PK_yPosition);   // T
    glVertex2f(VALUE_FROM_PERCENT(0.415f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.219f, persent) + PK_yPosition); // G1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.41f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition); // U
    glEnd();

    glBegin(GL_QUADS); // stair2 I1,H1,J1,G1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.209f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.219f, persent) + PK_yPosition); // I1

    glColor3f(0.98f, 0.65f, 0.06f);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.24f, persent) + PK_yPosition);   // H1
    glVertex2f(VALUE_FROM_PERCENT(0.422f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.239f, persent) + PK_yPosition); // J1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.415f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.219f, persent) + PK_yPosition); // G1
    glEnd();

    glBegin(GL_QUADS); // stair3 L1,K1,M1,J1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.225f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.239f, persent) + PK_yPosition); // L1

    glColor3f(0.98f, 0.65f, 0.06f);
    glVertex2f(VALUE_FROM_PERCENT(0.225f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.26f, persent) + PK_yPosition); // K1
    glVertex2f(VALUE_FROM_PERCENT(0.428f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.26f, persent) + PK_yPosition); // M1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.422f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.239f, persent) + PK_yPosition); // J1
    glEnd();

    // FROM HERE WE START STAIR OF RIGHT SIDE OF THE MIDDLE

    glBegin(GL_QUADS); // STAIR 1 C1,F1,D1,E1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.632f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition); // C1

    glColor3f(0.98f, 0.65f, 0.06f);
    glVertex2f(VALUE_FROM_PERCENT(0.624f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.22f, persent) + PK_yPosition); // F1
    glVertex2f(VALUE_FROM_PERCENT(0.848f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.22f, persent) + PK_yPosition); // D1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.848f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.2f, persent) + PK_yPosition); // E1
    glEnd();

    glBegin(GL_QUADS); // STAIR 2 F1,P1,N1,O1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.624f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.22f, persent) + PK_yPosition); // F1

    glColor3f(0.98f, 0.65f, 0.06f);
    glVertex2f(VALUE_FROM_PERCENT(0.616f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.24f, persent) + PK_yPosition); // P1
    glVertex2f(VALUE_FROM_PERCENT(0.83f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.24f, persent) + PK_yPosition);  // N1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.830f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.22f, persent) + PK_yPosition); // O1
    glEnd();

    glBegin(GL_QUADS); // STAIR 3 P1,Q1,R1,S1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.616f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.24f, persent) + PK_yPosition); // P1

    glColor3f(0.98f, 0.65f, 0.06f);
    glVertex2f(VALUE_FROM_PERCENT(0.608f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.260f, persent) + PK_yPosition); // Q1
    glVertex2f(VALUE_FROM_PERCENT(0.815f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.26f, persent) + PK_yPosition);  // R1

    glColor3f(0.64f, 0.41f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.815f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.24f, persent) + PK_yPosition); // S1
    glEnd();

    glBegin(GL_QUADS); // A3,Z2,B3,C3 LEFT SIDE SMALL MANDIR BASE

    glColor3f(0.33f, 0.18f, 0.14f);
    glVertex2f(VALUE_FROM_PERCENT(0.252f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.260f, persent) + PK_yPosition); // A3
    glVertex2f(VALUE_FROM_PERCENT(0.252f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.298f, persent) + PK_yPosition); // Z2
    glVertex2f(VALUE_FROM_PERCENT(0.38f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.298f, persent) + PK_yPosition);  // B3
    glVertex2f(VALUE_FROM_PERCENT(0.38f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.260f, persent) + PK_yPosition);  // C3
    glEnd();

    glBegin(GL_QUADS); // F9,S12,G9,H9 RIGHT SIDE SMALL MANDIR BASE

    glColor3f(0.33f, 0.18f, 0.14f);
    glVertex2f(VALUE_FROM_PERCENT(0.668f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.260f, persent) + PK_yPosition); // F9
    glVertex2f(VALUE_FROM_PERCENT(0.668f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.298f, persent) + PK_yPosition); // S12
    glVertex2f(VALUE_FROM_PERCENT(0.785f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.298f, persent) + PK_yPosition); // V12
    glVertex2f(VALUE_FROM_PERCENT(0.785f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.260f, persent) + PK_yPosition); // W12
    glEnd();

    glBegin(GL_QUADS); // u2,t2,w2,v2 left  SIDE SMALL MANDIR BASE upper box

    glColor3f(0.91f, 0.67f, 0.41f);
    glVertex2f(VALUE_FROM_PERCENT(0.248f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.298f, persent) + PK_yPosition); // U2
    glVertex2f(VALUE_FROM_PERCENT(0.248f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // T2
    glVertex2f(VALUE_FROM_PERCENT(0.384f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // W2
    glVertex2f(VALUE_FROM_PERCENT(0.384f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.298f, persent) + PK_yPosition); // V2
    glEnd();

    glBegin(GL_QUADS); // E9,B9,C9,D9 RIGHT  SIDE SMALL MANDIR BASE upper box

    glColor3f(0.91f, 0.67f, 0.41f);
    glVertex2f(VALUE_FROM_PERCENT(0.66f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.298f, persent) + PK_yPosition); // E9
    glVertex2f(VALUE_FROM_PERCENT(0.66f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // B9
    glVertex2f(VALUE_FROM_PERCENT(0.79f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // C9
    glVertex2f(VALUE_FROM_PERCENT(0.79f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.298f, persent) + PK_yPosition); // D9
    glEnd();

    glBegin(GL_QUADS); // W5,V5,E6,D6 middle mandir base

    glColor3f(0.91f, 0.67f, 0.41f);
    glVertex2f(VALUE_FROM_PERCENT(0.408f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.288f, persent) + PK_yPosition); // W5
    glVertex2f(VALUE_FROM_PERCENT(0.408f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // V5
    glVertex2f(VALUE_FROM_PERCENT(0.625f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // E6
    glVertex2f(VALUE_FROM_PERCENT(0.625f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.288f, persent) + PK_yPosition); // D6
    glEnd();

    glBegin(GL_QUADS); // E3,D3,F3,G3 LEFT SIDE MANDIR BACKGROUND

    glColor3f(0.76f, 0.57f, 0.18f);
    glVertex2f(VALUE_FROM_PERCENT(0.255f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // E3

    glColor3f(1.0f, 0.79f, 0.05f);                                                                                     // YELLOW
    glVertex2f(VALUE_FROM_PERCENT(0.255f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition); // D3
    glVertex2f(VALUE_FROM_PERCENT(0.378f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition); // F3

    glColor3f(0.76f, 0.57f, 0.18f);
    glVertex2f(VALUE_FROM_PERCENT(0.378f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // G3
    glEnd();

    glBegin(GL_QUADS); // Z8,Z12,L9,M9 RIGHT SIDE MANDIR BACKGROUND

    glColor3f(0.76f, 0.57f, 0.18f);
    glVertex2f(VALUE_FROM_PERCENT(0.668f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // Z8

    glColor3f(1.0f, 0.79f, 0.05f);                                                                                     // YELLOW
    glVertex2f(VALUE_FROM_PERCENT(0.668f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition); // Z12
    glVertex2f(VALUE_FROM_PERCENT(0.78f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // L9

    glColor3f(0.76f, 0.57f, 0.18f);
    glVertex2f(VALUE_FROM_PERCENT(0.78f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // M9
    glEnd();

    // from here  we star to build right side mandir
    // all things of right mandir is here

    glBegin(GL_QUADS); // Z8,Z12,A13,W8 RIGHT SIDE MANDIR left side column

    glColor3f(0.32f, 0.08f, 0.03f);
    glVertex2f(VALUE_FROM_PERCENT(0.668f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // Z8
    glVertex2f(VALUE_FROM_PERCENT(0.668f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // Z12
    glVertex2f(VALUE_FROM_PERCENT(0.678f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // A13
    glVertex2f(VALUE_FROM_PERCENT(0.678f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // W8
    glEnd();

    glBegin(GL_QUADS); // W8,A13,Z9,A10

    glColor3f(0.57f, 0.55f, 0.38f);
    glVertex2f(VALUE_FROM_PERCENT(0.678f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // W8
    glVertex2f(VALUE_FROM_PERCENT(0.678f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // A13
    glVertex2f(VALUE_FROM_PERCENT(0.686f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // Z9
    glVertex2f(VALUE_FROM_PERCENT(0.686f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // A10
    glEnd();

    glBegin(GL_QUADS); // RIGHT SIDE MANDIR RIGHT side column

    glColor3f(0.57f, 0.55f, 0.38f);
    glVertex2f(VALUE_FROM_PERCENT(0.766f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // E10
    glVertex2f(VALUE_FROM_PERCENT(0.766f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // D10
    glVertex2f(VALUE_FROM_PERCENT(0.772f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // B10
    glVertex2f(VALUE_FROM_PERCENT(0.772f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // C10
    glEnd();

    glBegin(GL_QUADS); // C10,B10,L9,M9

    glColor3f(0.32f, 0.08f, 0.03f);
    glVertex2f(VALUE_FROM_PERCENT(0.772f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // C10
    glVertex2f(VALUE_FROM_PERCENT(0.772f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // B10
    glVertex2f(VALUE_FROM_PERCENT(0.780f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // L9
    glVertex2f(VALUE_FROM_PERCENT(0.780f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // M9
    glEnd();

    glBegin(GL_QUADS); // 0.37, 0.34, 0.18 UPPER BOX J9,K9,O9,N9

    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(VALUE_FROM_PERCENT(0.66f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);   // J9
    glVertex2f(VALUE_FROM_PERCENT(0.66f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.402f, persent) + PK_yPosition);  // K9
    glVertex2f(VALUE_FROM_PERCENT(0.788f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.402f, persent) + PK_yPosition); // O9
    glVertex2f(VALUE_FROM_PERCENT(0.788f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // N9
    glEnd();

    glBegin(GL_QUADS); // 0.37, 0.34, 0.18 UPPER upper BOX P9,Q9,S9,R9

    glColor3f(0.07f, 0.04f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.65f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.402f, persent) + PK_yPosition);  // P9
    glVertex2f(VALUE_FROM_PERCENT(0.65f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.414f, persent) + PK_yPosition);  // Q9
    glVertex2f(VALUE_FROM_PERCENT(0.798f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.414f, persent) + PK_yPosition); // S9
    glVertex2f(VALUE_FROM_PERCENT(0.798f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.402f, persent) + PK_yPosition); // R9
    glEnd();

    glBegin(GL_QUADS); // door BOX outer U11,W11,G12,T11

    glColor3f(0.51f, 0.26f, 0.19f);
    glVertex2f(VALUE_FROM_PERCENT(0.697f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // U11
    glVertex2f(VALUE_FROM_PERCENT(0.697f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.372f, persent) + PK_yPosition); // W11
    glVertex2f(VALUE_FROM_PERCENT(0.754f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.372f, persent) + PK_yPosition); // G12
    glVertex2f(VALUE_FROM_PERCENT(0.754f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // T11
    glEnd();

    glBegin(GL_QUADS); // door BOX inner V11,Z11,F12,R11

    glColor3f(0.25f, 0.05f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.701f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // V11
    glVertex2f(VALUE_FROM_PERCENT(0.701f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.366f, persent) + PK_yPosition); // Z11
    glVertex2f(VALUE_FROM_PERCENT(0.75f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.366f, persent) + PK_yPosition);  // F12
    glVertex2f(VALUE_FROM_PERCENT(0.75f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition);  // R11
    glEnd();

    glBegin(GL_QUADS); // door upper H12,I12,K12,J12

    glColor3f(0.6f, 0.5f, 0.44f);
    glVertex2f(VALUE_FROM_PERCENT(0.692f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.372f, persent) + PK_yPosition); // H12
    glVertex2f(VALUE_FROM_PERCENT(0.692f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.376f, persent) + PK_yPosition); // I12
    glVertex2f(VALUE_FROM_PERCENT(0.758f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.376f, persent) + PK_yPosition); // K12
    glVertex2f(VALUE_FROM_PERCENT(0.758f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.372f, persent) + PK_yPosition); // J12
    glEnd();

    glBegin(GL_QUADS); // door upper upper box I12,L12,M12,K12

    glColor3f(0.31f, 0.11f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.692f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.376f, persent) + PK_yPosition); // I12

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.696f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.378f, persent) + PK_yPosition); // L12
    glVertex2f(VALUE_FROM_PERCENT(0.754f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.378f, persent) + PK_yPosition); // M12

    glColor3f(0.31f, 0.11f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.758f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.376f, persent) + PK_yPosition); // K12
    glEnd();

    // upper upper upper box of door
    glBegin(GL_QUADS); // L12,N12,O12,M12

    glColor3f(0.31f, 0.11f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.696f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.378f, persent) + PK_yPosition); // L12

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.696f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition); // N12
    glVertex2f(VALUE_FROM_PERCENT(0.754f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition); // O12

    glColor3f(0.31f, 0.11f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.754f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.378f, persent) + PK_yPosition); // M12
    glEnd();

    glBegin(GL_QUADS); // door upper H12,I12,K12,J12

    glColor3f(1.0f, 0.82f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.65f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.414f, persent) + PK_yPosition); // H12

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.67f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.435f, persent) + PK_yPosition);  // T9
    glVertex2f(VALUE_FROM_PERCENT(0.772f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.435f, persent) + PK_yPosition); // G10

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.798f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.414f, persent) + PK_yPosition); // S9
    glEnd();

    glBegin(GL_QUADS); // T9,U9,F10,G10 mandir kalas box first

    glColor3f(0.18f, 0.12f, 0.01f);
    glVertex2f(VALUE_FROM_PERCENT(0.67f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.435f, persent) + PK_yPosition);  // T9
    glVertex2f(VALUE_FROM_PERCENT(0.67f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.44f, persent) + PK_yPosition);   // U9
    glVertex2f(VALUE_FROM_PERCENT(0.772f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.44f, persent) + PK_yPosition);  // F10
    glVertex2f(VALUE_FROM_PERCENT(0.772f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.435f, persent) + PK_yPosition); // G10
    glEnd();

    glBegin(GL_QUADS); // J10,K10,L10,M10 mandir kalas box second

    glColor3f(1.0f, 0.9f, 0.48f);
    glVertex2f(VALUE_FROM_PERCENT(0.681f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.44f, persent) + PK_yPosition); // J10
    glVertex2f(VALUE_FROM_PERCENT(0.681f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.46f, persent) + PK_yPosition); // K10
    glVertex2f(VALUE_FROM_PERCENT(0.763f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.46f, persent) + PK_yPosition); // L10
    glVertex2f(VALUE_FROM_PERCENT(0.763f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.44f, persent) + PK_yPosition); // M10
    glEnd();

    glBegin(GL_QUADS); // N10,O10,P10,Q10 mandir kalas box second

    glColor3f(0.18f, 0.12f, 0.01);
    glVertex2f(VALUE_FROM_PERCENT(0.675f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.46f, persent) + PK_yPosition); // N10
    glVertex2f(VALUE_FROM_PERCENT(0.675f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.47f, persent) + PK_yPosition); // O10
    glVertex2f(VALUE_FROM_PERCENT(0.768f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.47f, persent) + PK_yPosition); // P10
    glVertex2f(VALUE_FROM_PERCENT(0.768f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.46f, persent) + PK_yPosition); // Q10
    glEnd();

    glBegin(GL_QUADS); // O10,U10,Z10,P10 mandir kalas box second

    glColor3f(1.0f, 0.82f, 0.0f);                                                                                      // kalsh top
    glVertex2f(VALUE_FROM_PERCENT(0.675f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.47f, persent) + PK_yPosition); // O10

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.708f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.515f, persent) + PK_yPosition); // V10
    glVertex2f(VALUE_FROM_PERCENT(0.735f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.515f, persent) + PK_yPosition); // Z10

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.768f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.47f, persent) + PK_yPosition); // P10
    glEnd();

    glBegin(GL_QUADS); // V10,W10,A11,Z10 mandir kalas box second

    glColor3f(0.18f, 0.12f, 0.01f);
    glVertex2f(VALUE_FROM_PERCENT(0.708f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.515f, persent) + PK_yPosition); // V10
    glVertex2f(VALUE_FROM_PERCENT(0.708f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.525f, persent) + PK_yPosition); // W10
    glVertex2f(VALUE_FROM_PERCENT(0.735f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.525f, persent) + PK_yPosition); // A11
    glVertex2f(VALUE_FROM_PERCENT(0.735f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.515f, persent) + PK_yPosition); // Z10
    glEnd();

    // flag code start from here

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.9f, 0.48f);
    glVertex2f(VALUE_FROM_PERCENT(0.72f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.515f, persent) + PK_yPosition);  // B11
    glVertex2f(VALUE_FROM_PERCENT(0.72f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.575f, persent) + PK_yPosition);  // C11
    glVertex2f(VALUE_FROM_PERCENT(0.722f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.575f, persent) + PK_yPosition); // D11
    glVertex2f(VALUE_FROM_PERCENT(0.722f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.525f, persent) + PK_yPosition); // E11
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.722f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.575f, persent) + PK_yPosition); // D11
    glVertex2f(VALUE_FROM_PERCENT(0.738f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.575f, persent) + PK_yPosition); // F11
    glVertex2f(VALUE_FROM_PERCENT(0.722f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.56f, persent) + PK_yPosition);  // G11

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.722f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.56f, persent) + PK_yPosition);  // G11
    glVertex2f(VALUE_FROM_PERCENT(0.738f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.545f, persent) + PK_yPosition); // H11
    glVertex2f(VALUE_FROM_PERCENT(0.722f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.545f, persent) + PK_yPosition); // I11

    glEnd();

    // from here  we star to build LEFT side mandir
    // all things of LEFT mandir is here

    glBegin(GL_QUADS); // E3,D3,F4,G4  LEFT SIDE MANDIR left side column

    glColor3f(0.32f, 0.08f, 0.03f);
    glVertex2f(VALUE_FROM_PERCENT(0.255f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // E3
    glVertex2f(VALUE_FROM_PERCENT(0.255f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // D3
    glVertex2f(VALUE_FROM_PERCENT(0.261f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // F4
    glVertex2f(VALUE_FROM_PERCENT(0.261f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // G4
    glEnd();

    glBegin(GL_QUADS); // W8,A13,Z9,A10

    glColor3f(0.57f, 0.55f, 0.38f);
    glVertex2f(VALUE_FROM_PERCENT(0.261f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // G4
    glVertex2f(VALUE_FROM_PERCENT(0.261f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // F4
    glVertex2f(VALUE_FROM_PERCENT(0.269f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // E4
    glVertex2f(VALUE_FROM_PERCENT(0.269f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // H4
    glEnd();

    glBegin(GL_QUADS); // LEFT SIDE MANDIR RIGHT side column

    glColor3f(0.57f, 0.55f, 0.38f);
    glVertex2f(VALUE_FROM_PERCENT(0.36f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition);  // C4
    glVertex2f(VALUE_FROM_PERCENT(0.36f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);   // A4
    glVertex2f(VALUE_FROM_PERCENT(0.368f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // B4
    glVertex2f(VALUE_FROM_PERCENT(0.368f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // D4
    glEnd();

    glBegin(GL_QUADS); // C10,B10,L9,M9

    glColor3f(0.32f, 0.08f, 0.03f);
    glVertex2f(VALUE_FROM_PERCENT(0.368f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // D4
    glVertex2f(VALUE_FROM_PERCENT(0.368f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // B4
    glVertex2f(VALUE_FROM_PERCENT(0.378f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // F3
    glVertex2f(VALUE_FROM_PERCENT(0.378f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // G3
    glEnd();

    glBegin(GL_QUADS); // 0.37, 0.34, 0.18 UPPER BOX J9,K9,O9,N9

    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(VALUE_FROM_PERCENT(0.248f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // J4
    glVertex2f(VALUE_FROM_PERCENT(0.248f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.402f, persent) + PK_yPosition); // I4
    glVertex2f(VALUE_FROM_PERCENT(0.385f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.402f, persent) + PK_yPosition); // L4
    glVertex2f(VALUE_FROM_PERCENT(0.385f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition);  // K4
    glEnd();

    glBegin(GL_QUADS); // 0.37, 0.34, 0.18 UPPER upper BOX P9,Q9,S9,R9

    glColor3f(0.07f, 0.04f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.238f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.402f, persent) + PK_yPosition); // M4
    glVertex2f(VALUE_FROM_PERCENT(0.238f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.414f, persent) + PK_yPosition); // N4
    glVertex2f(VALUE_FROM_PERCENT(0.395f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.414f, persent) + PK_yPosition); // P4
    glVertex2f(VALUE_FROM_PERCENT(0.395f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.402f, persent) + PK_yPosition); // O4
    glEnd();

    glBegin(GL_QUADS); // LEFT MANDIR door BOX outer

    glColor3f(0.51f, 0.26f, 0.19f);
    glVertex2f(VALUE_FROM_PERCENT(0.288f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // Q3
    glVertex2f(VALUE_FROM_PERCENT(0.288f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.372f, persent) + PK_yPosition); // P3
    glVertex2f(VALUE_FROM_PERCENT(0.340f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.372f, persent) + PK_yPosition); // R3
    glVertex2f(VALUE_FROM_PERCENT(0.340f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // S3
    glEnd();

    glBegin(GL_QUADS); // LEFT MANDIR door BOX inner

    glColor3f(0.25f, 0.05f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.293f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // V3
    glVertex2f(VALUE_FROM_PERCENT(0.293f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.366f, persent) + PK_yPosition); // U3
    glVertex2f(VALUE_FROM_PERCENT(0.335f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.366f, persent) + PK_yPosition); // Z3
    glVertex2f(VALUE_FROM_PERCENT(0.335f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.308f, persent) + PK_yPosition); // W3
    glEnd();

    glBegin(GL_QUADS); // door upper H12,I12,K12,J12

    glColor3f(0.6f, 0.5f, 0.44f);
    glVertex2f(VALUE_FROM_PERCENT(0.283f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.372f, persent) + PK_yPosition); // N3
    glVertex2f(VALUE_FROM_PERCENT(0.283f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.376f, persent) + PK_yPosition); // L3
    glVertex2f(VALUE_FROM_PERCENT(0.346f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.376f, persent) + PK_yPosition); // M3
    glVertex2f(VALUE_FROM_PERCENT(0.346f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.372f, persent) + PK_yPosition); // O3
    glEnd();

    glBegin(GL_QUADS); // door upper upper box

    glColor3f(0.31f, 0.11f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.283f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.376f, persent) + PK_yPosition); // L3

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.287f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.378f, persent) + PK_yPosition); // I3
    glVertex2f(VALUE_FROM_PERCENT(0.342f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.378f, persent) + PK_yPosition); // K3

    glColor3f(0.31f, 0.11f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.346f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.376f, persent) + PK_yPosition); // M3
    glEnd();

    // upper upper upper box of door
    glBegin(GL_QUADS); // L12,N12,O12,M12

    glColor3f(0.31f, 0.11f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.287f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.378f, persent) + PK_yPosition); // I3

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.287f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition); // H3
    glVertex2f(VALUE_FROM_PERCENT(0.342f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.39f, persent) + PK_yPosition); // J3

    glColor3f(0.31f, 0.11f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.342f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.378f, persent) + PK_yPosition); // K3
    glEnd();

    glBegin(GL_QUADS); // door upper H12,I12,K12,J12

    glColor3f(1.0f, 0.82f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.238f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.414f, persent) + PK_yPosition); // N4

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.252f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.435f, persent) + PK_yPosition); // Q4
    glVertex2f(VALUE_FROM_PERCENT(0.376f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.435f, persent) + PK_yPosition); // R4

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.395f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.414f, persent) + PK_yPosition); // P4
    glEnd();

    glBegin(GL_QUADS); // T9,U9,F10,G10 mandir kalas box first

    glColor3f(0.18f, 0.12f, 0.01f);
    glVertex2f(VALUE_FROM_PERCENT(0.252f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.435f, persent) + PK_yPosition); // Q4
    glVertex2f(VALUE_FROM_PERCENT(0.252f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.44f, persent) + PK_yPosition);  // S4
    glVertex2f(VALUE_FROM_PERCENT(0.376f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.44f, persent) + PK_yPosition);  // T4
    glVertex2f(VALUE_FROM_PERCENT(0.376f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.435f, persent) + PK_yPosition); // R4
    glEnd();

    glBegin(GL_QUADS); // mandir kalas box second

    glColor3f(1.0f, 0.9f, 0.48f);
    glVertex2f(VALUE_FROM_PERCENT(0.26f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.44f, persent) + PK_yPosition);  // V4
    glVertex2f(VALUE_FROM_PERCENT(0.26f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.46f, persent) + PK_yPosition);  // U4
    glVertex2f(VALUE_FROM_PERCENT(0.366f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.46f, persent) + PK_yPosition); // H10
    glVertex2f(VALUE_FROM_PERCENT(0.366f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.44f, persent) + PK_yPosition); // I10
    glEnd();

    glBegin(GL_QUADS); //

    glColor3f(0.18f, 0.12f, 0.01);
    glVertex2f(VALUE_FROM_PERCENT(0.256f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.46f, persent) + PK_yPosition); // z4
    glVertex2f(VALUE_FROM_PERCENT(0.256f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.47f, persent) + PK_yPosition); // a5
    glVertex2f(VALUE_FROM_PERCENT(0.37f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.47f, persent) + PK_yPosition);  // b5
    glVertex2f(VALUE_FROM_PERCENT(0.37f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.46f, persent) + PK_yPosition);  // c5
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.82f, 0.0f);                                                                                      // kalsh top
    glVertex2f(VALUE_FROM_PERCENT(0.256f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.47f, persent) + PK_yPosition); // A5

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.298f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.515f, persent) + PK_yPosition); // R10
    glVertex2f(VALUE_FROM_PERCENT(0.33f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.515f, persent) + PK_yPosition);  // T10

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.37f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.47f, persent) + PK_yPosition); // B5
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.18f, 0.12f, 0.01f);
    glVertex2f(VALUE_FROM_PERCENT(0.298f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.515f, persent) + PK_yPosition); // R10
    glVertex2f(VALUE_FROM_PERCENT(0.298f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.525f, persent) + PK_yPosition); // S10
    glVertex2f(VALUE_FROM_PERCENT(0.33f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.525f, persent) + PK_yPosition);  // U10
    glVertex2f(VALUE_FROM_PERCENT(0.33f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.515f, persent) + PK_yPosition);  // T10
    glEnd();

    // flag code start from here

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.9f, 0.48f);
    glVertex2f(VALUE_FROM_PERCENT(0.312f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.525f, persent) + PK_yPosition); // J11
    glVertex2f(VALUE_FROM_PERCENT(0.312f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.575f, persent) + PK_yPosition); // K11
    glVertex2f(VALUE_FROM_PERCENT(0.314f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.575f, persent) + PK_yPosition); // M11
    glVertex2f(VALUE_FROM_PERCENT(0.314f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.525f, persent) + PK_yPosition); // L11
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.314f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.575f, persent) + PK_yPosition); // M11
    glVertex2f(VALUE_FROM_PERCENT(0.328f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.575f, persent) + PK_yPosition); // N11
    glVertex2f(VALUE_FROM_PERCENT(0.314f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.56f, persent) + PK_yPosition);  // O11

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.314f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.56f, persent) + PK_yPosition);  // O11
    glVertex2f(VALUE_FROM_PERCENT(0.328f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.545f, persent) + PK_yPosition); // P11
    glVertex2f(VALUE_FROM_PERCENT(0.314f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.545f, persent) + PK_yPosition); // Q11

    glEnd();

    // FROM HERE WE STARTED MIDDLE MANDIR

    glBegin(GL_QUADS); // OUTER BOX OF DOOR

    glColor3f(0.51f, 0.26f, 0.19f);
    glVertex2f(VALUE_FROM_PERCENT(0.474f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.288f, persent) + PK_yPosition); // Z5
    glVertex2f(VALUE_FROM_PERCENT(0.474f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // A6
    glVertex2f(VALUE_FROM_PERCENT(0.562f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // B6
    glVertex2f(VALUE_FROM_PERCENT(0.562f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.288f, persent) + PK_yPosition); // C6
    glEnd();

    glBegin(GL_QUADS); // MIDDLE MANDIR door BOX inner

    glColor3f(0.25f, 0.05f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.49f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // S6
    glVertex2f(VALUE_FROM_PERCENT(0.49f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.4f, persent) + PK_yPosition);   // R6
    glVertex2f(VALUE_FROM_PERCENT(0.55f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.4f, persent) + PK_yPosition);   // U6
    glVertex2f(VALUE_FROM_PERCENT(0.55f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // T6
    glEnd();

    glBegin(GL_QUADS); // MIDDLE MANDIR LEFT SIDE COLUMN

    glColor3f(0.32f, 0.08f, 0.03f);                                                                                     // Q5,P5,S5,R5
    glVertex2f(VALUE_FROM_PERCENT(0.427f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // Q5
    glVertex2f(VALUE_FROM_PERCENT(0.427f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // P5
    glVertex2f(VALUE_FROM_PERCENT(0.436f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // S5
    glVertex2f(VALUE_FROM_PERCENT(0.436f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // R5
    glEnd();

    glBegin(GL_QUADS); // W8,A13,Z9,A10

    glColor3f(0.57f, 0.55f, 0.38f);
    glVertex2f(VALUE_FROM_PERCENT(0.436f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // R5
    glVertex2f(VALUE_FROM_PERCENT(0.436f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // S5
    glVertex2f(VALUE_FROM_PERCENT(0.444f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // T5
    glVertex2f(VALUE_FROM_PERCENT(0.444f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // U6
    glEnd();

    glBegin(GL_QUADS); // MIDDLE MANDIR RIGHT SIDE COLUMN

    glColor3f(0.57f, 0.55f, 0.38f);                                                                                     // G6,F6,J6,K6
    glVertex2f(VALUE_FROM_PERCENT(0.592f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // G6
    glVertex2f(VALUE_FROM_PERCENT(0.592f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // F6
    glVertex2f(VALUE_FROM_PERCENT(0.601f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // J6
    glVertex2f(VALUE_FROM_PERCENT(0.601f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // K6
    glEnd();

    glBegin(GL_QUADS); // W8,A13,Z9,A10

    glColor3f(0.32f, 0.08f, 0.03f);

    glVertex2f(VALUE_FROM_PERCENT(0.601f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // K6
    glVertex2f(VALUE_FROM_PERCENT(0.601f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // J6
    glVertex2f(VALUE_FROM_PERCENT(0.609f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // I6
    glVertex2f(VALUE_FROM_PERCENT(0.609f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.306f, persent) + PK_yPosition); // H6
    glEnd();

    glBegin(GL_QUADS); // N5,M5,W9,V9

    glColor3f(0.32f, 0.08f, 0.03f); // BOX ABOVE THE MIDDLE DOOR

    glVertex2f(VALUE_FROM_PERCENT(0.409f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // N5
    glVertex2f(VALUE_FROM_PERCENT(0.409f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.438f, persent) + PK_yPosition); // M5
    glVertex2f(VALUE_FROM_PERCENT(0.625f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.438f, persent) + PK_yPosition); // W9
    glVertex2f(VALUE_FROM_PERCENT(0.625f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.424f, persent) + PK_yPosition); // V9
    glEnd();

    glBegin(GL_QUADS); // K5,G5,I5,L5

    glColor3f(0.32f, 0.08f, 0.03f); // UPPER UPPER BOX

    glVertex2f(VALUE_FROM_PERCENT(0.396f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.438f, persent) + PK_yPosition); // K5
    glVertex2f(VALUE_FROM_PERCENT(0.38f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.452f, persent) + PK_yPosition);  // G5
    glVertex2f(VALUE_FROM_PERCENT(0.666f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.452, persent) + PK_yPosition);  // I5
    glVertex2f(VALUE_FROM_PERCENT(0.65f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.438f, persent) + PK_yPosition);  // L5
    glEnd();

    glBegin(GL_QUADS); // N5,M5,W9,V9

    glColor3f(1.0f, 0.82f, 0.0f); // kalsh top

    glVertex2f(VALUE_FROM_PERCENT(0.38f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.452f, persent) + PK_yPosition); // G5

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.402f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.478f, persent) + PK_yPosition); // H5
    glVertex2f(VALUE_FROM_PERCENT(0.644f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.478f, persent) + PK_yPosition); // J5

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.666f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.452f, persent) + PK_yPosition); // I5
    glEnd();

    glBegin(GL_QUADS); // K5,G5,I5,L5

    glColor3f(0.32f, 0.08f, 0.03f); // UPPER UPPER BOX

    glVertex2f(VALUE_FROM_PERCENT(0.402f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.478f, persent) + PK_yPosition); // H5
    glVertex2f(VALUE_FROM_PERCENT(0.402, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.488f, persent) + PK_yPosition);  // L6
    glVertex2f(VALUE_FROM_PERCENT(0.644f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.488, persent) + PK_yPosition);  // M6
    glVertex2f(VALUE_FROM_PERCENT(0.644f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.478f, persent) + PK_yPosition); // J5
    glEnd();

    glBegin(GL_QUADS); //

    glColor3f(1.0f, 0.9f, 0.48f);

    glVertex2f(VALUE_FROM_PERCENT(0.425f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.488f, persent) + PK_yPosition); // O6
    glVertex2f(VALUE_FROM_PERCENT(0.425, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.516f, persent) + PK_yPosition);  // N6
    glVertex2f(VALUE_FROM_PERCENT(0.62f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.516, persent) + PK_yPosition);   // P6
    glVertex2f(VALUE_FROM_PERCENT(0.62f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.488f, persent) + PK_yPosition);  // Q6
    glEnd();

    // from here we start the middle mandir background kalash

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.82f, 0.0f); // kalsh top

    glVertex2f(VALUE_FROM_PERCENT(0.35f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.53f, persent) + PK_yPosition); // V6

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.35f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.55f, persent) + PK_yPosition); // Z6
    glVertex2f(VALUE_FROM_PERCENT(0.688f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.55, persent) + PK_yPosition); // A7

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.688f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.53f, persent) + PK_yPosition); // W6
    glEnd();

    glBegin(GL_QUADS); //

    glColor3f(0.32f, 0.08f, 0.03f); // UPPER UPPER BOX

    glVertex2f(VALUE_FROM_PERCENT(0.371f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.55f, persent) + PK_yPosition); // D7
    glVertex2f(VALUE_FROM_PERCENT(0.371f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.57f, persent) + PK_yPosition); // C7
    glVertex2f(VALUE_FROM_PERCENT(0.661f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.57, persent) + PK_yPosition);  // F7
    glVertex2f(VALUE_FROM_PERCENT(0.661f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.55f, persent) + PK_yPosition); // E7
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.82f, 0.0f); // kalsh top

    glVertex2f(VALUE_FROM_PERCENT(0.366f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.57f, persent) + PK_yPosition); // G7

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.378f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.59f, persent) + PK_yPosition); // H7
    glVertex2f(VALUE_FROM_PERCENT(0.66f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.59, persent) + PK_yPosition);   // J7

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.672f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.57f, persent) + PK_yPosition); // I7
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.32f, 0.08f, 0.03f); // UPPER UPPER BOX

    glVertex2f(VALUE_FROM_PERCENT(0.385f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.59f, persent) + PK_yPosition); // K7
    glVertex2f(VALUE_FROM_PERCENT(0.385f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.61f, persent) + PK_yPosition); // L7
    glVertex2f(VALUE_FROM_PERCENT(0.655f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.61, persent) + PK_yPosition);  // N7
    glVertex2f(VALUE_FROM_PERCENT(0.655f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.59f, persent) + PK_yPosition); // M7
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.82f, 0.0f); // kalsh top

    glVertex2f(VALUE_FROM_PERCENT(0.38f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.61f, persent) + PK_yPosition); // O7

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.39, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.625f, persent) + PK_yPosition); // P7
    glVertex2f(VALUE_FROM_PERCENT(0.65f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.625, persent) + PK_yPosition); // R7

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.66f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.61f, persent) + PK_yPosition); // Q7
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.32f, 0.08f, 0.03f); // UPPER UPPER BOX

    glVertex2f(VALUE_FROM_PERCENT(0.4f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.625f, persent) + PK_yPosition);   // S7
    glVertex2f(VALUE_FROM_PERCENT(0.4f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.64f, persent) + PK_yPosition);    // T7
    glVertex2f(VALUE_FROM_PERCENT(0.632f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.64, persent) + PK_yPosition);   // V7
    glVertex2f(VALUE_FROM_PERCENT(0.632f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.625f, persent) + PK_yPosition); // U7
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.82f, 0.0f); // kalsh top

    glVertex2f(VALUE_FROM_PERCENT(0.396f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.64f, persent) + PK_yPosition); // W7

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.404, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.655f, persent) + PK_yPosition); // Z7
    glVertex2f(VALUE_FROM_PERCENT(0.628f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.655, persent) + PK_yPosition); // B8

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.638f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.64f, persent) + PK_yPosition); // A8
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.32f, 0.08f, 0.03f); // UPPER UPPER BOX

    glVertex2f(VALUE_FROM_PERCENT(0.42f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.655f, persent) + PK_yPosition);  // C8
    glVertex2f(VALUE_FROM_PERCENT(0.42f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.67f, persent) + PK_yPosition);   // D8
    glVertex2f(VALUE_FROM_PERCENT(0.615f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.67f, persent) + PK_yPosition);  // F8
    glVertex2f(VALUE_FROM_PERCENT(0.615f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.655f, persent) + PK_yPosition); // E8
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.82f, 0.0f); // kalsh top

    glVertex2f(VALUE_FROM_PERCENT(0.42f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.67f, persent) + PK_yPosition); // D8

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.496, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.765f, persent) + PK_yPosition); // G8
    glVertex2f(VALUE_FROM_PERCENT(0.54f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.765, persent) + PK_yPosition);  // H8

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.615f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.67f, persent) + PK_yPosition); // F8
    glEnd();
    // TOP
    glBegin(GL_QUADS);

    glColor3f(0.32f, 0.08f, 0.03f); // UPPER UPPER BOX

    glVertex2f(VALUE_FROM_PERCENT(0.496, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.765f, persent) + PK_yPosition); // G8
    glVertex2f(VALUE_FROM_PERCENT(0.496, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.785f, persent) + PK_yPosition); // I8
    glVertex2f(VALUE_FROM_PERCENT(0.54f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.785, persent) + PK_yPosition);  // J8
    glVertex2f(VALUE_FROM_PERCENT(0.54f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.765, persent) + PK_yPosition);  // H8
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.82f, 0.0f); // kalsh top

    glVertex2f(VALUE_FROM_PERCENT(0.502f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.785f, persent) + PK_yPosition); // K8

    glColor3f(0.62f, 0.36f, 0.2f);

    glVertex2f(VALUE_FROM_PERCENT(0.504, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.795f, persent) + PK_yPosition); // L8
    glVertex2f(VALUE_FROM_PERCENT(0.532f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.795, persent) + PK_yPosition); // N8

    glColor3f(1.0f, 0.82f, 0.0f);                                                                                       // kalsh top
    glVertex2f(VALUE_FROM_PERCENT(0.534f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.785f, persent) + PK_yPosition); // M8
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.504, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.795f, persent) + PK_yPosition); // L8

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT(0.496, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.81f, persent) + PK_yPosition); // P8
    glVertex2f(VALUE_FROM_PERCENT(0.54f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.81, persent) + PK_yPosition);  // O8

    glColor3f(0.62f, 0.36f, 0.2f);
    glVertex2f(VALUE_FROM_PERCENT(0.532f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.795, persent) + PK_yPosition); // N8
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.32f, 0.08f, 0.03f); // UPPER UPPER BOX

    glVertex2f(VALUE_FROM_PERCENT(0.496, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.81f, persent) + PK_yPosition);  // P8
    glVertex2f(VALUE_FROM_PERCENT(0.496, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.815f, persent) + PK_yPosition); // Q8
    glVertex2f(VALUE_FROM_PERCENT(0.54f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.815, persent) + PK_yPosition);  // R8
    glVertex2f(VALUE_FROM_PERCENT(0.54f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.81, persent) + PK_yPosition);   // O8
    glEnd();

    glBegin(GL_TRIANGLES); // it was the last triangle

    glColor3f(1.0f, 0.82f, 0.0f); // kalsh top
    glVertex2f(VALUE_FROM_PERCENT(0.499f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.815f, persent) + PK_yPosition);
    glVertex2f(VALUE_FROM_PERCENT(0.518f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.855f, persent) + PK_yPosition);
    glVertex2f(VALUE_FROM_PERCENT(0.536f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.815f, persent) + PK_yPosition);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.77f, 0.53f, 0.12f);                                                                                    // kalsh top
    glVertex2f(VALUE_FROM_PERCENT(0.425, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.516f, persent) + PK_yPosition); // N6

    glColor3f(1.0f, 0.82f, 0.0f);                                                                                      // kalsh top
    glVertex2f(VALUE_FROM_PERCENT(0.518f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.67f, persent) + PK_yPosition); // B7

    glColor3f(0.77f, 0.53f, 0.12f);                                                                                   // kalsh top
    glVertex2f(VALUE_FROM_PERCENT(0.62f, persent) + PK_xPosition, VALUE_FROM_PERCENT(0.516, persent) + PK_yPosition); // P6

    glEnd(); // middle mandir top triangle kalash
}

// Prasad mandir code

// Tree code

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

// Tree code

// Astromedicomp

void AstroMediComp(float x_pos, float y_pos)
{
    // A

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(VALUE_FROM_PERCENT(-0.99f, persent) + x_pos, VALUE_FROM_PERCENT(0.6f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.96f, persent) + x_pos, VALUE_FROM_PERCENT(0.6f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.96f, persent) + x_pos, VALUE_FROM_PERCENT(0.2f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.99f, persent) + x_pos, VALUE_FROM_PERCENT(0.2f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.99f, persent) + x_pos, VALUE_FROM_PERCENT(0.6f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.87f, persent) + x_pos, VALUE_FROM_PERCENT(0.6f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.87f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.99f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.87f, persent) + x_pos, VALUE_FROM_PERCENT(0.6f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.90f, persent) + x_pos, VALUE_FROM_PERCENT(0.6f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.90f, persent) + x_pos, VALUE_FROM_PERCENT(0.2f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.87f, persent) + x_pos, VALUE_FROM_PERCENT(0.2f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.99f, persent) + x_pos, VALUE_FROM_PERCENT(0.42f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.87f, persent) + x_pos, VALUE_FROM_PERCENT(0.42f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.87f, persent) + x_pos, VALUE_FROM_PERCENT(0.38f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.99f, persent) + x_pos, VALUE_FROM_PERCENT(0.38f, persent) + y_pos);

    glEnd();

    // S

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.96f, 0.90f);

    glVertex2f(VALUE_FROM_PERCENT(-0.85f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.85f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.85f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.82f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.82f, persent) + x_pos, VALUE_FROM_PERCENT(0.40f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.85f, persent) + x_pos, VALUE_FROM_PERCENT(0.40f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.85f, persent) + x_pos, VALUE_FROM_PERCENT(0.425f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, persent) + x_pos, VALUE_FROM_PERCENT(0.425f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.85f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.76f, persent) + x_pos, VALUE_FROM_PERCENT(0.40f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, persent) + x_pos, VALUE_FROM_PERCENT(0.40f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.76f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.85f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.73f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.85f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // T

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.92f, 0.80f);

    glVertex2f(VALUE_FROM_PERCENT(-0.71f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.59f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.59f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.71f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.664f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.635f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.635f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.664f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // R

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.88f, 0.70f);

    glVertex2f(VALUE_FROM_PERCENT(-0.57f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.54f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.54f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.57f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.57f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.57f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.57f, persent) + x_pos, VALUE_FROM_PERCENT(0.425f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, persent) + x_pos, VALUE_FROM_PERCENT(0.425f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.57f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.48f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.45f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.48f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.54f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.50f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.44f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.48f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // O

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.84f, 0.60f);

    glVertex2f(VALUE_FROM_PERCENT(-0.43f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.40f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.40f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.43f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.31f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.28f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.28f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.31f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.43f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.28f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.28f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.43f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.43f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.28f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.28f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.43f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // M

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.80f, 0.50f);

    glVertex2f(VALUE_FROM_PERCENT(-0.26f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.23f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.23f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.26f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.26f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.09f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.09f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.26f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.09f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.06f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.06f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.09f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.17f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.14f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.14f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.17f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // E

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.76f, 0.40f);

    glVertex2f(VALUE_FROM_PERCENT(-0.04f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.01f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.01f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.04f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.04f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.08f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.08f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.04f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.04f, persent) + x_pos, VALUE_FROM_PERCENT(0.425f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.06f, persent) + x_pos, VALUE_FROM_PERCENT(0.425f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.06f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.04f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(-0.04f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.08f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.08f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(-0.04f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // D

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.72f, 0.30f);

    glVertex2f(VALUE_FROM_PERCENT(0.09f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.12f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.12f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.09f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.09f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.09f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.18f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.18f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.09f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.21f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.09f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // I

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.68f, 0.20f);

    glVertex2f(VALUE_FROM_PERCENT(0.22f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.32f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.32f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.22f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.255f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.285f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.285f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.255f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.22f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.32f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.32f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.22f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // C

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.64f, 0.10f);

    glVertex2f(VALUE_FROM_PERCENT(0.33f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.36f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.36f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.33f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.33f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.45f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.45f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.33f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.33f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.45f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.45f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.33f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // O

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.62f, 0.05f);

    glVertex2f(VALUE_FROM_PERCENT(0.46f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.49f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.49f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.46f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.58f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.58f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.46f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.46f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.46f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, persent) + x_pos, VALUE_FROM_PERCENT(0.25f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.61f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.46f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // M

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.60f, 0.02f);

    glVertex2f(VALUE_FROM_PERCENT(0.62f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.65f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.65f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.62f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.62f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.80f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.80f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.62f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.80f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.83f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.83f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.80f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.71f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.74f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.74f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.71f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glEnd();

    // P

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.60f, 0.00f);

    glVertex2f(VALUE_FROM_PERCENT(0.84f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.87f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.87f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.84f, persent) + x_pos, VALUE_FROM_PERCENT(0.20f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.84f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.84f, persent) + x_pos, VALUE_FROM_PERCENT(0.55f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.93f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, persent) + x_pos, VALUE_FROM_PERCENT(0.60f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.93f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);

    glVertex2f(VALUE_FROM_PERCENT(0.84f, persent) + x_pos, VALUE_FROM_PERCENT(0.425f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, persent) + x_pos, VALUE_FROM_PERCENT(0.425f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.96f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);
    glVertex2f(VALUE_FROM_PERCENT(0.84f, persent) + x_pos, VALUE_FROM_PERCENT(0.375f, persent) + y_pos);

    glEnd();
}

// Astromedicomp

// Shriniwas name code

void suj_s(void)
{
    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.95f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.95f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.95f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.895f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.895f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.95f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.95f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.95f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.80f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.80f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.95f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.75f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.95f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();
}

void suj_h(void)
{
    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.735f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.685f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.685f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.735f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.595f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.545f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.545f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.595f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.2f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.685f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.03f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.595f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.03f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.595f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.03f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.685f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.03f, suj_percent), 0.0f);
    glEnd();
}

void suj_r(void)
{
    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.52f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.47f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.47f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.52f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.47f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.33f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.33f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.47f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.47f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.33f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.33f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.47f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.38f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.33f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.33f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.38f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.47f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.41f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.33f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.39f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();
}

void suj_i(void)
{
    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.305f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.115f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.115f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.305f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.235f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.185f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.185f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.235f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.305f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.115f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.115f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.305f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();
}

void suj_n(void)
{
    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.09f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.09f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.10f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.10f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.09f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.05f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();
}

void suj_i2(void)
{
    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.125f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.315f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.315f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.125f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.195f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.245f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.245f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.195f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.125f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.315f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.315f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.125f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();
}

void suj_v(void)
{
    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.34f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.40f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.45f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.40f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.53f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.47f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.42f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.47f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();
}

void suj_a(void)
{
    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.555f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.610f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.665f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.625f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.690f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.745f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.675f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.635f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.605f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.02f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.695f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.02f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.695f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.03f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.605f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.03f, suj_percent), 0.0f);
    glEnd();
}

void suj_s2(void)
{
    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.77f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.96f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.96f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.77f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.77f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.82f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.82f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.77f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.77f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.96f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.96f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.77f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.04f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.91f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.96f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(0.00f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.96f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.91f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.77f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.96f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.12f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.96f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glVertex3f(suj_x + suj_VALUE_FROM_PERCENT(0.77f, suj_percent), suj_y + suj_VALUE_FROM_PERCENT(-0.20f, suj_percent), 0.0f);
    glEnd();
}

// Shriniwas name code

// sagar name code

void drawSagarName(float startingPointX, float startingPointY, float width, float thickness, float SR_namePercent)
{
    float originalStartingPointX = startingPointX;

    letterS(startingPointX, startingPointY, width, thickness, SR_namePercent);

    startingPointX = startingPointX + width;

    letterA(startingPointX, startingPointY, width, thickness, SR_namePercent);

    startingPointX = startingPointX + width + thickness / 1.3f;

    letterG(startingPointX, startingPointY, width, thickness, SR_namePercent);

    startingPointX = startingPointX + width;

    letterA(startingPointX, startingPointY, width, thickness, SR_namePercent);

    startingPointX = startingPointX + width + thickness / 1.3f;

    letterR(startingPointX, startingPointY, width, thickness, SR_namePercent);

    startingPointX = originalStartingPointX;
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

// sagar name code

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
