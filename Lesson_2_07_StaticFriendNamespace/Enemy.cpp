#include "Enemy.h"
#include <iostream>

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