#ifndef LASER_H
#define LASER_H

#include "Bullet.h"
#include <GL/glut.h>

class Laser : public Bullet
{
public:
    Laser() { }
    Laser(int worldWidth, int worldHeight, PointF center, float angle, float scaleFactor = 1, float accFactor = 30.0, float dragFactor = 0)
        : Bullet(worldWidth, worldHeight, center, angle, scaleFactor, accFactor, dragFactor)
    {
        this->endPoint_ = center;
        this->shootingTimer_ = glutGet(GLUT_ELAPSED_TIME);
    }

    ~Laser() { }

	virtual void update();
    virtual void draw();
	virtual int getRadius() { return 0; }
    
#define LASER_LENGTH 20
private:
    PointF endPoint_;
    int shootingTimer_;
};

#endif // LASER_H
