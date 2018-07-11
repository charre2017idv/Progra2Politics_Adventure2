#pragma once
#include <iostream>
#include <string>
#include "CBar.h"
using namespace std;
class CBall
{
public:
	CBall();
	~CBall();
	CBar Bar;
public:
	// Functions
	void fn_movment();

public:
	// COORDINATES
	int PosX = 0;
	int PosY = 0; 
	int DirX = 5; // Direction X (where the ball is going to move in axis X)
	int DirY = 5; // Direction Y (where the ball is going to move in axis Y)

	// Size of the window (Most be on CScene class)
	long m_bottom;
	long m_right;

	// Size of the bitmap "Ball / Dummie"

	int m_ballSizeX;
	int m_BallSizeY;
	
};

