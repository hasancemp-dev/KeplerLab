#include "Dusman.h"		//kendi header'ını dahil et
#include <iostream>		//Bilgi() içinde cout kullanılacağı için burada lazım

//Getter
std::string Dusman::GetAd() const	// Sinif::Metod() — "bu fonksiyon Dusman'a ait" der
{
	return ad;
}

int Dusman::GetCan() const
{
	return can;
}

int Dusman::GetHasar() const
{
	return hasar;
}

//Setter
void Dusman::SetAd(const std::string& yeniAd)
{
	ad = yeniAd;
}

void Dusman::SetCan(int yeniCan)
{
	if (yeniCan < 0)
	{
		can = 0;
	}
	else
	{
		can = yeniCan;
	}
}

void  Dusman::SetHasar(int yeniHasar)
{
	if (yeniHasar < 0)
	{
		hasar = 0;
	}
	else
	{
		hasar = yeniHasar;
	}
}

void  Dusman::HasarAl(int gelenHasar)
{
	can -= gelenHasar;
	if (can <= 0)
	{
		can = 0;
		std::cout << ad << " oldu!" << std::endl;
	}
}

void  Dusman::Bilgi() const
{
	std::cout << ad << " - Can: " << can << ", Hasar: " << hasar << std::endl;
}