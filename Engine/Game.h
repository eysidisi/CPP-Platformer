/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once
#include "Player.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Platform.h"
#include "Goal.h"
#include "Opponent.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <ratio>
#include "Score.h"
using namespace std;
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	bool isCollading(Player & player, Platform& platform) const;
	bool isCollading(Opponent & opponent, Platform & platform) const;
	bool goalAndPlayerColliding(int obj1XLoc, int obj1YLoc, int obj1Length, int obj1Width, int obj2XLoc, int obj2YLoc, int obj2Length, int obj2Width);
	Score playerScore, opponentScore;
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	
	/********************************/
	/*  User Variables              */
	Player player;
	Opponent opponent;
	 const int  numberOfPlatforms = 8;
	 const int numberOfGoals = 8;
	Platform platform[8];
	Goal goals[8];
	int playerGround = Graphics::ScreenHeight - 20;
	int opponentGround= Graphics::ScreenHeight - 20;
	bool playerIsCollading = false;
	long int newTime;
	long int oldTime;
	bool isGoalTaken[8] = {false};
	bool gameStarted = false;
	/********************************/
};