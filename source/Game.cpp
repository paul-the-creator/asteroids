#include "Game.h"
#include <string>

//======= Main functions =======//
//
//main draw function
//
void Game::drawScene()
{
    if(drawScenePtr)
        (this->*drawScenePtr)();
}

//
//main control key callback
//
void Game::controlKeyCallBack(int key)
{
    if(controlKeyCallBackPtr)
        (this->*controlKeyCallBackPtr)(key);
}
//

//
//main key callback
//
void Game::keyCallBack(unsigned char key)
{
    if(keyCallBackPtr)
        (this->*keyCallBackPtr)(key);
}
//

//======= Additional functions =======//

//
//Init functions
//
void Game::initStartScene()
{
    objectManager.reset();
    for(int i = 0; i < 5; i++)
        objectManager.createAsteroid();

    //function pointers initialization
    controlKeyCallBackPtr = &Game::startSceneControlKeyCallBack;
    keyCallBackPtr = &Game::startSceneKeyCallBack;
    drawScenePtr = &Game::drawStartScene;
}
//
void Game::initMainScene()
{
    objectManager.reset();
    objectManager.createShip();
    objectManager.createAsteroid();
    asteroidTimer_ = saucerTimer_ = laserTimer_ = glutGet(GLUT_ELAPSED_TIME);

    //function pointers initialization
    controlKeyCallBackPtr = &Game::mainSceneControlKeyCallBack;
    keyCallBackPtr = &Game::mainSceneKeyCallBack;
    drawScenePtr = &Game::drawMainScene;
}
//
void Game::initEndScene()
{
    objectManager.resetShip();

    //function pointers initialization
    controlKeyCallBackPtr = nullptr;
    keyCallBackPtr = &Game::endSceneKeyCallBack;
    drawScenePtr = &Game::drawEndScene;
}
//

//
//additional draw functions
//
void Game::drawStartScene()
{
    //drawing background objects
    objectManager.draw();

    //drawing menu text
    RGB startColor, exitColor;
    switch (startButton_)
    {
    case RUN_GAME:
        startColor = RGB(0, 0.6, 1);
        exitColor = RGB(1, 1, 1);
        break;
    case EXIT_GAME:
        startColor = RGB(1, 1, 1);
        exitColor = RGB(0, 0.6, 1);
        break;
    }
    renderString(-0.5 * MAX_X, 0.5 * MAX_Y, GLUT_BITMAP_9_BY_15, RGB(1, 1, 1), "ASTEROIDS");
    renderString(-0.45 * MAX_X, 0.3 * MAX_Y, GLUT_BITMAP_8_BY_13, startColor, "START GAME");
    renderString(-0.45 * MAX_X, 0.2 * MAX_Y, GLUT_BITMAP_8_BY_13, exitColor, "EXIT GAME");

    //drawing key manual
    //  some uninteresting hardcode
    glPushMatrix();
    glTranslatef(0.5 * MAX_X, -0.4 * MAX_Y, 0);
    glColor3f(1, 1, 1);

    const int sizeFactor = 0.1 * MAX_X;
    const int intervalFactor = 0.2 * sizeFactor;
    //cursor keys
    glBegin(GL_TRIANGLES);
        //up key symbol
        glVertex2f(0, 0);
        glVertex2f(0.5 * sizeFactor, -sizeFactor);
        glVertex2f(-0.5 * sizeFactor, -sizeFactor);
        //left key symbol
        glVertex2f(-1.5 * sizeFactor - intervalFactor, -1.5 * sizeFactor - intervalFactor);
        glVertex2f(-0.5 * sizeFactor - intervalFactor, -sizeFactor - intervalFactor);
        glVertex2f(-0.5 * sizeFactor - intervalFactor, -2 * sizeFactor - intervalFactor);
        //right key symbol
        glVertex2f(1.5 * sizeFactor + intervalFactor, -1.5 * sizeFactor - intervalFactor);
        glVertex2f(0.5 * sizeFactor + intervalFactor, -sizeFactor - intervalFactor);
        glVertex2f(0.5 * sizeFactor + intervalFactor, -2 * sizeFactor - intervalFactor);
    glEnd();

    //space key symbol
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.5 * sizeFactor, -3 * sizeFactor - 3 * intervalFactor);
        glVertex2f(-1.5 * sizeFactor, -2 * sizeFactor - 3 * intervalFactor);
        glVertex2f(1.5 * sizeFactor, -2 * sizeFactor - 3 * intervalFactor);
        glVertex2f(1.5 * sizeFactor, -3 * sizeFactor - 3 * intervalFactor);
    glEnd();
    renderString(0, -2.5 * sizeFactor - 3 * intervalFactor, GLUT_BITMAP_9_BY_15, RGB(1, 1, 1), "SPACE");

    //space key symbol
    glBegin(GL_LINE_LOOP);
        glVertex2f(1.5 * sizeFactor + intervalFactor, -3 * sizeFactor - 3 * intervalFactor);
        glVertex2f(1.5 * sizeFactor + intervalFactor, -2 * sizeFactor - 3 * intervalFactor);
        glVertex2f(3.25 * sizeFactor + intervalFactor, -2 * sizeFactor - 3 * intervalFactor);
        glVertex2f(3.25 * sizeFactor + intervalFactor, -sizeFactor - 3 * intervalFactor);
        glVertex2f(4.5 * sizeFactor + intervalFactor, -sizeFactor - 3 * intervalFactor);
        glVertex2f(4.5 * sizeFactor + intervalFactor, -3 * sizeFactor - 3 * intervalFactor);
    glEnd();
    renderString(3 * sizeFactor, -2.5 * sizeFactor - 3 * intervalFactor, GLUT_BITMAP_9_BY_15, RGB(1, 1, 1), "ENTER");

    glPopMatrix();
}
//
void Game::drawMainScene()
{
    //adding new enemies
    int curTime = glutGet(GLUT_ELAPSED_TIME);
    if((curTime - asteroidTimer_) > 4500)
    {
        objectManager.createAsteroid();
        asteroidTimer_ = curTime;
    }
    if((curTime - saucerTimer_) > 10000)
    {
        objectManager.createSaucer();
        saucerTimer_ = curTime;
    }
    //drawing enemies
    objectManager.draw();

    //checking for ship destroying
    if(objectManager.isShipDestroyed() == true)
    {
        objectManager.resetShip();
        initEndScene();
    }

    //printing laser mode
    int stringWidth;
    if((curTime - laserTimer_) > 4500)
        stringWidth = renderString(0.6 * MAX_X, 0.9 * MAX_Y, GLUT_BITMAP_9_BY_15, RGB(0, 0.6, 1), "LASER ON");
    else
        stringWidth = renderString(0.6 * MAX_X, 0.9 * MAX_Y, GLUT_BITMAP_9_BY_15, RGB(0.3, 0.3, 0.3), "LASER OFF");

    //printing score
    std::string totalScore(std::to_string(objectManager.getTotalScore()));
    renderString(0.65 * MAX_X + stringWidth, 0.9 * MAX_Y, GLUT_BITMAP_9_BY_15, RGB(0, 0.6, 1), totalScore);
}
//
void Game::drawEndScene()
{
    //drawing background objects
    objectManager.draw();

    //drawing text
    int stringWidth = renderString(-0.25 * MAX_X, 0.1 * MAX_Y, GLUT_BITMAP_9_BY_15, RGB(1, 1, 1), "TOTAL SCORE: ");
    std::string totalScore(std::to_string(objectManager.getTotalScore()));
    renderString(-0.25 * MAX_X + stringWidth, 0.1 * MAX_Y, GLUT_BITMAP_9_BY_15, RGB(0, 0.6, 1), totalScore);
}

