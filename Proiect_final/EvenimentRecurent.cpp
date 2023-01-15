#include<iostream>
#include<string>
#include"EvenimentrRecurent.h"
#include"Locatie.h"
using namespace std;


//constructor fara parametrii
EvenimentRecurent::EvenimentRecurent():Eveniment()
{
	recurenta = 0;
}

//constructor cu parametrii
EvenimentRecurent::EvenimentRecurent(string data, string ora, string denumire, Locatie locatie, int recurenta) :Eveniment(data, ora, denumire, locatie)
{
	this->recurenta = recurenta;
}

//getteri
int EvenimentRecurent::getRecurenta()
{

	return this->recurenta;
}

//setteri
void EvenimentRecurent::setRecurenta(int recurenta) 
{
	if (recurenta > 0)
		this->recurenta = recurenta;
}

