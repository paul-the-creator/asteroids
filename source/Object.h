#ifndef OBJECT_H
#define OBJECT_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <random>
#include <time.h>
#include "Point.h"

inline int randomValue(int minValue, int maxValue)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);
    return dis(gen);
}

class Object
{
public:
    Object() { }
    Object(int worldWidth, int worldHeight, float scaleFactor = 1, float accFactor = 0, float dragFactor = 0)
    {
        setMainParameters(worldWidth, worldHeight, scaleFactor, accFactor, dragFactor);
    }

    ~Object() { }

    inline void setMainParameters(int worldWidth, int worldHeight, float scaleFactor, float accFactor, float dragFactor)
    {
        this->worldWidth_ = worldWidth;
        this->worldHeight_ = worldHeight;
        this->scaleFactor_ = scaleFactor;
        this->accFactor_ = accFactor;
        this->dragFactor_ = dragFactor;
        this->isCollision_ = false;
    }

    virtual void rotate(int angle);
    virtual void move();
    virtual void update();
    virtual void draw() = 0;
    virtual int getRadius() = 0;

    inline void setCollision() { isCollision_ = true; }
    bool isCollision() const { return isCollision_; }

    inline PointF getCenter() const { return center_; }
    inline float getAngle() const { return angle_; }
    inline float getScaleFactor() const { return scaleFactor_; }
    inline PointF getDirection()
    {
        //normalized vector of the direction
        float xN = static_cast<float>(sin(2 * M_PI * (angle_ / 360)));
        float yN = static_cast<float>(cos(2 * M_PI * (angle_ / 360)));
        return PointF(-xN, yN);
    }

    inline void followToPoint(PointF point)
    {
        PointF followDir = point - center_;
        velocityVec_ = followDir.normalized() * accFactor_;
    }

protected:
    //game world size
    int worldWidth_, worldHeight_;
    //object center position
    PointF center_;
    //object angle of rotation
    float angle_;
    //object velocity vector
    PointF velocityVec_;
    //object acceleration factor
    float accFactor_;
    //object drag factor
    float dragFactor_;
    //object scale factor
    float scaleFactor_;
    //collision flag
    bool isCollision_;
};

#endif // OBJECT_H
