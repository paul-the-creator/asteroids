/**
 * @file Renderer.h
 * @brief Provides class for object rendering
 * @author paul-the-creator
 * @date 2013
 */

#ifndef RENDERER_H
#define RENDERER_H

#include "Object.h"

class Renderer
{
public:
    Renderer() { setVectorMode(); }
    /**
     * @brief function sets drawing mode to vector-mode
     * @return void
     */
    inline void setVectorMode() { drawMethod = &Renderer::vectorDraw; }
    /**
     * @brief function sets drawing mode to sprite-mode
     * @return void
     */
    inline void setSpriteMode() {drawMethod = &Renderer::spriteDraw; }
    /**
     * @brief function perfoms object drawing
     * @return void
     */
    inline void draw(Object& object) { (this->*drawMethod)(object); }
    /**
     * @brief Singleton pattern realization
     * @return Renderer& - refence on a single Renderer object
     */
    static Renderer& Instance()
    {
        static Renderer instance;
        return instance;
    }

public:
    //pointer on drawing function
    void (Renderer::*drawMethod)(Object&);
    //drawing functions
    void vectorDraw(Object&);
    void spriteDraw(Object&);
};

#define renderer Renderer::Instance()

#endif // RENDERER_H
