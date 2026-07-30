// ============================================================
// DERS 1.9 — Bellek Boyutları ve Taşma (Overflow)
// ============================================================

/*
1. sizeof(tip): Bir veri tipinin RAM'de kaç Byte yer kapladığını döndürür. (int = 4B, char = 1B, double = 8B)
2. Overflow (Taşma): Bir kutunun sınırını aşarsan, sayı başa döner. (uint16_t max 65535. +1 = 0 olur!)
3. unsigned: "Eksi sayı olmayacak" demektir. Eksi tarafı iptal edip artı sınırı ikiye katlar.
4. <cstdint>: uint8_t (1B), uint16_t (2B), uint32_t (4B), uint64_t (8B) gibi kesin boyutlu tipler sağlar.
5. uint8_t = char'dır! cout ile yazdırırken (int) ile cast etmelisin, yoksa harf basar.
6. Oyun motorlarında RAM tasarrufu için her değişkene "tam yetecek kadar" kutu boyutu seçilir.
*/

#include <iostream>
#include <cstdint>
 
int main()
{ 
	int8_t yas = 32;			//127
	uint8_t seviye = 64;		//255
	int16_t maksCan = 10000;	//32,767
	uint32_t coin = 1000000000; //4,294,967,295

	uint16_t test = 65535;
	test += 1;

	std::cout << "Yas: " << (int)yas << std::endl;
	std::cout << "Seviye: " << (int)seviye << std::endl;
	std::cout << "Maksimum Can: " << maksCan << std::endl;
	std::cout << "Altin: " << coin << std::endl;

	std::cout << "Hata: " << test << std::endl;


	return 0;
}