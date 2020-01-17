/*
1. Napisz program, który wczyta 3 liczby podane przez u¿ytkownika do tablicy, a nastêpnie wylosuje 2 z nich bez powtórzeñ. Wynik wypisz na ekran. Postaraj siê napisaæ ten program w oparciu o funkcje.
2. Zmodyfikuj program z pierwszego zadania tak, aby u¿ytkownik musia³ podaæ 10 liczb, a 8 z nich bêdzie losowanych bez powtórzeñ. SprawdŸ czy wyniki s¹ poprawne.
*/


#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <limits.h>



void wczytaj_liczby(unsigned int tab[], unsigned int roz)
{
	unsigned int pom = 0;

	do
	{
		std::cout << "\nPodaj " << pom + 1 << " Liczbe: ";
		std::cin >> tab[pom];
		++pom;
	} while (pom <= roz);
	return;
}

void losowanie(unsigned int tab[], unsigned int roz)
{
	unsigned int pom, los, najwieksza, najmniejsza, wynik;
	pom = los = najwieksza = 0;
	wynik = 1;
	najmniejsza = UINT_MAX;
	srand(static_cast<unsigned int>(time(NULL)));
	do
	{
		if (tab[pom] > najwieksza) { najwieksza = tab[pom]; std::cout << najwieksza << " , " << najmniejsza << "\n"; };
		if (tab[pom] < najmniejsza) { najmniejsza = tab[pom]; std::cout << najwieksza << " . " << najmniejsza << "\n"; };
		++pom;
	} while (pom <= roz);
	std::cout << najwieksza << " " << najmniejsza << "\n";
	pom = 0;
	do
	{
		std::cout << "(" << tab[pom] << ")";
		++pom;
	} while (pom <= roz);
	pom = 0;
	do
	{
		los = (std::rand() % (najwieksza - najmniejsza + 1)) + najmniejsza;
		if (wynik < los) wynik = los;
		std::cout << "\n" << los << ", " << tab[pom] << "(" << wynik << ")";
		_getch();
		if (los == tab[pom]) { ++pom; std::cout << "Zgadlem liczbe " << los << "\n"; };
	} while (pom <= roz);
	_getch();
	return;
}

void los_3_liczb_bez_powtorzen(int rozmiar)
{
	unsigned int tablica[2], tablica2[9];
	if (rozmiar == 2)
	{
		wczytaj_liczby(tablica, rozmiar);
		losowanie(tablica, rozmiar);
	};
	if (rozmiar == 9)
	{
		wczytaj_liczby(tablica2, rozmiar);
		losowanie(tablica2, rozmiar);
	}

	std::cout << "Wyszlismy z procedury";
	int i;
	if (rozmiar == 2)
	{
		for (tablica[i=0]; tablica[2]; ++i) { std::cout << "\n " << tablica[i]; };
	};
	if (rozmiar == 9)
	{
		for (tablica2[i]; tablica2[9]; ++i) { std::cout << "\n " << tablica2[i]; }
	};
	_getch();
	return;
}


int main()
{
	std::cout << "Ktora wersje programu chcesz uruchomic?\n"
		<< "1.Losowanie 2 z 3 podanych liczb bez powtorzen\n"
		<< "2.Losowanie 8 z 10 podanych liczb bez powtorzen\n";
	char a = _getch();
	switch (a)
	{
	case 49:los_3_liczb_bez_powtorzen(2); break;
	case 50:los_3_liczb_bez_powtorzen(9); break;
	default:break;
	}
	std::cout << "\nI tak oto zakonczylismy program.\n";
	_getch();
	return 0;
}

