#pragma once
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;
void saveHotelList(multimap<string, Hotel>, std::string name);
multimap<string, Hotel> loadHotelList( std::string name);
void updateList(multimap<string, Hotel>& list, std::string name);
void saveBooking(Hotel& TheOne, Klient& klient, std::string city ,std::string name);
//To Do: maybe loading/saving client data?
