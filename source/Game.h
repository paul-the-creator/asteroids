/**
 * @file Game.h
 * @brief Provides main class
 * @author paul-the-creator
 * @date 2013
 */

#ifndef GAME_H
#define GAME_H

#include "ObjectManager.h"

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

/**
 * @class Game
 * @brief main class
 * @author paul-the-creator
 * @date 2013
 */
class Game
{
protected:
    /**
      * @brief constructor
      * @brief inits game world size and start scene
      */
    Game()
    {
        objectManager.initWorldSize(WIDTH, HEIGHT);
        initStartScene();
    }

    ~Game() { }

public:
    //game sindow size
    enum {WIDTH = 800, HEIGHT = 600};
    enum {MAX_X = WIDTH/2, MAX_Y = HEIGHT/2};

    /**
      * @brief init scene functions
      * @remarks provides scene initialization
      * @return void
      */
    void initStartScene();
    void initMainScene();
    void initEndScene();

    /**
      * @brief main control key callback
      * @remarks provides control keys action
      * @param[in] key - key code
      * @return void
      */
    void controlKeyCallBack(int key);
    /**
      * @brief main key callback
      * @remarks provides additional keys action
      * @param[in] key - key code
      * @return void
      */
    void keyCallBack(unsigned char key);

    /**
      * @brief additional key callbacks
      * @param[in] key - key code
      * @return void
      */
    void startSceneControlKeyCallBack(int key);
    void mainSceneControlKeyCallBack(int key);
    void startSceneKeyCallBack(unsigned char key);
    void mainSceneKeyCallBack(unsigned char key);
    void endSceneKeyCallBack(unsigned char key);

    /**
      * @brief main draw function
      * @brief draws necessary scene according game state
      * @return void
      */
    void drawScene();

    /**
      * @brief additional draw functions
      * @brief draws necessary scene according game state
      * @return void
      */
    void drawStartScene();
    void drawMainScene();
    void drawEndScene();

    /**
      * @brief singleton pattern realization
      * @return Game& - reference on single Game object
      */
    static Game& Instance()
    {
        static Game instance;
        return instance;
    }

private:
    //start buttons
    enum {ESC_KEY = 27, SPACE_KEY = 32, ENTER_KEY = 13};
    enum StartButton {RUN_GAME, EXIT_GAME} startButton_;

    //pointers on key callback and rendering functions
    void (Game::*controlKeyCallBackPtr) (int);
    void (Game::*keyCallBackPtr) (unsigned char);

    //pointer on rendering function
    void (Game::*drawScenePtr) ();

    //timers
    int asteroidTimer_, saucerTimer_, laserTimer_;
};

#define asteroidGame Game::Instance()

/**
  * @brief drawing text function
  * @brief draws text according input parameters
  * @param[in] x - x position coordinate
  * @param[in] y - y position coordinate
  * @param[in] font - glut font
  * @param[in] RGB - color presentation
  * @param[in] text -text to be drawed
  * @return int - width of resulting string
  */
inline int renderString(const float x, const float y, void *font, const RGB color, const std::string text)
{
    glColor3f(color.redComponent, color.greenComponent, color.blueComponent);
    glRasterPos2f(x, y);

    int stringWidth = 0;
    for(auto &character : text)
    {
        glutBitmapCharacter(font, character);
        stringWidth += glutBitmapWidth(font, character);
    }

    return stringWidth;
}

#endif // GAME_H
