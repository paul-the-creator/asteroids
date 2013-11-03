/**
 * @file SpaceShip.h
 * @brief Provides class for space ship object
 * @author paul-the-creator
 * @date 2013
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Object.h"
#include "Point.h"

class SpaceShip : public Object
{
public:
    /**
      * @brief constructors
      */
    SpaceShip() { }
    SpaceShip(int worldWidth, int worldHeight, float scaleFactor = 1, float accFactor = 0.35, float dragFactor = 0.03)
        : Object(worldWidth, worldHeight, scaleFactor, accFactor, dragFactor) { this->angle_ = 0; }

    ~SpaceShip() { }

    /**
      * @brief draw function
      * @remarks function is virtual
      * @return void
      */
    virtual void draw();

#define MAX_SHIP_LENGTH 20
    /**
      * @brief function returns space ship radius
      * @remarks function needed for collision detection
      * @remarks function is virtual
      * @return int - radius value
      */
    virtual int getRadius() { return scaleFactor_ * MAX_SHIP_LENGTH; }
    PointF getGunPosition();
};

#endif // SPACESHIP_H
