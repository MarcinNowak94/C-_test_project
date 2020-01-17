/*
Using the C++ language, have the function FirstFactorial(num) take the num parameter being passed and return the factorial of it (e.g. if num = 4, return (4 * 3 * 2 * 1)). 
For the test cases, the range will be between 1 and 18 and the input will always be an integer.
*/

#include "stdafx.h"


int FirstFactorial(int num)
{
	//std::cout << "\n" << "NUM = " << num;
	if (num == 0) return 1;
	else return (FirstFactorial(num-1)*num);
}

void silnia_rekurencyjnie()
{
	system("cls");
	std::cout << "Podaj liczbe\n";
	int  num;
	std::cin >> (num);
	std::cout << FirstFactorial(num);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
	return;
}