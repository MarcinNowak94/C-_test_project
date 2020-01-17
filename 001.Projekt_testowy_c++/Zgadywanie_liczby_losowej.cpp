#include "stdafx.h"
#include "second.h"
#include <climits>

void Uzytkownik(unsigned int min, unsigned int max)
{
	std::random_device random;
	std::mt19937 mersennetwister(random());
	std::uniform_int_distribution<unsigned int> finaldistribution(min, max);
	unsigned int unWylosowana_liczba = finaldistribution(mersennetwister);
	std::cout << "\nProgram wylosowal liczbe w przedziale <" << min << ", " << max << ">, sprobuj ja zgadnac:\n";
	int niloscprob = 0;
	unsigned int unpodanaliczba = 0;
	do
	{
		if (unpodanaliczba != 0)
		{
			if (unpodanaliczba>unWylosowana_liczba)
			{
				std::cout << "\tMniej\n";
			}
			else { std::cout << "\tWiecej\n"; };
		};
		do
		{
			if (std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); };
			std::cout << "Podaj liczbe: ";
			std::cin >> unpodanaliczba;
		} while (std::cin.fail());
		niloscprob++;
	} while (unpodanaliczba != unWylosowana_liczba);

	std::cout << "Zgadles! Wylosowana liczba to " << unWylosowana_liczba << " zagdles po " << niloscprob << " probach.\n";
	_getch();
	return;
};

void Program(unsigned int min, unsigned int max)
{
	unsigned int podanaliczba=0, iloscprob=0;
	do
	{
		if (std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); };
		std::cout << "\nPodaj liczbe z zakresu <" << min << ", " << max << "> : ";
		std::cin >> podanaliczba;
	} while (std::cin.fail());
	unsigned int proba;
	do
	{
		proba = ((unsigned int)min+((max - min) / 2));
		iloscprob++;
		podanaliczba < proba ? max = proba : min = proba;
		std::cout << "\nProba " << iloscprob << ": " << proba;
	} while (proba!=podanaliczba);
	_getch();
	return;
};


void Zgadywanie_liczby_losowej()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<unsigned int> distribution(0, UINT16_MAX);
	unsigned int unMinimal=0, unMaximal=0;
	do
	{
		unMinimal = distribution(mt);
		unMaximal = distribution(mt);
	} while (!(unMinimal<unMaximal));
	bool exit = false;
	do
	{
		cls(hStdout);
		std::cout << "Pprzedzial ktory wylosowano: <" << unMinimal << ", " << unMaximal << ">\n"
			<< "-------------------------------------------------------------------------\n"
			<< "1.Program losuje liczbe, uzytkownik ja zgaduje\n"
			<< "2.Uzytkownik podaje liczbe, program ja zgaduje\n"
			<< "3.Losuj nowy przedzial\n"
			<< "\n---------------------------------------------------------------------------\n"
			<< "Wcisnij klawisz X by powrocic do menu\n";
		switch (_getch())
		{
		case '1':Uzytkownik(unMinimal, unMaximal); break;
		case '2':Program(unMinimal, unMaximal); break;
		case '3':
			{
				do
				{
					unMinimal = distribution(mt);
					unMaximal = distribution(mt);
				} while (!(unMinimal<unMaximal));
			}; break;
		case ('x'): exit = true; break;
		default: break;
		};
		
	} while (exit==false);
	return;
};