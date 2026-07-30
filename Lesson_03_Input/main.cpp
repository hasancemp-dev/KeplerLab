// ============================================================
// DERS 1.3 — Girdi Alma (cin) ve Aritmetik
// ============================================================

/*
1. cin >> degisken;      // Kullanıcıdan boşluğa veya enter'a kadar girdi alır. (cin.ignore() tavsiye edilir)
2. getline(cin, metin);  // Kullanıcıdan tüm satırı boşluklarla birlikte alır.
3. Kural: cin >> kullandıktan sonra getline kullanacaksan, arada mutlaka cin.ignore(); olmalı.
		  Yoksa getline tamponda (buffer) kalan enter'ı okur ve boş geçer.
4. int / int tuzağı: C++'ta iki tam sayı bölünürse küsurat atılır. (Örn: 5 / 2 = 2 olur).
   Bölme işleminde küsurat isteniyorsa en az bir taraf float yapılmalı. (Örn: 5.0f / 2 veya (float)5 / 2)
5. Kısayol: can -= hasar; ifadesi can = can - hasar; demektir.
*/



#include <iostream>
#include <string>

int main()
{
    // === 1. OYUNCU DEĞİŞKENLERİ ===
    std::string oyuncuAdi;
    int saldiriGucu;
    float oyuncuCani;

    // === 2. DÜŞMAN DEĞİŞKENLERİ ===
    std::string dusmanAdi = "Krakovic";
    int dusmanZirhi = 100;
    float dusmanCani = 100.0f; // Başlangıç değeri verildi, çöp değer yok!

    // === 3. KULLANICIDAN VERİ ALMA ===
    std::cout << "Oyuncu adi girin:\t\t";
    std::getline(std::cin, oyuncuAdi);

    std::cout << "Saldiri gucunu girin:\t\t";
    std::cin >> saldiriGucu;

    std::cout << "Oyuncunun can degerini girin:\t";
    std::cin >> oyuncuCani;

    std::cout << std::endl;

    // === 4. SAVAŞ MANTIĞI VE HESAPLAMALAR ===
    std::cout << "Bir dusman belirdi: " << dusmanAdi << "!" << std::endl;
    std::cout << "Oyuncu saldirdi! Bam Bam!" << std::endl;

    // Gerçek hasar hesabı (2.0f ile int / int tuzağından kaçtık)
    float gercekHasar = saldiriGucu - (dusmanZirhi / 2.0f);

    // Hasarı düşmeden önce, ekrana yazdırmak için eski canı bir kutuya yedeğe alıyoruz
    float dusmanEskiCani = dusmanCani;

    // Şimdi düşmanın gerçek canından hasarı düşüyoruz
    dusmanCani -= gercekHasar;

    // === 5. ÇIKTI EKRANI (HİZALAMALI) ===
    std::cout << "========================================" << std::endl;
    std::cout << "\tSAVAŞ SONRASI RAPORU" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\t[ OYUNCU ]" << std::endl;
    std::cout << "- Nick:\t\t\t" << oyuncuAdi << std::endl;
    std::cout << "- Can:\t\t\t" << oyuncuCani << std::endl;
    std::cout << "- Saldiri Gucu:\t\t" << saldiriGucu << std::endl;

    std::cout << std::endl;

    std::cout << "\t[ DUSMAN ]" << std::endl;
    std::cout << "- Nick:\t\t\t" << dusmanAdi << std::endl;
    std::cout << "- Zirh:\t\t\t" << dusmanZirhi << std::endl;
    std::cout << "- Hasar Oncesi Can:\t" << dusmanEskiCani << std::endl;
    std::cout << "- Hasar Sonrasi Can:\t" << dusmanCani << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "- Yapilan Net Hasar:\t" << gercekHasar << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}