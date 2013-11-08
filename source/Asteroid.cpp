/**
 * @file Asteroid.cpp
 * @brief Provides class for asteroid object
 * @author paul-the-creator
 * @date 2013
 */

#include "Asteroid.h"
#include "GL/glut.h"
#include <algorithm>

void Asteroid::createGeometry()
{
    // Creating asteroid geometry
    int minRadius = 30;
    int maxRadius = MAX_RADIUS;
    int granularity = 20;
    int minVary = 20;
    int maxVary = 70;

    for(double ang = 0; ang < 2 * M_PI; ang += 2 * M_PI / granularity)
    {
        int angleVaryPc = randomValue(minVary, maxVary);
        double angleVaryRadians = (2 * M_PI / granularity) * static_cast<double>(angleVaryPc) / 100;
        double angleFinal = ang + angleVaryRadians - (M_PI / granularity);
        int radius = randomValue(minRadius, maxRadius);
        float x = static_cast<float>(sin(angleFinal) * radius);
        float y = static_cast<float>(-cos(angleFinal) * radius);
        shapePoints_.push_back(PointF(x, y));
    }

    lineColor_ = WHITE;
    polygonColor_ = BLACK;
}

void Asteroid::additionalUpdate()
{
    angle_ += rotFactor_;
}
