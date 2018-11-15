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
using namespace std;

int main()
{
	string wat;
	
	Hotel nr1{ "Hyatt", "Philadelphia",200 };
	Hotel nr2("WaterGates", "New York", 220);
	Hotel nr3{ "Four Seasons", "Paris", 100 };
	Hotel nr4("Hilton", "New York", 250);		//tworze instancje klasy Hotel
	vector<Hotel> Murica;//inicjalizuje vector typu Hotel
	vector<Hotel> France;
	vector<Hotel> murica2;
	France.push_back(nr3);
	murica2.push_back(nr1);
	Murica.push_back(nr2);
	Murica.push_back(nr4);
	map<string, vector<Hotel>> cities{
		{"New York", Murica},
		{"Paris", France},
		{"Philadelphia", murica2}
	};
	saveHotelList(cities, "list.txt");
	
	
}

