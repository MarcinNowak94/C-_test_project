// Cpp0x_lekcja16(2)_cieplo_zimno.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.

/*
Twoim zadaniem domowym jest napisanie prostej gry, która ma dzia³aæ nastêpuj¹co:
1. Program losuje liczbê z przedzia³u od 1 do 1000.
2. U¿ytkownik zgaduje liczbê, która zosta³a wylosowana.
3. Je¿eli podana liczba jest za du¿a (za ma³a) gra wypisuje stosowny komunikat i powraca do kroku 2.
4. Je¿eli gracz trafi liczbê wylosowan¹ to progam koñczy dzia³anie, wypisuj¹c na ekran wylosowan¹ liczbê oraz liczbê 'strza³ów', które odda³ gracz.
Gra ma byæ zabezpieczona przed mo¿liwoœci¹ wprowadzenia b³êdnych wartoœci liczbowych.
*/

#include "stdafx.h"


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	unsigned int a, b,c;
	b = c = 0;
	bool input=false;
	a = (std::rand() % 1000);
	std::cout << "\tWylosowano liczbe w przedziale 0-1000 - zgadnij ja \n";
	do
	{
		std::cout << "\nPodaj liczbe: ";
		do
		{
			std::cin >> b;
		} while (b > 1000 || b < 0);
		++c;
		if (a != b)
		 {
			if (a > b)
			{
				std::cout << "\nLiczba jest wieksza od " << b << ". Podejscie: " << c << ".\n";
			}
			else
			{
				std::cout << "\nLiczba jest mniejsza od " << b << ". Podejscie: " << c << ".\n";
			};
		 }
		else
		{
			std::cout << "\n Brawo! udalo ci sie za " << c << " podejsciem.\n";
			input = true;
		};

	} while (input != true);
	_getch();
    return 0;
}

