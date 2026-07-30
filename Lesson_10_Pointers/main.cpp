// ============================================================
// DERS 1.10 — Pointer'lar & Referanslar
// ============================================================

/*
1. &degisken: Değişkenin RAM'deki ADRESİNİ (kapı numarasını) verir.
2. int* ptr: Bir int değişkenin adresini tutan POINTER (işaretçi) tanımlar.
3. *ptr: Dereference. Pointer'ın gösterdiği adrese gidip ORİJİNAL DEĞERİ okur/değiştirir.
4. int& ref: REFERANS. Bir değişkenin takma adıdır, aynı kutuyu paylaşır. Ömür boyu bağlıdır.
5. Fonksiyona referans (int&) ile gönder → orijinal değişir. Kopya (int) ile gönder → orijinal değişmez.
6. nullptr: Pointer hiçbir yeri göstermiyor demektir. *nullptr yapılırsa program ÇÖKER!
   Güvenli kullanım: if (ptr != nullptr) { *ptr = 10; }
*/

#include <iostream>
 
//GOREV 2 FONK.
void LevelUp(int& seviye)
{
	seviye += 1;
	std::cout << "Seviye atladin! Yeni seviye: " << seviye << std::endl;
}

int main()
{ 
	//GOREV 1
	int dusmanCan = 100;
	int* dusmanPtr = &dusmanCan;

	int oyuncuSeviye = 5;

	std::cout << "Dusman can degeri: " << dusmanCan << std::endl;
	std::cout << "Dusman ptr can adresi: " << dusmanPtr << std::endl;
	std::cout << "Dusman ptr can degeri: " << *dusmanPtr << std::endl;

	*dusmanPtr -= 30;
	std::cout << "Dusman *30* hasar aldi" << std::endl;

	
	std::cout << "Dusman can degeri: " << dusmanCan << std::endl;
	std::cout << "Dusman ptr can degeri: " << *dusmanPtr << std::endl;

	//GOREV 2

	LevelUp(oyuncuSeviye);

	return 0;
} 