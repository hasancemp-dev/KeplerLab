#pragma once

#include <string>

class Enemy
{
private:

	static int enemyCount;    
	std::string name;
	int health, damage;

public:

	Enemy(const std::string& n, int h, int d);

	~Enemy();

	static int GetEnemyCount();
};
