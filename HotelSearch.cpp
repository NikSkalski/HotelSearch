// HotelSearch.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "Hotel.h"
#include <vector>

int main()
{
	string wat;
	Hotel* nr0 = new Hotel("", "", 0);
	Hotel* nr1 = new Hotel("California", "Los Angeles", 120);
	Hotel* nr2 = new Hotel("WaterGates", "New York", 220);
	Hotel* nr3 = new Hotel("Mariott", "Warszawa", 250);
	Hotel* nr4 = new Hotel("Hilton", "New York", 250);		//tworze instancje klasy Hotel
	vector<Hotel> ListOfHotels;								//inicjalizuje vector typu Hotel
	cout << "Prosze wpisac miasto" << endl;
	getline(cin, wat, '\n');
	ListOfHotels.push_back(*nr1);							//przekazuje referencje do obiektów do vectora
	ListOfHotels.push_back(*nr2);
	ListOfHotels.push_back(*nr3);
	ListOfHotels.push_back(*nr4);

	nr0->HotelFinder(ListOfHotels,wat);		//wywołuje wyszukiwarke (Warszawe znajduje jednak jesli wchodzi miasto ze spacja to nie znajduje)
	cout << "Znaleziono" << endl;
	cin >> wat ;//zeby sie frajer nie zamykał
}

