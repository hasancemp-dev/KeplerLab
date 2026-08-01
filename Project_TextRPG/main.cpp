#include <iostream>
#include <string>
#include <cstdlib>  // rand, srand için
#include <ctime>    // time için
#include <memory>
#include <vector>



void SinifSecimi(std::string& oyuncuSinif, int& oyuncuCan, int& oyuncuHasar)
{
	int secim;
	std::cin >> secim;

	switch (secim)
	{
	case 1:
		oyuncuSinif = "Savasci";
		oyuncuCan = 150;
		oyuncuHasar = 20;
		break;
	case 2:
		oyuncuSinif = "Okcu";
		oyuncuCan = 100;
		oyuncuHasar = 30;
		break;
	case 3:
		oyuncuSinif = "Buyucu";
		oyuncuCan = 80;
		oyuncuHasar = 40;
		break;
	default:
		std::cout << "Gecerli secim yapilmadi, varsayilan olarak Savasci secildi.\n";
		oyuncuSinif = "Savasci";
		oyuncuCan = 150;
		oyuncuHasar = 20;
		break;
	}//switch //sinif secimi
}

void SaldiriYap(int& hedefCan, const int& hasar)
{
	hedefCan -= hasar;
}//Hedefe hasar verir

void IksirKullan(int& can, const int& miktar, bool& iksirVar)
{
	can += miktar;
	iksirVar = false;
}//Can ekler, hakkı düşer

int CaniSifiraKirp(int can)
{
	return (can > 0) ? can : 0;
}

void DurumGoster(const std::string& oyuncuAd, const int& oyuncuCan, const std::string& dusmanAd, const int& dusmanCan)
{
	std::cout << "[" << oyuncuAd << ": " << oyuncuCan << " Can]  ["
		<< dusmanAd << ": " << dusmanCan << " Can]" << std::endl;
	std::cout << std::endl;
}//Her iki tarafın canını yazdırır

void YeniDusmanUret(std::string& dusmanAd, int& dusmanCan, int& dusmanHasar)
{
	int cusNum = rand() % 3;

	switch (cusNum)
	{
	case 0:
		dusmanAd = "Goblin";
		dusmanCan = 40;
		dusmanHasar = 10;
		break;
	case 1:
		dusmanAd = "Ork";
		dusmanCan = 70;
		dusmanHasar = 15;
		break;
	case 2:
		dusmanAd = "Ejderha";
		dusmanCan = 120;
		dusmanHasar = 25;
		break;
	}
}

void YeniDusmanBaslat(std::string& dusmanAd, int& dusmanCan, int& dusmanHasar, std::unique_ptr<int>& dusmanCanPtr)
{
	YeniDusmanUret(dusmanAd, dusmanCan, dusmanHasar);      // önceki fonksiyonu içeriden çağırıyoruz
	dusmanCanPtr = std::make_unique<int>(dusmanCan);
	std::cout << "Bir " << dusmanAd << " belirdi! (Can: " << *dusmanCanPtr << ")" << std::endl;
}



