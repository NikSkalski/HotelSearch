#include "pch.h"
#include "Hotel.h"
#include <vector>
#include <string>


Hotel HotelFinder(multimap<string, Hotel>& ListOfHotels, string Place) {
	if (ListOfHotels.count(Place) == 0) {
		cout << "No hotels found in " << Place << endl;
		return Hotel(); //return default-constructed object if no matches found
	}
	auto range = ListOfHotels.equal_range(Place);
	int index = 1;
	cout << "Results:\n";
	for (auto it = range.first; it != range.second; it++) {
		cout << index++ << ".\t" << it->second.getName() << "\t" << it->second.Cost(1) << endl;
	}
	cout << "Select hotel" << endl;
	int k;
	cin >> k;
	//advance iterator to the position of the selected Hotel 
	for (int i = 0; i < (k - 1); i++) {
		range.first++;
	}
	//return matching Hotel object
	return Hotel(range.first->second.getName(), range.first->second.Cost(1));

}