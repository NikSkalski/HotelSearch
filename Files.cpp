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

void saveHotelList(multimap<string, Hotel> list, string name) {

	ofstream stream;
	stream.open(name, ios::out | ios::trunc); //otwiera plik w trybie do pisania, jak cos w nim wczesniej bylo to usuwa
	if (!stream.is_open()) {
		cerr << "Could not open file" << endl;
		exit(1);
	} 
	auto ran = list.equal_range(list.begin()->first);
	/*the outer loop iterates over each key, while the inner loop operates over all values corresponding 
	to a given key*/
	for (auto iterator = ran.first ;iterator != list.end();) {
		stream << iterator->first << ":\n";
		for (auto i = iterator; i != ran.second; ++i ) {
			stream << "\t" << i->second.getName() << "\t" << i->second.Cost(1) << "\n";
		}
		stream << "END " << iterator->first << "\n";
		if (ran.second == list.end()) break; //awkward fix, if this check is not done the function will crash the program by dereferencing a null pointer
												//after reaching the end of the list
		ran = list.equal_range(ran.second->first);
		iterator = ran.first;
	}
	stream.close();
};

multimap<string, Hotel> loadHotelList(string name) {
	ifstream stream;
	stream.open(name);
	if (!stream.is_open()) {
		cerr << "Could not open file" << endl;
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
