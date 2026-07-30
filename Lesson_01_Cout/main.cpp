// ============================================================
// DERS 1.1 — İlk Programım: cout, endl, Yorumlar
// Tarih: 2026-07-24
// Konu: Ekrana yazdırma temelleri
// ============================================================

#include <iostream>
// #include = "dahil et" komutu
// <iostream> = ekrana yazdırma (cout) aracını içeren dosya
// Bu satır olmadan cout kullanamam
// < > = sistem kütüphanesi (C++'ın kendi dosyaları)
// " " = benim kendi dosyalarım (ileride göreceğim)

int main()
// main = programın başladığı yer. Her programda 1 tane olmak zorunda.
// int = main'in bir sayı döndüreceğini söylüyor (return 0 ile)
// () = şimdilik boş, ileride parametre alabilir
{
    // std = standard kütüphane (araç dolabının adı)
    // :: = "içindeki" demek (std'nin içindeki cout)
    // cout = character output (ekrana yazdırma aracı)
    // << = "şunu gönder" oku (sağdaki veriyi cout'a iletir)

    std::cout << "Merhaba!" << std::endl;
    // endl = end line = satır sonu + tampon boşaltma
    // \n de satır atlar ama daha hızlıdır (tamponu boşaltmaz)

    // ÖĞRENME NOTU: using namespace std; yazmak mümkün ama YAPMA
    // Büyük projelerde isim çakışması riski var
    // Her zaman std::cout yaz — profesyonel alışkanlık

    // === DENEMELERIM ===

    // endl olmadan iki cout: yan yana yapışır
    std::cout << "AB";
    std::cout << "CD" << std::endl;
    // Çıktı: ABCD

    // \t = tab boşluğu, hizalama için
    std::cout << "Isim:\tKepler" << std::endl;

    // \\ = ekrana \ basar (tek \ kaçış karakteri başlatır)
    // \" = ekrana " basar (tek " stringi bitirir)
    std::cout << "Dosya: C:\\Games\\Kepler" << std::endl;
    std::cout << "Lakap: \"Motor\"" << std::endl;

    // === PRATİK SONUCUM ===
    // Çıktı tahminlerini hepsini doğru bildim (endl hariç - onu da anladım)
    // endl görünür karakter yazmaz ama satır ATLAR, "hiçbir şey yapmaz" demek yanlış

    return 0;
    // return 0 = "program sorunsuz bitti" sinyali
    // Yazmasam da çalışır (C++11+) ama YAZMALIYIM — açıklık önemli
}