// Towers_of_Hanoi.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "second.h"


//TODO: Fix 

void Wieze_Hanoi_Solver()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::cout << "How many elements do you want to shift ?:";
	int nnumberofelements = 0;
	std::cin >> nnumberofelements;
	std::vector<int> vtower1{0}, vtower2{ 0 }, vtower3{ 0 };
	for (int i = 1, hlp=nnumberofelements ; i <= nnumberofelements; i++, hlp--)
	{
		vtower1.push_back(hlp);
	};
	unsigned int nmoves = 0;
	while (!(vtower3.at(1) == nnumberofelements))
	{
		if (vtower1.back() > vtower2.back()) 
		{vtower1.push_back(vtower2.back()); vtower2.pop_back();}
		else if (vtower1.back() > vtower3.back())
		{vtower1.push_back(vtower3.back()); vtower3.pop_back();}
		else if (vtower2.back() > vtower3.back())
		{vtower2.push_back(vtower3.back()); vtower3.pop_back();}
		else { vtower3.push_back(vtower2.back()); vtower2.pop_back(); };
		nmoves++;
	};
	std::cout << "Done in " << nmoves << " moves." << std::endl;
	std::cout << "---------------------------------------------------\n"
				<< "\tWcisnij dowolny klawisz by wyjsc" << std::endl;
	_getch();
    return;
}

