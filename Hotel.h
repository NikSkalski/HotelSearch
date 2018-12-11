#pragma once
#include "Klient.h"
#include <iostream>
#include <map>
using namespace std;
class Hotel
{
public:
	Hotel(string HotelName,  unsigned int price) {
		this->HotelName = HotelName;
		this->price = price;
	}
	~Hotel() {};
	Hotel() {};

	int Cost(int days) {
		return days * price;
	}
	string getName() {
		return HotelName;
	}
	void ToString() {
		cout << "Name: " << HotelName << endl;
	}
	
	

private:
	string HotelName;
	unsigned int price;

};

Hotel HotelFinder(multimap<string, Hotel>& ListOfHotels, string Place);


