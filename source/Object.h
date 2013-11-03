/**
 * @file Object.h
 * @brief Provides main abstract class for game objects
 * @author paul-the-creator
 * @date 2013
 */

#ifndef OBJECT_H
#define OBJECT_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <random>
#include <time.h>
#include "Point.h"

/**
  * @brief Function returns random number
  * @param[in] minValue - low range
  * @param[in] maxValue - up range
  * @return int - random value
  */
inline int randomValue(int minValue, int maxValue)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);
    return dis(gen);
}

/**
 * @class Object
 * @brief Main abstract class for game objects
 * @author paul-the-creator
 * @date 2013
 */
class Object
{
public:
    /**
      * @brief constructors
      */
    Object() { }
    Object(int worldWidth, int worldHeight, float scaleFactor = 1, float accFactor = 0, float dragFactor = 0)
    {
        setMainParameters(worldWidth, worldHeight, scaleFactor, accFactor, dragFactor);
    }

    ~Object() { }

    /**
      * @brief Function sets parameters initial state
      * @param worldWidth - game scene width
      * @param worldHeight - game scene height
      * @param scaleFactor - scale parameter
      * @param accFactor - acceleration parameter
      * @param dragFactor - drag parameter
      * @return void
      */
    inline void setMainParameters(int worldWidth, int worldHeight, float scaleFactor, float accFactor, float dragFactor)
    {
        this->worldWidth_ = worldWidth;
        this->worldHeight_ = worldHeight;
        this->scaleFactor_ = scaleFactor;
        this->accFactor_ = accFactor;
        this->dragFactor_ = dragFactor;
        this->isCollision_ = false;
    }

    /**
      * @brief Function provides object moving
      * @remarks function updates velocity
      * @return void
      */
    virtual void rotate(int angle);
    /**
      * @brief Function provides object moving
      * @remarks function updates velocity
      * @return void
      */
    virtual void move();
    /**
      * @brief update function
      * @remarks function updates object position
      * @return void
      */
    virtual void update();
    /**
      * @brief draw function
      * @remarks function is empty virtual method; needed to be determined at inheritance class
      * @return int - radius value
      * @return void
      */
    virtual void draw() = 0;
    /**
      * @brief function returns bullet radius
      * @remarks function needed for collision detection
      * @remarks function is empty virtual method; needed to be determined at inheritance class
      * @return int - radius value
      */
    virtual int getRadius() = 0;
    /**
      * @brief function sets collision flag
      * @return void
      */
    inline void setCollision() { isCollision_ = true; }
    /**
      * @brief function returns collision flag
      * @return bool - flag value
      */
    bool isCollision() const { return isCollision_; }
    /**
      * @brief function returns object center
      * @return PointF - center coordinates
      */
    inline PointF getCenter() const { return center_; }
    /**
      * @brief function returns angle value
      * @return float - angle
      */
    inline float getAngle() const { return angle_; }
    /**
      * @brief function returns scale parameter
      * @return float - scale parameter
      */
    inline float getScaleFactor() const { return scaleFactor_; }
    /**
      * @brief function returns direction vector
      * @return PointF - vector coordinates
      */
    inline PointF getDirection()
    {
        //normalized vector of the direction
        float xN = static_cast<float>(sin(2 * M_PI * (angle_ / 360)));
        float yN = static_cast<float>(cos(2 * M_PI * (angle_ / 360)));
        return PointF(-xN, yN);
    }
    /**
      * @brief function changes velocity vector to follow to point
      * @param point - necessary point
      * @return void
      */
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
