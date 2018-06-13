#include "CHUD.h"
#include <iostream>
#include <fstream>
#include "windows.h"
using namespace std;



CHUD::CHUD(int dinero, int popularidad, int seguidores, int casasBlancas, int autos, int departamentos, int casasInfonavit, int terrenos, int votos_Salon1, int votos_Salon2, int votos_Salon6, int votos_Salon7, int votos_Salon10, int visitado_Salon1, int visitado_Salon2, int visitado_Salon6, int visitado_Salon7, int visitado_Salon10, int visitado_Pasillo1, int visitado_Pasillo2, int visitado_Pasillo3, int visitado_Pasillo4, int visitado_Pasillo5, int visitado_Pasillo6, int visitado_Pasillo7, int visitado_Pasillo8)
{
	m_dinero_Jugador = dinero;
	m_popularidad = popularidad;
	m_seguidores = seguidores;
	m_casasBlancas = casasBlancas;
	m_Autos = autos;
	m_departamentos = departamentos;
	m_casasInfonavit = casasInfonavit;
	m_terrenos = terrenos;

	m_votos_Salon1 = votos_Salon1;
	m_votos_Salon2 = votos_Salon2;
	m_votos_Salon6 = votos_Salon6;
	m_votos_Salon7 = votos_Salon7;
	m_votos_Salon10 = votos_Salon10;

	m_visitado_Salon1 = visitado_Salon1;
	m_visitado_Salon2 = visitado_Salon2;
	m_visitado_Salon6 = visitado_Salon6;
	m_visitado_Salon7 = visitado_Salon7;
	m_visitado_Salon10 = visitado_Salon10;

	m_visitado_Pasillo1 = visitado_Pasillo1;
	m_visitado_Pasillo2 = visitado_Pasillo2;
	m_visitado_Pasillo3 = visitado_Pasillo3;
	m_visitado_Pasillo4 = visitado_Pasillo4;
	m_visitado_Pasillo5 = visitado_Pasillo5;
	m_visitado_Pasillo6 = visitado_Pasillo6;
	m_visitado_Pasillo7 = visitado_Pasillo7;
	m_visitado_Pasillo8 = visitado_Pasillo8;
}


CHUD::~CHUD()
{
}


void CHUD::HUD()
{
	cout << endl;
	cout << "------  Stats Generales  ------" << endl;
	cout << " ______________________________________________________________________________________________" << endl;
	cout << "|Dinero|Popularidad|Seguidores|CasasBlancas|Automoviles|Departamentos|CasasInfonavit| Terrenos |" << endl;
	cout << "|______|___________|__________|____________|___________|_____________|______________|__________|" << endl;
	cout << "|      |           |          |            |           |             |              |          |" << endl;
	cout << "| " << m_dinero_Jugador << "  |     " << m_popularidad << "     |     " << m_seguidores << "    |      " << m_casasBlancas << "     |     " << m_Autos << "     |      " << m_departamentos << "      |       " << m_casasInfonavit << "      |     " << m_terrenos << "    |" << endl;
	cout << "|______|___________|__________|____________|___________|_____________|______________|__________|" << endl;
	cout << endl;
}

