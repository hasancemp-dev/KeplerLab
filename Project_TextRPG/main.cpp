#include <iostream>
#include <string>
#include <vector>
#include <variant>

/*
 1. Oyuncu Oluşturma (Ders 1.2, 1.3, 1.5)
Oyun başladığında oyuncudan isim al (cin).
Oyuncuya 3 sınıf sun ve switch ile seçtir:
1 → Savaşçı (can: 150, hasar: 20)
2 → Okçu (can: 100, hasar: 30)
3 → Büyücü (can: 80, hasar: 40)
Seçimi switch ile yap. Geçersiz girişte varsayılan olarak Savaşçı ata. 
*/

//p for player

void OyunAcilisi()
{

}



int main()
{
	//Değişkenler, listeler topluluğu buraya
	std::string pAlias;
	int secim;
	std::string pClass;
	int pHealth;
	std::string pWeapon;
	int pDamage;
	using myVariant = std::variant<int, float, std::string>;
	std::vector<myVariant> pStats;



	std::cout << "Takma ad girin:";
	std::cin >> pAlias;
	std::cout << std::endl;

	std::cout << pAlias << ", simdi kaderini yazma vakti geldi! Kendini yoluna adayacagin bir sinif sec ve UNUTMA!! Burada yaptigin secimler hayattaki gibidir, bazi seyler icin bir kere karar verilir..." << std::endl;

	std::cout << "====================" << std::endl;
	std::cout << "\t SINIFLAR" << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << "1) Savasci (can: 150, hasar: 20)" << std::endl;
	std::cout << "2) Okcu (can: 100, hasar: 30)" << std::endl;
	std::cout << "1) Buyucu (can: 80, hasar: 40)" << std::endl;
	std::cout << std::endl;
	std::cout << "Secim vakti..." << std::endl;
	std::cin >> secim;
	std::cout << std::endl;

	switch (secim)
	{
	case 1:
		pClass = "Savasci (can: 150, hasar: 20)";
		pHealth = 150;
		pDamage = 20;
		std::cout << "" << std::endl;
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}

}
