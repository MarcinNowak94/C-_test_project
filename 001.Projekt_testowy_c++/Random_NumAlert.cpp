// Random_NumAlert.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

/* Program generuje podan¹ iloœæ liczb losowych z podanego zakresu i zapisuje je do pliku, dodatkowo testuje dzia³anie \a (alarmu systemu) */

#include "stdafx.h"
#include "second.h"

int Generator(unsigned long long, long long, long long);

int Generator(unsigned long long Amount_of_nums, long long Min, long long Max)
{
	std::cout << Amount_of_nums << " " << Max << " " << Min << "\n";
	std::random_device rd;	//random number
	std::mt19937 Random(rd()); //using random number as seed for generator
	std::uniform_int_distribution<long long int> Range(Min, Max); //defining range of random numbers
	
	std::ofstream File;
	File.open("../Pliki/Generated_Numbers.txt");

	long long Display=0;
	
	for (unsigned long long i = 0; i <= Amount_of_nums; ++i)
	{
		Display = Range(Random);
		std::cout << Display << " ";
		File << Display << " ";
		while (i % 50 == 0) File << "\n";
	};
	File.close();
	std::cout << "\a\nDone!";
	return 0;
};

int Random_NumAlert()
{
	unsigned long long Amount_of_numbers=0;
	long long  Minimal = 0, Maximal = 0;
	std::cout << "\nThis program generates random numbers of specified range.\n"
	<< "How many numbers do you want to generate?:";
		do
		{
			std::cin.clear(); std::cin.sync();
			std::cin >> Amount_of_numbers;
		} while (std::cin.fail());
	std::cout << "Minimal: ";
	do
	{
		std::cin.clear(); std::cin.sync();
		std::cin >> Minimal;
	} while (std::cin.fail());
	std::cout << "Maximal: ";
	do
	{
		std::cin.clear(); std::cin.sync();
		std::cin >> Maximal;
	} while (std::cin.fail());
	std::cout << "\n---------------------------------------------------------------\n";
	Generator(Amount_of_numbers, Minimal, Maximal);
	std::cout << "\n---------------------------------------------------------------\n"
		<< "Press any key to continue...\n";
	_getch();
    return 0;
}

