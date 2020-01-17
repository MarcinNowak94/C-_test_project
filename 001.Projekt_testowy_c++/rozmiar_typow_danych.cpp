#include "stdafx.h"
#include "second.h"
#include <limits>


void rozmiar_typow_danych()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::cout << "\tRozmiar poszczegolnych typow danych:\n";
	std::cout << "-----------------------------------------------------------------------------------------------\n";
	std::cout << "sizeof(bool)\t\t\t" << sizeof(bool) << " bit " << "\tMin: 0  \t\t\tMax: 1" << std::endl;
	std::cout << "sizeof(char)\t\t\t" << sizeof(char) << " bit " << "\tMin: " << MINCHAR <<  " \t\t\tMax:" << MAXCHAR << std::endl;
	std::cout << "sizeof(unsigned char)\t\t" << sizeof(unsigned char) << " bit" << "\tMin: 0 " <<  " \t\t\tMax:" << UCHAR_MAX << std::endl;
	std::cout << "sizeof(wchar_t)\t\t\t" << sizeof(wchar_t) << " bit " << "\tMin: " << WCHAR_MIN <<  " \t\t\t\tMax:" << WCHAR_MAX << std::endl;
	std::cout << "sizeof(short)\t\t\t" << sizeof(short) << " bit " << "\tMin: " << SHRT_MIN <<  " \t\t\tMax:" << SHRT_MAX << std::endl;
	std::cout << "sizeof(unsigned short)\t\t" << sizeof(unsigned short) << " bit " << "\tMin: 0 "  << " \t\t\tMax:" << USHRT_MAX << std::endl;
	std::cout << "sizeof(int)\t\t\t" << sizeof(int) << " bit " << "\tMin: " << INT_MIN <<  "\t\tMax:" << INT_MAX << std::endl;
	std::cout << "sizeof(unsigned int)\t\t" << sizeof(unsigned int) << " bit " << "\tMin: 0"  << " \t\t\t\tMax:" << UINT_MAX << std::endl;
	std::cout << "sizeof(long)\t\t\t" << sizeof(long) << " bit " << "\tMin: " << LONG_MIN << " \t\tMax:" << LONG_MAX << std::endl;
	std::cout << "sizeof(unsigned long)\t\t" << sizeof(unsigned long) << " bit " << "\tMin: 0 " << " \t\t\tMax:" << ULONG_MAX << std::endl;
	std::cout << "sizeof(long long)\t\t" << sizeof(long long) << " bit " << "\tMin: " << LLONG_MIN << " \tMax:" << LLONG_MAX << std::endl;
	std::cout << "sizeof(float)\t\t\t" << sizeof(float) << " bit " << std::endl;
	std::cout << "sizeof(double)\t\t\t" << sizeof(double) << " bit " << std::endl;
	std::cout << "sizeof(long double)\t\t" << sizeof(long double) << " bit " << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------\n";
	std::cout << "Tablica = rozmiar typu danych * ilosc elementow np.: int tab[100]= 100*"<< sizeof(int) <<" = "<< 100*sizeof(int) << "b = " <<(100 * sizeof(int))/8 <<"B\n";
	std::cout << "Wcisnij dowolny klawisz by powrocic\n"; _getch();
	return;
}