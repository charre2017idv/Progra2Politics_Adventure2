#include "CCuartos.h"



CCuartos::CCuartos(string nombreCuarto, string descripcionCuarto, string direccionesCuarto, string accionesCuarto, objetos_Cuarto objetosCuarto)
{
	m_nombreCuarto = nombreCuarto;
	m_descripcionCuarto = descripcionCuarto;
	m_direccionesCuarto = direccionesCuarto;
	m_accionesCuarto = accionesCuarto;
	Item = objetosCuarto;

	Salon_1 = nullptr;
	Salon_2 = nullptr;
	Salon_6 = nullptr;
	Salon_7 = nullptr;
	Salon_10 = nullptr;
	Pasillo_1 = nullptr;
	Pasillo_2 = nullptr;
	Pasillo_3 = nullptr;
	Pasillo_4 = nullptr;
	Pasillo_5 = nullptr;
	Pasillo_6 = nullptr;
	Pasillo_7 = nullptr;
	Pasillo_8 = nullptr;
}


CCuartos::~CCuartos()
{
	if (Salon_1 != nullptr)
		delete(Salon_1);
	if (Salon_2 != nullptr)
		delete(Salon_2);
	if (Salon_6 != nullptr)
		delete(Salon_6);
	if (Salon_7 != nullptr)
		delete(Salon_7);
	if (Salon_10 != nullptr)
		delete(Salon_10);
	if (Pasillo_1 != nullptr)
		delete(Pasillo_1);
	if (Pasillo_2 != nullptr)
		delete(Pasillo_2);
	if (Pasillo_3 != nullptr)
		delete(Pasillo_3);
	if (Pasillo_4 != nullptr)
		delete(Pasillo_4);
	if (Pasillo_5 != nullptr)
		delete(Pasillo_5);
	if (Pasillo_6 != nullptr)
		delete(Pasillo_6);
	if (Pasillo_7 != nullptr)
		delete(Pasillo_7);
	if (Pasillo_8 != nullptr)
		delete(Pasillo_8);

}

// Metodos
void CCuartos::fn_cuartos()
{
	cout << "Nombre del salon: " << m_nombreCuarto << endl;
	//cout << "Descripcion: " << m_descripcionCuarto << endl;
	cout << "Direcciones: " << m_direccionesCuarto << endl;
	cout << "Acciones que se pueden realizar: " << m_accionesCuarto << endl;
}

string CCuartos::Get_Item()
{
	cout << endl;
	cout << "----- INTERACCION -----" << endl;
	cout << endl;
	return Arreglo_Pistas[Item - 1];
}