#pragma once

class Envanter
{
private:
    // DIKKAT: uye tanim sirasi onemli.
    // Initializer list bu sirayi izlemeli, yoksa -Wreorder uyarisi alirsin.
    int  boyut;
    int* esyalar;    // <<< YONETILEN KAYNAK: heap'te ayrilmis dizi

public:
    Envanter(int b);                                // normal constructor
    Envanter(const Envanter& other);                // COPY CONSTRUCTOR
    Envanter& operator=(const Envanter& other);     // COPY ASSIGNMENT
    ~Envanter();                                    // DESTRUCTOR

    void Ayarla(int index, int deger);
    int  Getir(int index) const;
};