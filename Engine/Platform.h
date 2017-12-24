#pragma once
#include "Graphics.h"
class Platform
{
public:
	Platform()  {};
	~Platform();

private:
	int xLoc, yLoc, length, width;

public:
	void drawPlatform(Graphics& gfx) const;
	int getXloc();
	int getYloc();
	int getLength();
	int getWidth();
	void init(int xLocl, int yLocl, int lengthl, int widthl);
	
};

