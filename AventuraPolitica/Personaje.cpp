#include "Personaje.h"



Personaje::Personaje()
{

}


Personaje::~Personaje()
{
}

void Personaje::fn_norte()
{
	if (Mapa_Escuela[fila_X - 1][columna_Y] != 0)
	{
		fila_X -= 1;
	}
	else
	{
		cout << endl;
		cout << "Hay una pared, amigo. No creo que puedas atravesarla." << endl;
		cout << endl;
	}
}
void Personaje::fn_sur()
{
	if (Mapa_Escuela[fila_X + 1][columna_Y] != 0)
	{
		fila_X += 1;
	}
	else
	{
		cout << endl;
		cout << "Hay una pared, amigo. No creo que puedas atravesarla." << endl;
		cout << endl;
	}
}
void Personaje::fn_este()
{
	if (Mapa_Escuela[fila_X][columna_Y + 1] != 0)
	{
		columna_Y += 1;
	}
	else
	{
		cout << endl;
		cout << "Hay una pared, amigo. No creo que puedas atravesarla." << endl;
		cout << endl;
	}
}
void Personaje::fn_oeste()
{
	if (Mapa_Escuela[fila_X][columna_Y - 1] != 0)
	{
		columna_Y -= 1;
	}
	else
	{
		cout << endl;
		cout << "Hay una pared, amigo. No creo que puedas atravesarla." << endl;
		cout << endl;
	}
}


