#include<iostream>
#include<string>
#include"Bilet.h"
#include"Eveniment.h"
#include"Locatie.h"

using namespace std;

int main()
{
	Eveniment eveniment;
	Locatie locatie;
	Bilet bilet;
	char* standard;
	int* x;


	Eveniment("11.07.2022", "11:30", "Untold", locatie);

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


	Bilet("standard", 20, 50, eveniment);

	//bilet.validareBilet();

	//cout<<bilet.getTip();

	//cout<<bilet.getId();

	//cout<<bilet.getEveniment();

	//bilet.SetTip("standard");

	//bilet.setEveniment(eveniment);

	Locatie("standard", 3, 10);

	/*cout<<locatie.getZone();
	cout<<locatie.getNrZone();
	cout<<locatie.getNrLocuriPerZona();
	locatie.setZone("loja");
	locatie.setNrZone(3);
	locatie.setNrLocuriPerZone(x);
	locatie.esteValida();*/





}