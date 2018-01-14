#pragma once
#include "Graphics.h"
#include "Goal.h"
class Opponent
{
public:
	Opponent(int xLoc = Graphics::ScreenWidth - 20, int yLoc = Graphics::ScreenHeight - 23, int speed = 3) :xLoc(xLoc), yLoc(yLoc), speed(speed) {};
	~Opponent();

public:
	int xLoc, yLoc;
	int speed;
	static const int xDimension = 19;
	static const int yDimension = 19;
	
public:
	void Draw(Graphics &gfx);
	int findClosestToken(Goal* goals,int numberOfGoals, bool* isGoalTaken) const;
	int getDistance(int x1, int x2, int y1, int y2) const;
	void update(Goal* goals, int numberOfGoals, bool* isGoalTaken);
	bool isTokenAtSameLevel(Goal& token) const;


};

