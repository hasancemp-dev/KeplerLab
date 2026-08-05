#include "Enemy.h"
#include <iostream>

namespace Kepler
{
    // static member — within the scope of a file, WITHOUT a class wrapper
    int Enemy::enemyCount = 0;

    Enemy::Enemy(const std::string& n, int h, int d) : name(n), health(h), damage(d)
    {
        enemyCount++;
    }

    Enemy::~Enemy()
    {
        enemyCount--;
    }

    int Enemy::GetEnemyCount()
    {
        return enemyCount;
    }

    bool WinsAgainst(const Enemy& a, const Enemy& b)
    {
        return a.damage > b.damage;     // valid anymore — a.damage is private normally
    }
}