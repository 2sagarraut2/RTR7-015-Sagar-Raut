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
#include <stdlib.h>
#include <math.h>

#define VALUE_FROM_PERCENT(complete_value, percent) ((complete_value * percent) / 100)

void renderFighterJet(float xPosition, float yPosition, float percent)
{

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition - 0.075f), percent), VALUE_FROM_PERCENT((yPosition + 0.12f), percent));
    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition), percent), VALUE_FROM_PERCENT((yPosition + 0.12f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition), percent), VALUE_FROM_PERCENT((yPosition + 0.07f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition - 0.075f), percent), VALUE_FROM_PERCENT((yPosition + 0.07f), percent));

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition - 0.075f), percent), VALUE_FROM_PERCENT((yPosition - 0.06f), percent));
    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition), percent), VALUE_FROM_PERCENT((yPosition - 0.06f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition), percent), VALUE_FROM_PERCENT((yPosition - 0.11f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition - 0.075f), percent), VALUE_FROM_PERCENT((yPosition - 0.11f), percent));

    glEnd();

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition - 0.03f), percent), VALUE_FROM_PERCENT((yPosition + 0.2f), percent));
    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition), percent), VALUE_FROM_PERCENT((yPosition + 0.2f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition), percent), VALUE_FROM_PERCENT((yPosition - 0.2f), percent));
    // glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition - 0.03f), percent), VALUE_FROM_PERCENT((yPosition - 0.2f), percent));

    glEnd();

    glBegin(GL_TRIANGLES);

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition), percent), VALUE_FROM_PERCENT((yPosition + 0.2f), percent));
    // glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.05f), percent), VALUE_FROM_PERCENT((yPosition), percent));
    // glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition), percent), VALUE_FROM_PERCENT((yPosition - 0.2f), percent));

    glEnd();

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition), percent), VALUE_FROM_PERCENT((yPosition + 0.07f), percent));
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.22f), percent), VALUE_FROM_PERCENT((yPosition + 0.07f), percent));
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.22f), percent), VALUE_FROM_PERCENT((yPosition - 0.07f), percent));
    glVertex2f(VALUE_FROM_PERCENT((xPosition), percent), VALUE_FROM_PERCENT((yPosition - 0.07f), percent));

    glEnd();

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.03f), percent), VALUE_FROM_PERCENT((yPosition + 0.3f), percent));
    // glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.07f), percent), VALUE_FROM_PERCENT((yPosition + 0.3f), percent));

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.20f), percent), VALUE_FROM_PERCENT((yPosition), percent));
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.07f), percent), VALUE_FROM_PERCENT((yPosition), percent));

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.03f), percent), VALUE_FROM_PERCENT((yPosition - 0.3f), percent));
    // glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.07f), percent), VALUE_FROM_PERCENT((yPosition - 0.3f), percent));

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.20f), percent), VALUE_FROM_PERCENT((yPosition), percent));
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.07f), percent), VALUE_FROM_PERCENT((yPosition), percent));

    glEnd();

    glBegin(GL_QUADS);

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.22f), percent), VALUE_FROM_PERCENT((yPosition + 0.03f), percent));
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.28f), percent), VALUE_FROM_PERCENT((yPosition + 0.03f), percent));
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.28f), percent), VALUE_FROM_PERCENT((yPosition - 0.03f), percent));
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.22f), percent), VALUE_FROM_PERCENT((yPosition - 0.03f), percent));

    glEnd();

    glBegin(GL_TRIANGLES);

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.28f), percent), VALUE_FROM_PERCENT((yPosition + 0.03f), percent));
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.4f), percent), VALUE_FROM_PERCENT((yPosition), percent));
    glVertex2f(VALUE_FROM_PERCENT((xPosition + 0.28f), percent), VALUE_FROM_PERCENT((yPosition - 0.03f), percent));

    glEnd();
}
