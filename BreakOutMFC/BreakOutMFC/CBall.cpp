#include "stdafx.h"
#include "CBall.h"


CBall::CBall()
{
}


CBall::~CBall()
{
}

void CBall::fn_movment()
{
	/* COOLIDER BALL */
	RECT rectA;
	
	/* En el eje Y */
	// Si posY es igual a 0 entonces la direccion sera 5
	if (PosY <= 0)
	{
		DirY = 5;
	}
	/* En el eje X */
	if (PosX <= 0)
	{
		DirX = 5;
	}
	if (PosX > m_right - 64)
	{
		DirX = -5;
	}
	// Si la posy es mayor que el ancho, la direccion de Y sube
	if (PosY > m_bottom - 64)
	{
		// Si la posY es mayor que el ancho de la pantalla
		PosY = 0;
		PosX = 0;
		//m_score -= 1;
		//m_scoreString = to_string(m_score).c_str();
		//UpdateData(FALSE);
		MessageBeep(MB_OK);
	}

	//if (PosY + 64 > m_bottom - 50)
	//{
	//	if (PosX + 32 > Bar.m_xWidth1 && PosX + 32 < Bar.m_xWidth2)
	//	{
	//		DirY = -5;
	//	}
	//}

	PosX += DirX;
	PosY = PosY + DirY;
}
