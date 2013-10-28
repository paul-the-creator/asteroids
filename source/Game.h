#ifndef GAME_H
#define GAME_H

#include "ObjectManager.h"

#undef RGB
struct RGB
{
	RGB() { }
    RGB(float red, float green, float blue) : redComponent(red), greenComponent(green), blueComponent(blue) { }
    float redComponent;
    float greenComponent;
    float blueComponent;
};

class Game
{
protected:
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

    //scene initialization
    void initStartScene();
    void initMainScene();
    void initEndScene();

    //main key callbacks
    void controlKeyCallBack(int key);
    void keyCallBack(unsigned char key);

    //additional key callbacks
    void startSceneControlKeyCallBack(int key);
    void mainSceneControlKeyCallBack(int key);
    void startSceneKeyCallBack(unsigned char key);
    void mainSceneKeyCallBack(unsigned char key);
    void endSceneKeyCallBack(unsigned char key);

    //main draw function
    void drawScene();

    //additional draw functions
    void drawStartScene();
    void drawMainScene();
    void drawEndScene();

    //singleton pattern realization
    static Game& Instance()
    {
        static Game instance;
        return instance;
    }

private:
    //start buttons
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

//drawing text function
inline int renderString(const float x, const float y, void *font, const RGB color, const std::string text)
{
    glColor3f(color.redComponent, color.greenComponent, color.blueComponent);
    glRasterPos2f(x, y);

    int stringWidth = 0;
    for(auto character : text)
    {
        glutBitmapCharacter(font, character);
        stringWidth += glutBitmapWidth(font, character);
    }

    return stringWidth;
}

#endif // GAME_H
