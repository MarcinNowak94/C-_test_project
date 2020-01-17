// Cpp0x_lekcja_15(p2)_kalkulator.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//
/*
Napisz prosty kalkulator, który bêdzie potrafi³ dodawaæ, odejmowaæ, mno¿yæ i dzieliæ. Program ten ma dzia³aæ nastêpuj¹co:
1. Wypisuje obecny wynik
2. WprowadŸ liczbê
3. Wybierz dzia³anie (je¿eli liczba ró¿na od 0)
4. Wykonaj obliczenia (je¿eli liczba ró¿na od 0)
5. Wróæ do kroku 1.
6. Je¿eli wprowadzon¹ liczb¹ jest 0, zakoñcz program.
*/


#include "stdafx.h"


int main()
{
	int a, b, c;
	bool pom=false;
	a = b = c = 0;
		do
		{
			 system("cls");
			 std::cout << "Ponizszy program to kalkulator\n"
			 << "Jezeli chcesz zakonczyc obliczenia wcisnij [0]\n"
			<< "--------------------------------------\n";
			//do
			//{
				std::cout << "Podaj liczbe 1: ";
				//pom = false;
				//std::cin.clear();
				std::cin >> a;
				//pom = std::cin.fail();
				//std::cout << a << " "<< pom;
				//_getch();
			//} while (pom == true);			
				std::cout << "\nPodaj liczbe 2: ";
				std::cin >> b;
			std::cout << "\nCo chcesz z nia zrobic?\n"
				<< "-----------------\n"
				<< "[1].Dodawanie\n"
				<< "[2].Odejmowanie\n"
				<< "[3].Mnozenie\n"
				<< "[4].Dzielenie\n"
				<< "[5].Rezygnuj\n"
				<< "-----------------\n";
			std::cin >> c;
			switch (c)
				{
			case 1: {std::cout << a << " + " << b << " = " << a + b; _getch(); }; break;
			case 2: {std::cout << a << " - " << b << " = " << a - b; _getch(); }; break;
			case 3: {std::cout << a << " * " << b << " = " << a * b; _getch(); }; break;
			case 4: {std::cout << a << " / " << b << " = " << a / b; _getch(); }; break;
			case 5: {a = b = b = 0; }; break;
			default: break;
				}
					
		} while (a!=0);
		std::cout << "\n Dziekujemy za skorzystanie. Milego dnia :)\n";
		_getch();
    return 0;
}

