#ifndef ASTEROID_H
#define ASTEROID_H

#include "Object.h"
#include "Point.h"
#include <vector>
#include <GL/glut.h>

class Asteroid : public Object
{
public:
    Asteroid() { }
    Asteroid(int worldWidth, int worldHeight, PointF center, float angle, float scaleFactor = 1)
        : Object(worldWidth, worldHeight, scaleFactor, 2.5)
    {
        this->center_ = center;
        this->angle_ = angle;
        this->velocityVec_ = this->getDirection() * (accFactor_ / scaleFactor);
        this->rotFactor_ = static_cast<float>(randomValue(1, 10)) / 10;

        createGeometry();
    }

    ~Asteroid() { }

#define MAX_RADIUS 60
    virtual void draw();
    virtual int getRadius() { return scaleFactor_ * MAX_RADIUS; }

private:
    void createGeometry();
    float rotFactor_;
    std::vector<PointF> shapePoints_;
};

#endif // ASTEROID_H