//
//additional control key callbacks
//
void Game::startSceneControlKeyCallBack(int key)
{
    switch(key)
    {
    //control buttons
    case GLUT_KEY_UP:
        startButton_ = RUN_GAME;
        break;

    case GLUT_KEY_DOWN:
        startButton_ = EXIT_GAME;
        break;
    }
}
//
void Game::mainSceneControlKeyCallBack(int key)
{
    switch(key)
    {
    //control buttons
    case GLUT_KEY_LEFT:
        objectManager.getShip()->rotate(10);
        break;

    case GLUT_KEY_UP:
        objectManager.getShip()->move();
        break;

    case GLUT_KEY_RIGHT:
        objectManager.getShip()->rotate(-10);
        break;
    }
}
//

//
//additional key call backs
//
void Game::startSceneKeyCallBack(unsigned char key)
{
    switch(key)
    {
    //escape key
    case 27:
        glutDestroyWindow(glutGetWindow());
        break;
    //menu key
    case 32:
    case 13:
        if(startButton_ == RUN_GAME)
            initMainScene();
        if(startButton_ == EXIT_GAME)
            glutDestroyWindow(glutGetWindow());
        break;
    }
}
//
void Game::mainSceneKeyCallBack(unsigned char key)
{
    switch(key)
    {
    //escape key
    case 27:
        initEndScene();
        break;
    //fire key
    case 32:
        objectManager.createBullet();
        break;
    case 13:
    {
        int curTime = glutGet(GLUT_ELAPSED_TIME);
        if((curTime - laserTimer_) > 5000)
        {
            objectManager.createLaser();
            laserTimer_ = curTime;
        }
    }
    break;
    }
}
//
void Game::endSceneKeyCallBack(unsigned char key)
{
    switch(key)
    {
    //escape key
    case 27:
        glutDestroyWindow(glutGetWindow());
        break;
    //fire key
    case 32:
    case 13:
        initStartScene();
        break;
    }
}
//
