#pragma once
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <assert.h>
using namespace std;
void saveHotelList(std::map<std::string, std::vector<Hotel>>& list, std::string name);
void PrintEnd(Hotel TheOne, Klient klient, std::string name);
void saveHotelList(std::map<std::string, std::vector<Hotel>>& list, std::string name) {

	ofstream stream;
	stream.open(name, ios::out || ios::trunc); //otwiera plik w trybie do pisania, jak cos w nim wczesniej bylo to usuwa
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
//void loadHotelList(vector<Hotel>& list, std::string name);
//void insertInList(vector<Hotel>& list, std::string name);

void PrintEnd(Hotel *TheOne, Klient *klient, std::string name) {
	ofstream stream;
	stream.open(name, ios::out || ios::trunc);
	assert(stream.is_open());
	stream << "\t" << &TheOne->getName << "\t" << &TheOne->GetCity << "\t" << &klient->GetName << "  " << &klient->GetSurename << endl;
	stream.close();
}