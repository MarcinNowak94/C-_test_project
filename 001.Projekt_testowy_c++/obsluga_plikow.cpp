#include "stdafx.h"
#include "second.h"
#include <fstream>
#include <string>

//http://www.cplusplus.com/reference/fstream/ifstream/
//http://www.cplusplus.com/reference/fstream/fstream/

void odczyt(std::string nazwa_pliku)
{
	std::ifstream wczytany_plik;
	wczytany_plik.open(nazwa_pliku.c_str());  //w razie podania pliku przez uzytkownika zmienna musi zostac przekanana przez zmienna.c_str()
	/*zawartoœæ przykladowy.txt:
	1 2 3
	4
			<<pusty wiersz, brak spacji ((...)4+enter+enter+5(...))== \n || std::endl
	5
	a
	6
	janusz
	34+98
	true
	*/
	/*zawartoœæ liczbowy.txt: 4 8 15 16 23 42 176+284 10/5*4 */
	/*zawartoœæ tekstowy.txt:
	Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. 
	Ut enim ad minim veniam, quis nostrud exercitation ullamco 
	laboris nisi ut aliquip ex ea commodo consequat. 
	Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. 
	Excepteur sint occaecat cupidatat non proident,
	sunt in culpa qui officia deserunt mollit anim id est laborum.
	*/
	if (wczytany_plik.good()==true) {std::cout << "\nPlik wczytany poprawnie.\n";}
	else { std::cout << "\nNie udalo sie wczytac pliku\n"; };	
	//TODO: Odczyt danych z pliku
	std::string wczytane_dane, wczytany_tekst;
	int wczytana_liczba;
	if (nazwa_pliku == "pliki\\przykladowy.txt") { while (std::getline(wczytany_plik, wczytane_dane)) { std::cout << wczytane_dane << "\n"; }; wczytany_plik.close(); return; };
	if (nazwa_pliku == "pliki\\liczbowy.txt") { while (wczytany_plik >> wczytana_liczba) { std::cout << wczytana_liczba << ", "; }; wczytany_plik.close(); return; };
	if (nazwa_pliku == "pliki\\tekstowy.txt") { while (wczytany_plik >> wczytane_dane) { std::cout << wczytane_dane << " "; }; wczytany_plik.close(); return; };
	wczytany_plik.close();
	return;
}

void zapis()
{
	//TODO: Zapis danych do pliku
	return;
}

void obsluga_plikow()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::cout << "Do obsugi plikow sluzy zmienna typu ifstream zmienna z naglowka fstream\n"
		<< "tak zadeklarowana zmienna jest obiektem przechowujacym uchwyt do pliku\n"
		<< "Plik wczytujemy za pomoca metody .open(\"sciezka_do_pliku\") przy czym wyrozniamy dwa rodzaje sciezek:\n"
		<< "-Sciezka wzgledna: wcytywanie z katalogu roboczego lub podanie TYLKO nazwy pliku\n"
		<< "-Sciezka bezwzgledna: pelna sciezka do lokalizacji pliku n.p.: C:\\\\Folder\\Podfolder\\wczytywany_plik\n"
		<< "w razie podania pliku przez uzytkownika zmienna musi zostac przekanana przez zmienna.c_str() -\ntaki sposob zwraca wartosc tylko do odczytu\n"
		<< "Dane moga zostac odczytane przez program standardowymi metodami - getline(sposob odczytu, zmienna string)\n"
		<< "Odczytany plik nalezy zamknac metoda .close(). Do wczytywanego pliku mozna tez zajrzec metoda .peek()\n"
		<< "Przetestujmy wiec odczyt z pliku. Jakiego typu dane chcesz odczytac?:\n"
		<< "P - plik, T- Tekstowe, L - liczbowe\n";
	char a = _getch();
	switch (a)
	{
	case 'p': case 'P': odczyt("pliki\\przykladowy.txt"); break;
	case 't': case 'T': odczyt("pliki\\tekstowy.txt"); break;
	case 'l': case 'L': odczyt("pliki\\liczbowy.txt"); break;
	default:break;
	};
	std::cout << "\n\nObsluga bledow odbywa sie za pomoca metod:"
		<< "\n.eof()\t nazwa_pliku.eof()=1 gdy program odczyta wszystkie dane i napotka koniec pliku"
		<< "\n.good() / .bad() \t bad=1(analogicznie good=0) jesli nie udalo sie wczytac danych z pliku z powodu sprzetowego (brak dostepu do pliku)"
		<< "\n.fail() \t fail=1 jesli nie udalo sie wczytac danych z powodu bledu odczytu pliku (blad programu)"
		<< "\n.clear() \t standardowo czysci flagi bledow (strumien wczytuje dane tylko jesli flaga bledu = false)";
	std::cout << "\n--------------------------------------------------------------------------\n"
		<< "Poruszanie sie po pliku:\n"
		<< "Jest kilka sposobow na poruszanie sie po danych zawartych w pliku dzieki metodzie .seekg() ktora ma kilka wywolan\n"
		<< ".seekg(numer_znaku) - przechodzi do wybranego bajta danych\n"
		<< ".seekg(n_z, parametr) - wybiera bajt o numerze n_z szukajac od:\n:"
		<< "std::ios::beg - poczatku (beginning), std::ios::curr - obecnego miejsca(current), std::ios::end - konca pliku\n"
		<< "Obecna pozycje mozna uzyskac uzywajac ponizszego zapisu:\n"
		<< "std::streampos nazwa_zmiennej = plik.tellg()\n"
	<< "A teraz krotko o zapisie do pliku:\n";
	std::cout << "\n--------------------------------------------------------------------------\n"
			<< "Uwagi:\n"
			<< "Katalog roboczy moze byc inny niz katalog, w ktorym znajduje sie plik *.exe w sytuacji, gdy:\n"
			<< "-aplikacja jest uruchamiana za pomoca wiersza polecen poprzez podanie sciezki bezwzglêdnej do aplikacji\n"
			<< "-aplikacja jest uruchamiana za pomoca wiersza polecen poprzez podanie sciezki wzglednej,\n wskazuj¹cej na aplikacje znajdujaca sie w innym katalogu niz katalog widoczny w wierszu polecen\n"
			<< "-aplikacja jest uruchamiana przez srodowisko programistyczne\n(w kazdym szanujacym sie srodowisku programistycznym istnieje mozliwosc ustawiania katalogu roboczego dla uruchamianej aplikacji)\n"
			<< "-do utworzonej aplikacji utworzono skrot, w ktorym zdefiniowano ustawianie innego katalogu roboczego niz domyslny\n"
			<< "-uruchamiana aplikacja samodzielnie zmienia katalog roboczy, bo tak zostala zaprogramowana\n"
			<< "---------------------------------------------------------------------------\n"
			<< "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
	return;
}