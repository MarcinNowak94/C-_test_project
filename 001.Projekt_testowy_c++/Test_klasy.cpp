// Test_klasy.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
// 

/*
Test tworzenia i zasad dzia³ania klas C++
https://www.youtube.com/watch?v=Rub-JsjMhWY
*/

#include "stdafx.h"

class Zwierze																		//Klasa 'Zwierze' 
{
private:																			//prywatne - moga byc wykorzystwane tylko przez obiekt nalezacy do klasy 'Zwierze'
	unsigned short Wysokosc;														//Atrybuty klasy - zmienne opisujace obiekty klasy 'Zwierze'
	unsigned short Waga;															//
	std::string Nazwa;																//
	static unsigned short Ilosc;													//static - atrybut wspoldzielony przez kazdy obiekt klasy 'Zwierze' i jego podklas

public:
	void NadajWysokosc(unsigned short cm) { Wysokosc = cm; };						//Metody do zapisywania danych o obiekcie
	void NadajWaga(unsigned short kg) { Waga = kg; };								//
	void NadajNazwa(std::string Imie) { Nazwa = Imie; };							//

public:
	unsigned short PodajWysokosc() { return Wysokosc; };							//Metody do uzyskiwania danych o obiekcie
	unsigned short PodajWage() { return Waga; };									//
	std::string PodajNazwe() { return Nazwa; };										//
	

	Zwierze(unsigned short, unsigned short, std::string);							//Konstruktor, Prototyp - TYLKO deklaracja funkcji(nazwa i typy danych jakie przyjmuje), definicja znajdzie sie ponizej zawarta w {}
	~Zwierze() { std::cout << "\nZwierze " << this->Nazwa << " unicestwiono.";  Zwierze::Ilosc=Zwierze::Ilosc-1 ; };	//Destruktor
	Zwierze() { std::cout << "\nUtworzono zwierze za pomoca przeladowanej metody."; Ilosc++;};	//Konstruktor przeladowany(overload) - funkcja o identycznej nazwie co istniejaca, ale przyjmujaca inne wartosci
	static unsigned short PodajIloscZwierzat() { return Ilosc; };					//Statyczna metoda - tylko taka metoda moze uzyskac dostep do statycznych atrybutow obiektu klasy 'Zwierze'
	void Wyswietl()																	//Metoda wyswietlajaca zwierze o podanej nazwie
	{
		std::cout << this->Nazwa << " jest wyoki na " << this->Wysokosc << "cm, wazy: " << this->Waga << " kg";
	};
};

Zwierze::Zwierze(unsigned short wys, unsigned short wag, std::string PodanaNazwa)	//Klasa::Metoda (w tym wypadku Konstruktor) - definicja
{																					//
	this->Wysokosc = wys;															//
	this->Waga = wag;																//
	this->Nazwa = PodanaNazwa;														//
	Zwierze::Ilosc++;																//
};																					//

class Pies : public Zwierze																						//Podklasa Pies 
{
public: std::string glos = "Hau!";																				//Atrybut podklasy Pies

		void DajGlos() { std::cout << glos << "\n"; };
		Pies(unsigned short Wysokosc, unsigned short Waga, std::string Nazwa, std::string Glos) :				//Konstruktor podklasy - podklasa(wszystkie, przyjmowane, wartosci) : superklasa(przyjmowane, wartosci) {wszystkie = przypisanie}
			Zwierze(Wysokosc, Waga, Nazwa) {this->glos = Glos;};												//									
		void Wyswietl() 
		{
			std::cout << this->PodajNazwe();
			std::cout << " ma " << this->PodajWysokosc();
			std::cout << "cm i wazy " << this->PodajWage() << ". Daj glos!:";
			this->DajGlos();
		};				//Metoda odwoluje sie do wartosci podklasy przechowywane przez superklase + metody wyswietlajacej atrybuty podklasy
};																												




unsigned short Zwierze::Ilosc = 0;

int Test_klasy()
{
	unsigned short Rozmiar = 0, Ciezar = 0;
	std::string Nazwa;
	//std::cout << "Utworz obiekt klasy Zwierze podajac: "
	//<< "\nNazwe: ";
	//std::cin >> Nazwa;
	//std::cout << "\nRozmiar w cm: ";
	//std::cin >> Rozmiar;
	//std::cout << "\nCiezar w kg: ";
	//std::cin >> Ciezar;
	Zwierze Fred(18, 2, "Fred");																					//Kreator nowego obiektu klasy Zwierze
	std::cout << "Utworzono zwierze Nr." << Zwierze::PodajIloscZwierzat() << ", 'Fred' o wlasciwosciach:\n"
		<< "Nazwa: " << Fred.PodajNazwe() << "\n"
		<< "Rozmiar: " << Fred.PodajWysokosc() << "cm\n"
		<< "Ciezar: " << Fred.PodajWage() << "kg\n";

	Zwierze Janusz;																										//Uzycie operatora przeciazonego
	Janusz.NadajNazwa("Janusz");																							//Nadanie wartosci polu Obiekt.Nazwa
	Janusz.NadajWysokosc(170);																								//Nadanie wartosci polu Obiekt.Wysokosc
	Janusz.NadajWaga(80);																									//Nadanie wartosci polu Obiekt.Ciezar

	std::cout << "\nUtworzono zwierze Nr." << Zwierze::PodajIloscZwierzat() << ", 'Janusz' o wlasciwosciach:\n";
	Janusz.Wyswietl();
		/*<< "Nazwa: " << Janusz.PodajNazwe() << "\n"
		<< "Rozmiar: " << Janusz.PodajWysokosc() << "cm\n"
		<< "Ciezar: " << Janusz.PodajWage() << "kg\n";*/

	std::cout << "\nObecna ilosc zwierzat: " << Zwierze::PodajIloscZwierzat() << "\n";
	Janusz.~Zwierze();
	std::cout << "\nObecna ilosc zwierzat: " << Zwierze::PodajIloscZwierzat() << "\n";
	Fred.~Zwierze();
	std::cout << "\nObecna ilosc zwierzat: " << Zwierze::PodajIloscZwierzat() << "\n";
	Pies Czaki(15,6,"Czaki", "Hau");																		
	std::cout << "\nUtworzono obiekt 'Czaki' klasy Zwierze, podklasy Pies o podanych atrybutach:\n";
	Czaki.Wyswietl();
	std::cout << "\nObecna ilosc zwierzat: " << Zwierze::PodajIloscZwierzat() << "\n";
	Czaki.Zwierze::~Zwierze();																							//Wywolanie metody superklasy przez podklase - obiekt.superklasa::metoda
	std::cout << "\n---------------------------------------------------------------------------\n"
		<< "Wcisnij dowolny klawisz by powrocic\n";
	_getch();
    return 0;
}

