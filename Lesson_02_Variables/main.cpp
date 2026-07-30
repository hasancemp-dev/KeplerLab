// ============================================================
// DERS 1.2 — Değişkenler & Veri Tipleri
// Tarih: 2026-07-24
// ============================================================

#include <iostream>
#include <string>   // string kullanmak için gerekli — iostream yetmez

int main()
{
    // === OYUNCU PROFİLİ DEĞİŞKENLERİ ===

    std::string oyuncuAdi = "Kepler";   // string — metin, boyutu içeriğe bağlı
    int seviye = 10;                     // int — tam sayı, 4 byte
    float can = 85.5f;                   // float — ondalıklı, 4 byte, sonunda f!
    float hiz = 7.2f;
    char rutbe = 'S';                    // char — tek karakter, tek tırnak, 1 byte
    bool hayattaMi = true;               // bool — true/false, 1 byte

    // === EKRANA YAZDIRMA ===

    std::cout << "=============================" << std::endl;
    std::cout << "\tOYUNCU PROFILI" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Isim:\t\t" << oyuncuAdi << std::endl;
    std::cout << "Seviye:\t\t" << seviye << std::endl;
    std::cout << "Can:\t\t" << can << std::endl;
    std::cout << "Hiz:\t\t" << hiz << std::endl;
    std::cout << "Rutbe:\t\t" << rutbe << std::endl;

    // boolalpha → bool'u 1/0 yerine true/false olarak yazdırır
    std::cout << std::boolalpha;
    std::cout << "Hayatta:\t" << hayattaMi << std::endl;
    std::cout << "=============================" << std::endl;

    // === HASAR SİSTEMİ ===
    // Oyuncuya hasar geldiğinde canı düşer

    float alinanHasar = 23.2f;
    can = can - alinanHasar;    // can'ı güncelle — ayrı değişken gerekmez

    std::cout << "\n--- HASAR ALINDI ---" << std::endl;
    std::cout << "Yeni Can:\t" << can << std::endl;

    // === BELLEK BOYUTLARI ===
    // sizeof(tip) → o tipin bellekte kaç byte kapladığını gösterir

    std::cout << "\n--- BELLEK BOYUTLARI ---" << std::endl;
    std::cout << "int:\t" << sizeof(int) << " byte" << std::endl;
    std::cout << "float:\t" << sizeof(float) << " byte" << std::endl;
    std::cout << "double:\t" << sizeof(double) << " byte" << std::endl;  // 8 byte!
    std::cout << "bool:\t" << sizeof(bool) << " byte" << std::endl;
    std::cout << "char:\t" << sizeof(char) << " byte" << std::endl;
    std::cout << "=============================" << std::endl;

    return 0;
}