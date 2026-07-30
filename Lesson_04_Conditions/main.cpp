// ============================================================
// DERS 1.4 — Değişkenler & Veri Tipleri
// Tarih: 2026-07-28
// ============================================================
 
/*
1. if (koşul): İçindeki koşul doğru (true) ise çalışır. Yanlışsa bloğu atlar.
2. else if (koşul): Önceki 'if' yanlışsa ve bu koşul doğruysa çalışır. Zincirleme seçenekler için kullanılır.
3. else: Kendinden önceki hiçbir if veya else if çalışmadıysa KESİN çalışır (koşul yazılmaz).
4. Karşılaştırmalar: == (eşit mi?), != (eşit değil mi?), <, >, <=, >=
5. BÜYÜK TUZAK: = atama yapar (kutunun içine koyar). == karşılaştırma yapar. (if (can = 10) YANLIŞTIR!)
6. Scope (Kapsam): Süslü parantez { } içindeki değişkenler sadece o parantez içinde yaşar, dışarı çıkamaz.
*/
 
#include <iostream>
#include <string>


int main()
{ 
    float oyuncuAltini = 150;
    unsigned int secim;

    std::cout << "Tuccara hos geldin! Altinin:" << oyuncuAltini << "\n"
        << "1. Kilic (100 Altin)\n"
        << "2. Iksir (50 Altin)\n"
        << "3. Kalkan (200 Altin)\nNe almak istersin? (1, 2 veya 3): ";
    
    std::cin >> secim;
    
    if (secim > 0 && secim < 4 )
    {
        if (secim == 1)
        {
            if (oyuncuAltini >= 100)
            {
                oyuncuAltini -= 100;
                std::cout << "Kilic alindi! Bakiyen: " << oyuncuAltini << std::endl;
            }
            else
            {
                std::cout << "Yeterli altiniz yok!";
            }
        }
        if (secim == 2)
        {
            if (oyuncuAltini >= 50)
            {
                oyuncuAltini -= 50;
                std::cout << "Iksir alindi! Bakiyeniz: " << oyuncuAltini << std::endl;
            }
            else
            {
                std::cout << "Yeterli altininiz yok!" << std::endl;
            }
        }
        if (secim == 3)
        {
            if (oyuncuAltini >= 200)
            {
                oyuncuAltini -= 200;
                std::cout << "Kalkan alindi! Bakiyeniz: " << oyuncuAltini << std::endl;
            }
            else
            {
                std::cout << "Yeterli altininiz yok!" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Boyle bir esya yok! Secim sadece 1-2-3 olarak yapilmaktadir." << std::endl;
    }
     
    return 0;
} 