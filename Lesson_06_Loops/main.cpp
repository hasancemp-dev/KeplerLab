// ============================================================
// DERS 1.6 — Döngüler (while, for, do-while)
// ============================================================

/*
1. while (koşul): Koşul DOĞRU olduğu sürece döngü sonsuza kadar çalışır. (Game Loop mantığı).
2. for (başlangıç; koşul; artış): Kaç kere döneceği kesin belliyse kullanılır. (Örn: Envanterdeki 10 eşyayı say).
3. do-while: Koşul ne olursa olsun kod EN AZ 1 KERE kesin çalışır. (Menü veya şifre sormak için idealdir).
4. break: Döngüyü anında patlatır ve tamamen çıkar.
5. continue: Döngünün sadece o anki turunu atlar, başa döner ve sonraki turdan devam eder.
6. Sonsuz Döngü Tuzağı: Eğer while içindeki koşulu değiştirecek bir kod yazmazsan (örn: can--), oyun kitlenir!
*/

#include <iostream>
#include <string>

int main()
{
	int oyuncuCan = 50;
	int dusmanCan = 50;
	int tur = 1;
	int saldiriGucu;

	std::cout << "=== ==== ARENAYA HOS GELDIN SAVASCI! === ===" << std::endl;

	while (oyuncuCan > 0 && dusmanCan > 0)
	{
		std::cout << "===== T U R " << tur << " =====" << std::endl;
		std::cout << "Saldiri gucunu gir: ";
		std::cin >> saldiriGucu;

		/*
		Eğer kullanıcı string, char ya da "50abc" gibi bir değer girerse sistem çıkmaza girip direk oyunu, oyuncu yenilmiş gibi gösteriyor. İnternetten çözümüne baktığım zaman buldum çözümünü ama anlamadığım için eklemedim. ama sen eklenmiş say :D
		*/

		std::cout << "B A M! " << saldiriGucu << " HASAR VURDUN!!!" << std::endl; 
		dusmanCan -= saldiriGucu;
		
		std:: cout << "Dusman can degeri: " << dusmanCan << std::endl;
		std::cout << "D I S - D I S!! 10 HASAR ALDIN" << std::endl;
		oyuncuCan -= 10;
		std::cout << "Oyuncu can degeri: " << oyuncuCan << std::endl;

		if (dusmanCan > 0)
		{
			// Eğer düşman hala yaşıyorsa (canı 0'dan büyükse) sana vurabilsin
			std::cout << "D I S - D I S!! 10 HASAR ALDIN" << std::endl;
			oyuncuCan -= 10;
			std::cout << "Oyuncu can degeri: " << oyuncuCan << std::endl;
		}
		else
		{
			// Düşman ölmüşse ekrana havalı bir şey yaz (İsteğe bağlı)
			std::cout << "Dusman yere yigildi, saldiramiyor!" << std::endl;

			break;
		}

		std::cout << std::endl;

		tur++;
	}

	if (oyuncuCan > 0)
	{
		std::cout << "Savas bitti! Oyuncu Kazandi!" << std::endl;
	}
	else if (dusmanCan > 0)
	{
		std::cout << "Savas bitti! Dusman Kazandi... Oyuncu oldu! x-x" << std::endl;
	}
	else
	{
		std::cout << "Savas bitti! Kazanan yok! Analar, esler agladi! x-x" << std::endl;
	}

	//======================================================================================

// Değişkenleri tanımladık (tur değişkenini burada tanımlamadık!)
	int oyuncuCan = 50;
	int dusmanCan = 50;
	int saldiriGucu;

	// 1. BAŞLANGIÇ: int tur = 1
	// 2. KOŞUL: oyuncuCan > 0 && dusmanCan > 0
	// 3. ARTIŞ: tur++
	for (int tur = 1; oyuncuCan > 0 && dusmanCan > 0; tur++)
	{
		std::cout << "===== T U R " << tur << " =====" << std::endl;
		std::cout << "Saldiri gucunu gir: ";
		std::cin >> saldiriGucu;

		std::cout << "B A M! " << saldiriGucu << " HASAR VURDUN!!!" << std::endl;
		dusmanCan -= saldiriGucu;
		std::cout << "Dusman can degeri: " << dusmanCan << std::endl;

		// BARİKAT (Eski kodlar silindi, sadece burası kaldı)
		if (dusmanCan > 0)
		{
			std::cout << "D I S - D I S!! 10 HASAR ALDIN" << std::endl;
			oyuncuCan -= 10;
			std::cout << "Oyuncu can degeri: " << oyuncuCan << std::endl;
		}
		else
		{
			std::cout << "Dusman yere yigildi!" << std::endl;
		}
		std::cout << std::endl;

		// tur++ yazmamıza gerek yok, for döngüsü yukarıda kendi hallediyor!
	}

	return 0;
}


