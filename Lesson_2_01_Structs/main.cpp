// ============================================================
// DERS 2.1 — struct: Verileri Paketlemek
// ============================================================

/*
1. struct: Birden fazla değişkeni tek bir paket altında gruplar. Kendi tipini oluşturursun.
   struct Dusman { string ad; int can; int hasar; };  ← Noktalı virgül ŞART!
2. Erişim: Nokta (.) ile → goblin.can, goblin.ad
3. Kısa oluşturma: Dusman goblin = {"Goblin", 40, 10}; (sıralama struct tanımıyla aynı olmalı)
4. Fonksiyona gönderme:
   - const Dusman& d  → Sadece oku, değiştirme (güvenli + hızlı)
   - Dusman& d        → Oku VE değiştir (hasar verme gibi)
5. vector<Dusman> ordu; → struct vektörü. push_back ile ekle, ordu[i].ad ile eriş.
6. struct içinde struct: Oyuncu içinde Silah → oyuncu.silah.hasar (zincir erişim)
7. Eski 3 ayrı değişken yerine 1 paket. 3 parametreli fonksiyon yerine 1 parametreli.
*/


#include <iostream>
#include <string>
#include <vector> 

struct Dusman
{
	std::string ad;
	int can;
	int hasar;
};

struct Silah
{
	std::string ad;
	int hasar;
};

struct Oyuncu
{
	std::string ad;
	int can;
	Silah silah;
};

void DusmanBilgiGoster(const Dusman& d)
{
	std::cout << "\n\n=================================" << std::endl;
	std::cout << "\t    STATS" << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << "Dusman adi:\t" << d.ad << std::endl;
	std::cout << "Dusman cani:\t" << d.can << std::endl;
	std::cout << "Dusman hasar:\t" << d.hasar << std::endl;
}

void OyuncuBilgiGoster(const Oyuncu& d)
{
	std::cout << "\n\n=================================" << std::endl;
	std::cout << "\t    STATS" << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << "Oyuncu adi:\t" << d.ad << std::endl;
	std::cout << "Oyuncu cani:\t" << d.can << std::endl;
	std::cout << "Oyuncu silahi:\t" << d.silah.ad << std::endl;
	std::cout << "Oyuncu hasar:\t" << d.silah.hasar << std::endl;
}

void HasarVer(Dusman& hedef, const int& hasar)
{
	hedef.can -= hasar;
	if (hedef.can <= 0)
	{
		std::cout << hedef.ad << " oldu!";
	}
	DusmanBilgiGoster(hedef);
}

int main()
{ 

	Dusman goblin = { "Goblin", 40, 10 };
	Dusman ork = { "Ork", 70, 15 };
	Dusman ejderha = { "Ejderha", 120, 25 };

	std::vector<Dusman> ordu;

	ordu.push_back(goblin);
	ordu.push_back(ork);
	ordu.push_back(ejderha);

	for (int i = 0; i < ordu.size(); i++)
	{
		DusmanBilgiGoster(ordu[i]);
	}


	Oyuncu oyuncu = { "Kepler", 100,{"Yay", 30} };

	HasarVer(ordu[1], oyuncu.silah.hasar);

	OyuncuBilgiGoster(oyuncu);

	 

	return 0;
}
