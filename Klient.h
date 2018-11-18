#pragma once
#include <string>
#include <stdio.h>
using namespace std;
class Klient
{
private:
	string Name, Surename, Date;// Szuka³em typu daty ale nie znalaz³em takiego który pozwala³by na odejmowanie dat itp.
public:
	Klient();
	Klient(string Name, string Surename, string StartDate) {
		this->Name = Name;
		this->Surename = Surename;
		this->Date = Date;
	}
	string GetName() {
		return Name;
	}
	string GetSurename() {
		return Surename;
	}
	string GetDate() {
		return Date;
	}
	~Klient();
};

