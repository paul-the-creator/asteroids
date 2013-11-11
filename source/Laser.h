/**
 * @file Laser.h
 * @brief Provides class for laser object
 * @author paul-the-creator
 * @date 2013
 */

#ifndef LASER_H
#define LASER_H

#include "Bullet.h"

/**
 * @class Laser
 * @brief class for laser object
 * @author paul-the-creator
 * @date 2013
 */
class Laser : public Bullet
{
public:
    Laser() { createGeometry(); }
    Laser(int worldWidth, int worldHeight, PointF center, float angle, float scaleFactor = 1, float accFactor = 30.0, float dragFactor = 0)
        : Bullet(worldWidth, worldHeight, center, angle, scaleFactor, accFactor, dragFactor)
    {
        this->endPoint_ = center;
        this->shootingTimer_ = glutGet(GLUT_ELAPSED_TIME);

        createGeometry();
    }

    virtual ~Laser() { }

#define LASER_LENGTH 20

    /**
      * @brief function returns laser radius
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
    /**
      * @brief function permormce special update for this object type
      * @remarks function is virtual
      * @return void
      */
    virtual void additionalUpdate();

private:
    /**
      * @brief function generates lazer's shape points
      * @return void
      */
    virtual void createGeometry();
    
private:
    /// laser end point
    PointF endPoint_;
    /// time value in ms for proportional laser increasing
    int shootingTimer_;
};

#endif // LASER_H
