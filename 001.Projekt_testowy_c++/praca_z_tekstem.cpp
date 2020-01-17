#include "stdafx.h"
#include "second.h"
#include <string>

void szukaj(std::string & tekst, char znak, bool wystapienia)\
{
	size_t miejsce = tekst.find(znak);
	if (miejsce == std::string::npos)
	{std::cout << "\n Nie znaleziono znaku '" << znak << "' w podanym tekscie\n";}
	else
	{
		if (wystapienia==false)
		{
			std::cout << "\nW podanym tekscie znak '" << znak << "' znajduje sie na " << miejsce + 1 << " miejscu.\n";
			return ;
		}
		else
		{
			std::cout << "\n" << znak << " znalezion na miejscach: ";
			do
			{
				std::cout << miejsce+1 ;
				miejsce = tekst.find(znak, miejsce + 1);
				if (miejsce!=std::string::npos)
				{
					std::wcout << ", ";
				};
			} while (miejsce != std::string::npos);
			return;
		}
	}
}
void szukaj_frazy(std::string & text, std::string fraza)
{
	size_t znaleziono = text.find(fraza);
	if (znaleziono == std::string::npos)
	{
		std::cout << "\nW podanym tekscie nie znajduje sie podana fraza.";
		return;
	}
	else
	{
		std::cout << "\nFraze '" << fraza << "' znaleziono na pozycjach: ";
		do
		{
			std::cout << znaleziono+1 << "-" << znaleziono+fraza.size();
			znaleziono = text.find(fraza, znaleziono + fraza.size());
			if (znaleziono != std::string::npos)
			{
					std::cout << ", ";
			};
		} while (znaleziono != std::string::npos);
		return;
	};	
}


void praca_z_tekstem()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::string wyraz;
	char clear;
	std::cout << "\nKlasa string za pomoca roznych metod pozwala na modyfikowanie i dzialania na zmiennych tekstowych."
		<< "\nZmienne przechowywane jako typ string mozna dodawac na rozne sposoby:"
		<< "\nPodaj jakis tekst: ";
	std::getline(std::cin, wyraz);
	std::cout << "\nDo podanego tekstu mozemy dodac znaki za pomoca: "
		<< "\noperatora przeciazonego (+=): \n"; wyraz += " (dodano sposobem +=)"; std::cout << wyraz
		<< "\n\nlub metoda zmienna.append(\" tekst \"): \n"; wyraz.append(" (dodano metoda .append)"); std::cout << wyraz
		<< "\n\nPonadto mamy mozliwosc wstawienia zmiany w dowolne miejsce metoda zmienna.insert(znak_poczatkowy, \"tekst\"): \n" << wyraz.insert(10, " (wstawiono metoda insert) "); std::cout << wyraz
		<< "\n\nco wiaze sie przy okazji z mozliwoscia kopiowania .insert(znak_poczatkowy, inna_zmienna, znak_poczatkowy, znak_koncowy):\n"; wyraz.insert(27, wyraz, 10, 27); std::cout << wyraz
		<< "\n]nJest tez mozliwosc usuniecia czesci tekstu tekstu  metoda erase :\n"; wyraz.erase(10, 44); std::cout << wyraz
		<< "\n-----------------------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Wyczyscic ekran (t\\n)?";
	clear = _getch();
	if (clear=='t' || clear=='T')
	{
		cls(hStdout);
	};
	std::cout << "W celu wyszukania podanego znaku w tekscie mozna uzyc metody .find('znak') nalezacej do klasy string\n"
		<< "Zwracany jest numer pod ktorym znajduje sie dany znak liczony od 0\n"
		<<"(np. w powyzszej linijce literka 'p' jest na 22 miejscu, 'Z' to litera nr.0)\n\n"
		<< "Przetestujmy zatem jej dzialanie, wpisz jakis tekst :\n";
	std::string podany_tekst, c;
	std::getline(std::cin, podany_tekst);
	char a, b;
	bool test=false;
	std::cout << "\nChcesz znalezc (P)PIERWSZE WYSTAPIENIE, (K)KAZDA POZYCJE znaku czy (F)Fraze? :";
	do
	{
		b = _getch();
		if (b == 'p' || b == 'P' || b == 'k' || b == 'K' || b == 'f' || b == 'F') { test = true; }
		else std::cout << "\nAkceptowane znaki to: p, P, k, K, f, F. Sprobuj jeszcze raz :";
	} while (test==false);
	if (b == 'p' || b == 'P') { std::cout << "\nA wiec jakiego znaku szukasz? :"; a = _getch(); szukaj(podany_tekst, a, false); }
	if (b == 'k' || b == 'K') { std::cout << "\nA wiec jakiego znaku szukasz? :"; a = _getch(); szukaj(podany_tekst, a, true); }
	else { std::cout << "\nJakiej frazy szukamy?: "; std::getline(std::cin, c); szukaj_frazy(podany_tekst, c); };

	std::cout << "\n-----------------------------------------------------------------------------------\n"
		<< "\t\t\tUwagi\n"
		<< "-Jesli metoda nie znajdzie znaku zwraca wartosc string::npos (rownoznaczna z -1)\n"
		<< "-Szukanie odwrotne mozna wykonac metoda .rfind(znak)\n"
		<< "-----------------------------------------------------------------------------------\n"
	<< "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
	return;
}