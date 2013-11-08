/**
 * @file EngineTrack.cpp
 * @brief Provides class for engine track object
 * @author paul-the-creator
 * @date 2013
 */

#include "EngineTrack.h"

void EngineTrack::createGeometry()
{
    shapePoints_.push_back( PointF(-0.9*MAX_TRACK_LENGTH, -MAX_TRACK_LENGTH) );
    shapePoints_.push_back( PointF(-0.6*MAX_TRACK_LENGTH, -MAX_TRACK_LENGTH) );
    shapePoints_.push_back( PointF(-0.3*MAX_TRACK_LENGTH, -MAX_TRACK_LENGTH) );
    shapePoints_.push_back( PointF(0, -MAX_TRACK_LENGTH) );
    shapePoints_.push_back( PointF(0.3*MAX_TRACK_LENGTH, -MAX_TRACK_LENGTH) );
    shapePoints_.push_back( PointF(0.6*MAX_TRACK_LENGTH, -MAX_TRACK_LENGTH) );
    shapePoints_.push_back( PointF(0.9*MAX_TRACK_LENGTH, -MAX_TRACK_LENGTH) );
    shapePoints_.push_back( PointF(0, -0.2*MAX_TRACK_LENGTH) );

    lineColor_ = BLACK;
    polygonColor_ = BLACK;
}

void EngineTrack::additionalUpdate()
{
    float engTrack = 2 * sqrt(pow(velocityVec_.x, 2) + pow(velocityVec_.y, 2));
    lineColor_ = RGB(0, 0.07 * engTrack, 0.15 * engTrack);

    shapePoints_[1] = PointF(-0.6*MAX_TRACK_LENGTH, -MAX_TRACK_LENGTH - engTrack);
    shapePoints_[3] = PointF(0, -MAX_TRACK_LENGTH - engTrack);
    shapePoints_[5] = PointF(0.6*MAX_TRACK_LENGTH, -MAX_TRACK_LENGTH - engTrack);
}
