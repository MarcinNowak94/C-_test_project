// Cpp0x_lekcja18(2)_tablice_generator.cpp: Okre�la punkt wej�cia dla aplikacji konsoli.

/*
Napisz program, kt�ry wylosuje 999 liczb ca�kowitych z zakresu od 4 do 10 w��cznie, wypisze te warto�ci na ekran, po czym zsumuje je i wynik wypisze na ekran. 
Program ma wykorzystywa� tablic�, kt�ra zostanie najpierw wype�niona liczbami losowymi z okre�lonego przedzia�u, a nast�pnie wynik zostanie obliczony na podstawie zawarto�ci ca�ej tablicy.
*/


#include "stdafx.h"


int main()
{
	unsigned int tab[1000];
	unsigned int wynik, pom;
	pom = wynik = 0;
	srand(static_cast<unsigned int>(time(NULL)));
	std::cout << "Generuje 999 liczb i zsumuje je\n";
	for (pom=0; pom<=999; ++pom)
	{
		tab[pom] = (std::rand()%6)+4;
		if (pom%10==0) 
		{
			std::cout << tab[pom] << "\n";
		}
		else
		{
			std::cout << "(" << pom <<")"<<tab[pom] << ", ";
			//_getch(;
		};
		
	};
	for (pom = 0; pom <= 999; ++pom)
	{
		wynik = wynik + tab[pom];
	};
	std::cout << "\nSuma wylosowanych liczb wynosi: " << wynik << "\n";
	_getch();
    return 0;
}

