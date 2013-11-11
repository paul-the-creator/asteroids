/**
 * @file FlyingSaucer.h
 * @brief Provides class for saucer object
 * @author paul-the-creator
 * @date 2013
 */

#ifndef FLYINGSAUCER_H
#define FLYINGSAUCER_H

#include "Object.h"

/**
 * @class FlyingSaucer
 * @brief class for saucer objects
 * @author paul-the-creator
 * @date 2013
 */
class   FlyingSaucer : public Object
{
public:
    FlyingSaucer() { createGeometry(); }
    FlyingSaucer(int worldWidth, int worldHeight, PointF center) : Object(worldWidth, worldHeight)
    {
        this->center_ = center;
        this->angle_ = 0;
        this->accFactor_ = 2;
        this->velocityVec_ = PointF();
        this->scaleFactor_ = static_cast<float>(randomValue(5, 12)) / 10;

        createGeometry();
        loadTexture("../other/asteroid_texture.jpg");
        setFollowingByLine();
    }

    virtual ~FlyingSaucer() { }

#define MAX_LENGTH 50

    /**
      * @brief function returns saucer radius
      * @remarks function needed for collision detection
      * @remarks function is virtual
      * @return int - radius value
      */
    virtual int getRadius() { return scaleFactor_ * 0.75 * MAX_LENGTH; }

private:
    /**
      * @brief function generates saucer's shape points
      * @return void
      */
    virtual void createGeometry();
};

#endif // FLYINGSAUCER_H
