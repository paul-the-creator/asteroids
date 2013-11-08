/**
 * @file Object.cpp
 * @brief Provides main abstract class for game objects
 * @author paul-the-creator
 * @date 2013
 */

#include "Object.h"

void Object::update()
{
    updatePosition();
    checkWorldPosition();
    additionalUpdate();
}

void Object::updatePosition()
{
    // Update position based on velocity vector
    center_ += velocityVec_;

    // Use Stokes' law to apply drag to the object
    velocityVec_.x -= velocityVec_.x * dragFactor_;
    velocityVec_.y -= velocityVec_.y * dragFactor_;
}

void Object::checkWorldPosition()
{
    // Keep object in game world
    if (center_.x < -worldWidth_/2) center_.x += worldWidth_;
    if (center_.x >= worldWidth_/2) center_.x -= worldWidth_;
    if (center_.y < -worldHeight_/2) center_.y += worldHeight_;
    if (center_.y >= worldHeight_/2) center_.y -= worldHeight_;
}
