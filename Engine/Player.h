#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Missile.h"
#include <thread>
#include <chrono>

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
Missile* mis1,* mis2,* mis3;
bool isMissile1Fired = false, isMissile2Fired = false, isMissile3Fired = false;
int missileCounter = 0;
private:
	int x, y, speed,baseY, jumpFlag=0,jumpLenght=40,jumpSpeed=2,startingY;
	
	
	
	
};

