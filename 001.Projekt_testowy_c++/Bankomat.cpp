// ConsoleApplication1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//ATM machine - banknotes 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1$ gives specified amount of money in as few bills as possible

#include "stdafx.h"
#include "second.h"
#include <limits>

void withdrawal_IF(unsigned long int cash)
{
	unsigned short thousand, five_hundred, two_hundred, one_hundred, fifty, twenty, ten, five, two, one;
	thousand = five_hundred = two_hundred = one_hundred = fifty = twenty = ten = five = two = one = 0;
	while (cash > 0)
	{
		if (cash/1000 >= 1)
		{
			thousand += 1;
			cash = cash - 1000;
		}
		else if (cash/500 >= 1)
		{
			five_hundred += 1;
			cash = cash - 500;
		}
		else if (cash/200 >= 1)
		{
			two_hundred += 1;
			cash = cash - 200;
		}
		else if (cash/100 >= 1)
		{
			one_hundred += 1;
			cash = cash - 100;
		}
		else if (cash/50 >= 1)
		{
			fifty += 1;
			cash = cash - 50;
		}
		else if (cash/20 >= 1)
		{
			twenty += 1;
			cash = cash - 20;
		}
		else if (cash/10 >= 1)
		{
			ten += 1;
			cash = cash - 10;
		}
		else if (cash/5 >= 1)
		{
			five += 1;
			cash = cash - 5;
		}
		else if (cash/2 >= 1)
		{
			two += 1;
			cash = cash - 2;
		}
		else
		{
			one += 1;
			cash = cash - 1;
			//std::cout << cash << "\n"; _getch();
		};
	};
	std::cout << "\n\nHere is your money: " << thousand << "x1000$, " << five_hundred << "x500$, " << two_hundred << "x200$, " << one_hundred << "x100$, " << fifty << "x50$, " << twenty << "x20$, " << ten << "x10$, " << five << "x5$, " << two << "x2$, and " << one << "x1$" << std::endl;
	return;
};

/*void withdrawal_switche(unsigned long int money)
{
	unsigned short thousand, five_hundred, two_hundred, one_hundred, fifty, twenty, ten, five, two, one;
	thousand = five_hundred = two_hundred = one_hundred = fifty = twenty = ten = five = two = one = 0;
	
	while (money>0)
	{
		switch (money)
		{
		 case (money%1000>=1)
		default:
			break;
		}
	}
}*/


void Bankomat()
{
	
	unsigned long int money;
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::cout << "\t\t---ATM Machine.inc---\t\t\n"
		<< "----------------------------------------------\n"
		<< "How much would you like to withdraw:";
	do
	{
		std::cin.ignore(10000, '\n');
		std::cin.clear();// std::cin.sync();
		std::cin >> money; 
		std::cout << "(" << std::cin.good() << ")";
	} while (!std::cin.good());

	std::cout << money << "\n";
	withdrawal_IF(money);
	std::cout << "\n---------------------------------------------------------------------------\n"
		<< "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
	return;
}

