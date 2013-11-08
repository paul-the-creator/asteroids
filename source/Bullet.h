/**
 * @file Bullet.h
 * @brief Provides class for bullet object
 * @author paul-the-creator
 * @date 2013
 */

#ifndef BULLET_H
#define BULLET_H

#include "Object.h"

/**
 * @class Bullet
 * @brief class for bullet object
 * @author paul-the-creator
 * @date 2013
 */
class Bullet : public Object
{
public:
    Bullet() { createGeometry(); }
    Bullet(int worldWidth, int worldHeight, PointF center, float angle, float scaleFactor = 1, float accFactor = 10.0, float dragFactor = 0)
        : Object(worldWidth, worldHeight, scaleFactor, accFactor, dragFactor)
    {
        this->center_ = center;
        this->angle_ = angle;
        this->velocityVec_ = getDirection() * accFactor;
        this->angle_ = 0;

        createGeometry();
    }

    virtual ~Bullet() { }

    /**
      * @brief function returns bullet radius
      * @remarks function needed for collision detection
      * @remarks function is virtual
      * @return int - radius value
      */
    virtual int getRadius() { return 0; }

protected:
    /**
      * @brief function checks object position inside game world
      * @remarks function is virtual
      * @return void
      */
    virtual void checkWorldPosition();

private:
    /**
      * @brief function generates asteroid's shape points
      * @return void
      */
    void createGeometry();
};

#endif // BULLET_H
