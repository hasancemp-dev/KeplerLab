#pragma once

#include <string>

namespace Kepler
{

	class Enemy
	{
	private:

		static int enemyCount;
		std::string name;
		int health, damage;
		friend bool WinsAgainst(const Enemy& a, const Enemy& b); // give the accesibility per once

	public:

		Enemy(const std::string& n, int h, int d);

		~Enemy();

		static int GetEnemyCount();


	};//class

}//namespace
