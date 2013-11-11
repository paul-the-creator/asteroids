/**
 * @file SpaceShip.cpp
 * @brief Provides class for space ship object
 * @author paul-the-creator
 * @date 2013
 */

#include "SpaceShip.h"

void SpaceShip::createGeometry()
{
    shapePoints_.push_back( PointF(0, MAX_SHIP_LENGTH) );
    shapePoints_.push_back( PointF(0.6*MAX_SHIP_LENGTH, -0.5*MAX_SHIP_LENGTH) );
    shapePoints_.push_back( PointF(0, 0) );
    shapePoints_.push_back( PointF(-0.6*MAX_SHIP_LENGTH, -0.5*MAX_SHIP_LENGTH) );

    lineColor_ = WHITE;
    polygonColor_ = BLACK;
}

void SpaceShip::move()
{
    //normalized vector of the direction
    PointF dirVec = this->getDirection();
    velocityVec_ += dirVec * accFactor_;
    engineTrack_->setVelocityVec(velocityVec_);
}

void SpaceShip::rotate(int angle)
{
    this->angle_ += angle;
    engineTrack_->setAngle(angle_);
}

PointF SpaceShip::getGunPosition()
{
    PointF dirVec = this->getDirection();
    PointF gunPosition = center_ + dirVec * 10;
    return gunPosition;
}
