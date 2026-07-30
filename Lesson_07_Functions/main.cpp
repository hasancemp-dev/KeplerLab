// ============================================================
// DERS 1.7 — Fonksiyonlar (Functions)
// ============================================================

/*
1. Fonksiyonlar her zaman int main() bloğunun YUKARISINA (dışına) tanımlanır.
2. void: Geriye matematiksel bir cevap/veri fırlatmayan (sadece işlem yapan) fonksiyon tipidir. return yazılmaz.
3. return: Fonksiyonun sonucunu fırlatır. Fonksiyon return'ü gördüğü an KAPANIR, altındaki kodlar çalışmaz.
4. Parametreler: Fonksiyonun dışarıdan aldığı malzemelerdir. (Örn: int saldiriGucu)
5. Fonksiyonların amacı kodu parçalara bölmek, kendini tekrar etmemek ve main() bloğunu temiz tutmaktır.
*/

#include <iostream>
#include <string>


float GercekHasarHesapla(int saldiriGucu, int dusmanZirhi)
{
	float sonuc = saldiriGucu - (dusmanZirhi / 2.0f);
	return sonuc;
}
void SavasBittiRaporu(std::string kazananIsmi)
{
	std::cout << "=====================================" << std::endl;
	std::cout << " Savas bitti! Kazanan: " << kazananIsmi << std::endl;
	std::cout << "=====================================" << std::endl;
}

int main()
{
	int guc = 40;
	int zirh = 30;
	float netHasar = GercekHasarHesapla(guc, zirh);
	std::cout << "Alinan Hasar: " << netHasar << std::endl;
	SavasBittiRaporu("Kepler");
	return 0;
} 