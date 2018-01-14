#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Missile.h"
#include <thread>
#include <chrono>

class Player
{
public:
	Player(int xLoc=0, int yLoc=Graphics::ScreenHeight-20, int speed=3) :x(xLoc), y(yLoc), speed(speed),baseY(yLoc) {};
	~Player();
	void drawPlayer( Graphics &gfx) const;
	void updateLoc(const Keyboard &kbd);
	int getXloc();
	int getYloc();
	void setBaseY( int newBaseY);
static const int xDimension = 19;
static const int yDimension = 19;
Missile* mis[5];
int numberOfMissiles = 5;
bool isMissileFired[5] = { false };
bool isFiringEnabled = true;
int missileCounter = 0;
bool isLookingRight = true;
private:
	int x, y, speed,baseY, jumpFlag=0,jumpLenght=40,jumpSpeed=2,startingY;
	
	
	
	
};

