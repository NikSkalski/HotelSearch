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
	/* Multimap jest calkiem dobre, przerobie jeszcze funkcje do zapisywania na uzywanie multimap i powinno być git*/
	/*metoda equal_range zwraca pare iteratorow ktore sa potem uzyte w petli for. 
	/*wszystko pomiedzy tymi iteratorami to dane pasujące do danego klucza*/
	auto list = loadHotelList("list.txt");//jak najedziesz na "auto" to ci pokaze jakiego typu to jest. 
	//auto hotels = list.equal_range("Philadelphia"); //wiec wygodne ale chyba lepiej tego nienadużywać.
	Klient klient(imie, nazwisko, data);//tworze klienta
	//saveHotelList(cities, "list.txt");
	Hotel one=HotelFinder(list, city);//wyszukuje dla niego hotel
	saveBooking(one, klient, city, "Out.txt");

	
}

