/**
 * @file Bullet.cpp
 * @brief Provides class for bullet object
 * @author paul-the-creator
 * @date 2013
 */
#include "iostream"
#include "Bullet.h"
#include <GL/glut.h>

void Bullet::createGeometry()
{
    shapePoints_.push_back( PointF(-3, -3) );
    shapePoints_.push_back( PointF(-3, 3) );
    shapePoints_.push_back( PointF(3, 3) );
    shapePoints_.push_back( PointF(3, -3) );

    lineColor_ = WHITE;
    polygonColor_ = WHITE;
}

void Bullet::checkWorldPosition()
{
    //Remove bullet in case if it out game world
    if (center_.x < -worldWidth_/2 || center_.x >= worldWidth_/2 ||
        center_.y < -worldHeight_/2 || center_.y >= worldHeight_/2)
        this->setCollision();
}
