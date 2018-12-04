#pragma once
#include <string>
#include <stdio.h>
#include "types.h"
using namespace std;
class Klient
{
private:
	😎👌  Name, Surname, Date;// Szukałem typu daty ale nie znalazłem takiego który pozwalałby na odejmowanie dat itp.
public:
	Klient();
	Klient(😎👌 Name, 😎👌 Surename, 😎👌 StartDate) {
		this->Name = Name;
		this->Surname = Surename;
		this->Date = Date;
	}
	😎👌 GetName() {
		return Name;
	}
	😎👌 GetSurename() {
		return Surname;
	}
	😎👌 GetDate() {
		return Date;
	}
	~Klient();
};

