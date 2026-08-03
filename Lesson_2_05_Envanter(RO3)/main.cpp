#include <iostream>
#include "Envanter.h"

int main()
{
    std::cout << "--- a olusturuluyor, ilk elemani 111 yapiliyor ---" << std::endl;
    Envanter a(3);
    a.Ayarla(0, 111);

    std::cout << "\n--- Envanter b = a;   (b DOGUYOR -> copy ctor) ---" << std::endl;
    Envanter b = a;

    std::cout << "\n--- DERIN KOPYA TESTI: b'nin ilk elemanini 999 yapiyoruz ---" << std::endl;
    b.Ayarla(0, 999);
    std::cout << "    a[0] = " << a.Getir(0) << "   (111 kaldiysa bagimsizlar = DERIN kopya)" << std::endl;
    std::cout << "    b[0] = " << b.Getir(0) << std::endl;

    std::cout << "\n--- c olusturuluyor, sonra c = a;   (c ZATEN VAR -> copy assignment) ---" << std::endl;
    Envanter c(5);
    c = a;

    std::cout << "\n--- a = a;   (kendine atama) ---" << std::endl;
    a = a;

    std::cout << "\n--- main bitiyor, hepsi olecek ---" << std::endl;
    return 0;
}