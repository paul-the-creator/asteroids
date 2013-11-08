/**
 * @file Laser.cpp
 * @brief Provides class for laser object
 * @author paul-the-creator
 * @date 2013
 */

#include "Laser.h"

void Laser::createGeometry()
{
    shapePoints_.clear();
    shapePoints_.push_back( PointF(0, 0) );
    shapePoints_.push_back( velocityVec_ * 1.5 );

    lineColor_ = BLUE;
    polygonColor_ = BLUE;
}

void Laser::checkWorldPosition()
{
    //Remove laser shoot in case if it out game world
    if (endPoint_.x < -worldWidth_/2 || endPoint_.x >= worldWidth_/2 ||
        endPoint_.y < -worldHeight_/2 || endPoint_.y >= worldHeight_/2)
        setCollision();
}

void Laser::additionalUpdate()
{
    //making effect of growing shoot
    if(glutGet(GLUT_ELAPSED_TIME) - shootingTimer_ > accFactor_ * 5)
    {
        //endPoint_ += velocityVec_;
        shapePoints_[1] += velocityVec_;
    }
}
