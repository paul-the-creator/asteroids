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
#include "GL/glut.h"
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
 * @struct RGB
 * @brief struct for color presentation
 * @author paul-the-creator
 * @date 2013
 */
#undef RGB
struct RGB
{
    RGB() { }
    RGB(float red, float green, float blue) : redComponent(red), greenComponent(green), blueComponent(blue) { }
    float redComponent;
    float greenComponent;
    float blueComponent;

};
#define WHITE RGB(1, 1, 1)
#define BLACK RGB(0, 0, 0)
#define RED RGB(1, 0, 0)
#define GREEN RGB(0, 1, 0)
#define BLUE RGB(0, 0, 1)
#define YELLOW RGB(1, 1, 0)


/**
 * @class Object
 * @brief Main abstract class for game objects
 * @author paul-the-creator
 * @date 2013
 */
class Object
{
public:
    Object() { }
    Object(int worldWidth, int worldHeight, float scaleFactor = 1, float accFactor = 0, float dragFactor = 0)
    {
        setMainParameters(worldWidth, worldHeight, scaleFactor, accFactor, dragFactor);
        followToPointFunc = nullptr;
        updateVelocityFunc = nullptr;
    }

    virtual ~Object() { }

    /**
      * @brief main update function
      * @remarks function updates object state
      * @return void
      */
    void update();
    /**
      * @brief function loads texture
      * @param texturePath - path to texture image
      * @return void
      */
    void loadTexture(std::string texturePath);
    /**
      * @brief function returns object radius
      * @remarks function needed for collision detection
      * @remarks function is empty virtual method; needed to be determined at inheritance class
      * @return int - radius value
      */
    virtual int getRadius() = 0;
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
      * @brief function returns direction vector
      * @return PointF - vector coordinates
      */
    inline const std::vector<PointF>& getShapePointsRef() { return shapePoints_; }
    /**
      * @brief function returns line color
      * @return RGB - line color
      */
    inline RGB getLineColor() { return lineColor_; }
    /**
      * @brief function returns polygon color
      * @return RGB - line color
      */
    inline RGB getPolygonColor() { return polygonColor_; }
    /**
      * @brief function returns texture ID
      * @return GLuint - texture ID
      */
    inline GLuint getTextureID() { return textureID_; }
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
      * @brief function leads object to follow the point
      * @param point - necessary point
      * @return void
      */
    inline void followToPoint(PointF point)
    {
        if(this->followToPointFunc != nullptr)
            (this->*followToPointFunc)(point);
    }
    /**
      * @brief function sets following trajectory as line
      * @return void
      */
    inline void setFollowingByLine()
    {
        followToPointFunc = &Object::followToPointByLine;
        updateVelocityFunc = nullptr;
    }
    /**
      * @brief function sets following trajectory as arc
      * @return void
      */
    inline void setFollowingByArc()
    {
        followToPointFunc = &Object::followToPointByArc;
        updateVelocityFunc = &Object::updateVelocityToArc;
    }
    /**
      * @brief function sets following trajectory as zig-zag
      * @return void
      */
    inline void setFollowingByZigZag()
    {
        followToPointFunc = &Object::followToPointByZigZag;
        updateVelocityFunc = &Object::updateVelocityToZigZag;
    }

protected:
    virtual void createGeometry() = 0;
    virtual void checkWorldPosition();
    virtual void additionalUpdate() { }

private:
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
      * @brief function updates object coordinates
      * @return void
      */
    void updatePosition();
    /**
      * @brief function updates velocity
      * @remarks changes velocity vector to follow to point
      * @return void
      */
    void updateVelocity();
    /**
      * @brief function changes velocity vector to follow the point by line trajectory
      * @return void
      */
    inline void followToPointByLine(PointF point)
    {
        PointF followDir = point - center_;
        velocityVec_ = followDir.normalized() * accFactor_;
    }
    /**
      * @brief function changes velocity vector to follow the point by arc trajectory
      * @return void
      */
    inline void followToPointByArc(PointF point)
    {
        PointF followDir = point - center_;
        followDir.normalize();
        velocityVec_ = PointF(followDir.y, -followDir.x) * accFactor_;
    }
    /**
      * @brief function changes velocity vector to follow the point by zig-zag trajectory
      * @return void
      */
    inline void followToPointByZigZag(PointF point)
    {
        PointF followDir = point - center_;
        followDir.normalize();
        //rotating vector by 45 deg
        const int angle = 45;
        float x = followDir.x * cos(angle) - followDir.y * sin(45);
        float y = followDir.y * cos(angle) + followDir.x * sin(angle);
        velocityVec_ = PointF(x, y) * accFactor_;
    }
    /**
      * @brief function updates velocity to follow the point by arc trajectory
      * @return void
      */
    inline void updateVelocityToArc()
    {
        //rotating velocity vector by some angle
        const int angle = 15;
        float x = velocityVec_.x * cos(angle) - velocityVec_.y * sin(angle);
        float y = velocityVec_.y * cos(angle) + velocityVec_.x * sin(angle);
        velocityVec_ = PointF(x, y);
    }
    /**
      * @brief function updates velocity to follow the point by zig-zag trajectory
      * @return void
      */
    inline void updateVelocityToZigZag()
    {
        int curTime = glutGet(GLUT_ELAPSED_TIME);
        float modTime = static_cast<float>(curTime % 50);
        if(modTime < 5 || modTime > 45)
            velocityVec_ = PointF(velocityVec_.y, -velocityVec_.x);
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
    //points
    std::vector<PointF> shapePoints_;
    //line color
    RGB lineColor_;
    //polygon color
    RGB polygonColor_;
    //texture ID
    GLuint textureID_;

private:
    //pointers on method
    void(Object::*followToPointFunc)(PointF point);
    void(Object::*updateVelocityFunc)();
};

#endif // OBJECT_H
