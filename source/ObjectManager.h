#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Asteroid.h"
#include "Bullet.h"
#include "FlyingSaucer.h"
#include "Laser.h"
#include "SpaceShip.h"

#include <list>
#include <memory>

class ObjectManager
{
public:
    ObjectManager() { reset(); }
    ObjectManager(int worldWidth, int worldHeight)
        : worldWidth_(worldWidth), worldHeight_(worldHeight) { reset(); }

    inline void initWorldSize(const int worldWidth, const int worldHeight)
    {
        worldWidth_ = worldWidth; worldHeight_ = worldHeight;
    }

    void createShip();
    void createAsteroid();
    void createSaucer();
    void createBullet();
    void createLaser();
    inline void reset() { enemies_.clear(); bullets_.clear(); ship.reset(); isSaucerDestroyed_ = true; totalScore_ = 0; }
    inline void resetShip() { ship.reset(); }

    SpaceShip* getShip() { return ship.get(); }
    inline bool isShipDestroyed() const { return ship->isCollision(); }
    int getTotalScore() { return totalScore_; }

    void checkCollision();
    void draw();

    //singleton pattern realization
    static ObjectManager& Instance()
    {
        static ObjectManager instance;
        return instance;
    }

private:
    void createAsteroidSpalls(std::shared_ptr<Object> asteroid);
    void checkEnemyCollision(std::shared_ptr<Object>, std::shared_ptr <Bullet>);
    void checkShipCollision(std::shared_ptr <Object>);

private:
    //game world size
    int worldWidth_, worldHeight_;
    //saucer existance identifier
    bool isSaucerDestroyed_;
    //score value
    int totalScore_;

    //objects
    std::shared_ptr <SpaceShip> ship;
    std::list < std::shared_ptr <Object> > enemies_;
    std::list < std::shared_ptr <Bullet> > bullets_;
};

#define objectManager ObjectManager::Instance()

#endif // OBJECTMANAGER_H
