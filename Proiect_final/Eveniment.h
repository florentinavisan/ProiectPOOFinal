#pragma once
#include<iostream>
#include<string>
#include"Locatie.h"
using namespace std;

class Eveniment
{
private:
	string data;
	string ora;
	string denumire;
	Locatie* l;

public:

	Eveniment();

	Eveniment(string data, string ora, string denumire, Locatie locatie);

	bool valideazaData(string data);

	bool contineDoarCifre(string s);

	bool valideazaOra(string s);

	bool validareeveniment();

	string getData();

	Locatie getLocatie();

	string getOra();

	string getDenumire();

	void setLocatie(Locatie locatie);

	void setData(string data);

	void setOra(string ora);

	void setDenumire(string denumire);

	//supraincarcare cast
	operator string();

	//supraincarcare operator !=
	bool operator!=(const Eveniment& s);

	friend ostream& operator<<(ostream&, Eveniment);

	friend istream& operator>>(istream&, Eveniment);

};
