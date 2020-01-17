#include "stdafx.h"
#include "second.h"
#include <vector>
#include <random>

void Utworz_wektor(unsigned short rozmiar, unsigned short pocz, unsigned short kon)
{
	std::vector <unsigned short> Wiktor(1);
	std::cout << "\nPoczatkowy rozmiar wektora to "<< Wiktor.size() <<" (przechowuje tylko wartosc o indeksie 0)\nProcedura wylosuje " << rozmiar << " liczb z zakresu " << pocz << "-" << kon << ".\n\n";	std::random_device rd;
	Wiktor.reserve(rozmiar);			//rezerwuje w pamiêci systemu iloœæ pamiêci do przechowania iloœci elementów równej podanemu rozmiarowi
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<unsigned short> mt(pocz,kon);
	for (unsigned long i = 0; i < rozmiar; i++)
	{
		Wiktor.push_back(mt(mersenne));
	}
	for (unsigned long i = 0; i < rozmiar; i++)
	{ 
		std::cout << Wiktor.at(i);
		if (i % 10 != 0)  {std::cout << "(" << i + 1 << ")\t";}
		else { std::cout << "(" << i + 1 << ")\n";}
	};
	std::cout << "\n\nJak widac w wektorze zmiescilismy wiecej wartosci niz 1 liczba, dokladniej bylo ich " << Wiktor.size() << "\n"
		<< "Pierwszy element wektora ma wartosc: " << Wiktor.at(0) << "\nOstatni element wektora ma wartosc: " << Wiktor.back() << ".\n"; //
	return;
}


void Wektory()
{
	unsigned short rozm = 0, poczatek=0, koniec =10;
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::cout << "Wektory to typ danych zarzadzany dynamicznie, podczas tworzenia wektora nalezy podac jego poczatkowy rozmiar,"
		<< "(vector <typ_danych> nazwa_zmiennej(poczatkowy_rozmiar))jednak po utworzeniu mozna zarzadzac nim za pomoca metod:\n"
		<< "-nazwa_zmiennej.push_back(wartosc) - nadajac tym samym wartosc elementowi o indeksie poczatkowy_rozmiar+1\n"
		<< "-nazwa_zmiennej.pop_back() - usuwajac tym samym element o indeksie poczatkowy_rozmiar\n"
		<< "-nazwa_zmiennej.begin() - wskazuje na piewszy element wektora\n"
		<< "-nazwa_zmiennej.back() - wskazuje na ostatni element wektora\n"
		<< "-nazwa_zmiennej.insert(indeks, wartosc) - nadaje wartosc elementowi o podanym indeksie\n"
		<< "-------------------------------------------------------------------------------------------------------------------\n"
		<< "Sprobojmy wiec utworzyc wektor losowych danych o podanej wartosci,\nPodaj rozmiar wektora: ";
	/*std::cin >> rozm;
	std::cout << "Liczba poczatkowa:";
		std::cin >> poczatek;
		std::cin.clear(); std::cin.sync();
		std::cin.ignore(1000, '\n');
		std::cout << "\nLiczba koncowa: ";
		std::cin >> koniec;*/
	rozm = 60; poczatek = 8; koniec = 40;
	Utworz_wektor(rozm, poczatek, koniec);
	std::cout << "-------------------------------------------------------------------------------------------------------------------\n"
		<< "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
	return;
}