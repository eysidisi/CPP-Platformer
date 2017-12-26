#pragma once
#include "Graphics.h"
class Goal
{
public:
	Goal(int xLoc = 0, int yLoc = 0) :xLoc(xLoc), yLoc(yLoc) {};
	~Goal();
	void drawGoal(Graphics& gfx);
	void init(int x, int y);
	static constexpr int goalWidth = 10;
	static constexpr int goalHeight = 10;
private:
	int xLoc, yLoc, length=10, width=10;
};

