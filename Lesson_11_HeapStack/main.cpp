// ============================================================
// DERS 1.11 — Stack vs Heap & Dinamik Bellek (new / delete)
// ============================================================

/*
1. Stack: Otomatik, hızlı, küçük (1-8 MB). Süslü parantez kapanınca değişken ölür.
2. Heap: Manuel, yavaş, devasa (GB'larca). delete yazana kadar yaşar. HERHANGİ BİR bloktan silinebilir.
3. new int(100): Heap'te kutu oluşturur, adresini (pointer) döndürür.
4. delete ptr: Heap'teki kutuyu yok eder, RAM'i geri verir. Sonra ptr = nullptr yap!
5. new int[N] / delete[] ptr: Dizi için köşeli parantezli versiyon. delete[] ŞART!
6. Memory Leak: new ile oluşturup delete ile silmezsen, RAM sessizce dolar. Program çökmez ama yavaşlar ve ölür.
*/

#include <iostream> 
#include <string>

//Görev 1: new
int* DusmanOlustur()
{
	int* can = new int(100);
	return can;
}
int* ListeOlustur(int& outBoyut)
{
	outBoyut = 4; // Boyutu burada belirliyoruz
	int* yeniDizi = new int[outBoyut];
	return yeniDizi;
}


int main()
{
	int* dusmanCan = DusmanOlustur();
	std::cout << "Dusman can degeri: " << *dusmanCan << std::endl;

	*dusmanCan -= 40;
	std::cout << "Dusman can degeri: " << *dusmanCan << std::endl;

	//Görev 1 delete
	delete dusmanCan;
	dusmanCan = nullptr;
	std::cout << "Bellek temizlendi" << std::endl;

	//Görev 2
	int diziBoyutu = 0;
	int* hasarListesi = ListeOlustur(diziBoyutu);
	hasarListesi[0] = 10;
	hasarListesi[1] = 25;
	hasarListesi[2] = 50;
	hasarListesi[3] = 100;

	for (int i = 0; i < diziBoyutu; i++)
	{
		int sira = i + 1;
		std::string ek = (sira == 1 || sira == 2) ? ".'ci" : ".'cu";
		//std::string ek = (sira == 1 || sira == 2 || sira == 7 || sira == 8) ? ".'ci" : (sira == 3 || sira == 4) ? ".'cü" : ".'cı"; // burada çopklu şartlı kullanma örneğini bırakıyorum(ternary)
		std::cout << "Hasar listesi " << sira << ek << " elemani: " << hasarListesi[i] << std::endl;
	}

	delete[] hasarListesi;
	hasarListesi = nullptr;
	std::cout << "Bellek temizlendi" << std::endl;

	//Görev 3

	for (int i = 1; i <= 5; i++)
	{
		new int(999);
	}

	return 0;
}