#pragma once
#include<iostream>
#include<string>
#include"Eveniment.h"
using namespace std;

class Bilet
{
private:
	char* tip;
	int static nrBilete;
	int id;
	int loc;
	const int nrMaximBilete;
	Eveniment e;


public:

	//constructor fara parametrii
	Bilet();

	//constructor cu parametrii
	Bilet(char* tip, int nrBilete, int nrMaximBilete, Eveniment ev);

	//constructor de copiere
	Bilet(const Bilet& s);

	//operatorul =
	Bilet& operator=(const Bilet& s);

	//validare bilet
	bool validareBilet();

	//getteri
	char* getTip();

	int getId();

	Eveniment getEveniment();

	//setteri
	void SetTip(const char* tip);

	void setEveniment(Eveniment e);

	//supraincarcare ++ post incrementare
	const Bilet operator++(int i);

	//destructor
	~Bilet();


	friend ostream& operator<<(ostream& out, Bilet& s);
	friend istream& operator>>(istream& in, Bilet& s);
};

int Bilet::nrBilete = 0;
