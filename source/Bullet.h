/**
 * @file Bullet.h
 * @brief Provides class for bullet object
 * @author paul-the-creator
 * @date 2013
 */

#ifndef BULLET_H
#define BULLET_H

#include "Object.h"
#include "Point.h"

/**
 * @class Bullet
 * @brief class for bullet object
 * @author paul-the-creator
 * @date 2013
 */
class Bullet : public Object
{
public:
    /**
      * @brief constructors
      */
    Bullet() { }
    Bullet(int worldWidth, int worldHeight, PointF center, float angle, float scaleFactor = 1, float accFactor = 10.0, float dragFactor = 0)
        : Object(worldWidth, worldHeight, scaleFactor, accFactor, dragFactor)
    {
        this->center_ = center;
        this->angle_ = angle;
        this->velocityVec_ = getDirection() * accFactor;
        this->angle_ = 0;
    }

    ~Bullet() { }

    /**
      * @brief update function
      * @remarks function updates object position
      * @return void
      */
	virtual void update();
    /**
      * @brief draw function
      * @remarks function is virtual
      * @return void
      */
    virtual void draw();
    /**
      * @brief function returns bullet radius
      * @remarks function needed for collision detection
      * @remarks function is virtual
      * @return int - radius value
      */
    virtual int getRadius() { return 0; }

};

#endif // BULLET_H
