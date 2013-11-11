#include "Game.h"
#include "GL/glut.h"
#include <cstdlib>

void init(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Game::WIDTH, Game::HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Asteroids");
    glClearColor(0, 0, 0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-Game::WIDTH / 2, Game::WIDTH / 2, -Game::HEIGHT / 2, Game::HEIGHT / 2, -1.0, 1.0);
}

void displayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);
    asteroidGame.drawScene();
    glutSwapBuffers();
}

void keyboardFunc(unsigned char key, int, int)
{
    asteroidGame.keyCallBack(key);
}

void keyboardSpecialFunc(int key, int, int)
{
    asteroidGame.controlKeyCallBack(key);
}

void timerFunc(int)
{
    glutPostRedisplay();
    glutTimerFunc(25, timerFunc, 0);
}

int main(int argc, char **argv)
{
    init(argc, argv);
    glutDisplayFunc(displayFunc);
    glutKeyboardFunc(keyboardFunc);
    glutSpecialFunc(keyboardSpecialFunc);
    glutTimerFunc(25, timerFunc, 0);
    glutMainLoop();
}