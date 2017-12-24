#pragma once
#include "Graphics.h"
#include "Keyboard.h"
class Missile
{
public:
	Missile();
	~Missile();


private:
	int xLoc, yLoc;
	const int speed = 5,length=5;

public:
	void DrawMissile(Graphics &gfx);
	void UpdateMissile(const Keyboard &kbd);
};

