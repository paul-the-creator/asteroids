#ifndef BULLET_H
#define BULLET_H

#include "Object.h"
#include "Point.h"

class Bullet : public Object
{
public:
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

	virtual void update();
    virtual void draw();
	virtual int getRadius() { return 0; }

};

#endif // BULLET_H
