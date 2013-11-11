/**
 * @file Renderer.cpp
 * @brief Provides class for object rendering
 * @author paul-the-creator
 * @date 2013
 */

#include "Renderer.h"
#include "GL/glut.h"

void Renderer:: vectorDraw(Object& object)
{
    object.update();

    auto shapePointsRef = object.getShapePointsRef();
    RGB lineColor = object.getLineColor();
    RGB polygonColor = object.getPolygonColor();

    glPushMatrix();
    glTranslatef(object.getCenter().x, object.getCenter().y, 0);
    glScalef(object.getScaleFactor(), object.getScaleFactor(), 1);
    glRotatef(object.getAngle(), 0, 0, 1);

    glColor3f(polygonColor.redComponent, polygonColor.greenComponent, polygonColor.blueComponent);
    glBegin(GL_POLYGON);
        for(auto &point: shapePointsRef)
            glVertex2f(point.x, point.y);
    glEnd();

    glColor3f(lineColor.redComponent, lineColor.greenComponent, lineColor.blueComponent);
    glBegin(GL_LINE_LOOP);
        for(auto &point: shapePointsRef)
            glVertex2f(point.x, point.y);
    glEnd();

    glPopMatrix();
}

void Renderer::spriteDraw(Object& object)
{
    if(object.getTextureID() == 0)
        vectorDraw(object);

    object.update();

    glPushMatrix();
    glTranslatef(object.getCenter().x, object.getCenter().y, 0);
    glScalef(object.getScaleFactor(), object.getScaleFactor(), 1);
    glRotatef(object.getAngle(), 0, 0, 1);

    //RGB lineColor = object.getLineColor();
    //glColor3f(lineColor.redComponent, lineColor.greenComponent, lineColor.blueComponent);
    glBindTexture(GL_TEXTURE_2D, object.getTextureID());
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -10.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -10.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  10.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  10.0f,  1.0f);
    glEnd();

    glPopMatrix();
}
