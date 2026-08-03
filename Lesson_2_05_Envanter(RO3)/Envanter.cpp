#include "Envanter.h"
#include <iostream>

// ---------- NORMAL CONSTRUCTOR ----------
Envanter::Envanter(int b)
    : boyut(b), esyalar(new int[b])
{
    for (int i = 0; i < boyut; i++)
        esyalar[i] = 0;
    std::cout << "[NORMAL CTOR]  " << boyut << " elemanli yeni dizi ayrildi" << std::endl;
}

// ---------- COPY CONSTRUCTOR ----------
// Nesne SU AN doguyor. Elinde hicbir sey yok -- temiz sayfa.
// Bu yuzden burada YOK: self-check, eski kaynagi birakma, return.
Envanter::Envanter(const Envanter& other)
    : boyut(other.boyut),                    // (a) basit uye: dogrudan kopyala
    esyalar(new int[other.boyut])          // (b) KENDI bellegini al -- other'inkini PAYLASMA!
{
    for (int i = 0; i < boyut; i++)          // (c) icerigi tek tek kopyala = DERIN kopya
        esyalar[i] = other.esyalar[i];

    std::cout << "[COPY CTOR]    yeni dizi ayrildi, " << boyut << " eleman kopyalandi" << std::endl;
}

// ---------- COPY ASSIGNMENT ----------
// Nesne ZATEN VAR ve ZATEN bir kaynaga sahip. Dolu sayfanin ustune yaziyoruz.
// 4 adim var; (1) ve (2) copy ctor'da HIC YOK.
Envanter& Envanter::operator=(const Envanter& other)
{
    std::cout << "[COPY ASSIGN]  basladi" << std::endl;

    // (1) KENDINE ATAMA KORUMASI   <-- copy ctor'da YOK (orada imkansiz)
    if (this == &other)
    {
        std::cout << "               kendine atama yakalandi, dokunmadan cikiyorum" << std::endl;
        return *this;
    }

    // (2) ESKI KAYNAGI BIRAK       <-- copy ctor'da YOK (nesne yepyeniydi)
    delete[] esyalar;
    std::cout << "               eski dizi silindi" << std::endl;

    // (3) YENI KAYNAGI AL ve kopyala  <-- copy ctor'daki (b)+(c) ile ayni is
    boyut = other.boyut;
    esyalar = new int[boyut];
    for (int i = 0; i < boyut; i++)
        esyalar[i] = other.esyalar[i];
    std::cout << "               yeni dizi ayrildi, " << boyut << " eleman kopyalandi" << std::endl;

    // (4) KENDINI DONDUR           <-- copy ctor'da YOK (ctor deger dondurmez)
    return *this;                   //     bu sayede  a = b = c;  zinciri calisir
}

// ---------- DESTRUCTOR ----------
Envanter::~Envanter()
{
    delete[] esyalar;
    std::cout << "[DESTRUCTOR]   dizi serbest birakildi" << std::endl;
}

// ---------- yardimci uye fonksiyonlar ----------
void Envanter::Ayarla(int index, int deger)
{
    esyalar[index] = deger;
}

int Envanter::Getir(int index) const
{
    return esyalar[index];
}