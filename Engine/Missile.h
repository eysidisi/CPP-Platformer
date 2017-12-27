#pragma once
#include "Graphics.h"
#include "Keyboard.h"
class Missile
{
public:
	Missile(int xLoc = 0, int yLoc = 0, bool isGoingRight=true) :xLoc(xLoc), yLoc(yLoc), isGoingRight(isGoingRight) 
	{
		if (isGoingRight)
			speed = speedReal;
		else
			speed = -speedReal;
		};
	~Missile();
	int xLoc, yLoc;
	 int speed ,length=5;
	 const int speedReal = 6;
	bool isGoingRight;

public:
	void DrawMissile(Graphics &gfx);
	void UpdateMissile();
};

