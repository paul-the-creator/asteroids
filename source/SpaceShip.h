/**
 * @file SpaceShip.h
 * @brief Provides class for space ship object
 * @author paul-the-creator
 * @date 2013
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Object.h"
#include "EngineTrack.h"
#include <memory>

/**
 * @class SpaceShip
 * @brief class for space ship objects
 * @author paul-the-creator
 * @date 2013
 */
class SpaceShip : public Object
{
public:
    SpaceShip() { createGeometry(); }
    SpaceShip(int worldWidth, int worldHeight, float scaleFactor = 1, float accFactor = 0.35, float dragFactor = 0.03)
        : Object(worldWidth, worldHeight, scaleFactor, accFactor, dragFactor)
    {
        this->angle_ = 0;
        engineTrack_ = std::shared_ptr <EngineTrack>( new EngineTrack(worldWidth, worldHeight, scaleFactor, accFactor, dragFactor) );

        createGeometry();
    }

    virtual ~SpaceShip() { }

#define MAX_SHIP_LENGTH 20

    /**
      * @brief Function provides object moving
      * @remarks function updates velocity
      * @return void
      */
    void move();
    /**
      * @brief Function provides object rotation
      * @remarks function updates object's angle
      * @return void
      */
    void rotate(int angle);
    /**
      * @brief function returns space ship radius
      * @remarks function needed for collision detection
      * @remarks function is virtual
      * @return int - radius value
      */
    virtual int getRadius() { return scaleFactor_ * MAX_SHIP_LENGTH; }
    /**
      * @brief function returns space ship's gun position
      * @return PointF - position coorfinates
      */
    PointF getGunPosition();
    /**
      * @brief function returns pointer on engine track object
      * @return PointF - position coorfinates
      */
    inline EngineTrack* getEngineTrack() { return engineTrack_.get(); }

private:
    /**
      * @brief function generates ship's shape points
      * @return void
      */
    void createGeometry();

private:
    std::shared_ptr <EngineTrack> engineTrack_;
};

#endif // SPACESHIP_H
