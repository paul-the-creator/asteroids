#include "Bullet.h"
#include <GL/glut.h>

void Bullet::update()
{
    // Update position based on velocity vector
    center_ += velocityVec_;

    // Use Stokes' law to apply drag to the bullet
    velocityVec_.x -= velocityVec_.x * dragFactor_;
    velocityVec_.y -= velocityVec_.y * dragFactor_;

    //Remove bullet in case if it out game world
    if (center_.x < -worldWidth_/2 || center_.x >= worldWidth_/2 ||
        center_.y < -worldHeight_/2 || center_.y >= worldHeight_/2)
        this->setCollision();
}

void Bullet::draw()
{
    update();

    glPushMatrix();
    glTranslatef(center_.x, center_.y, 0);
    glScalef(scaleFactor_, scaleFactor_, 1);
    glRotatef(angle_, 0, 0, 1);
    glColor3f(1, 1, 1);

    //drawing bullet
    glBegin(GL_QUADS);
        glVertex2f(-3, -3);
        glVertex2f(-3, 3);
        glVertex2f(3, 3);
        glVertex2f(3, -3);
    glEnd();

    glPopMatrix();
}
