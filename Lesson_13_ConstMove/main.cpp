// ============================================================
// DERS 1.13 — const Doğruluğu & Move Semantics
// ============================================================

/*
1. const int x = 100: Değişkeni kilitler. Değiştirmeye kalkarsan DERLEME HATASI.
   Oyun sabitleri için kullan: maxCan, yerCekimi, maxDusmanSayisi.
2. const&: Referansla gönder (hızlı) ama değiştirme hakkı yok (güvenli).
   void Goster(const std::string& isim) → okur ama değiştiremez.
3. Parametre seçimi:
   - int x         → Küçük tipler için kopya gönder
   - int& x        → Fonksiyon değeri DEĞİŞTİRECEKSE
   - const int& x  → Sadece OKUYACAKSA (büyük nesneler için)
4. std::move(ptr): Sahipliği DEVREDER. Eski nesne BOŞALIR, yeni nesne sahip olur.
   Kopyalama değil, taşıma! Eski ev boş kalır, eşyalar yeni evde.
5. unique_ptr kopyalanamaz ama std::move ile DEVREDİLEBİLİR.
*/

#include <iostream>
#include <string>
#include <memory>
 

//Görev 2 - const&
void OyuncuBilgiGoster(const std::string& isim, const int& can)
{
	std::cout << "====================" << std::endl;
	std::cout << "  OYUNCU BILGILERI" << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << std::endl;
	std::cout << "Isim: " << isim << std::endl;
	std::cout << "Can : " << can << std::endl;
}

void SilahKullan(std::unique_ptr<int> silah)
{
	std::cout << "Silah hasari: " << *silah << std::endl;
}

int main()
{
	//Görev 1 - const

	const int maxCan = 100;
	std::cout << "Maksimum can: " << maxCan << std::endl;
	// maxCan = 200; // Bu satır derleme hatası verir çünkü const!

	//Görev 2 - const&
	OyuncuBilgiGoster("Kepler", 100);

	//Görev 3 - std::move

	auto silahHasar = std::make_unique<int>(75);
	SilahKullan(std::move(silahHasar));
	// silahHasar artık boş! Sahiplik SilahKullan'a devredildi.

	if (silahHasar != nullptr)
	{
		std::cout << *silahHasar << std::endl;
	}
	else
	{
		std::cout << "Silah artik yok, devredildi!" << std::endl;
	}

	return 0;
}