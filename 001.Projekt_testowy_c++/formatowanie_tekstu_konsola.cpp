#include "stdafx.h"
#include <iostream>
#include "second.h"

void formatowanie_tekstu_konsola()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::cout << "Mozliwoœci formatowania wyswietlanego tekstu:"
		<< "\n-------------------------------------"
		<< "\n1." << "\t tabulacja "
		<< "\n2." << "Znaki specjalne: \\, \, \:, ..." << "\n" << "\n";
	int stala;
	float rzeczywista;
	char znak;
	std::string tekst_a, tekst_b;
	std::cout << "\n \nObsluga strumienia wejsciowego(szcegoly):\n"
		<< "-------------------------------------\n"
		<< "Wpisz liczbe calkowita (i.e.: 3, 6, 4692, 18)\n";
	std::cin >> stala;
	std::cout << "\nWczytane poprawnie? " << std::cin.good() << std::endl;
	std::cout << "Blad wczytywania? " << std::cin.fail() << std::endl;
	std::cout << "Wpisz liczbe rzeczywista (i.e.: 7.5 , 4.56 , 8.123)\n";
	std::cin.clear(); std::cin.sync(); std::cin.ignore(1000, '\n');										//czyszczenie flagi bledu i bufora
	std::cin >> rzeczywista;
	std::cout << "\nWczytane poprawnie? " << std::cin.good() << "\n";
	std::cout << "Blad wczytywania? " << std::cin.fail() << "\n";
	std::cout << "Wpisz litere (i.e.: a, f, o, q)\n";
	std::cin.clear(); std::cin.sync(); std::cin.ignore(1000,'\n');
	std::cin >> znak;
	std::cout << "\nWczytane poprawnie? " << std::cin.good() << "\n";
	std::cout << "Blad wczytywania? " << std::cin.fail() << "\n \n";
	std::cout << "Dodatkowo strumien wczytywania mozna wyczyscic za pomoca komend: \n";
	std::cout << "-------------------------------------\n"
		<< "std\:\:cin.clear() - czyszczenie flag bledu\n"
		<< "std\:\:cin.sync() lub std\:\:cin.ignore(ilosc znakow, '\\n') - czyszczenie bufora\n"
		<< "\n\n\t\tA teraz o tekscie.\n"
		<< "-------------------------------------\n"
		<< "Do przechowywania tekstu sluzy zmienna typu string zawarte w pliku naglowkowym <string>\n"
		<< "co ciekawe mozna nimi operowac jak kazda inna zmienna \n"
		<< "Podaj tekst a: ";
	std::cin.clear(); std::cin.sync(); std::cin.ignore(1000, '\n');
	std::cin >> tekst_a;
	std::cout << "\nPodaj tekst b: ";
	std::cin.clear(); std::cin.sync(); std::cin.ignore(1000, '\n');
	std::cin >> tekst_b;
	std::cout << "\n\nTekst a ( " << tekst_a << " ) + tekst b ( " << tekst_b << " ) = " << tekst_a + tekst_b << " .\n"
		<<"Czyszczenie zmiennej odbywa sie za pomoca komendy (metody) nazwa_zmiennej.clear()\n";
	std::cin.clear(); std::cin.sync();
	std::cout << "Po wyczyszczeniu nasze zmienne wygladaja tak: tekst a ( " << tekst_a << " ), tekst b ( " << tekst_b << " ).\n"
		<< "Warto jednak zauwazyc ze podany tekst jest wczytywany tylko do momentu wpisania spacji\n"
		<< "program zabezpieczono przed przekazaniem reszty tekstu z buforu do drugiej zmiennej,\n"
		<< "jednak istnieje mozliwosc wczytywania calych linijek - std::getline(std::cin, zmienna_string)\n"
		<< "\t\t\nWyprobujmy wiec powyzszy sposob:\n"
		<< "Podaj tekst a: ";
	std::cin.clear(); std::cin.sync(); std::cin.ignore(1000, '\n');
	std::getline(std::cin, tekst_a);
	std::cout << "Podaj tekst b: ";
	std::getline(std::cin, tekst_b);
	std::cout << "\nTekst a ( " << tekst_a << " ) + tekst b ( " << tekst_b << " ) = " << tekst_a + tekst_b << " .\n";
	std::cout << "\nWcisnij dowolny klawisz by powrocic\n";
	_getch();
	return;
}