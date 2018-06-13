#include "CEscenario.h"

CHUD HUD(200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
// Funciones Cuartos - Pasillos
CCuartos Salon_1(string("Salon 1"), string("En este salon se encuentra el representante de Zapopan."), string("Sur"), string("examinar salon , convencer politico"), objetos_Cuarto::PISTA_UNO);
CCuartos Salon_2(string("Salon 2"), string("Actualmente tiene problemas en el paraiso...  (fiscal)"), string("Sur"), string("examinar salon , convencer politico"), objetos_Cuarto::PISTA_DOS);
CCuartos Salon_6(string("Salon 6"), string("Es el 'gran' representante de Guadalajara."), string("Norte"), string("examinar salon , convencer politico"), objetos_Cuarto::PISTA_TRES);
CCuartos Salon_7(string("Salon 7"), string("Esta en su segunda propuesta de campana."), string("Norte"), string("examinar salon , convencer politico"), objetos_Cuarto::PISTA_CUATRO);
CCuartos Salon_10(string("Politics - Shop"), string("Se dice que los duenos vienen de Rusia."), string("Norte"), string("examinar salon , convencer politico"), objetos_Cuarto::PISTA_CINCO);

CCuartos Pasillo_1(string("Pasillo 1"), string("Casilleros alrededor"), string("Norte, Sur, Este"), string("examinar pasillo "), objetos_Cuarto::PISTA_VACIO);
CCuartos Pasillo_2(string("Pasillo 2"), string("Casilleros alrededor."), string("Este, Oeste"), string("examinar pasillo "), objetos_Cuarto::PISTA_VACIO);
CCuartos Pasillo_3(string("Pasillo 3"), string("Casilleros alrededor"), string("Norte, Sur, Este, Oeste"), string("examinar pasillo "), objetos_Cuarto::PISTA_VACIO);
CCuartos Pasillo_4(string("Pasillo 4"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo "), objetos_Cuarto::PISTA_VACIO);
CCuartos Pasillo_5(string("Pasillo 5"), string("Casilleros alrededor"), string("Sur, Este, Oeste"), string("examinar pasillo "), objetos_Cuarto::PISTA_VACIO);
CCuartos Pasillo_6(string("Pasillo 6"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo "), objetos_Cuarto::PISTA_VACIO);
CCuartos Pasillo_7(string("Pasillo 7"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo "), objetos_Cuarto::PISTA_VACIO);
CCuartos Pasillo_8(string("Congreso de postulados"), string("En este lugar se decide quien sera elegido."), string("Oeste"), string("examinar pasillo , convencer politico"), objetos_Cuarto::PISTA_VACIO);

CEscenario::CEscenario()
{
	//m_HUD = nullptr;
	m_SinPolitico = nullptr;
}

CEscenario::~CEscenario()
{
	if (m_SinPolitico != nullptr)
		delete(m_SinPolitico);
}

void CEscenario::fn_historia()
{
	cout << "Campana Electoral 2018" << endl;
	cout << endl;
	cout << "Cada seis anos se hace el cambio de representante presidencial en el congreso electoral, en este lugar, " << endl;
	cout << "los representantes politicos, postulan a su candidato para demostrar cuantos seguidores tienen y cual es su " << endl;
	cout << "propuesta para liderear al pais, antiguos candidatos decidiran si apoyan a ese reprentante o no..." << endl;
	Sleep(3000);
}

void CEscenario::fn_desplazamiento()
{
	if (m_Accion == "ir" && m_Instruccion == "norte")
	{
		if (m_Mapa_Escuela[HUD.m_fila_X - 1][HUD.m_columna_Y] != 0)
			HUD.m_fila_X -= 1;
		else
		{
			cout << endl;
			cout << "Hay una pared, amigo. No creo que puedas atravesarla." << endl;
			cout << endl;
		}
	}
	if (m_Accion == "ir" && m_Instruccion == "sur")
	{
		if (m_Mapa_Escuela[HUD.m_fila_X + 1][HUD.m_columna_Y] != 0)
			HUD.m_fila_X += 1;
		else
		{
			cout << endl;
			cout << "Hay una pared, amigo. No creo que puedas atravesarla." << endl;
			cout << endl;
		}
	}
	if (m_Accion == "ir" && m_Instruccion == "este")
	{
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y + 1] != 0)
			HUD.m_columna_Y += 1;
		else
		{
			cout << endl;
			cout << "Hay una pared, amigo. No creo que puedas atravesarla." << endl;
			cout << endl;
		}
	}
	if (m_Accion == "ir" && m_Instruccion == "oeste")
	{
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y - 1] != 0)
			HUD.m_columna_Y -= 1;
		else
		{
			cout << endl;
			cout << "Hay una pared, amigo. No creo que puedas atravesarla." << endl;
			cout << endl;
		}
	}
}

void CEscenario::fn_cuartos()
{
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 1)
	{
		Salon_1.fn_cuartos();
		CPoliticos Felipe_Calderon(nombre_Politicos::FELIPE_CALDERON, status_Politicos::STATUS_FELIPE);
		cout << Felipe_Calderon.Get_Nombre() << endl;
		cout << Felipe_Calderon.Get_Status() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 1 && HUD.m_visitado_Salon1 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Salon1 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 2)
	{
		Salon_2.fn_cuartos();
		CPoliticos Duarte(nombre_Politicos::DUARTE, status_Politicos::STATUS_DUARTE);
		cout << Duarte.Get_Nombre() << endl;
		cout << Duarte.Get_Status() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 2 && HUD.m_visitado_Salon2 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Salon2 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 6)
	{
		Salon_6.fn_cuartos();
		CPoliticos Fox(nombre_Politicos::FOX, status_Politicos::STATUS_FOX);
		cout << Fox.Get_Nombre() << endl;
		cout << Fox.Get_Status() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 6 && HUD.m_visitado_Salon6 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Salon6 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 7)
	{
		Salon_7.fn_cuartos();
		CPoliticos Margarita(nombre_Politicos::MARGARITA, status_Politicos::STATUS_MARGARTIA);
		cout << Margarita.Get_Nombre() << endl;
		cout << Margarita.Get_Status() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 7 && HUD.m_visitado_Salon7 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Salon7 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10)
	{
		Salon_10.fn_cuartos();
		CPoliticos Carlos(nombre_Politicos::CARLOS_SALINAS, status_Politicos::STATUS_CARLOSS);
		cout << Carlos.Get_Nombre() << endl;
		cout << Carlos.Get_Status() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10 && HUD.m_visitado_Salon10 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Salon10 += 1;

		cout << endl;
		cout << "===============================================================================" << endl;
		cout << "===========             Bienvenido al Politics - Shop              ============" << endl;
		cout << "===============================================================================" << endl;
		cout << "= 1) Si desea comprar CasasBlancas      $600.........\tESCRIBA 'comprar + casablanca'.     =" << endl; // Se agregan 5 puntos al marcador de ganar
		cout << "= 2) Si desea comprar Departamentos     $400.........\tESCRIBA 'comprar + departamento'.    =" << endl; // Se agregan 3 puntos al marcador de ganar
		cout << "= 3) Si desea comprar Autos             $300.........\tESCRIBA 'comprar + auto'.              =" << endl; // Se agregan 2 puntos al marcador de ganar
		cout << "= 4) Si desea comprar Casas Infonavit   $100.........\tESCRIBA 'comprar + casainfonavit'.  =" << endl; // Se agregan 1 punto al marcador de ganar
		cout << "= 5) Si desea hacer Terrenos            $100.........\tESCRIBA 'hacer + terreno'.  =" << endl; // Se agregan 0 punto al marcador de ganar
		cout << "= 6) Si desea obtener fondos            $++.........\tESCRIBA 'hacer + promocion'.  =" << endl; // Se agregan 1 punto al dinero
		cout << "===============================================================================" << endl;
		cout << endl;

		// Comprar Politicos + 5 puntos al marcador de ganar
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10 && m_Accion == "comprar" && m_Instruccion == "casaBlanca" && HUD.m_dinero_Jugador > 0)
		{
			HUD.m_dinero_Jugador -= 600;
			HUD.m_popularidad += 5;
			HUD.m_casasBlancas += 1;
			cout << "/* HAS COMPRADO UNA CASA BLANCA */" << endl;
			cout << "Casas Blancas: " << HUD.m_casasBlancas << endl;
		}
		// Comprar Votos + 3 puntos al marcador de ganar
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10 && m_Accion == "comprar" && m_Instruccion == "departamento" && HUD.m_dinero_Jugador > 0)
		{
			HUD.m_dinero_Jugador -= 400;
			HUD.m_popularidad += 3;
			HUD.m_departamentos += 1;
			cout << "/* HAS COMPRADO UN DEPARTAMENTO */" << endl;
			cout << "Departamentos: " << HUD.m_departamentos << endl;
		}
		// Comprar Cancion + 2 puntos al marcador de ganar
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10 && m_Accion == "comprar" && m_Instruccion == "auto" && HUD.m_dinero_Jugador > 0)
		{
			HUD.m_dinero_Jugador -= 300;
			HUD.m_popularidad += 2;
			HUD.m_Autos += 1;
			cout << "/* HAS COMPRADO UN AUTOMOVIL */" << endl;
			cout << "Autos: " << HUD.m_Autos << endl;
		}
		// Comprar despensas + 1 punto al marcador de ganar
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10 && m_Accion == "comprar" && m_Instruccion == "casasInfonavit" && HUD.m_dinero_Jugador > 0)
		{
			HUD.m_dinero_Jugador -= 100;
			HUD.m_popularidad += 1;
			HUD.m_casasInfonavit += 1;
			cout << "/* HAS COMPRADO UNA CASA DEL INFONAVIT */" << endl;
			cout << "Casas Infonavit: " << HUD.m_casasInfonavit << endl;
		}
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10 && m_Accion == "comprar" && m_Instruccion == "terreno" && HUD.m_dinero_Jugador > 0)
		{
			HUD.m_dinero_Jugador -= 100;
			HUD.m_popularidad += 1;
			HUD.m_terrenos += 1;
			cout << "/* HAS COMPRADO UN TERRENO */" << endl;
			cout << "Terrenos: " << HUD.m_terrenos << endl;
		}
		// cout << "Numero Cuarto: " << Salon_10.numeroHabitacion << endl;
	}
	// Pasillos
	CPoliticos m_SinPolitico(nombre_Politicos::NADIE, status_Politicos::SIN_STATUS);
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 3)
	{
		Pasillo_1.fn_cuartos();
		cout << m_SinPolitico.Get_Nombre() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 3 && HUD.m_visitado_Pasillo1 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Pasillo1 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 4)
	{
		Pasillo_2.fn_cuartos();
		cout << m_SinPolitico.Get_Nombre() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 4 && HUD.m_visitado_Pasillo2 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Pasillo2 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 5)
	{
		Pasillo_3.fn_cuartos();
		cout << m_SinPolitico.Get_Nombre() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 5 && HUD.m_visitado_Pasillo3 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Pasillo3 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 8)
	{
		Pasillo_4.fn_cuartos();
		cout << m_SinPolitico.Get_Nombre() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 8 && HUD.m_visitado_Pasillo4 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Pasillo4 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 9)
	{
		Pasillo_5.fn_cuartos();
		cout << m_SinPolitico.Get_Nombre() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 9 && HUD.m_visitado_Pasillo5 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Pasillo5 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 11)
	{
		Pasillo_6.fn_cuartos();
		cout << m_SinPolitico.Get_Nombre() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 11 && HUD.m_visitado_Pasillo6 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Pasillo6 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 12)
	{
		Pasillo_7.fn_cuartos();
		cout << m_SinPolitico.Get_Nombre() << endl;
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 12 && HUD.m_visitado_Pasillo7 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Pasillo7 += 1;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 13)
	{
		Pasillo_8.fn_cuartos();
		if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 13 && HUD.m_visitado_Pasillo8 <= 0) // Condicion del mapa para mostrarse
			HUD.m_visitado_Pasillo8 += 1;
	}
}

