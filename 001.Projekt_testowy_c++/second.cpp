#include "stdafx.h"
#include "second.h"

int second(int & a)
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::cout << "Jestesmy w osobnym pliku zrodlowym\n"
		<< "Operacja powiodla sie poniewaz utworzono plik second.h\n"
		<< "ktory zawiera definicje funkcji second (w ktorej jestesmy)\n"
		<< "znajdujacej sie w pliku second.cpp ktory wlasnie zostal wykonany.\n"
		<< "--------------------------------------------------------------------------\n"
		<< "Przy okazji wykonano referencje - do funkcji second przekazano zmienna: " << a << "\n"
		<< "ktora zadeklarowana zostala w bloku glownym i to tam ja zmieniamy.\n"
		<< "Zmienna a zostala wyswietlona przed  wybraniem opcji w menu\n"
		<< "Powiedzmy ze do " << a << " chcemy dodac 7, teraz a wynosi: "; a = a + 7; std::cout << a << "\n"
		<< "Po powrocie z procedury a zostanie ponownie wyswietlona w ramce.\n";
	std::cout << "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
	return 0;
};