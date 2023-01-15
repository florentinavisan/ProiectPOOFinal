#pragma once
#include<iostream>
#include<string>
using namespace std;

class Locatie
{
private:

	char* zone; // zona A B C
	int nrZone;  // cate zone am
	int* nrLocuriPerZone;  //cate locuri are fiecare zona 
	/*
	zona=a,b,c
	nrzone=3
	nr locuri perzone= pt zona a=3
						pt zona b=4
						pt zona c=5
	*/
public:

	Locatie();

	Locatie(const char* zone, int nrZone, int* nrLocuriZone);

	Locatie(const Locatie& s);

	Locatie& operator=(const Locatie& s);

	char* getZone();

	int getNrZone();

	int* getNrLocuriPerZona();

	void setZone(const char* zone);

	void setNrZone(const int y);

	void setNrLocuriPerZone(const int* z);

	bool esteValida();

	char operator[] (int i);

	const Locatie operator--(int i);

	~Locatie();

	friend ostream& operator<<(ostream&, Locatie);

	friend istream& operator>>(istream&, Locatie);
};