// Cpp0x_lekcja_15(p2)_kalkulator.cpp: Okre�la punkt wej�cia dla aplikacji konsoli.
//
/*
Napisz prosty kalkulator, kt�ry b�dzie potrafi� dodawa�, odejmowa�, mno�y� i dzieli�. Program ten ma dzia�a� nast�puj�co:
1. Wypisuje obecny wynik
2. Wprowad� liczb�
3. Wybierz dzia�anie (je�eli liczba r�na od 0)
4. Wykonaj obliczenia (je�eli liczba r�na od 0)
5. Wr�� do kroku 1.
6. Je�eli wprowadzon� liczb� jest 0, zako�cz program.
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

