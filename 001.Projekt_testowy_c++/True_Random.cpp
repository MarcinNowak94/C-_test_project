// True_Random.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <time.h>

int True_Random()
{
	time_t czas_rozpoczecia = time(NULL);
	std::cout << "Czas rozpoczecia: " << czas_rozpoczecia << "\n";
	std::random_device ziarno;
	std::mt19937 mt(ziarno());
	std::uniform_int_distribution<int> zakres(0, 99);
	int tab[100];
	for (int i = 0; i <= 99; i++)
	{
		tab[i] = 0; //inicjalizacja
	};
	for (int j = 0; j < 1000; j++)	
	{
		for (int i = 0; i < 30; i++)
		{
			std::cout << zakres(mt) << ", ";
			tab[zakres(mt)]+=1;
		};
		std::cout << std::endl;
	};
	std::cout << "---------------------------------------------------------------------------------" << std::endl;
	int pom = 0;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			pom += 1;
			std::cout << pom << ": " << tab[pom] << ", ";
		};
		std::cout << std::endl;
	};
	time_t czas_zakonczenia = time(NULL);
	std::cout << "Czas zakonczenia: " << czas_zakonczenia << ". Wykonano w: "<< czas_zakonczenia-czas_rozpoczecia <<"sekund\n";
	std::cout << "\nZakonczono pomyslnie!";
	_getch();
	return 0;
}

