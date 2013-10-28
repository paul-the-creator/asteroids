#ifndef FLYINGSAUCER_H
#define FLYINGSAUCER_H

#include "Object.h"
#include "Point.h"

class   FlyingSaucer : public Object
{
public:
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

#define MAX_LENGTH 50
    virtual void draw();
    virtual int getRadius() { return scaleFactor_ * 0.75 * MAX_LENGTH; }
};

#endif // FLYINGSAUCER_H
