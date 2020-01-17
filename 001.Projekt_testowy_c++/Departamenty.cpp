/*
Department numbers:
-Fire
-Police
-Sanitation

Each assigned number in the range 1-7
Fire #, Police #, sanitation # all different
fire # + police # + Sanitation # =12
Police # must be even

Write a program to display all valid Department number permutations.
*/

#include "stdafx.h"
#include "second.h"

void Departamenty()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	unsigned short possibilities=0;
	std::cout << "Kazda mozliwa kombinacja numerow departamentow zgodna z podanymi wymogami:";
	for (unsigned short fire_dept = 1; fire_dept <= 7; fire_dept++)
	{
		//std::cout << "\nStraz: " << fire_dept;
		for (unsigned short sanitation_dept = 1; sanitation_dept <= 7; sanitation_dept++)
		{
			//std::cout << "\nOczyszczalnia: " << sanitation_dept;
			for (unsigned short police_dept = 2; police_dept < 7; police_dept=police_dept+2)
			{
				//std::cout << "\nPolicja: " << police_dept;
				if (fire_dept+sanitation_dept+police_dept==12)
				{
					std::cout << "\nNumer Strazy " << fire_dept << ", numer oczyszczalni " << sanitation_dept << ", numer policji " << police_dept;
					possibilities++;
				}
			};
		};
	};
	std::cout << "\n Jest " << possibilities << " mozliwych kombinacji.";
	std::cout << "\n---------------------------------------------------------------------------\n"
	<< "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
	return;
};