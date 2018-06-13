#pragma once
#include <iostream>
#include <string>
using namespace std;

enum nombre_Politicos
{
	vacio = 0,
	FELIPE_CALDERON,
	DUARTE,
	FOX,
	MARGARITA,
	CARLOS_SALINAS,
	NADIE
};

enum status_Politicos
{
	Libre = 0,
	STATUS_FELIPE,
	STATUS_DUARTE,
	STATUS_FOX,
	STATUS_MARGARTIA,
	STATUS_CARLOSS,
	SIN_STATUS
};
class CPoliticos
{
public:
	CPoliticos(nombre_Politicos nombrePoliticos, status_Politicos statsPoliticos);
	~CPoliticos();

public:
	// GETER: Este regresa el objeto que hay en un cuarto.
	string Get_Nombre();
	string Get_Status();

private:
	nombre_Politicos Nombre;
	string Arreglo_Nombres[7] =
	{
		"FELIPE CALDERON",
		"DUARTE",
		"FOX",
		"MARGARITA",
		"CARLOS SALINAS",
		"SIN POLITICO"
	};

	status_Politicos Status;
	string Arreglo_Status[7] =
	{
		"Ex Presidente de la Republica Mexicana, acusado del sexenio de sangre.",
		"Profugo de la justicia, acusado de robo de dinero. (Buenos contactos).",
		"Casi olvidado pero despiadado, malo para el pais. (Buenos contactos).",
		"Iniciando su campaña independiente, con poca posibilidad de ganar.",
		"Titere de titeres. (Es mejor tener cuidado cuando se tiene cierta popularidad).",
		"SIN STATUS SOCIAL",
	};
};

