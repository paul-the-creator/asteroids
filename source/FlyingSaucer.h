/**
 * @file FlyingSaucer.h
 * @brief Provides class for saucer object
 * @author paul-the-creator
 * @date 2013
 */

#ifndef FLYINGSAUCER_H
#define FLYINGSAUCER_H

#include "Object.h"
#include "Point.h"

/**
 * @class FlyingSaucer
 * @brief class for saucer objects
 * @author paul-the-creator
 * @date 2013
 */
class   FlyingSaucer : public Object
{
public:
    /**
      * @brief constructors
      */
    FlyingSaucer() { }
    FlyingSaucer(int worldWidth, int worldHeight, PointF center) : Object(worldWidth, worldHeight)
    {
        this->center_ = center;
        this->angle_ = 0;
        this->accFactor_ = 2;
        this->velocityVec_ = PointF();
        this->scaleFactor_ = static_cast<float>(randomValue(5, 12)) / 10;
    }

    ~FlyingSaucer() { }

    /**
      * @brief draw function
      * @remarks function is virtual
      * @return void
      */
    virtual void draw();

#define MAX_LENGTH 50
    /**
      * @brief function returns asteroid radius
      * @remarks function needed for collision detection
      * @remarks function is virtual
      * @return int - radius value
      */
    virtual int getRadius() { return scaleFactor_ * 0.75 * MAX_LENGTH; }
};

#endif // FLYINGSAUCER_H
