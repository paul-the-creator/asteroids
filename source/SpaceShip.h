#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Object.h"
#include "Point.h"

class SpaceShip : public Object
{
public:
    SpaceShip() { }
    SpaceShip(int worldWidth, int worldHeight, float scaleFactor = 1, float accFactor = 0.35, float dragFactor = 0.03)
        : Object(worldWidth, worldHeight, scaleFactor, accFactor, dragFactor) { this->angle_ = 0; }

    ~SpaceShip() { }

#define MAX_SHIP_LENGTH 20
    virtual void draw();
    virtual int getRadius() { return scaleFactor_ * MAX_SHIP_LENGTH; }
    PointF getGunPosition();
};

#endif // SPACESHIP_H
