#pragma once
#include <string>
#include <stdio.h>
using namespace std;
class Klient
{
private:
	string  Name, Surname, Date; //ToDo: date handling
public:
	Klient();
	Klient(string Name, string Surename, string StartDate) {
		this->Name = Name;
		this->Surname = Surename;
		this->Date = Date;
	}
	string GetName() {
		return Name;
	}
	string GetSurename() {
		return Surname;
	}
	string GetDate() {
		return Date;
	}
	~Klient();
};

