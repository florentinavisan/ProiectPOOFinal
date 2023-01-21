#include<iostream>
#include<string>
#include"Bilet.h"
#include"Eveniment.h"
#include"Locatie.h"

using namespace std;

int main()
{
	//Eveniment eveniment;
	Locatie locatie;
	Bilet bilet;
	char* zone;
	zone = new char[strlen("a") + 1];
		strcpy_s(zone, strlen("a") + 1, "a");
	int x[1];
	x[0] = 4;



	Eveniment eveniment("11.07.2022", "11:30", "Untold", locatie);
	cout << eveniment;

	//eveniment.valideazaData("11.07.2023");

	//eveniment.contineDoarCifre("24");

	//eveniment.valideazaOra("11:30");

	//eveniment.setLocatie(locatie);

	//eveniment.setData("11.08.2023");

	//eveniment.setOra("18:30");

	//eveniment.setDenumire("Untold");

	//cout<<eveniment.getData();

	//cout<<eveniment.getLocatie();

	//cout<<eveniment.getOra();

	//cout<<eveniment.getDenumire();


	Bilet b(zone, 20, 50, eveniment);
	cout << b;

	//bilet.validareBilet();

	//cout<<bilet.getTip();

	//cout<<bilet.getId();

	//cout<<bilet.getEveniment();

	//bilet.SetTip("standard");

	//bilet.setEveniment(eveniment);

	Locatie l(zone, 3, x);
	cout << l;

	/*cout<<locatie.getZone();
	cout<<locatie.getNrZone();
	cout<<locatie.getNrLocuriPerZona();
	locatie.setZone("loja");
	locatie.setNrZone(3);
	locatie.setNrLocuriPerZone(x);
	locatie.esteValida();*/





}