void CEscenario::fn_examinarSalon()
{
	// Salones
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 1 && m_Accion == "examinar" && m_Instruccion == "salon")
		cout << Salon_1.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 2 && m_Accion == "examinar" && m_Instruccion == "salon")
		cout << Salon_2.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 6 && m_Accion == "examinar" && m_Instruccion == "salon")
		cout << Salon_6.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 7 && m_Accion == "examinar" && m_Instruccion == "salon")
		cout << Salon_7.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10 && m_Accion == "examinar" && m_Instruccion == "salon")
		cout << Salon_10.Get_Item() << endl;
	// Pasillos
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 3 && m_Accion == "examinar" && m_Instruccion == "pasillo")
		cout << Pasillo_1.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 4 && m_Accion == "examinar" && m_Instruccion == "pasillo")
		cout << Pasillo_2.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 5 && m_Accion == "examinar" && m_Instruccion == "pasillo")
		cout << Pasillo_3.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 8 && m_Accion == "examinar" && m_Instruccion == "pasillo")
		cout << Pasillo_4.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 9 && m_Accion == "examinar" && m_Instruccion == "pasillo")
		cout << Pasillo_5.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 11 && m_Accion == "examinar" && m_Instruccion == "pasillo")
		cout << Pasillo_6.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 12 && m_Accion == "examinar" && m_Instruccion == "pasillo")
		cout << Pasillo_7.Get_Item() << endl;
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 13 && m_Accion == "examinar" && m_Instruccion == "salon")
		cout << Pasillo_8.Get_Item() << endl;
}

