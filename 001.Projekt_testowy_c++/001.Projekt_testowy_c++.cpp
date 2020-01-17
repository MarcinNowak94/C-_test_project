// 001.Projekt_testowy_c++.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "second.h"
#include "Silnia_rekurencyjnie.h"
#include "Simplemenu.h"

void procedura()
{
	std::cout << "\n\nJestesmy wewnatrz procedury\n";
	std::cout << "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
	return;
}

int main()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	const int arsize = 20;
	char cursor[arsize]{ ' ' }, input = '0', subinput='0';
	cursor[0] = '*';
	std::string practicemenuoptions[]
	{
		"Formatowanie tekstu konsolowego",
		"Rozmiar typow zmiennych",
		"Pre vs Post inkrementacja",
		"Kolory w konsoli",
		"Liczby losowe",
		"Praca z tekstem (klasa string)",
		"Obsluga plikow",
		"Wektory",
		"Klasy i obiekty",
		"ESC aby wrrocic do menu"//, "x aby zamknac program"
	};
	int zmienna_globalna = 0, cursorposition = 0, maxoptions=0;
	do
	{
		cls(hStdout);
		maxoptions = 4;
		if (cursorposition >= maxoptions) { cursor[maxoptions-1] = cursor[cursorposition]; cursor[cursorposition] = ' '; cursorposition = maxoptions-1; };
		std::cout << "\t\tNew Menu\n"
			<< "--------------------------------------------------\n"
			<< "[" << cursor[0] << "] Test Procedury\n"
			<< "[" << cursor[1] << "] Test linkera (+referencja[" << zmienna_globalna << "]\n"
			<< "[" << cursor[2] << "] Cwiczenia\n"
			<< "[" << cursor[3] << "] Wyzwania\n"
			<< "---------------------------------------------------\n"
			<< "ESC aby zamknac program";
		
		input = _getch();
		if (input == '0' || input == '0xE0') { input = _getch(); };		//arrow keys are precieded either by 0 or 0xE0 in input
		switch (input)
		{
			case 72: {if (cursorposition != 0)			//up arrow
		{
			cursor[cursorposition - 1] = cursor[cursorposition];
			cursor[cursorposition] = ' ';
			cursorposition -= 1;
		}; }; break;
			case 80: {if (cursorposition != maxoptions - 1)			//down arrow
		{
			cursor[cursorposition + 1] = cursor[cursorposition];
			cursor[cursorposition] = ' ';
			cursorposition += 1;
		}; }; break;
			case '\r':											//enter carriage return
				{
					switch (cursorposition)
						{
							case 0: procedura(); break;
							case 1: second(zmienna_globalna); break;
							case 2:
							{
								do
								{
									if (cursorposition >= maxoptions) { cursor[maxoptions - 1] = cursor[cursorposition]; cursor[cursorposition] = ' '; cursorposition = maxoptions - 1; };
									int number = sizeof(practicemenuoptions)/sizeof(*practicemenuoptions);
									switch (subinput=static_cast<char>(simplemenu(practicemenuoptions)))
										{
											case 0: formatowanie_tekstu_konsola(); break;
											case 1: rozmiar_typow_danych(); break;
											case 2: post_vs_preinkrementacja(); break;
											case 3: kolory_w_konsoli(); break;
											case 4: liczby_losowe(); break;
											case 5: praca_z_tekstem(); break;
											case 6: obsluga_plikow(); break;
											case 7: Wektory(); break;
											case 8: Test_klasy(); break;
											default:break;
										};
								} while (subinput != 'x' && 'X' && 27);
							}; break;//Submenu Cwiczenia
							case 3: 
							{
								do
								{
									cls(hStdout);
									maxoptions = 8;
									if (cursorposition >= maxoptions) { cursor[maxoptions - 1] = cursor[cursorposition]; cursor[cursorposition] = ' '; cursorposition = maxoptions - 1; };
									std::cout << "\t\tWyzwania\n"
										<< "--------------------------------------------------\n"
										<< "\t\tCoderbyte\n"
										<< "[" << cursor[0] << "] Silnia Rekurencyjnie\n"
										<< "[" << cursor[1] << "] --------placeholder--------\n"	//po dodaniu opcji w menu nalezy zwiekszyc maxoptions
										<< "[" << cursor[2] << "] --------placeholder--------\n"
										<< "[" << cursor[3] << "] --------placeholder--------\n"
										<< "\t\tInne\n"
										<< "[" << cursor[4] << "] Departamenty\n"
										<< "[" << cursor[5] << "] Bankomat\n"
										<< "[" << cursor[6] << "] Zgadywanie liczby losowej\n"
										<< "[" << cursor[7] << "] Wieze Hanoi\n"	
										//po dodaniu opcji w menu nalezy zwiekszyc maxoptions
										<< "---------------------------------------------------\n"
										<< "ESC aby powrocic do menu\n"
										<< "x aby zamknac program\n";
									
									subinput = _getch();
									if (subinput == '0' || subinput == '0xE0') { subinput = _getch(); };		//arrow keys are precieded either by 0 or 0xE0 in input
									switch (subinput)
									{
									case 72: {if (cursorposition != 0)			//up arrow
									{
										cursor[cursorposition - 1] = cursor[cursorposition];
										cursor[cursorposition] = ' ';
										cursorposition -= 1;
									}; }; break;
									case 80: {if (cursorposition != maxoptions - 1)			//down arrow
									{
										cursor[cursorposition + 1] = cursor[cursorposition];
										cursor[cursorposition] = ' ';
										cursorposition += 1;
									}; }; break;
									case '\r':											//enter - carriage return, wybor opcji
									{
										switch (cursorposition)
										{
										case 0: silnia_rekurencyjnie(); break;
										case 1: {std::cout << "\n\t\tComing Soon!\nWcisnij dowolny klawisz by powrocic do menu"; _getch(); }; break; //TODO
										case 2: {std::cout << "\n\t\tComing Soon!\nWcisnij dowolny klawisz by powrocic do menu"; _getch(); }; break; //TODO
										case 3: {std::cout << "\n\t\tComing Soon!\nWcisnij dowolny klawisz by powrocic do menu"; _getch(); }; break; //TODO
										case 4: Departamenty(); break;
										case 5: Bankomat(); break;
										case 6: Zgadywanie_liczby_losowej(); break;
										case 7: Wieze_Hanoi_Solver(); break; //todo
										default:break;
										};
									};
									default:break;
									};
								} while (subinput != 'x' && 'X' && 27);
							}; break;//Submenu wyzwania
							default:break;
						}
		
				}; break;
			default:break;
		};
	} while (input != 27 && (subinput!='x'&&'X'));
	cls(hStdout);
	std::cout << "\t\t   Do zobaczenia\t\t\n"
		<< "---------------------------------------------------\n"
		<< "\tPprogram edukacyjny na uzytek wlasny\n"
		<< "\t\tProjekt i wykonanie:\t\t\n"
		<< "\t\t   Nowak Marcin \t\t\n"
		<< "\t\t      2017\t\t\n"
		<< "---------------------------------------------------\n"
		<< "\tWcisnij dowolny klawisz by wyjsc\n"; _getch();
	return 0;
}