int main()
{
	srand(static_cast<unsigned int>(time(0)));  // Seed'i "şu an"a bağla — main'in EN BAŞINA, bir kere yazılır 

	std::string oyuncuAd;
	std::string oyuncuSinif;
	int oyuncuCan;
	int oyuncuHasar;
	std::vector<std::string> oldurulenDusmanlar;

	std::cout << "Takma ad girin: ";
	std::cin >> oyuncuAd;
	std::cout << std::endl;

	std::cout << oyuncuAd << ", sinifin nedir?\n" << std::endl;
	std::cout << "1) Savasci (can:150, hasar:20)\n2) Okcu (can:100, hasar:30)\n3) Buyucu (can:80, hasar:40)" << std::endl;


	SinifSecimi(oyuncuSinif, oyuncuCan, oyuncuHasar);

	std::cout << oyuncuAd << ", " << oyuncuSinif << " sectin. Can: "
		<< oyuncuCan << ", Hasar: " << oyuncuHasar << std::endl;

	const int IKSIR_IYILESTIRME = 30;

	int turSayaci = 1;
	bool iksirVar = true;

	int dusmanCan;
	int dusmanHasar;
	std::string dusmanAd;
	std::unique_ptr<int> dusmanCanPtr;

	YeniDusmanBaslat(dusmanAd, dusmanCan, dusmanHasar, dusmanCanPtr);

	while (oyuncuCan > 0)
	{
		std::cout << "\n--- TUR " << turSayaci << " ---" << std::endl;
		if (iksirVar)
		{
			std::cout << "1 - Saldir\n2 - Iksir Kullan (1 hak)\n3 - Kac" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "1 - Saldir\n2 - Iksir Kullan (0 hak)\n3 - Kac" << std::endl;
			std::cout << std::endl;
		}

		int savasSecim;
		std::cin >> savasSecim;
		std::cout << std::endl;

		if (savasSecim == 1)
		{
			SaldiriYap(*dusmanCanPtr, oyuncuHasar);
			std::cout << oyuncuAd << ", " << dusmanAd << "'e " << oyuncuHasar << " hasar verdi!" << std::endl;

			if (*dusmanCanPtr > 0)
			{
				SaldiriYap(oyuncuCan, dusmanHasar);
				std::cout << dusmanAd << ", " << oyuncuAd << "'a " << dusmanHasar << " hasar verdi!" << std::endl;
			}

			DurumGoster(oyuncuAd, CaniSifiraKirp(oyuncuCan), dusmanAd, CaniSifiraKirp(*dusmanCanPtr));

			if (*dusmanCanPtr <= 0)
			{
				std::cout << dusmanAd << " oldu. " << oyuncuAd << " kazandi." << std::endl;
				std::cout << std::endl;
				oldurulenDusmanlar.push_back(dusmanAd);
				YeniDusmanBaslat(dusmanAd, dusmanCan, dusmanHasar, dusmanCanPtr);
			}
			if (oyuncuCan <= 0)
			{
				std::cout << oyuncuAd << " oldu. " << dusmanAd << " kazandi." << std::endl;

				std::cout << std::endl;
				std::cout << "OYUN BITTI! " << turSayaci << " tur hayatta kaldin." << std::endl;
				break;
			}
		} // Saldır seçeneği
		else if (savasSecim == 2)
		{
			if (iksirVar)
			{
				IksirKullan(oyuncuCan, IKSIR_IYILESTIRME, iksirVar);
				std::cout << oyuncuAd << " iksir kullandi! Can: " << oyuncuCan << std::endl;
			}
			else
			{
				std::cout << "Iksir hakkin kalmadi!" << std::endl;
			}

			// iksir kullanılsın kullanılmasın, düşman saldırır (tur harcandı)
			SaldiriYap(oyuncuCan, dusmanHasar);
			std::cout << dusmanAd << ", " << oyuncuAd << "'a " << dusmanHasar << " hasar verdi!" << std::endl;

			DurumGoster(oyuncuAd, CaniSifiraKirp(oyuncuCan), dusmanAd, CaniSifiraKirp(*dusmanCanPtr));

			if (oyuncuCan <= 0)
			{
				std::cout << oyuncuAd << " oldu. " << dusmanAd << " kazandi." << std::endl;
				std::cout << std::endl;
				std::cout << "OYUN BITTI! " << turSayaci << " tur hayatta kaldin." << std::endl;
				break;
			}
		}//İksir kullan seçeneği
		else if (savasSecim == 3)
		{
			std::cout << "Arenadan kactin! " << oldurulenDusmanlar.size() << " dusman oldurdun." << std::endl;
			break;
		}//kaçış seçeneği

		turSayaci++;

	}//while /savaş döngüsü

	std::cout << std::endl;
	std::cout << "\nOldurdugun dusmanlar:" << std::endl;
	for (int i = 0; i < oldurulenDusmanlar.size(); i++)
	{
		std::cout << " " << (i + 1) << ". " << oldurulenDusmanlar[i] << std::endl;
	}

	return 0;

}//main //ana kod