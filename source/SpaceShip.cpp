#include "SpaceShip.h"
#include <GL/glut.h>

PointF SpaceShip::getGunPosition()
{
    PointF dirVec = this->getDirection();
    PointF gunPosition = center_ + dirVec * 10;
    return gunPosition;
}

void SpaceShip::draw()
{
    update();
    glPushMatrix();
    glTranslatef(center_.x, center_.y, 0);
    glScalef(scaleFactor_, scaleFactor_, 1);
    glRotatef(angle_, 0, 0, 1);
    glColor3f(1, 1, 1);

    //drawing ship
    glBegin(GL_LINE_LOOP);
        glVertex2f(0, MAX_SHIP_LENGTH);
        glVertex2f(0.6*MAX_SHIP_LENGTH, -0.5*MAX_SHIP_LENGTH);
        glVertex2f(0, 0);
        glVertex2f(-0.6*MAX_SHIP_LENGTH, -0.5*MAX_SHIP_LENGTH);
    glEnd();

    //drawing engine track
    float engTrack = 2 * sqrt(pow(velocityVec_.x, 2) + pow(velocityVec_.y, 2));
    glColor3f(0, 0.7, 0.15 * engTrack);
    glBegin(GL_LINES);
        glVertex2f(-0.25*MAX_SHIP_LENGTH, -0.5*MAX_SHIP_LENGTH);
        glVertex2f(-0.25*MAX_SHIP_LENGTH, -0.5*MAX_SHIP_LENGTH - engTrack);
        glVertex2f(0, -0.5*MAX_SHIP_LENGTH);
        glVertex2f(0, -0.5*MAX_SHIP_LENGTH - engTrack);
        glVertex2f(0.25*MAX_SHIP_LENGTH, -0.5*MAX_SHIP_LENGTH);
        glVertex2f(0.25*MAX_SHIP_LENGTH, -0.5*MAX_SHIP_LENGTH - engTrack);
    glEnd();

    glPopMatrix();
}