void CHUD::fn_guardarPartida()
{
	fstream *Nueva_Partida = new fstream("Nueva_Partida.txt", ios::out);
	//fstream Nueva_Partida;
	//Nueva_Partida.open("Nueva_Partida.txt", ios::out);
	if (Nueva_Partida->fail())
	{
		cout << "C0003: (!) Error de creacion de nueva partida." << endl;
	}
	// Guardar
	// Se almacena la 'ultima' posicion actual
	(*Nueva_Partida) << m_fila_X << endl;
	(*Nueva_Partida) << endl;
	(*Nueva_Partida) << m_columna_Y << endl;
	(*Nueva_Partida) << endl;
	// Dinero Jugador
	(*Nueva_Partida) << m_dinero_Jugador << endl;
	(*Nueva_Partida) << endl;

	// Popularidad
	(*Nueva_Partida) << m_popularidad << endl;
	(*Nueva_Partida) << endl;

	// Seguidores
	(*Nueva_Partida) << m_seguidores << endl;
	(*Nueva_Partida) << endl;

	// Votos
	(*Nueva_Partida) << m_departamentos << endl;
	(*Nueva_Partida) << endl;

	// Despensas
	(*Nueva_Partida) << m_terrenos << endl;
	(*Nueva_Partida) << endl;

	// Politicos
	(*Nueva_Partida) << m_casasBlancas << endl;
	(*Nueva_Partida) << endl;

	// Cumplidos
	(*Nueva_Partida) << m_casasInfonavit << endl;
	(*Nueva_Partida) << endl;

	// Canciones 
	(*Nueva_Partida) << m_Autos << endl;
	(*Nueva_Partida) << endl;

	// Votos_Salon1
	(*Nueva_Partida) << m_votos_Salon1 << endl;
	(*Nueva_Partida) << endl;

	// Votos_Salon2
	(*Nueva_Partida) << m_votos_Salon2 << endl;
	(*Nueva_Partida) << endl;

	// Votos_Salon6
	(*Nueva_Partida) << m_votos_Salon6 << endl;
	(*Nueva_Partida) << endl;

	// Votos_Salon7
	(*Nueva_Partida) << m_votos_Salon7 << endl;
	(*Nueva_Partida) << endl;

	// Votos_Salon10
	(*Nueva_Partida) << m_votos_Salon10 << endl;
	(*Nueva_Partida) << endl;

	/* MAPA */
	// Visitado_Salon1
	(*Nueva_Partida) << m_visitado_Salon1 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Salon2
	(*Nueva_Partida) << m_visitado_Salon2 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Salon6
	(*Nueva_Partida) << m_visitado_Salon6 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Salon7
	(*Nueva_Partida) << m_visitado_Salon7 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Salon10
	(*Nueva_Partida) << m_visitado_Salon10 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Pasillo1
	(*Nueva_Partida) << m_visitado_Pasillo1 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Pasillo2
	(*Nueva_Partida) << m_visitado_Pasillo2 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Pasillo3
	(*Nueva_Partida) << m_visitado_Pasillo3 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Pasillo4
	(*Nueva_Partida) << m_visitado_Pasillo4 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Pasillo5
	(*Nueva_Partida) << m_visitado_Pasillo5 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Pasillo6
	(*Nueva_Partida) << m_visitado_Pasillo6 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Pasillo7
	(*Nueva_Partida) << m_visitado_Pasillo7 << endl;
	(*Nueva_Partida) << endl;
	// Visitado_Pasillo8
	(*Nueva_Partida) << m_visitado_Pasillo8 << endl;
	(*Nueva_Partida) << endl;

	// Se cierra el documento
	Nueva_Partida->close();

	if (Nueva_Partida) // Revisa que Nueva_Partida no sea nulo(vacio). REvisa que el puntero
	{
		cout << "/* C008: (!) RELEASED MEMORY */" << endl;
		delete(Nueva_Partida);
	}
	else
	{
		cout << "/* C009: (!) MEMORYLEAK PROBLEM */" << endl;
	}

	cout << "/* C004: (!) SE HA GUARDADO EXITOSAMENTE LA PARTIDA */" << endl;
	cout << endl;
	cout << "/* Nombre de la partida guardada: Nueva_Partida.txt */" << endl;
	cout << endl;

}

