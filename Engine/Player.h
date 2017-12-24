#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Game.h"
class Player
{
public:
	Player(int xLoc=0, int yLoc=Graphics::ScreenHeight-23, int speed=5) :x(xLoc), y(yLoc), speed(speed),baseY(yLoc) {};
	~Player();
	void drawPlayer( Graphics &gfx) const;
	void updateLoc(const Keyboard &kbd);
	int getXloc();
	int getYloc();
	void setBaseY( int newBaseY);
static const int xDimension = 20;
static const int yDimension = 20;

private:
	int x, y, speed,baseY, jumpFlag=0,jumpLenght=40,jumpSpeed=2,startingY;
	
	
	
	
};

