/**
 * @file ObjectManager.cpp
 * @brief Provides class for objects managment
 * @author paul-the-creator
 * @date 2013
 */

#include "ObjectManager.h"
#include "Renderer.h"
#include <cmath>
#include <algorithm>

template <typename T> float countDistance(Point<T> point1, Point<T> point2)
{
    return std::sqrt(std::pow(point1.x - point2.x, 2) + std::pow(point1.y - point2.y, 2));
}

PointF getRandPoint(const int xRange, const int yRange)
{
    int randIndet1 = randomValue(0, 99);
    int randIndet2 = randomValue(0, 99);
    float xCord, yCord;
    if(randIndet1 % 2 == 0)
    {
        xCord = (randIndet2 % 2 == 0) ? -xRange : xRange;
        yCord = randomValue(0, yRange);
    }
    else
    {
        xCord = randomValue(0, xRange);
        yCord = (randIndet2 % 2 == 1) ? -yRange : yRange;
    }
    return PointF(xCord, yCord);
}

void ObjectManager::createShip()
{
    ship = std::shared_ptr <SpaceShip>(new SpaceShip(worldWidth_, worldHeight_));
}

void ObjectManager::createAsteroid()
{
    PointF center = getRandPoint(worldWidth_/2, worldHeight_/2);

    float angle = randomValue(1, 360);
    enemies_.push_back(std::shared_ptr <Asteroid>(new Asteroid(worldWidth_, worldHeight_, center, angle)) );
}

void ObjectManager::createAsteroidSpalls(std::shared_ptr <Object> asteroid)
{
    if(asteroid->getScaleFactor() != 1)
        return;

    PointF center = asteroid->getCenter();
    float angle = asteroid->getAngle();
    enemies_.push_back( std::shared_ptr <Asteroid>(new Asteroid(worldWidth_, worldHeight_, center, angle - 90, 0.5)) );
    enemies_.push_back( std::shared_ptr <Asteroid>(new Asteroid(worldWidth_, worldHeight_, center, angle + 90, 0.5)) );
}

void ObjectManager::createSaucer()
{
    //only one saucer can exist
    if(isSaucerDestroyed_ == false)
        return;

    PointF center = getRandPoint(worldWidth_/2, worldHeight_/2);
    enemies_.push_back( std::shared_ptr <FlyingSaucer>(new FlyingSaucer(worldWidth_, worldHeight_, center)) );

    isSaucerDestroyed_ = false;
}

void ObjectManager::createBullet()
{
    bullets_.push_back( std::shared_ptr <Bullet>(new Bullet(worldWidth_, worldHeight_, ship->getGunPosition(), ship->getAngle())) );
}

void ObjectManager::createLaser()
{
    bullets_.push_back( std::shared_ptr <Laser>(new Laser(worldWidth_, worldHeight_, ship->getGunPosition(), ship->getAngle())) );
}

void ObjectManager::checkCollision()
{
    //checking enemy collision
    for(auto &enemy : enemies_)
    {
        //collision with bullets
        for(auto &bullet : bullets_)
        {
            if(bullet->isCollision())
                continue;
            checkEnemyCollision(enemy, bullet);
        }
        //collision with ship
        if(ship)
            checkShipCollision(enemy);
    }

    //deletting structed obects
    for(auto enemyIt = enemies_.begin(); enemyIt != enemies_.end(); ++enemyIt)
        if((*enemyIt)->isCollision() == true)
            enemyIt = enemies_.erase(enemyIt);

    //deletting used bullets
    for(auto bulletIt = bullets_.begin(); bulletIt != bullets_.end(); ++bulletIt)
        if((*bulletIt)->isCollision() == true)
            bulletIt = bullets_.erase(bulletIt);
}

void ObjectManager::checkEnemyCollision(std::shared_ptr <Object> enemy, std::shared_ptr <Bullet> bullet)
{
    float dist = countDistance(enemy->getCenter(), bullet->getCenter());

    if(dist < enemy->getRadius())
    {
        enemy->setCollision();
        if(typeid(*enemy) == typeid(Asteroid))
        {
            createAsteroidSpalls(enemy);
            totalScore_ += 10;
        }
        if(typeid(*enemy) == typeid(FlyingSaucer))
        {
            isSaucerDestroyed_ = true;
            totalScore_ += 25;
        }

        if(typeid(*bullet) == typeid(Bullet))
            bullet->setCollision();
    }
}

void ObjectManager::checkShipCollision(std::shared_ptr <Object> enemy)
{
    float dist = countDistance(ship->getCenter(), enemy->getCenter());

         if(dist < enemy->getRadius())
        ship->setCollision();
}

void ObjectManager::draw()
{
    checkCollision();

    if(ship)
    {
        renderer.draw(*ship);
        renderer.draw(*(ship->getEngineTrack()));
    }

    for(auto enemy : enemies_)
    {
        if(typeid(*enemy) == typeid(FlyingSaucer))
            if(ship) enemy->followToPoint(ship->getCenter());
        renderer.draw(*enemy);
    }

    for(auto bullet : bullets_)
        renderer.draw(*bullet);
}
