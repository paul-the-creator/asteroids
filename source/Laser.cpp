#include "Laser.h"

void Laser::update()
{
    // Update position based on velocity vector
    center_ += velocityVec_;

    //making effect of growing shoot
    if(glutGet(GLUT_ELAPSED_TIME) - shootingTimer_ > accFactor_ * 5)
        endPoint_ += velocityVec_;

    // Use Stokes' law to apply drag to the laser shoot
    velocityVec_.x -= velocityVec_.x * dragFactor_;
    velocityVec_.y -= velocityVec_.y * dragFactor_;

    //Remove laser shoot in case if it out game world
    if (endPoint_.x < -worldWidth_/2 || endPoint_.x >= worldWidth_/2 ||
        endPoint_.y < -worldHeight_/2 || endPoint_.y >= worldHeight_/2)
        setCollision();
}

void Laser::draw()
{
    update();

    glPushMatrix();
    glTranslatef(center_.x, center_.y, 0);
    glScalef(scaleFactor_, scaleFactor_, 1);
    glRotatef(angle_, 0, 0, 1);
    glColor3f(0, 0.5, 1);

    //drawing bullet
    glBegin(GL_LINES);
        glVertex2f(0, 0);
        glVertex2f(endPoint_.x - center_.x, endPoint_.y - center_.y);
    glEnd();

    glPopMatrix();
}

