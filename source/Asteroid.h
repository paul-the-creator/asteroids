/**
 * @file Asteroid.h
 * @brief Provides class for asteroid object
 * @author paul-the-creator
 * @date 2013
 */

#ifndef ASTEROID_H
#define ASTEROID_H

#include "Object.h"

/**
 * @class Asteroid
 * @brief class for asteroid objects
 * @author paul-the-creator
 * @date 2013
 */
class Asteroid : public Object
{
public:
    Asteroid() { createGeometry(); }
    Asteroid(int worldWidth, int worldHeight, PointF center, float angle, float scaleFactor = 1)
        : Object(worldWidth, worldHeight, scaleFactor, 2.5)
    {
        this->center_ = center;
        this->angle_ = angle;
        this->velocityVec_ = this->getDirection() * (accFactor_ / scaleFactor);
        this->rotFactor_ = static_cast<float>(randomValue(1, 10)) / 10;

        createGeometry();
        loadTexture("../other/asteroid_texture.jpg");
    }

    virtual ~Asteroid() { }

#define MAX_RADIUS 60
    /**
      * @brief function returns asteroid radius
      * @remarks function needed for collision detection
      * @remarks function is virtual
      * @return int - radius value
      */
    virtual int getRadius() { return scaleFactor_ * MAX_RADIUS; }

protected:
    /**
      * @brief function permormce special update for this object type
      * @remarks function is virtual
      * @return void
      */
    virtual void additionalUpdate();

private:
    /**
      * @brief function generates asteroid's shape points
      * @return void
      */
    virtual void createGeometry();
    /// variable sets rotation speed
    float rotFactor_;
};

#endif // ASTEROID_H
