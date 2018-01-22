#pragma once
#include "Graphics.h"
#include "Goal.h"
#include <math.h>
#include "Platform.h"
class Opponent
{
public:
	Opponent(int xLoc = Graphics::ScreenWidth - 20, int yLoc = Graphics::ScreenHeight - 20, int speed = 2) :xLoc(xLoc), yLoc(yLoc), speed(speed), baseY(yLoc),startingY(yLoc) {};
	~Opponent();

public:
	int xLoc, yLoc;
	int speed;
	static const int xDimension = 19;
	static const int yDimension = 19;
	int jumpLenght = 40;
	int closestToken = 0;
	bool isTokenAtSameLevel = false;
	bool isTokenAtUpperLevel = false;
	bool isPlatformReachable = false;
	bool isItReachableAtLowerLevel = false;
	bool isJumping = false;
	bool isCloseEnough = false;
	int jumpSpeed = 2;
	int baseY;
	int jumpFlag = 0;
	int startingY;
	int  numberOfPlatforms = 8;
public:
	void Draw(Graphics &gfx);
	int findClosestToken(Goal* goals,int numberOfGoals, bool* isGoalTaken) const;
	double getDistance(int x1, int x2, int y1, int y2) const;
	void update(Goal* goals, int numberOfGoals, bool* isGoalTaken, Platform *platform);
	bool ifTokenAtSameLevel(Goal& token) const;
	bool ifTokenAtUpperLevel(Goal& token) const;
	bool ifPlatformReachable(Platform& platform) const;
	bool ifCloseEnough(Platform& platform) const;
	void goAndGet(Goal* goals, int wantedGoal);
	int getXloc();
	int getYloc();
	void setBaseY(int newBaseY);
	void getToThePlatform(Platform& platform);
	void getCloseToPlatform(Platform& platform);
	bool ifItReachableAtLowerLevel(Platform p1, Platform p2)const;
	int findTheRelatedPlatform(Platform *platform);
	



};

