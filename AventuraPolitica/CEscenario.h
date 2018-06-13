#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "CCuartos.h"
#include "CHUD.h"
#include "CPoliticos.h"
class CEscenario
{
public:
	CHUD* m_HUD;


	CPoliticos* m_SinPolitico;

public:
	CEscenario();
	~CEscenario();

public:
	// Movimiento Personaje
	void fn_desplazamiento();
	// Cuartos - Descripcion
	void fn_cuartos();
	// Acciones
	void fn_examinarSalon();
	void fn_convencerPolitico();
	void fn_promocion();
	void fn_historia();
	void fn_accion();
	void fn_salir();
	void fn_mapa();
	void fn_ganar();
	void fn_perder();
	// Funciones
	void fn_guardarPartida();
	void fn_nuevaPartida();
	void fn_cargarPartida();
	void fn_world();

public:
	int m_Mapa_Escuela[5][11] =
	{
		{ 0, 0, 0, 0, 0, 0,  0,  0,  0,  0 },

		{ 0, 1, 0, 2, 0, 0,  0,  0,  0,  0 }, // Se inicializa en la segunda posicion

		{ 0, 3, 4, 5, 8, 9,  11, 12, 13, 0 },

		{ 0, 6, 0, 7, 0, 10, 0,  0,  0,  0 },

		{ 0, 0, 0, 0, 0, 0,  0,  0,  0,  0 }
	};
	string m_OpcionesMenu;
	string m_Accion;
	string m_Instruccion;
};

