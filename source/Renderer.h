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

    enum RenderMode{VECTOR_MODE, SPRITE_MODE};
    /**
     * @brief function changes drawing mode
     * @return void
     */
    inline void changeMode()
    {
        switch(renderMode_)
        {
        case VECTOR_MODE:
            setSpriteMode();
            break;
        case SPRITE_MODE:
            setVectorMode();
            break;
        }
    }
    /**
     * @brief function sets drawing mode to vector-mode
     * @return void
     */
    inline void setVectorMode() { drawMethod = &Renderer::vectorDraw; renderMode_ = VECTOR_MODE; }
    /**
     * @brief function sets drawing mode to sprite-mode
     * @return void
     */
    inline void setSpriteMode() {drawMethod = &Renderer::spriteDraw; renderMode_ = SPRITE_MODE; }
    /**
     * @brief function returns current drawing mode
     * @return RenderMode
     */
    inline RenderMode getRenderMode() { return renderMode_; }
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

private:
    //pointer on drawing function
    void (Renderer::*drawMethod)(Object&);
    //drawing functions
    void vectorDraw(Object&);
    void spriteDraw(Object&);
    //
    RenderMode renderMode_;
};

#define renderer Renderer::Instance()

#endif // RENDERER_H
