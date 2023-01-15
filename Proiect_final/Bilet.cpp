#include<iostream>
#include<string>
#include"Eveniment.h"
#include"Bilet.h"
using namespace std;

//constructor fara parametrii
Bilet::Bilet() : nrMaximBilete(100)
{
	this->tip = nullptr;
	this->id = nrBilete++;
}

//constructor cu parametrii
Bilet::Bilet(char* tip, int nrBilete, int nrMaximBilete, Eveniment ev) : nrMaximBilete(nrMaximBilete)
{
	if (tip != NULL && strlen(tip) != 0 && ev.validareeveniment() == true)
	{

		this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);

		this->id = nrBilete++;

		e = ev;

	}
	else cout << "Date incorecte";
}

//constructor de copiere
Bilet::Bilet(const Bilet& s) :nrMaximBilete(s.nrMaximBilete)
{
	this->tip = new char[strlen(s.tip) + 1];
	strcpy_s(this->tip, strlen(s.tip) + 1, s.tip);

	this->id = s.nrBilete++;
}

//operatorul =
Bilet& Bilet::operator=(const Bilet& s)
{
	if (this != &s)
	{
		if (tip != nullptr)
		{
			delete[] tip;
			tip = nullptr;
		}

		this->tip = new char[strlen(s.tip) + 1];
		strcpy_s(this->tip, strlen(s.tip) + 1, s.tip);

		this->id = s.nrBilete++;
	}
	return *this;
}

//validare bilet
/*bool Bilet::validareBilet()
{
}*/

//getteri
char* Bilet::getTip()
{
	char* copieTip = new char[strlen(this->tip) + 1];
	strcpy_s(copieTip, strlen(this->tip) + 1, this->tip);
	return copieTip;
}

int Bilet::getId()
{
	return this->id;
}

Eveniment Bilet::getEveniment()
{
	return e;
}

//setteri
void Bilet::SetTip(const char* tip)
{
	if (this->tip != NULL)
		delete[] this->tip;

	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

void Bilet::setEveniment(Eveniment e)
{
	if (e.validareeveniment() == true)
	{
		this->e = e;
	}
}

//supraincarcare ++ post incrementare
const Bilet Bilet::operator++(int i)
{
	Bilet copie = *this;
	this->loc++;
	return copie;
}

//destructor
Bilet::~Bilet()
{
	if (tip != nullptr)
	{
		delete[] tip;
		tip = nullptr;
	}
}

ostream& operator<<(ostream& out, Bilet& s)
{
	out << "Tipul biletului este:" << s.getTip() << " " << ",are id-ul" << s.getId() << " " << "la evenimentul" << s.getEveniment();
	return out;
}

istream& operator>>(istream& in, Bilet& s)
{
	cout << "Introdu tip";
	char buffer[200];
	in >> buffer;
	if (buffer != NULL)
	{
		if (s.tip != NULL)
		{
			delete[] s.tip;
		}
		s.tip = new char[strlen(buffer) + 1];
		strcpy_s(s.tip, strlen(buffer) + 1, buffer);
	}

	cout << "\nIntrodu ID";
	in >> s.id;

	cout << "\nIntrodu loc";
	in >> s.loc;

	return in;
}
