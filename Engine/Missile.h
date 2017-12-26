#pragma once
#include "Graphics.h"
#include "Keyboard.h"
class Missile
{
public:
	Missile(int xLoc = 0, int yLoc = 0) :xLoc(xLoc), yLoc(yLoc) {};
	~Missile();
	int xLoc, yLoc;
	const int speed = 5,length=5;

public:
	void DrawMissile(Graphics &gfx);
	void UpdateMissile();
};