void CEscenario::fn_convencerPolitico()
{
	if (m_Accion == "convencer" && m_Instruccion == "politico")
	{
		cout << endl;
		cout << "----- INTERACCION -----" << endl;
	}
	// Salon 1
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 1 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_dinero_Jugador >= 10 && HUD.m_departamentos >= 2 && HUD.m_terrenos >= 1 && HUD.m_votos_Salon1 <= 0)
	{
		HUD.m_seguidores += 1;
		HUD.m_dinero_Jugador += 50;
		HUD.m_votos_Salon1 += 1;
		cout << endl;
		cout << "/* FELICIDADES TIENES UN NUEVO SEGUIDOR */" << endl;
		cout << "/* Se Otorgan 50 pesos mas al fondo de la campana electoral */" << endl;
		cout << endl;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 1 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_departamentos < 2 && HUD.m_terrenos < 1)
	{
		cout << endl;
		cout << "/* NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA CONVENCER AL POLITICO */" << endl;
		cout << endl;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 1 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_votos_Salon1 >= 1 && HUD.m_departamentos >= 2 && HUD.m_terrenos >= 1)
	{
		cout << endl;
		cout << "/* YA TIENES A ESTE SEGUIDOR */" << endl;
		cout << endl;
	}
	// Salon 2
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 2 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_dinero_Jugador >= 10 && HUD.m_casasBlancas >= 1 && HUD.m_terrenos >= 8 && HUD.m_votos_Salon2 <= 0)
	{
		HUD.m_seguidores += 1;
		HUD.m_dinero_Jugador += 50;
		HUD.m_votos_Salon2 += 1;
		cout << endl;
		cout << "/* FELICIDADES TIENES UN NUEVO SEGUIDOR */" << endl;
		cout << "/* Se Otorgan 50 pesos mas al fondo de la campana electoral */" << endl;
		cout << endl;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 2 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_casasBlancas < 1 && HUD.m_terrenos < 8)
	{
		HUD.m_dinero_Jugador -= 25;
		cout << endl;
		cout << "/* NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA CONVENCER AL POLITICO */" << endl;
		cout << "/* DUARTE TE A ROBADO $25 PESOS.*/" << endl;
		cout << endl;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 2 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_votos_Salon2 >= 1 && HUD.m_casasBlancas >= 1 && HUD.m_terrenos >= 8)
	{
		cout << endl;
		cout << "/* YA TIENES A ESTE SEGUIDOR */" << endl;
		cout << endl;
	}
	// Salon 6 
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 6 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_dinero_Jugador >= 10 && HUD.m_Autos >= 1 && HUD.m_terrenos >= 6 && HUD.m_votos_Salon6 <= 0)
	{
		HUD.m_seguidores += 1;
		HUD.m_dinero_Jugador += 50;
		HUD.m_votos_Salon6 += 1;
		cout << endl;
		cout << "/* FELICIDADES TIENES UN NUEVO SEGUIDOR */" << endl;
		cout << "/* Se Otorgan 50 pesos mas al fondo de la campana electoral */" << endl;
		cout << endl;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 6 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_Autos < 1 && HUD.m_terrenos < 6)
	{
		cout << endl;
		cout << "/* NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA CONVENCER AL POLITICO */" << endl;
		cout << endl;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 6 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_votos_Salon6 >= 1 && HUD.m_Autos >= 1 && HUD.m_terrenos >= 6)
	{
		cout << endl;
		cout << "/* YA TIENES A ESTE SEGUIDOR */" << endl;
		cout << endl;
	}
	// Salon 7
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 7 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_dinero_Jugador >= 10 && HUD.m_departamentos >= 4 && HUD.m_casasInfonavit >= 5 && HUD.m_votos_Salon7 <= 0)
	{
		HUD.m_seguidores += 1;
		HUD.m_dinero_Jugador += 50;
		HUD.m_votos_Salon7 += 1;
		cout << endl;
		cout << "/* FELICIDADES TIENES UN NUEVO SEGUIDOR */" << endl;
		cout << "/* Se Otorgan 50 pesos mas al fondo de la campana electoral */" << endl;
		cout << endl;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 7 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_departamentos < 4 && HUD.m_casasInfonavit < 5)
	{
		cout << endl;
		cout << "/* NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA CONVENCER AL POLITICO */" << endl;
		cout << endl;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 7 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_votos_Salon7 >= 1 && HUD.m_departamentos >= 4 && HUD.m_casasInfonavit >= 5)
	{
		cout << endl;
		cout << "/* YA TIENES A ESTE SEGUIDOR */" << endl;
		cout << endl;
	}
	// Salon 10
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_dinero_Jugador >= 10 && HUD.m_casasBlancas >= 1 && HUD.m_casasInfonavit >= 1 && HUD.m_departamentos >= 1 && HUD.m_Autos >= 1 && HUD.m_terrenos >= 1 && HUD.m_votos_Salon10 <= 0)
	{
		HUD.m_seguidores += 1;
		HUD.m_dinero_Jugador += 50;
		HUD.m_votos_Salon10 += 1;
		cout << endl;
		cout << "/* FELICIDADES TIENES UN NUEVO SEGUIDOR */" << endl;
		cout << "/* Se Otorgan 50 pesos mas al fondo de la campana electoral */" << endl;
		cout << endl;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_casasBlancas < 1 && HUD.m_casasInfonavit < 1 && HUD.m_departamentos < 1 && HUD.m_Autos < 1 && HUD.m_terrenos < 1)
	{
		cout << endl;
		cout << "/* NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA CONVENCER AL POLITICO */" << endl;
		cout << endl;
	}
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 10 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_votos_Salon10 >= 1 && HUD.m_casasBlancas >= 1 && HUD.m_casasInfonavit >= 1 && HUD.m_departamentos >= 1 && HUD.m_Autos >= 1 && HUD.m_terrenos >= 1)
	{
		cout << endl;
		cout << "/* YA TIENES A ESTE SEGUIDOR */" << endl;
		cout << endl;
	}
	// Congreso de postulados
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 13 && m_Accion == "convencer" && m_Instruccion == "politico" && HUD.m_popularidad <= 100 && HUD.m_seguidores <= 3)
	{
		cout << "/*  NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA SER ELEGIDO COMO REPRESENTANTE. */" << endl;
	}

}

