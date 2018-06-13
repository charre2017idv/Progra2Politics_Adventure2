#include "CPoliticos.h"



CPoliticos::CPoliticos(nombre_Politicos nombrePoliticos, status_Politicos statsPoliticos)
{
	Nombre = nombrePoliticos;
	Status = statsPoliticos;
}


CPoliticos::~CPoliticos()
{
}

string CPoliticos::Get_Nombre()
{
	cout << endl;
	cout << "----- POLITICO -----" << endl;
	cout << endl;
	return Arreglo_Nombres[Nombre - 1];
}

string CPoliticos::Get_Status()
{
	cout<< "Status Social: ";
	return Arreglo_Status[Status - 1];
}