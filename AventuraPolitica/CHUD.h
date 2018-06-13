#pragma once
#include <iostream>
#include <vector>
using namespace std;
class CHUD
{
public:
	CHUD(int i_dinero_Jugador, int i_popularidad, int i_seguidores, int i_casasBlancas, int i_Autos, int i_departamentos, int i_casasInfonavit, int i_terrenos, int i_votos_Salon1, int i_votos_Salon2, int i_votos_Salon6, int i_votos_Salon7, int i_votos_Salon10, int i_visitado_Salon1, int i_visitado_Salon2, int i_visitado_Salon6, int i_visitado_Salon7, int i_visitado_Salon10, int i_visitado_Pasillo1, int i_visitado_Pasillo2, int i_visitado_Pasillo3, int i_visitado_Pasillo4, int i_visitado_Pasillo5, int i_visitado_Pasillo6, int i_visitado_Pasillo7, int i_visitado_Pasillo8);
	~CHUD();

public:
	void HUD();
	void fn_guardarPartida();
	void fn_cargarPartida();
public:
	/* Se inicializa la posicion actual */
	int m_columna_Y = 1;
	int m_fila_X = 1;

	int m_dinero_Jugador = 200;
	int m_popularidad = 0;
	int m_seguidores = 0;
	int m_casasBlancas = 0;
	int m_Autos = 0;
	int m_departamentos = 0;
	int m_casasInfonavit = 0;		
	int m_terrenos = 0;

	int m_votos_Salon1 = 0;
	int m_votos_Salon2 = 0;
	int m_votos_Salon6 = 0;
	int m_votos_Salon7 = 0;
	int m_votos_Salon10 = 0;

	/* CUARTOS VISITADO */

	int m_visitado_Salon1 = 0;
	int m_visitado_Salon2 = 0;
	int m_visitado_Salon6 = 0;
	int m_visitado_Salon7 = 0;
	int m_visitado_Salon10 = 0;

	int m_visitado_Pasillo1 = 0;
	int m_visitado_Pasillo2 = 0;
	int m_visitado_Pasillo3 = 0;
	int m_visitado_Pasillo4 = 0;
	int m_visitado_Pasillo5 = 0;
	int m_visitado_Pasillo6 = 0;
	int m_visitado_Pasillo7 = 0;
	int m_visitado_Pasillo8 = 0;

public:
	// Guardar / Cargar Partida
	vector <int> Array_ActualPosition;
	vector <int> Puntuaciones;
	vector <int> FILA_X;
	vector <int> COLUMNA_Y;
	vector <int> DINERO;
	vector <int> POPULARIDAD;
	vector <int> SEGUIDORES;
	vector <int> VOTOS;
	vector <int> DESPENSAS;
	vector <int> POLITICOS;
	vector <int> CUMPLIDOS;
	vector <int> CANCIONES;
	vector <int> VOTOS_SALON1;
	vector <int> VOTOS_SALON2;
	vector <int> VOTOS_SALON6;
	vector <int> VOTOS_SALON7;
	vector <int> VOTOS_SALON10;

	vector <int> VISITADO_SALON1;
	vector <int> VISITADO_SALON2;
	vector <int> VISITADO_SALON6;
	vector <int> VISITADO_SALON7;
	vector <int> VISITADO_SALON10;
	vector <int> VISITADO_PASILLO1;
	vector <int> VISITADO_PASILLO2;
	vector <int> VISITADO_PASILLO3;
	vector <int> VISITADO_PASILLO4;
	vector <int> VISITADO_PASILLO5;
	vector <int> VISITADO_PASILLO6;
	vector <int> VISITADO_PASILLO7;
	vector <int> VISITADO_PASILLO8;
};

