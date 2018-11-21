#pragma once
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <assert.h>
using namespace std;
void saveHotelList(std::map<std::string, std::vector<Hotel>>& list, std::string name);
multimap<string, Hotel> loadHotelList( std::string name);
void updateList(map<string, vector<Hotel>>& list, std::string name);
void PrintEnd(Hotel& TheOne, Klient& klient, std::string name);

