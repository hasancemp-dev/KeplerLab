#include <iostream>
// ============================================================
// DERS 1.8 — Diziler ve Vektörler
// ============================================================

/*
1. Dizi (Array): Bellekte yan yana duran kutulardır. Saymaya her zaman 0'dan başlanır! (0. indeks)
2. Buffer Overflow: Klasik dizilerde sınır aşılırsa C++ çökmez, gidip bellekte başka programların verisini bozar.
3. std::vector: Modern C++'ın dinamik dizisidir. İçi doldukça uzar, boşaldıkça küçülür.
4. .push_back(): Vektörün en arkasına yeni bir eşya ekler.
5. .pop_back(): Vektörün en sonundaki eşyayı siler.
6. .size(): Vektörün o anki güncel boyutunu / kaç elemanı olduğunu söyler.
7. Vektörleri tamamen okumanın en iyi yolu bir for döngüsü (i < vektor.size()) kurmaktır.
*/


#include <string>
#include <vector>

int main()
{
	std::vector<std::string> saticiEnvanteri;

	//Ekleme
	saticiEnvanteri.push_back("Kilic");
	saticiEnvanteri.push_back("Kalkan");
	saticiEnvanteri.push_back("Iksir");
	saticiEnvanteri.push_back("Ok");

	for (int i = 0; i < saticiEnvanteri.size(); i++)
	{
		std::cout << "Satilik Esya: " << saticiEnvanteri[i] << std::endl;
	}
	std::cout << "Ok satildi..." << std::endl;
	saticiEnvanteri.pop_back();
	std::cout << "Ok esyasi envanterden cikarildi." << std::endl;

	std::cout << "Guncel esya sayisi: " << saticiEnvanteri.size() << std::endl;

	return 0;
}