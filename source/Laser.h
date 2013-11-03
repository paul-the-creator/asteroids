/**
 * @file Laser.h
 * @brief Provides class for laser object
 * @author paul-the-creator
 * @date 2013
 */

#ifndef LASER_H
#define LASER_H

#include "Bullet.h"
#include <GL/glut.h>

/**
 * @class Laser
 * @brief class for laser object
 * @author paul-the-creator
 * @date 2013
 */
class Laser : public Bullet
{
public:
    /**
      * @brief constructors
      */
    Laser() { }
    Laser(int worldWidth, int worldHeight, PointF center, float angle, float scaleFactor = 1, float accFactor = 30.0, float dragFactor = 0)
        : Bullet(worldWidth, worldHeight, center, angle, scaleFactor, accFactor, dragFactor)
    {
        this->endPoint_ = center;
        this->shootingTimer_ = glutGet(GLUT_ELAPSED_TIME);
    }

    ~Laser() { }

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
      * @brief function returns laser radius
      * @remarks function needed for collision detection
      * @remarks function is virtual
      * @return int - radius value
      */
	virtual int getRadius() { return 0; }
    
#define LASER_LENGTH 20
private:
    PointF endPoint_;
    int shootingTimer_;
};

#endif // LASER_H
