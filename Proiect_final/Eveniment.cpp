#include<iostream>
#include<string>
#include"Eveniment.h"
#include"Locatie.h"
using namespace std;


//constructor fara parametrii
Eveniment::Eveniment()
{
	l = new Locatie();
	this->data = "ZZ//LL/AAAA";
	this->ora = "00:00";
	this->denumire = nullptr;
}

//constructor cu parametrii
Eveniment::Eveniment(string data, string ora, string denumire, Locatie locatie)
{
	l = new Locatie(locatie);
	this->data = data;
	this->ora = ora;
	this->denumire = denumire;
}

//validare data()
bool Eveniment::valideazaData(string data)
{
	if (data.length() == 10) {
		string ziua = data.substr(0, 2);
		string luna = data.substr(3, 2);
		string an = data.substr(6, 4);
		if (contineDoarCifre(ziua) && contineDoarCifre(luna) && contineDoarCifre(an)) {
			if (stoi(ziua) > 31)
			{
				cout << "Zi mai mare decat 31, mai incearca" << endl;
				return false;
			}

			if (stoi(luna) > 12)
			{
				cout << "Luna mai mare decat 12, mai incearca" << endl;
				return false;
			}

			if (data[2] != '.' || data[5] != '.')
			{
				cout << "Data nu are formatul zz.ll.yyyy" << endl;
				return false;
			}
		}
		return true;
	}
	cout << "Data nu are formatul zz.ll.yyyy" << endl;
	return false;
}

bool Eveniment::contineDoarCifre(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < 0 || s[i] > 9)
			return false;
	}
	return true;

}

//validare ora()
bool Eveniment::valideazaOra(string s)
{
	if (s.length() == 5)
	{
		string ora = s.substr(0, 2);
		string minut = s.substr(3, 2);
		if (contineDoarCifre(ora) && contineDoarCifre(minut))
		{
			if (stoi(ora) > 23)
			{
				cout << "Ora nu este valida" << endl;
				return false;
			}

			if (stoi(minut) > 59)
			{
				cout << "Minutul nu este valid" << endl;
				return false;
			}

			if (s[2] != ':')
			{
				cout << "Ora nu are formatul oo:mm" << endl;
				return false;
			}
			return true;
		}
		cout << "Ora nu are formatul oo:mm" << endl;
		return false;
	}
	cout << "Ora nu are formatul oo:mm" << endl;
	return false;
}

//validare eveniment

bool Eveniment::validareeveniment()
{
	if (valideazaOra(ora) == true && valideazaData(data) == true && denumire != "")
	{
		return true;
	}

	return false;

}

//getteri
string Eveniment::getData()
{

	return this->denumire;
}
Locatie Eveniment::getLocatie() {
	return *l;
}

string Eveniment::getOra()
{
	return this->ora;
}

string Eveniment::getDenumire()
{
	return this->denumire;
}

//setteri
void Eveniment::setLocatie(Locatie locatie) {
	if (locatie.esteValida()) {
		delete l;
		l = new Locatie(locatie);
	}
}

void Eveniment::setData(string data)
{
	if (data != "")
		this->data = data;
}

void Eveniment::setOra(string ora)
{
	if (ora != "")
		this->ora = ora;
}

void Eveniment::setDenumire(string denumire)
{
	if (denumire != "")
		this->denumire = denumire;
}

//supraincarcare cast
Eveniment:: operator string()
{
	return this->data;
}

//supraincarcare operator !=
bool Eveniment:: operator!=(const Eveniment& s)
{
	if (this->data == s.data && this->ora == s.ora)
		return false;

	else
		return true;
}

ostream& operator<<(ostream& out, Eveniment s)
{
	out << "Evenimentul" << s.getDenumire() << " " << "are loc pe data" << s.getData() << " " << "si ora : " << s.getOra() << " are locatia " << *s.l;
	return out;
}

istream& operator>>(istream& in, Eveniment s)
{
	cout << "Introdu numele evenimentului:";
	in >> s.denumire;

	cout << endl;

	cout << "Introdu data evenimentului";
	in >> s.data;

	cout << endl;

	cout << "Introdu ora evenimentului";
	in >> s.ora;

	return in;
}