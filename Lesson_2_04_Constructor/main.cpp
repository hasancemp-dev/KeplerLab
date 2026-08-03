#include <iostream>
#include <string>
#include "Dusman.h"

int main()
{
	Dusman goblin("Goblin", 40, 10);

	goblin.Bilgi();

	//Dusman ork; // no default constructor exists for class "Dusman" hatası alınıyor
	 
	Dusman kirikGoblin("Kirik", -500, -20);

	kirikGoblin.Bilgi(); // korumalı olduğundan can ve hasar 0 çıkıyor.

	std::cout << "--- blok basliyor ---" << std::endl;
	{
		Dusman ork("Ork", 70, 15);
		ork.Bilgi();
		Dusman troll("Troll", 90, 20);
		troll.Bilgi();
	}
	std::cout << "--- blok bitti ---" << std::endl;


	return 0;
}