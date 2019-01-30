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

	string imie,nazwisko,data,city;
	Hotel TheChosenOne;
	cout << "Wpisz swoje imie: " << endl;
	getline(cin, imie);
	cout << "Wpisz swoje nazwisko: " << endl;
	getline(cin, nazwisko);
	cout << "Wpisz date pobytu: " << endl;
	getline(cin, data);
	cout << "Wpisz miejsce pobytu: " << endl;
	getline(cin, city);
	
	auto list = loadHotelList("list.txt"); 
	Klient klient(imie, nazwisko, data);//tworze klienta
	//saveHotelList(cities, "list.txt");
	Hotel one=HotelFinder(list, city);//wyszukuje dla niego hotel
	if (one.getName() != "") {
		saveBooking(one, klient, city, "Out.txt");
	}
	
}