void CEscenario::fn_salir()
{
	if (m_Accion == "salir" && m_Instruccion == "juego")
		exit(1);
}

void CEscenario::fn_promocion()
{
	if (m_Accion == "hacer" && m_Instruccion == "promocion")
		HUD.m_dinero_Jugador += 150;
}

void CEscenario::fn_accion()
{
	cout << "--------------------------------------------" << endl;
	cout << "Escribe la accion que quieras realizar:" << endl;
	cout << "(?) Como jugar, tecle 'como jugar'." << endl;
	cout << "(?) Ayuda, tecle 'ver instrucciones'." << endl;
	cout << "> ";
	cin >> m_Accion >> m_Instruccion;
	cout << "____________________________________________" << endl;
	cout << endl;
}

void CEscenario::fn_mapa()
{
	// Mapa
	if (m_Accion == "ver" && m_Instruccion == "mapa")
	{
		cout << endl;
		cout << "-----    MAPA DE LAS INSTALACIONES     -----" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (m_Mapa_Escuela[i][j] == 1 && HUD.m_visitado_Salon1 >= 1)
				{
					cout << "S1    ";
					if (HUD.m_visitado_Salon1 <= 0)
						cout << "      ";
				}
				if (m_Mapa_Escuela[i][j] == 2 && HUD.m_visitado_Salon2 >= 1)
				{
					cout << "S2";
					if (HUD.m_visitado_Salon2 <= 0)
						cout << "  ";
				}
				if (m_Mapa_Escuela[i][j] == 6 && HUD.m_visitado_Salon6 >= 1)
				{
					cout << "S6    ";
					if (HUD.m_visitado_Salon6 <= 0)
						cout << "      ";
				}
				if (m_Mapa_Escuela[i][j] == 7 && HUD.m_visitado_Salon7 >= 1)
				{
					if (HUD.m_visitado_Salon6 <= 0)
						cout << "      S7";
					if (HUD.m_visitado_Salon6 >= 1)
						cout << "S7";
					if (HUD.m_visitado_Salon7 <= 0)
						cout << "      ";
				}
				if (m_Mapa_Escuela[i][j] == 10 && HUD.m_visitado_Salon10 >= 1)
				{

					if (HUD.m_visitado_Salon7 >= 1)
						cout << "    S10";
					if (HUD.m_visitado_Salon6 >= 1 && HUD.m_visitado_Salon7 <= 0)
						cout << "      S10";
					if (HUD.m_visitado_Salon6 <= 0 && HUD.m_visitado_Salon7 <= 0)
						cout << "            S10";
					if (HUD.m_visitado_Salon10 <= 0)
						cout << "  ";
				}
				if (m_Mapa_Escuela[i][j] == 3 && HUD.m_visitado_Pasillo1 >= 1)
				{
					cout << "P1";
					if (HUD.m_visitado_Pasillo1 <= 0)
						cout << "  ";
				}
				if (m_Mapa_Escuela[i][j] == 4 && HUD.m_visitado_Pasillo2 >= 1)
				{
					cout << " P2 ";
					if (HUD.m_visitado_Pasillo2 <= 0)
						cout << "    ";
				}
				if (m_Mapa_Escuela[i][j] == 5 && HUD.m_visitado_Pasillo3 >= 1)
				{
					cout << "P3";
					if (HUD.m_visitado_Pasillo3 <= 0)
						cout << "  ";
				}
				if (m_Mapa_Escuela[i][j] == 8 && HUD.m_visitado_Pasillo4 >= 1)
				{
					cout << " P4 ";
					if (HUD.m_visitado_Pasillo4 <= 0)
						cout << "    ";
				}
				if (m_Mapa_Escuela[i][j] == 9 && HUD.m_visitado_Pasillo5 >= 1)
				{
					cout << "P5";
					if (HUD.m_visitado_Pasillo5 <= 0)
						cout << "  ";
				}
				if (m_Mapa_Escuela[i][j] == 11 && HUD.m_visitado_Pasillo6 >= 1)
				{
					cout << " P6 ";
					if (HUD.m_visitado_Pasillo6 <= 0)
						cout << "    ";
				}
				if (m_Mapa_Escuela[i][j] == 12 && HUD.m_visitado_Pasillo7 >= 1)
				{
					cout << "P7";
					if (HUD.m_visitado_Pasillo7 <= 0)
						cout << "  ";
				}
				if (m_Mapa_Escuela[i][j] == 13 && HUD.m_visitado_Pasillo8 >= 1)
				{
					cout << " CP";
					if (HUD.m_visitado_Pasillo8 <= 0)
						cout << "   ";
				}
			}
			cout << "\n";
		}
		// Descripciones Salones
		if (HUD.m_visitado_Salon1 >= 1)
			cout << "S1 = Salon 1 (En el salon se encuentra un objeto y una persona)." << endl;
		if (HUD.m_visitado_Salon2 >= 1)
			cout << "S2 = Salon 2 (En el salon se encuentra un objeto y una persona)." << endl;
		if (HUD.m_visitado_Salon6 >= 1)
			cout << "S6 = Salon 6 (En el salon se encuentra un objeto y una persona)." << endl;
		if (HUD.m_visitado_Salon7 >= 1)
			cout << "S7 = Salon 7 (En el salon se encuentra un objeto y una persona)." << endl;
		if (HUD.m_visitado_Salon10 >= 1)
			cout << "PS = PoliticShop (Tienda) (En el salon se encuentra un objeto y una persona)." << endl;

		if (HUD.m_visitado_Pasillo1 >= 1)
			cout << "P1 = Pasillo 1 (En el pasillo no tiene objetos)." << endl;
		if (HUD.m_visitado_Pasillo2 >= 1)
			cout << "P2 = Pasillo 2 (En el pasillo no tiene objetos)." << endl;
		if (HUD.m_visitado_Pasillo3 >= 1)
			cout << "P3 = Pasillo 3 (En el pasillo no tiene objetos)." << endl;
		if (HUD.m_visitado_Pasillo4 >= 1)
			cout << "P4 = Pasillo 4 (En el pasillo no tiene objetos)." << endl;
		if (HUD.m_visitado_Pasillo5 >= 1)
			cout << "S5 = Pasillo 5 (En el pasillo no tiene objetos)." << endl;
		if (HUD.m_visitado_Pasillo6 >= 1)
			cout << "S6 = Pasillo 6 (En el pasillo no tiene objetos)." << endl;
		if (HUD.m_visitado_Pasillo7 >= 1)
			cout << "S7 = Pasillo 7 (En el pasillo no tiene objetos)." << endl;
		if (HUD.m_visitado_Pasillo8 >= 1)
			cout << "CP = Congreso de Postulados (En el pasillo no tiene objetos)." << endl;
	}
}

