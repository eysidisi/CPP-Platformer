#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Missile.h"
#include <thread>
#include <chrono>

class Player
{
public:
	Player(int xLoc=0, int yLoc=Graphics::ScreenHeight-23, int speed=3) :x(xLoc), y(yLoc), speed(speed),baseY(yLoc) {};
	~Player();
	void drawPlayer( Graphics &gfx) const;
	void updateLoc(const Keyboard &kbd);
	int getXloc();
	int getYloc();
	void setBaseY( int newBaseY);
static const int xDimension = 20;
static const int yDimension = 20;
Missile* mis[4];
int numberOfMissiles = 4;
bool isMissileFired[4] = { false };
bool isFiringEnabled = true;
int missileCounter = 0;
bool isLookingRight = true;
private:
	int x, y, speed,baseY, jumpFlag=0,jumpLenght=40,jumpSpeed=2,startingY;
	
	
	
	
};

