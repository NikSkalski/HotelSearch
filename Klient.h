#pragma once
#include <string>
#include <stdio.h>
using namespace std;
class Klient
{
private:
	string Name, Surename, Date;// Szuka�em typu daty ale nie znalaz�em takiego kt�ry pozwala�by na odejmowanie dat itp.
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