void CEscenario::fn_guardarPartida()
{
	if (m_Accion == "guardar" && m_Instruccion == "partida")
		HUD.fn_guardarPartida();
}

void CEscenario::fn_nuevaPartida()
{
	while (true)
	{
		system("cls");
		cout << "------  DATOS INSTALACIONES  ------" << endl;
		cout << endl;
		fn_desplazamiento();
		fn_cuartos();
		fn_promocion();
		fn_examinarSalon();
		fn_convencerPolitico();
		fn_mapa();
		fn_ganar();
		fn_perder();
		HUD.HUD();
		fn_guardarPartida();
		fn_accion();
		fn_salir();
	}
}

void CEscenario::fn_cargarPartida()
{
	HUD.fn_cargarPartida();
	fn_nuevaPartida();
}

void CEscenario::fn_ganar()
{
	if (m_Mapa_Escuela[HUD.m_fila_X][HUD.m_columna_Y] == 13 && m_Accion == "convencer" && m_Instruccion == "publico" && HUD.m_seguidores > 4)
	{
		cout << endl;
		cout << "/* FELICIDADES HAS SIDO ELEGIDO COMO PRESIDENTE.*/" << endl;
		cout << endl;
		HUD.fn_guardarPartida();
		Sleep(100000);
		exit(1);
	}
}

