#include <iostream>
#include <string>
#include "Enemy.h"


void EnemyQuery()
{
	int count = Enemy::GetEnemyCount();   // ask once and keep

	if (count == 1) { std::cout << "There is only " << count << " enemy" << std::endl; }
	else if (count > 1) { std::cout << "There are " << count << " enemies" << std::endl; }
	else { std::cout << "There is no enemy" << std::endl; }
}

int main()
{
	EnemyQuery();
	{

		Enemy g1 = { "Goblin", 40, 10 };
		Enemy g2 = { "Goblin", 40, 10 };
		Enemy g3 = { "Goblin", 40, 10 };

		EnemyQuery();
	}
	EnemyQuery();


	return 0;
} 