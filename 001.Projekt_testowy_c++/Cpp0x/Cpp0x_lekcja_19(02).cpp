// Cpp0x_lekcja_19(02).cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

/*
Napisz program, który wylosuje 999 liczb ca³kowitych z zakresu od 4 do 10 w³¹cznie, wypisze te wartoœci na ekran, po czym zsumuje je i wynik wypisze na ekran. Wszelkie operacje maj¹ zostaæ zrealizowane w oparciu o funkcje. Tablica ma byæ zadeklarowana w funkcji main. Oczekiwane funkcje:

Wype³nienie tablicy o podanym rozmiarze losowymi liczbami z przedzia³u podawanego przez argumenty funkcji.
Sumowanie okreœlonej iloœci liczb znajduj¹cych siê w tablicy i zwrot wyniku.
Wypisywanie zawartoœci tablicy.

Przyk³adowa implementacja funkcji main:
int main()
{
int tablica[ 999 ];
wylosujLiczby( tablica, 999, 4, 10 );
wypiszLiczby( tablica, 999 );
int iSuma = obliczSume( tablica, 999 );
std::cout << "Suma liczb wynosi: " << iSuma << std::endl;
return 0;
}
*/

#include "stdafx.h"

void wylosujLiczby(int tab[], unsigned int rozmiar, unsigned int a, unsigned  int b)
{
	srand(static_cast<unsigned int>(time(NULL)));
	unsigned int pom = 0;
	do
	{
		tab[pom] = ((std::rand()%b)+a);
		++pom;
	} while (pom <= rozmiar);
	return;
}

void wypiszLiczby(int tab[], unsigned int pom)
{
	unsigned int wykonano = 0;
	do
	{
		std::cout << "(" << wykonano << ")" << tab[wykonano] << ", ";
		++wykonano;
	} while (wykonano <= pom);
	return;
}

int obliczSume(int tab[], unsigned int rozmiar)
{
	unsigned int pom, suma;
	pom = suma = 0;
	do
	{
		suma = suma + tab[pom];
		++pom;
	} while (pom<=rozmiar);
	return (suma);
}

int main()
{
	int tablica[999];
	wylosujLiczby(tablica, 999, 4, 10);
	wypiszLiczby(tablica, 999);
	int iSuma = obliczSume(tablica, 999);
	std::cout << "\n\n\t\tSuma liczb wynosi: " << iSuma << std::endl;
	_getch();
	return 0;
}