void CEscenario::fn_perder()
{
	if (HUD.m_dinero_Jugador <= 0)
	{
		cout << endl;
		cout << "/* TE HAS QUEDADO SIN FONDOS.*/" << endl;
		cout << "    /* GRACIAS POR JUGAR*/" << endl;
		cout << endl;
		HUD.fn_guardarPartida();
		Sleep(100000);
		exit(1);
	}
}

void CEscenario::fn_world()
{
	cout << "==================================" << endl;
	cout << "=====     MENU PRINCIPAL     =====" << endl;
	cout << "==================================" << endl;
	cout << "= > 1) Nueva Partida             =" << endl;
	cout << "= > 2) Cargar partida            =" << endl;
	cout << "= > 0) Salir                     =" << endl;
	cout << "==================================" << endl;
	cout << "Tecle la accion que quiera realizar:" << endl;
	cout << "> ";
	cin >> m_OpcionesMenu;
	cout << endl;
	system("cls");
	if (m_OpcionesMenu == "0" || m_OpcionesMenu == "salir")
	{ // Se sale del juego (programa)
		cout << "/* GRACIAS POR JUGAR */" << endl;
		Sleep(6000);
		exit(1);
	}
	else if (m_OpcionesMenu == "1" || m_OpcionesMenu == "nueva_partida")
	{ // Se creara una nueva partida
		fn_historia();
		cout << endl;
		fn_nuevaPartida();
	}
	else if (m_OpcionesMenu == "2" || m_OpcionesMenu == "cargar_partida")
	{ // En esta seccion se abrira el nuevo archivo creado con la nueva informacion que se almaceno
		fn_cargarPartida();
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "C0001: (!) Comando incorrecto, posible error de escritura: " << m_OpcionesMenu << endl;
		cout << endl;
	}
}