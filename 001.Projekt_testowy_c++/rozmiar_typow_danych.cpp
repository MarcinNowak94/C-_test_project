#include "stdafx.h"
#include "second.h"
#include <limits>


void rozmiar_typow_danych()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::cout	<< "\tRozmiar poszczegolnych typow danych:\n"
		<< "-----------------------------------------------------------------------------------------------\n"
		<< "sizeof(bool)\t\t\t"			<< sizeof(bool) << " bit "			<< "\tMin: 0  \t\t\tMax: 1\n" 
		<< "sizeof(char)\t\t\t"			<< sizeof(char) << " bit "			<< "\tMin: " << MINCHAR	  << " \t\t\tMax:"  << MAXCHAR << '\n'
		<< "sizeof(unsigned char)\t\t"	<< sizeof(unsigned char) << " bit"	<< "\tMin: 0 \t\t\t\tMax:"					<< UCHAR_MAX << '\n'
		<< "sizeof(wchar_t)\t\t\t"		<< sizeof(wchar_t) << " bit "		<< "\tMin: " << WCHAR_MIN << " \t\t\t\tMax:"<< WCHAR_MAX << '\n'
		<< "sizeof(short)\t\t\t"		<< sizeof(short) << " bit "			<< "\tMin: " << SHRT_MIN  << " \t\t\tMax:"  << SHRT_MAX << '\n'
		<< "sizeof(unsigned short)\t\t" << sizeof(unsigned short)			<< " bit " << "\tMin: 0 " << " \t\t\tMax:"  << USHRT_MAX << '\n'
		<< "sizeof(int)\t\t\t"			<< sizeof(int) << " bit "			<< "\tMin: " << INT_MIN   << "\t\tMax:"     << INT_MAX << '\n'
		<< "sizeof(unsigned int)\t\t"	<< sizeof(unsigned int) << " bit "	<< "\tMin: 0 \t\t\t\tMax:"					<< UINT_MAX << '\n'
		<< "sizeof(long)\t\t\t"			<< sizeof(long) << " bit "			<< "\tMin: " << LONG_MIN  << " \t\tMax:"	<< LONG_MAX << '\n'
		<< "sizeof(unsigned long)\t\t"	<< sizeof(unsigned long) << " bit " << "\tMin: 0 \t\t\t\tMax:"					<< ULONG_MAX << '\n'
		<< "sizeof(long long)\t\t"		<< sizeof(long long) << " bit "		<< "\tMin: " << LLONG_MIN << " \tMax:"		<< LLONG_MAX << '\n'
		<<"sizeof(unsigned long long)\t"<< sizeof(unsigned long long)	<< " bit " << "\tMin: 0  \t\t\tMax:"			<< ULLONG_MAX << '\n'
		<< "sizeof(float)\t\t\t"		<< sizeof(float) << " bit " << '\n'
		<< "sizeof(double)\t\t\t"		<< sizeof(double) << " bit " << '\n'
		<< "sizeof(long double)\t\t"	<< sizeof(long double) << " bit " << '\n'
		<< "-----------------------------------------------------------------------------------------------\n"
		<< "Tablica = rozmiar typu danych * ilosc elementow np.: int tab[100]= 100*"<< sizeof(int) <<" = "<< 100*sizeof(int) << "b = " <<(100 * sizeof(int))/8 <<"B\n"
		<< "Wcisnij dowolny klawisz by powrocic\n"; _getch();
	return;
}