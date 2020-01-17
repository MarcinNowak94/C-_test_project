// Cpp0x_lekcja_34(4)_HARD_odczyt_i_sumowanie_liczb.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//http://cpp0x.pl/kursy/Kurs-C++/Poziom-4/Wczytywanie-zawartosci-pliku-a-kontrola-bledow/485

/*
2.[trudne zadanie] Napisz program, który dla ka¿dego wiersza w pliku:

wczyta liczby i wypisze ich sumê w przypadku, gdy wszystkie liczby uda siê wczytaæ;
wypisze komunikat o b³êdnych danych, je¿eli wyst¹pi b³¹d podczas wczytywania liczb (komunikat ma wyœwietlaæ numer wiersza, w którym wyst¹pi³ b³¹d).

Przyk³adowe dane:
1 2 3
3 4 a 5
3 2
5 2 2 1 3
# 3 4
Oczekiwane standardowe wyjœcie programu dla przyk³adowego zestawu danych:
6
Bledne dane w wierszu nr 2!
5
13
Bledne dane w wierszu nr 5!
Wykorzystaj poni¿sz¹ funkcjê do wykrywania znaku przejœcia do nowej linii: (bool czyNapotkanoZnakNowegoWiersza( std::ifstream & plik ))

Powy¿szej funkcji nie wolno modyfikowaæ.
*/
#include "stdafx.h"


bool czyNapotkanoZnakNowegoWiersza(std::ifstream & plik)
{
	char cZnak;
	for (;; ) //nieskoñczona pêtla
	{
		plik.clear();
		cZnak = plik.peek(); //sprawdzamy jaki kolejny znak zostanie zwrócony przez operacjê odczytu
		if (plik.fail() || plik.bad())
			return false; //wyst¹pi³ b³¹d odczytu danych

		if (!isspace(cZnak))
			return false; //pobrany znak nie jest bia³ym znakiem

		plik.get(cZnak); //odczytujemy bia³y znak z pliku
		if (plik.fail() || plik.bad())
			return false; //wyst¹pi³ b³¹d odczytu danych

		if (cZnak == '\n')
			return true;

	} //for
}

void oblicz(int tab[100][100], int kolumny[100], int wiersze)
{
	int suma_wiersza=0;
	for (int i = 0; i <= wiersze; ++i)
	{
		for (int j = 0; j <=kolumny[i]+1; ++j)
		{
			suma_wiersza = suma_wiersza + tab[i][j];
			//std::cout << "\nwartosc elementu tab[" << i << "][" << j << "] =" << tab[i][j] << " suma=" << suma_wiersza;
		};
		std::cout << "\nSuma wiersza " << i << ": " << suma_wiersza;
		suma_wiersza = 0;
	};
	//std::cout << "[5][1]=" << tab[4][0] << "[5][2]=" << tab[4][1];
	return;
}

void wczytaj_plik(std::string nazwa_pliku)
{
	int a[100][100], max_kolumn[100];

	bool blad=false;
	std::ifstream wczytany_plik;
	//std::cout << "\n" << nazwa_pliku << "\n";
	wczytany_plik.open(nazwa_pliku.c_str());
	if (wczytany_plik.good()!=true)
	{
		std::cout << "\nNie udalo sie wczytac pliku! Blad odczytu z dysku\n";
		return;
	}
	unsigned short ilosc_wierszy, ilosc_kolumn;
	ilosc_wierszy = ilosc_kolumn = 0;
	while (wczytany_plik.eof()!=true)
	{
		if (czyNapotkanoZnakNowegoWiersza(wczytany_plik)==true)
		{
			//std::cout << "\nPrzeszlismy do nsatepnej linijki.\n";
			
			//std::cout << "kolumny wiersza " << ilosc_wierszy << " : " << max_kolumn[ilosc_wierszy] << "\n";
			++ilosc_wierszy;
			ilosc_kolumn = 0;
		};
		wczytany_plik >> a[ilosc_wierszy][ilosc_kolumn];
		if (wczytany_plik.good()==false)
		{
			std::cout << "\nNie udalo sie wczytac pliku! Blad odczytu danych z wiersza "<< ilosc_wierszy+1 <<"(element" << ilosc_kolumn+1 << ").";
			char trash=NULL;
			wczytany_plik.clear();
			wczytany_plik >> trash;
			blad = true;
		};
		std::cout << "\n[" << ilosc_wierszy << "][" << ilosc_kolumn <<"]=" << a[ilosc_wierszy][ilosc_kolumn] << "";
		max_kolumn[ilosc_wierszy] = ilosc_kolumn - 1;
		if (blad == false) { ++ilosc_kolumn; } else blad = false;
	};
	wczytany_plik.close();
	oblicz(a, max_kolumn, ilosc_wierszy);
	return;
}



int main()
{
	wczytaj_plik("przykladowy_plik.txt");
	std::cout << "\nZkonczono obliczenia. Wcisnij dowolny klawisz by zakonczyc.\n";
	_getch();
    return 0;
}

/*Komentarz autora:
Chyba sie troche zagalopowalem poniewaz program nie tylko wyswietla ze nastapil blad odczytu,
potrafi go tez zignorowac i odczytac reszte danych mozliwych do odczytania 
po czym zlicza wszystkie odczytane dane w kazdej z kolumn. 
*/