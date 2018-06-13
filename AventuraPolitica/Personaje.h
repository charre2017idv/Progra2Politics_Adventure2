#pragma once
#include <iostream>
#include <string>
using namespace std;
class Personaje
{
public:
	Personaje();
	~Personaje();

public:
	void fn_movimiento(int Mapa_Escuela[5][11]);
	void fn_norte();
	void fn_sur();
	void fn_este();
	void fn_oeste();

	void fn_mapaPrincipal();
public:
	
	int Mapa_Escuela[5][11] =
	{
		{ 0, 0, 0, 0, 0, 0,  0,  0,  0,  0 },

		{ 0, 1, 0, 2, 0, 0,  0,  0,  0,  0 }, // Se inicializa en la segunda posicion

		{ 0, 3, 4, 5, 8, 9,  11, 12, 13, 0 },

		{ 0, 6, 0, 7, 0, 10, 0,  0,  0,  0 },

		{ 0, 0, 0, 0, 0, 0,  0,  0,  0,  0 }
	};
	/* Se inicializa la posicion actual */
	int columna_Y = 1;
	int fila_X = 1;

};

