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
}

void Asteroid::draw()
{
    update();

    angle_ += rotFactor_;

    glPushMatrix();
    glTranslatef(center_.x, center_.y, 0);
    glScalef(scaleFactor_, scaleFactor_, 1);
    glRotatef(angle_, 0, 0, 1);

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
        for(auto &point: shapePoints_)
            glVertex2f(point.x, point.y);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        for(auto &point: shapePoints_)
            glVertex2f(point.x, point.y);
    glEnd();

    glPopMatrix();
}
