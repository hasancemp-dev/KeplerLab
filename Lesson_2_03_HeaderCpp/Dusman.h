#pragma once	// bu dosyanın bir derleme biriminde birden fazla kez 
				
				// include edilmesini engeller (include guard'ın modern hali

#include <string>

class Dusman
{
private:
	std::string ad = "";
	int can = 0;
	int hasar = 0;

public:
	std::string GetAd() const;	//sadece imza, gövde yok - sonunda ";" var
	int GetCan() const;
	int GetHasar() const;

	void SetAd(const std::string& yeniAd);
	void SetCan(int yeniCan);
	void SetHasar(int yeniHasar);

	void HasarAl(int gelenHasar);
	void Bilgi() const;
};

