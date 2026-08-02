#include <iostream>
#include <string>
#include "Dusman.h"

int main()
{
	Dusman goblin;
	goblin.SetAd("Goblin");
	goblin.SetCan(40);
	goblin.SetHasar(10);

	std::cout << "============================" << std::endl;
	std::cout << "\t   STATS" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "Name:\t" << goblin.GetAd() << std::endl;
	std::cout << "Health:\t" << goblin.GetCan() << std::endl;
	std::cout << "Damage:\t" << goblin.GetHasar() << std::endl;


	for (int i = 0; i < 3; i++)
	{
		goblin.HasarAl(15);
		goblin.Bilgi();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	goblin.SetCan(500);
	goblin.Bilgi();
	std::cout << std::endl;
	goblin.SetCan(-500);
	goblin.Bilgi(); // Encapsulation sayesinde veri korundu!

	return 0;
}