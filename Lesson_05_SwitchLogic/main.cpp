// ============================================================
// DERS 1.5 — Switch-Case & Mantıksal Operatörler
// ============================================================

/*
1. && (VE) : İki koşul da DOĞRU olmak zorundadır. (örn: level > 10 && altin > 50)
2. || (VEYA): Tek bir koşulun doğru olması yeterlidir. (örn: anahtarVarMi || guc > 100)
3. ! (DEĞİL): Değeri tersine çevirir. (!dogru -> yanlis)

4. switch (degisken): Tek bir değişkenin eşitlik durumlarını kontrol etmenin en hızlı yoludur.
   Sadece tam sayılar (int) ve karakterler (char) kabul eder. (string KABUL ETMEZ).

5. case: if (degisken == x) mantığıyla aynıdır.
6. break: EN ÖNEMLİ KOMUT. Case bloğunun bittiğini belirtir. Unutulursa kod aşağıya taşar ve diğer caseler de çalışır!
7. default: Hiçbir case tutmazsa çalışır (else gibi).
*/

#include <iostream>
#include <string> 


int main()
{
    int seviye = 5;
    int zirh = 0;
    int guc = 0;
    char esyaSinifi;

    std::cout << "Sandigi actin! Icerideki esyanin sinifi ne? (S, A, B, C): ";
    std::cin >> esyaSinifi;

    switch (esyaSinifi)
    {
    case 'S':
        if(seviye >= 10)
        {
            guc += 50;
            std::cout << "Efsanevi kilic buldun! Gucun 50 artti.";
        }
        else
        {
            std::cout << "Uyar! Seviyen bu efsanevi esyayi kullanmak icin cok dusuk!" << std::endl;
        }
        break;
        
    case 'A':
        zirh += 20;
        std::cout << "Nadir zirh buldun! Zirhin 20 artti.";
        break;
    case 'B': 
        std::cout << "Sira dan bir yay buldun.";
        break;
    case 'C':
        guc -= 10;
        std::cout << "Kirik bir degnek buldun. Cop! Gucun 10 azaldi.";
        break;
    default:
        std::cout << "Bilinmeyen cisim!";
        break;
    }
    return 0;
}