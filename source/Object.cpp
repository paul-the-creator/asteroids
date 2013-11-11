/**
 * @file Object.cpp
 * @brief Provides main abstract class for game objects
 * @author paul-the-creator
 * @date 2013
 */

#include "Object.h"
//#include <SOIL/SOIL.h>

void Object::update()
{
    updatePosition();
    checkWorldPosition();
    additionalUpdate();
}

void Object::updatePosition()
{
    // Updating velocity according to follow trajectory
    updateVelocity();
    // Update position based on velocity vector
    center_ += velocityVec_;
}

void Object::updateVelocity()
{
    if(this->updateVelocityFunc != nullptr)
        (this->*updateVelocityFunc)();

    // Use Stokes' law to apply drag to the object
    velocityVec_.x -= velocityVec_.x * dragFactor_;
    velocityVec_.y -= velocityVec_.y * dragFactor_;
}

void Object::checkWorldPosition()
{
    // Keep object in game world
    if (center_.x < -worldWidth_/2) center_.x += worldWidth_;
    if (center_.x >= worldWidth_/2) center_.x -= worldWidth_;
    if (center_.y < -worldHeight_/2) center_.y += worldHeight_;
    if (center_.y >= worldHeight_/2) center_.y -= worldHeight_;
}

void Object::loadTexture(std::string texturePath)
{
//    textureID_ = SOIL_load_OGL_texture(texturePath.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
//                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

//    if(textureID_ == 0)
//       std::cout << "SOIL loading error: '" << SOIL_last_result() << "' (" << "res_texture.png" << ")" << std::endl;

    //texture creation
    //glGenTextures(1, &textureID_);
    glBindTexture(GL_TEXTURE_2D, textureID_);
    //filter parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //wrap parameter
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    //
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}
