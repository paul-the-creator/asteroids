#include "FlyingSaucer.h"
#include <GL/glut.h>

void FlyingSaucer::draw()
{
    update();

    glPushMatrix();
    glTranslatef(center_.x, center_.y, 0);
    glScalef(scaleFactor_, scaleFactor_, 1);
    glRotatef(angle_, 0, 0, 1);
    glColor3f(1, 1, 1);

    //drawing saucer
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.1*MAX_LENGTH, 0.2*MAX_LENGTH);
        glVertex2f(0.5*MAX_LENGTH, 0);
        glVertex2f(0.25*MAX_LENGTH, -0.15*MAX_LENGTH);
        glVertex2f(-0.25*MAX_LENGTH, -0.15*MAX_LENGTH);
        glVertex2f(-0.5*MAX_LENGTH, 0);
        glVertex2f(-0.1*MAX_LENGTH, 0.2*MAX_LENGTH);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-0.5*MAX_LENGTH, 0);
        glVertex2f(0.5*MAX_LENGTH, 0);
        glVertex2f(-0.25*MAX_LENGTH, 0.1*MAX_LENGTH);
        glVertex2f(0.25*MAX_LENGTH, 0.1*MAX_LENGTH);
    glEnd();

    //drawing power field
    int curTime = glutGet(GLUT_ELAPSED_TIME);
    float colorFactor = static_cast<float>(curTime % 5) / 5;
    glColor3f(0, colorFactor, colorFactor);

    glBegin(GL_LINE_LOOP);
       for(int i = 0; i < 360; ++i)
           glVertex2f(cos(2 * M_PI * i / 360) * 0.55 * MAX_LENGTH, sin(2 * M_PI * i / 360) * 0.35 * MAX_LENGTH);
    glEnd();

    glPopMatrix();
}

