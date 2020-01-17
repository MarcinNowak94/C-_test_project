#include "stdafx.h"
#include "second.h"
//https://msdn.microsoft.com/en-us/library/078sfkak(v=vs.110).aspx

void New_Menu()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	const int arsize = 4;
	char cursor[arsize]{' '}, input='0';
	cursor[0] = '*';
	int cursorposition = 0;
	do
	{
		cls(hStdout);
		std::cout << "\t\tNew Menu\n"
			<< "--------------------------------------------------\n"
			<< "[" << cursor[0] << "] Option 1\n"
			<< "[" << cursor[1] << "] Option 2\n"
			<< "[" << cursor[2] << "] Option 3\n"
			<< "[" << cursor[3] << "] Option 4\n"
			<< "---------------------------------------------------\n"
			<< "ESC to close";
		input = _getch();
		if (input == '0' || input == '0xE0') { input = _getch(); };
		switch (input)
		{
		case 72: {if (cursorposition != 0)			//up arrow
		{
			cursor[cursorposition - 1] = cursor[cursorposition];
			cursor[cursorposition] = ' ';
			cursorposition -= 1;
		}; }; break;
		case 80: {if (cursorposition != arsize-1)			//down arrow
		{
			cursor[cursorposition + 1] = cursor[cursorposition];
			cursor[cursorposition] = ' ';
			cursorposition += 1;
		}; }; break;
		case '\r':											//enter carriage return
		{
			switch (cursorposition)
			{
			case 0: {std::cout << "Option 1\nPress any key to continue ..."; _getch(); }; break;
			case 1: {std::cout << "Option 2\nPress any key to continue ..."; _getch(); }; break;
			case 2: {std::cout << "Option 3\nPress any key to continue ..."; _getch(); }; break;
			case 3: {std::cout << "Option 4\nPress any key to continue ..."; _getch(); }; break;
			default:break;
			};
		};
		default:break;
		}
	} while (input!=27);

	/*
	stare menu


	char a='0';
	int zmienna_globalna = 0;
	while (a != 27)
	{
	cls(hStdout);
	std::cout << "Hello world!\n" << "Wciœnij klawisz by uruchomic procedure\n"
	<< "---------------------------------------------------------\n"
	<< "1.Test procedury\n"
	<< "2.Test linkera (+referencja[" << zmienna_globalna <<"])\n"
	<< "3.Cwiczenia\n"
	<< "4.Wyzwania\n"
	<< "---------------------------------------------------------\n"
	<< "\tWcisnij ESC aby wyjsc. \n";
	a = _getch(); //DEBUG - przypisza wartosc konkretnego znaku zeby nie przechodzic przez menu
	switch (a)
	{
	case 49:procedura(); break;
	case 50:second(zmienna_globalna); break;
	case 51:
	{
	char b = 0;
	while (b != 27)
	{

	cls(hStdout);
	std::cout << "Wybierz tematyke:\n"
	<< "---------------------------------------------------------\n"
	<< "1.Formatowanie tekstu konsolowego\n"
	<< "2.Rozmiar typow zmiennych\n"
	<< "3.Pre vs Post inkrementacja\n"
	<< "4.Kolory w konsoli\n"
	<< "5.Liczby losowe\n"
	<< "6.Praca z tekstem (klasa string)\n"
	<< "7.Obsluga plikow\n"
	<< "8.Wektory\n"
	<< "---------------------------------------------------------\n"
	<< "ESC aby wyjsc do poprzeniego menu\n"
	<< "x aby zamknac program";
	b = _getch();
	switch (b)
	{
	case 49:formatowanie_tekstu_konsola(); break;
	case 50:rozmiar_typow_danych(); break;
	case 51:post_vs_preinkrementacja(); break;
	case 52:kolory_w_konsoli(); break;
	case 53:liczby_losowe(); break;
	case 54:praca_z_tekstem(); break;
	case 55:obsluga_plikow(); break;
	case 56:Wektory(); break;
	case 120:
	case 88: {a = 27; b = 27; }; break;
	default: break;
	};
	};
	}; break;
	case 52:
	{

	char c = 0;
	while (c != 27)
	{

	cls(hStdout);
	std::cout << "Wybierz wyzwanie:\n"
	<< "------------------------Coderbyte------------------------\n"
	<< "1.Silnia rekurencyjnie\n"
	<< "2.\n"
	<< "3.\n"
	<< "---------------------------------------------------------\n"
	<< "5.Departamenty\n"
	<< "6.Bankomat\n"
	<< "7.Zgadywanie liczby losowej\n"
	<< "---------------------------------------------------------\n"
	<< "ESC aby wyjsc do poprzeniego menu\n"
	<< "Shift+X aby zamknac program";

	c = _getch(); //DEBUG - przypisza wartosc konkretnego znaku zeby nie przechodzic przez menu
	switch (c)
	{
	case 49:silnia_rekurencyjnie(); break;
	//case '2':second(); break;
	//case '3':cwiczenia(); break;
	case '5': Departamenty(); break;
	case '6': Bankomat(); break;
	case '7': Zgadywanie_liczby_losowej(); break;
	case 120:
	case 88: {a = 27; c = 27; }; break;
	default: break;
	};
	}
	}; break;
	default: break;
	};
	};
	*/

	_getch;
	return;
}
