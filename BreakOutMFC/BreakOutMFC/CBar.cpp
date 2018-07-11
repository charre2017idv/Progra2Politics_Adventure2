#include "stdafx.h"
#include "CBar.h"


CBar::CBar()
{
}


CBar::~CBar()
{
}

void CBar::fn_movment(int x)
{
	m_xWidth1 = x - 50;
	m_xWidth2 = x + 50;
	// Stop in left
	if (m_xWidth1 < m_leftSideBar)
	{
		m_xWidth1 = m_leftSideBar;
		m_xWidth2 = m_xWidth1 + 100;
	}
	// Stop in right
	else if (m_xWidth2 > m_rightSideBar)
	{
		m_xWidth2 = m_rightSideBar;
		m_xWidth1 = m_xWidth2 - 100;
	}
}