void CHUD::fn_cargarPartida()
{
	ifstream *Cargar_Partida = new ifstream("Nueva_Partida.txt", ios::in);
	int Datos;
	if (Cargar_Partida->fail())
	{
		cout << "C0005: (!) Error de Carga del archivo." << endl;
	}
	while ((*Cargar_Partida) >> Datos) // Se almacenan todos los datos del archivo
	{
		Puntuaciones.push_back(Datos);
		//cout << Datos << endl;
	}
	if (Puntuaciones.size() < 1) // Error en caso de documento vacio
	{
		cout << "C0006: (!) Error de Carga del archivo: No cuenta con un archivo al cual cargar." << endl;
		cout << "C0007: (!) El programa se cerrara en breve." << endl;
		Sleep(6000);
		exit(1);
	}
	for (int i = 0; i < 1; i++) // fila_X
	{
		FILA_X.push_back(Puntuaciones[i]);
		m_fila_X = Puntuaciones[i];
	}
	for (int i = 1; i < 2; i++) // columna_Y
	{
		COLUMNA_Y.push_back(Puntuaciones[i]);
		m_columna_Y = Puntuaciones[i];
	}
	for (int i = 2; i < 3; i++) // Dinero
	{
		DINERO.push_back(Puntuaciones[i]);
		m_dinero_Jugador = Puntuaciones[i];
	}
	for (int i = 3; i < 4; i++) // Popularidad
	{
		POPULARIDAD.push_back(Puntuaciones[i]);
		m_popularidad = Puntuaciones[i];
	}
	for (int i = 4; i < 5; i++) // Seguidores
	{
		SEGUIDORES.push_back(Puntuaciones[i]);
		m_seguidores = Puntuaciones[i];
	}
	for (int i = 5; i < 6; i++) // Votos
	{
		VOTOS.push_back(Puntuaciones[i]);
		m_casasBlancas = Puntuaciones[i];
	}
	for (int i = 6; i < 7; i++) // Despensas
	{
		DESPENSAS.push_back(Puntuaciones[i]);
		m_Autos = Puntuaciones[i];
	}
	for (int i = 7; i < 8; i++) // Politicos
	{
		POLITICOS.push_back(Puntuaciones[i]);
		m_departamentos = Puntuaciones[i];
	}
	for (int i = 8; i < 9; i++) // Cumplidos
	{
		CUMPLIDOS.push_back(Puntuaciones[i]);
		m_casasInfonavit = Puntuaciones[i];
	}
	for (int i = 9; i < 10; i++) // Canciones
	{
		CANCIONES.push_back(Puntuaciones[i]);
		m_terrenos = Puntuaciones[i];
	}
	for (int i = 10; i < 11; i++) // votos_Salon1
	{
		VOTOS_SALON1.push_back(Puntuaciones[i]);
		m_votos_Salon1 = Puntuaciones[i];
	}
	for (int i = 11; i < 12; i++) // votos_Salon2
	{
		VOTOS_SALON2.push_back(Puntuaciones[i]);
		m_votos_Salon2 = Puntuaciones[i];
	}
	for (int i = 12; i < 13; i++) // votos_Salon6
	{
		VOTOS_SALON6.push_back(Puntuaciones[i]);
		m_votos_Salon6 = Puntuaciones[i];
	}
	for (int i = 13; i < 14; i++) // votos_Salon7
	{
		VOTOS_SALON7.push_back(Puntuaciones[i]);
		m_votos_Salon7 = Puntuaciones[i];
	}
	for (int i = 14; i < 15; i++) // votos_Salon10
	{
		VOTOS_SALON10.push_back(Puntuaciones[i]);
		m_votos_Salon10 = Puntuaciones[i];
	}
	for (int i = 15; i < 16; i++) // visitado_Salon1
	{
		VISITADO_SALON1.push_back(Puntuaciones[i]);
		m_visitado_Salon1 = Puntuaciones[i];
	}
	for (int i = 16; i < 17; i++) // visitado_Salon2
	{
		VISITADO_SALON2.push_back(Puntuaciones[i]);
		m_visitado_Salon2 = Puntuaciones[i];
	}
	for (int i = 17; i < 18; i++) // visitado_Salon6
	{
		VISITADO_SALON6.push_back(Puntuaciones[i]);
		m_visitado_Salon6 = Puntuaciones[i];
	}
	for (int i = 18; i < 19; i++) // visitado_Salon7
	{
		VISITADO_SALON7.push_back(Puntuaciones[i]);
		m_visitado_Salon7 = Puntuaciones[i];
	}
	for (int i = 19; i < 20; i++) // visitado_Salon10
	{
		VISITADO_SALON10.push_back(Puntuaciones[i]);
		m_visitado_Salon10 = Puntuaciones[i];
	}
	for (int i = 20; i < 21; i++) // visitado_Pasillo1
	{
		VISITADO_PASILLO1.push_back(Puntuaciones[i]);
		m_visitado_Pasillo1 = Puntuaciones[i];
	}
	for (int i = 21; i < 22; i++) // visitado_Pasillo2
	{
		VISITADO_PASILLO2.push_back(Puntuaciones[i]);
		m_visitado_Pasillo2 = Puntuaciones[i];
	}
	for (int i = 22; i < 23; i++) // visitado_Pasillo3
	{
		VISITADO_PASILLO3.push_back(Puntuaciones[i]);
		m_visitado_Pasillo3 = Puntuaciones[i];
	}
	for (int i = 23; i < 24; i++) // visitado_Pasillo4
	{
		VISITADO_PASILLO4.push_back(Puntuaciones[i]);
		m_visitado_Pasillo4 = Puntuaciones[i];
	}
	for (int i = 24; i < 25; i++) // visitado_Pasillo5
	{
		VISITADO_PASILLO5.push_back(Puntuaciones[i]);
		m_visitado_Pasillo5 = Puntuaciones[i];
	}
	for (int i = 25; i < 26; i++) // visitado_Pasillo6
	{
		VISITADO_SALON6.push_back(Puntuaciones[i]);
		m_visitado_Pasillo6 = Puntuaciones[i];
	}
	for (int i = 26; i < 27; i++) // visitado_Pasillo7
	{
		VISITADO_SALON7.push_back(Puntuaciones[i]);
		m_visitado_Pasillo7 = Puntuaciones[i];
	}
	for (int i = 27; i < 28; i++) // visitado_Pasillo8
	{
		VISITADO_PASILLO8.push_back(Puntuaciones[i]);
		m_visitado_Pasillo8 = Puntuaciones[i];
	}
	//fn_nuevaPartida();
	Cargar_Partida->close();
	if (Cargar_Partida)
	{
		cout << "/* C008: (!) RELEASED MEMORY */" << endl;
		delete(Cargar_Partida);
	}
	else
	{
		cout << "/* C009: (!) MEMORYLEAK PROBLEM */" << endl;
	}
}