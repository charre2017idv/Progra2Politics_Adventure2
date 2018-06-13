#pragma once
#include <iostream>
#include <string>
using namespace std;

enum objetos_Cuarto
{
	NADA = 0,
	PISTA_UNO,
	PISTA_DOS,
	PISTA_TRES,
	PISTA_CUATRO,
	PISTA_CINCO,
	PISTA_VACIO
};

class CCuartos
{
public:
	CCuartos* Salon_1;
	CCuartos* Salon_2;
	CCuartos* Salon_6;
	CCuartos* Salon_7;
	CCuartos* Salon_10;

	CCuartos* Pasillo_1;
	CCuartos* Pasillo_2;
	CCuartos* Pasillo_3;
	CCuartos* Pasillo_4;
	CCuartos* Pasillo_5;
	CCuartos* Pasillo_6;
	CCuartos* Pasillo_7;
	CCuartos* Pasillo_8;
public:
	CCuartos(string nombreCuarto, string descripcionCuarto, string direccionesCuarto, string accionesCuarto, objetos_Cuarto objetosCuarto);
	~CCuartos();

// Funciones
public:
	// GETER: Este regresa el objeto que hay en un cuarto.
	string Get_Item();
	void fn_cuartos();


// Variables
public:
	string m_nombreCuarto;
	string m_descripcionCuarto;
	string m_direccionesCuarto;
	string m_accionesCuarto;

private:
	objetos_Cuarto Item;
	string Arreglo_Pistas[7] =
	{ "Nota personal de Felipe Calderon: Me gustaria tener 2 departamentos y un terreno.",
		"Nota personal de Duarte: Aunque tenga algunos problemitas eso no evitara que obtenga algo de ayuda con 1 politico, 1 cancion, 3 votos y 8 despensas para acarrear a los que me estan presionando.",
		"Nota personal de Aristoteles: Con mi antigua candidatura, sera dificil convencerme,\n talvez con 1 cancion pegajosa y 6 despensas votaria por ese representante.",
		"Nota personal de Margarita: Con lo que conozco de politica,\n no votaria por alguien con menos de 4 votos y 5 despansas.",
		"Nota de empleado: Los duenos del lugar son personas complicadas,\n creo que solo con todas las cosas que venden podrian votar por ese candidato.",
		"Aqui no hay nada mas que publicidad ajena .-." };
};

