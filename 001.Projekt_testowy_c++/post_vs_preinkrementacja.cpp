#include "stdafx.h"
#include "second.h"

void post_vs_preinkrementacja()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::cout << "W tym programie sprawdzimy dzia³anie pre i post inkrementacji\n"
		<< "W dwóch identcznych pêtlach przesledzimy modyfikacje zmiennej\n";
		unsigned short i=0;
	while (i<10)
	{
		if (i == 0) std::cout << "\nPre inkrementacja :";
		std::cout << "\nPrzed: " << i << "Po:";
		++i;
		std::cout << " " << i << "\;";
	}
	i = 0;
	while (i<10)
	{
		if (i == 0) std::cout << "\nPost inkrementacja :";
		std::cout << "\nPrzed: " << i << "Po:";
		i++;
		std::cout << " " << i << "\;";
	}
	std::cout << "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
	return;
}