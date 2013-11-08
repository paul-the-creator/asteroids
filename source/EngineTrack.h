/**
 * @file EngineTrack.h
 * @brief Provides class for engine track object
 * @author paul-the-creator
 * @date 2013
 */

#ifndef ENGINETRACK_H
#define ENGINETRACK_H

#include "Object.h"

/**
 * @class EngineTrack
 * @brief class for engine track object
 * @author paul-the-creator
 * @date 2013
 */
class EngineTrack : public Object
{
public:
    EngineTrack() { createGeometry(); }
    EngineTrack(int worldWidth, int worldHeight, float scaleFactor = 1, float accFactor = 0.35, float dragFactor = 0.03)
        : Object(worldWidth, worldHeight, scaleFactor, accFactor, dragFactor) { this->angle_ = 0; createGeometry();}

    virtual ~EngineTrack() { }

#define MAX_TRACK_LENGTH 10

    /**
      * @brief function sets new value fot velocity vector
      * @param[in] newVelocityVec - new value
      * @return void
      */
    inline void setVelocityVec(const PointF newVelocityVec) { this->velocityVec_ = newVelocityVec; }
    /**
      * @brief function sets new value fot angle
      * @param[in] newAngle - new value
      * @return void
      */
    inline void setAngle(const float newAngle) { this->angle_ = newAngle; }
    virtual int getRadius(){ return 0; }

protected:
    /**
      * @brief function permormce special update for this object type
      * @remarks function is virtual
      * @return void
      */
    virtual void additionalUpdate();

private:
    /**
      * @brief function generates asteroid's shape points
      * @return void
      */
    virtual void createGeometry();
};

#endif // ENGINETRACK_H
