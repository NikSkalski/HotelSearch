#include "Files.h"
#include "pch.h"
#include <assert.h>
#include <map>
#include <string>
#include <vector>
#include "Hotel.h"
#include <iostream>
#include <fstream>
using namespace std;

void saveHotelList(map<string, vector<Hotel>>& list, string name) {

	ofstream stream;
	stream.open(name, ios::out | ios::trunc); //otwiera plik w trybie do pisania, jak cos w nim wczesniej bylo to usuwa
	assert(stream.is_open()); //wywo³uje abort() jak stream.is_open jest false i wyjebuje program
	for (map<string, vector<Hotel>>::iterator it = list.begin(); it != list.end(); ++it) { //nie wiem jak ten iterator dzia³a, znalazlem na Stack Overflow xD
		stream << it->first << ":\n";
		for (int i = 0; i < it->second.size(); ++i) { //samo wpisywanie do pliku dziala jak pisanie do np. cout wiec luzik
			stream << "\t" << it->second[i].getName() << "\t" << it->second[i].Cost(1) << "\n";
		}
		stream << "END " << it->first << "\n";
	}
	stream.close();
};

multimap<string, Hotel> loadHotelList(string name) {
	ifstream stream;
	stream.open(name);
	if (!stream.is_open()) {
		cerr << "COuld not open file" << endl;
		exit(1);
	}
	string line, hotelName, price, key;
	multimap<string, Hotel> list;
	while (!stream.eof()) {
		getline(stream, line);
		if (line.find(':') != std::string::npos) {
			line.pop_back();
			key = line;
			continue;
		}
		if (line.find("END") != std::string::npos) continue;
		if (line == "") break;
		unsigned int pos1 = line.find_first_of("\t");
		unsigned int pos2 = line.find_last_of("\t");
		hotelName = line.substr(pos1 + 1, pos2 - pos1 - 1);
		price = line.substr(pos2 + 1, line.length() - pos2 - 1);
		list.emplace(key,Hotel::Hotel(hotelName, stoi(price)));

	}
	stream.close();
	return list;
}


void PrintEnd(Hotel& TheOne, Klient &klient, std::string name) {
	ofstream stream;
	stream.open(name, ios::out | ios::trunc);
	assert(stream.is_open());
	stream << "\t" << TheOne.getName() << "\t" << TheOne.GetCity() << "\t" << klient.GetName() << "  " << klient.GetSurename() << endl;
	stream.close();
}
