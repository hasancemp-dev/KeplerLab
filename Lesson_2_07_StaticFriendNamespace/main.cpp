#include <iostream>
#include <string>
#include "Enemy.h"

// using namespace Kepler;  //Task 3
 
void EnemyQuery()
{
	int count = Kepler::Enemy::GetEnemyCount();   // ask once and keep

	if (count == 1) { std::cout << "There is only " << count << " enemy" << std::endl; }
	else if (count > 1) { std::cout << "There are " << count << " enemies" << std::endl; }
	else { std::cout << "There is no enemy" << std::endl; }
}

int main()
{
	using namespace Kepler;
	
		//Task 1
		EnemyQuery();
		{

			Enemy g1 = { "Goblin", 40, 10 };
			Enemy g2 = { "Goblin", 40, 10 };
			Enemy g3 = { "Goblin", 40, 10 };

			EnemyQuery();
		}
		EnemyQuery();

		//Task 2
		Enemy o1 = { "Ork", 70, 15 };
		Enemy d1 = { "Dragon",120,25 };

		bool orkWins = WinsAgainst(o1, d1);
		std::cout << (orkWins ? "Ork wins!" : "Ejderha wins!") << std::endl;

	
	return 0;
} 