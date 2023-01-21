#pragma once
#include<iostream>
#include<string>
#include"Eveniment.h"
using namespace std;

class EvenimentRecurent : public Eveniment
{
private:
	int recurenta;
public:

	EvenimentRecurent();// : Eveniment()
	/*{
		recurenta = 0;
	}*/

	EvenimentRecurent(string data, string ora, string denumire, Locatie locatie, int recurenta);// :Eveniment(data, ora, denumire, locatie);
	/*{
		this->recurenta = recurenta;
	}*/

	int getRecurenta();

	void setRecurenta(int recurenta);

	friend ostream& operator<<(ostream&, EvenimentRecurent);

	friend istream& operator>>(istream&, EvenimentRecurent);
};
