// HotelSearch.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include "Hotel.h"
#include "Files.h"
#include "Klient.h"
using namespace std;

int main()
{
	string imie,nazwisko,data,wat;
	/*Hotel TheChosenOne;
	Hotel nr1{ "Hyatt", "Philadelphia",200 };
	Hotel nr2("WaterGates", "New York", 220);
	Hotel nr3{ "Four Seasons", "Paris", 100 };
	Hotel nr4("Hilton", "New York", 250);		//tworze instancje klasy Hotel
	vector<Hotel> AllHotels;//inicjalizuje vector typu Hotel
	AllHotels.push_back(nr3);
	AllHotels.push_back(nr1);
	AllHotels.push_back(nr2);
	AllHotels.push_back(nr4);
	map<string, vector<Hotel>> cities{
		{"New York", AllHotels},
		{"Paris", AllHotels},
		{"Philadelphia", AllHotels}
	};*/
/*	cout << "Wpisz swoje imie: " << endl;
	getline(cin, imie);
	cout << "Wpisz swoje nazwisko: " << endl;
	getline(cin, nazwisko);
	cout << "Wpisz date pobytu: " << endl;
	getline(cin, data);
	cout << "Wpisz miejsce pobytu: " << endl;
	getline(cin, wat);
	Klient klient(imie, nazwisko, data);//tworze klienta*/
	//saveHotelList(cities, "list.txt");
	//Hotel one=TheChosenOne.HotelFinder(AllHotels, wat);//wyszukuje dla niego hotel
	//PrintEnd(one, klient, "Out.txt");
	/* Multimap jest calkiem dobre, przerobie jeszcze funkcje do zapisywania na uzywanie multimap i powinno być git*/
	/*metoda equal_range zwraca pare iteratorow ktore sa potem uzyte w petli for. wszystko pomiedzy tymi iteratorami to dane pasujące do danego klucza*/
	auto list = loadHotelList("list.txt");//jak najedziesz na "auto" to ci pokaze jakiego typu to jest. 
	auto hotels = list.equal_range("Philadelphia"); //wiec wygodne ale chyba lepiej tego nienadużywać.
	for (auto i = hotels.first; i != hotels.second; ++i) {
		cout << i->first << "\t" << i->second.getName()  << "\t" << i->second.Cost(1) << endl;
	}
	saveHotelList(list, "test.txt");
}

