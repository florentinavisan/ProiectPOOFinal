#include<iostream>
#include<string>
#include"Eveniment.h"
#include"Locatie.h"
using namespace std;

//constructor fara parametrii
Locatie::Locatie()
{
	this->zone = new char[strlen("standard") + 1];
	strcpy_s(this->zone, strlen("standard") + 1, "standard");
	nrZone = 0;
	nrLocuriPerZone = nullptr;
}

//constructor cu parametrii
Locatie::Locatie(const char* zone, int nrZone, int* nrLocuriZone)
{
	if (nrZone > 0 && nrLocuriPerZone != nullptr)
	{
		nrLocuriPerZone = new int[nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			this->nrLocuriPerZone[i] = nrLocuriZone[i];
		}
		this->nrZone = nrZone;
	}
	else
	{
		this->nrLocuriPerZone = nullptr;
		this->nrZone = 0;
	}

	this->zone = new char[strlen(zone) + 1];
	strcpy_s(this->zone, strlen(zone) + 1, zone);
}

//constructor de copiere
Locatie::Locatie(const Locatie& s)
{
	this->nrZone = s.nrZone;

	this->nrLocuriPerZone = new int[this->nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		this->nrLocuriPerZone[i] = s.nrLocuriPerZone[i];
	}

	this->zone = new char[strlen(s.zone) + 1];
	strcpy_s(this->zone, strlen(s.zone) + 1, s.zone);

}

//validare locatie
bool Locatie::esteValida()
{
	if (zone != nullptr && nrZone > 0 && nrLocuriPerZone != nullptr)
		return true;
	else return false;
}


//operatorul =
Locatie& Locatie:: operator=(const Locatie& s)
{
	if (this != &s)
	{
		if (this->zone != nullptr)
		{
			delete[] zone;
			zone = nullptr;
		}

		if (this->nrLocuriPerZone != nullptr)
		{
			delete[] nrLocuriPerZone;
			nrLocuriPerZone = nullptr;
		}

		this->nrZone = s.nrZone;

		this->nrLocuriPerZone = new int[this->nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			this->nrLocuriPerZone[i] = s.nrLocuriPerZone[i];
		}

		this->zone = new char[strlen(s.zone) + 1];
		strcpy_s(this->zone, strlen(s.zone) + 1, s.zone);
	}
	return *this;
}

//getteri 

char* Locatie::getZone()
{
	char* copie = new char[strlen(this->zone) + 1];
	strcpy_s(copie, strlen(zone) + 1, zone);
	return copie;
}

int Locatie::getNrZone()
{
	return this->nrZone;
}

int* Locatie::getNrLocuriPerZona()
{
	int* copie2 = new int[this->nrZone];
	for (int i = 0; i < nrZone; i++)
	{
		copie2[i] = nrLocuriPerZone[i];
	}
	return copie2;
}

//setteri

void Locatie::setZone(const char* zone)
{
	if (this->zone != nullptr)
		delete[] this->zone;

	this->zone = new char[strlen(zone) + 1];
	strcpy_s(this->zone, strlen(zone) + 1, zone);
}

void Locatie::setNrZone(const int y)
{
	if (nrZone > 0)
		nrZone = y;
}

void Locatie::setNrLocuriPerZone(const int* z)
{
	if (nrLocuriPerZone != nullptr)
		delete[] nrLocuriPerZone;

	nrLocuriPerZone = new int[nrZone];
	for (int i = 0; i < nrZone; i++)
		nrLocuriPerZone[i] = z[i];
}

//supraincarcare []
char Locatie::operator[] (int i)
{
	if (i < 0 || i >= strlen(this->zone))
	{
		throw "index invalid";
	}
	else
	{
		return this->zone[i];
	}
}

//supraincarcare -- post decrementare
const Locatie Locatie:: operator--(int i)
{
	Locatie copie = *this;
	this->nrLocuriPerZone--;
	return copie;
}


//destructor
Locatie::~Locatie()
{
	if (this->zone != nullptr)
	{
		delete[] zone;
		zone = nullptr;
	}

	if (this->nrLocuriPerZone != nullptr)
	{
		delete[] nrLocuriPerZone;
		nrLocuriPerZone = nullptr;
	}
}

ostream& operator<<(ostream& out, Locatie s)
{
	out << "Locul" << s.getNrLocuriPerZona() << "din Zona" << s.getZone();
	return out;
}

istream& operator>>(istream& in, Locatie s)
{
	cout << "Introdu zona:";
	char buffer[255];
	in >> buffer;
	if (buffer != NULL)
	{
		if (s.zone != NULL)
		{
			delete[] s.zone;
			s.zone = nullptr;
		}
		s.zone = new char[strlen(buffer) + 1];
		strcpy_s(s.zone, strlen(buffer) + 1, buffer);
	}

	cout << "\nIntrodu numarul de zone";
	in >> s.nrZone;

	cout << "\n Introdu nr locurile per zona";
	int buffer2[300];
	for (int i = -0; i < s.nrZone; i++)
	{
		in >> buffer2[i];
	}

	if (buffer2 != NULL)
	{
		if (s.nrLocuriPerZone != NULL)
		{
			delete[] s.nrLocuriPerZone;
			s.nrLocuriPerZone = nullptr;
		}
		s.nrLocuriPerZone = new int[s.nrZone];
		for (int i = 0; i < s.nrZone; i++)
			s.nrLocuriPerZone[i] = buffer2[i];
	}
	return in;
}