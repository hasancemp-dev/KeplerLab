// ============================================================
// DERS 1.12 — Smart Pointer'lar & RAII
// ============================================================

/*
1. RAII: Kaynağı bir nesneye bağla, nesne ölünce kaynak otomatik temizlensin.
2. unique_ptr: TEK sahipli akıllı pointer. Kopyalanamaz. delete yazmana gerek yok!
   std::unique_ptr<int> ptr = std::make_unique<int>(100);
3. shared_ptr: ORTAK sahipli akıllı pointer. Kopyalanabilir. Referans sayacı tutar.
   Sayaç 0'a düşünce kutu otomatik silinir.
   std::shared_ptr<int> ptr = std::make_shared<int>(100);
4. unique_ptr: "Bu sadece benim, kimse dokunmasın." (Varsayılan tercihin)
   shared_ptr: "Birçok sistem erişecek, en son çıkan ışığı kapatsın."
5. Modern C++: Artık ham new/delete yazma, make_unique/make_shared kullan!
6. #include <memory> eklemeyi unutma!
*/


#include <iostream>
#include <memory>  

int main()
{   
	//Görev 1 - unique_ptr

	std::unique_ptr<int> oyuncuCan = std::make_unique<int>(200); 
	std::cout << "Oyuncu can degeri: " << *oyuncuCan << std::endl;

	*oyuncuCan -= 50; 
	std::cout << "Dusman sana 50 hasar verdi!" << std::endl;
	std::cout << std::endl;
	std::cout << "Oyuncu guncel can degeri: " << *oyuncuCan << std::endl;

	//Görev 2 - shared_ptr

	std::shared_ptr<int> bossCan = std::make_shared<int>(500);

	{
		std::shared_ptr<int> yardimciPtr = bossCan;

		*yardimciPtr -= 100;

		std::cout << "Yardimci Pointer degeri: " << *yardimciPtr << std::endl;
	}

	std::cout << "Boss guncel can degeri: " << *bossCan << std::endl;

	return 0;
} 