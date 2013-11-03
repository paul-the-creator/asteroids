/**
 * @file ObjectManager.h
 * @brief Provides class for objects managment
 * @author paul-the-creator
 * @date 2013
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "Asteroid.h"
#include "Bullet.h"
#include "FlyingSaucer.h"
#include "Laser.h"
#include "SpaceShip.h"

#include <list>
#include <memory>

/**
 * @class ObjectManager
 * @brief Provides objects managment
 * @author paul-the-creator
 * @date 2013
 */
class ObjectManager
{
public:
    /**
      * @brief constructors
      */
    ObjectManager() { reset(); }
    ObjectManager(int worldWidth, int worldHeight)
        : worldWidth_(worldWidth), worldHeight_(worldHeight) { reset(); }

    /**
      * @brief Function sets game scene size
      * @param worldWidth - game scene width
      * @param worldHeight - game scene height
      * @return void
      */
    inline void initWorldSize(const int worldWidth, const int worldHeight)
    {
        worldWidth_ = worldWidth; worldHeight_ = worldHeight;
    }

    /**
      * @brief Function creates special object
      * @return void
      */
    void createShip();
    void createAsteroid();
    void createSaucer();
    void createBullet();
    void createLaser();
    /**
      * @brief Function delets all game objects
      * @return void
      */
    inline void reset() { enemies_.clear(); bullets_.clear(); ship.reset(); isSaucerDestroyed_ = true; totalScore_ = 0; }
    /**
      * @brief Function delets ship oject
      * @return void
      */
    inline void resetShip() { ship.reset(); }
    /**
      * @brief Function returns ship oject
      * @return SpaceShip* - pointer on ship object
      */
    SpaceShip* getShip() { return ship.get(); }
    /**
      * @brief Function checks if ship is destroyed
      * @return bool - true if ship is destroyed
      */
    inline bool isShipDestroyed() const { return ship->isCollision(); }
    /**
      * @brief Function returns total score
      * @return int - score value
      */
    int getTotalScore() { return totalScore_; }
    /**
      * @brief Function checks object collision
      * @return void
      */
    void checkCollision();
    /**
      * @brief Function draws all current objects
      * @return void
      */
    void draw();

    /**
      * @brief Singleton pattern realization
      * @return ObjectManager& - refence on a single ObjectManager object
      */
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
