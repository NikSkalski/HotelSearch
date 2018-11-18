#pragma once
#include "Klient.h";
using namespace std;
class Hotel
{
public:
	Hotel(string HotelName, string City, unsigned int price) {
		this->HotelName = HotelName;
		this->City = City;
		this->price = price;
	}
	~Hotel() {};
	Hotel() {};
	vector <Hotel> MatchedHotels;
	int k;

	int Cost(int days) {
		return days * price;
	}
	string getName() {
		return HotelName;
	}
	string GetCity() {
		return City;
	}
	void ToString() {
		cout << "Name: " << HotelName << " City: " << City << endl;
	}
	Hotel HotelFinder(vector <Hotel> ListOfHotels, string Place) {
		for (int i = 0; i < ListOfHotels.size(); i++) { //iteruje po wszystkich obiektach w vektorze
			if ((!ListOfHotels[i].GetCity().compare(Place))) {  //porównuje misto z wpisanym miastem
				ListOfHotels[i].ToString();		//wywo³uje funkcje wypisuj¹c¹
				MatchedHotels.push_back(ListOfHotels[i]);
			}
		}
		cout << "Wpisz numer hotelu,ktory wybrales" << endl;
		cin >> k;
		return MatchedHotels[k - 1];
	}
	

private:
	string HotelName, City; //City nie usunalem ale bedzie zbêdne w sumie
	unsigned int price;

};




