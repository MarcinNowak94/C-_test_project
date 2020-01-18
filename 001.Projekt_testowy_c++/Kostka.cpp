#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "Silnia_rekurencyjnie.h"


using namespace std;

void zasady()
{
    cout << "Program ma za zadanie obliczyc prawdopodobienstwo wygrania w gre o nastepujacych zasadach:" << endl;
    cout << "1.Wybierz 1 liczbe z szesciennej kostki, startujesz z okreslona przez ciebie iloscia punktow." << endl;
    cout << "2.Rzucasz 2 koscmi jednoczesnie okreslona przez ciebie ilosc razy:" << endl;
    cout << "   Jesli twoja liczba nie wypadnie tracisz 1 punkt." << endl;
    cout << "   Jesli twoja liczba wypadnie zdobywasz 2 punkty." << endl;
    cout << "   Jesli twoja liczba wypadnie 2 razy zdobywasz 5 punktow." << endl;
    cout << "---------------------------------------------------------------------" << endl;
}

int kostka()
{
	int x, y, z, a, b, liczba, punkty, pozostale_rzuty = {};
    zasady();
    srand(time(NULL));
    cout << "Wybierz liczbe:" << endl;
    cin >> x;
    while (x>6 )
        {
         if (x>=6) cout << "Wybierz liczbe od 1 do 6." << endl;
         cin >> x;
        };
    cout << "Poczatkowa ilosc punktow:" << endl;
    cin >> y;
    cout << "Ile rzutow przeprowadzic?" << endl;
    cin >> z;
    system("cls");
    pozostale_rzuty=z;
        punkty=y;
    cout << x << ", " << punkty << ", " << z << "." << endl;
    for ( z=z ; z<=0 ; z-- )
    {
        a==((rand()%6)+1);  //pierwszy rzut kostki
        b==((rand()%6)+1);  //drugi rzut kostki
        cout << a << " oraz " << b;
        if (a == x && b == x) punkty=punkty+5; else
        if (a == x || b == x) punkty=punkty+2; else
            punkty=punkty-1;
    cout << "kosc1= " << a << ", kosc2= " << b << ", pkt= " << punkty << " pozostalo " << z << " rzutow." << endl;
    };
    cout << "Wyniki:" << endl;
    cout << "Po " << z << " losowan ilosc punktow wynosi " << punkty << "." << endl;
    if (punkty <= y) cout << "Nie bedzie z ciebie dobry hazardzista :C " << endl; else cout << "Udalo sie, masz wiecej punktow niz wczesniej. Gratulacje!" << endl;
    system("pause");
	return EXIT_SUCCESS;
};
