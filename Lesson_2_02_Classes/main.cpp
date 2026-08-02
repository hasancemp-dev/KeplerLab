#include <iostream>
#include <string>


class Dusman
{
private:
	std::string ad = "";
	int can = 0;
	int hasar = 0;

public:

	//Getter
	std::string GetAd() const
	{
		return ad;						
	}

	int GetCan() const
	{
		return can;
	}

	int GetHasar() const
	{
		return hasar;
	}

	//Setter
	void SetAd(const std::string& yeniAd)
	{
		ad = yeniAd;
	}

	void SetCan(int yeniCan)
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

	void SetHasar(int yeniHasar)
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

	void HasarAl(int gelenHasar)
	{
		can -= gelenHasar;   
		if (can <= 0)
		{
			can = 0;
			std::cout << ad << " oldu!" << std::endl;
		}
	}

	void Bilgi() const
	{
		std::cout << ad << " - Can: " << can << ", Hasar: " << hasar << std::endl;
	}

};

int main()
{
	Dusman goblin;
	goblin.SetAd("Goblin");
	goblin.SetCan(40);
	goblin.SetHasar(10);

	std::cout << "============================" << std::endl;
	std::cout << "\t   STATS" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "Name:\t" << goblin.GetAd() << std::endl;
	std::cout << "Health:\t" << goblin.GetCan() << std::endl;
	std::cout << "Damage:\t" << goblin.GetHasar() << std::endl;


	for (int i = 0; i < 3; i++)
	{
		goblin.HasarAl(15);
		goblin.Bilgi();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	goblin.SetCan(500);
	goblin.Bilgi();
	std::cout << std::endl;
	goblin.SetCan(-500); 
	goblin.Bilgi(); // Encapsulation sayesinde veri korundu!

	return 0;
} 