/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"



Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)


{
	for (int n = 0; n < numberOfPlatforms - 4; n++)
		platform[n].init(50 + n * 90, 560 - 25 * n, 50, 0);

	for (int n = 4; n < numberOfPlatforms; n++)
		platform[n].init(50 + n * 90, 560 - 26 * (7 - n), 50, 0);

	for (int n = 0; n < numberOfGoals; n++)
	{
		goals[n].init(platform[n].getXloc() + platform[n].getLength() / 2 - Goal::goalWidth / 2, platform[n].getYloc());
	}
	playerScore.score = 0;
	opponentScore.score = 0;
	/*for (int n = 0; n < numberOfGoals; n++)
	{
		isGoalTaken[n] = true;
	}

	isGoalTaken[7] = false;
	isGoalTaken[5] = false;
	isGoalTaken[2] = false;
	*/
	oldTime = time(NULL);
}

void Game::Go()
{





	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();

}

void Game::UpdateModel()
{

	newTime = time(NULL);

	srand(time(NULL));

	if (newTime - oldTime >= 1)
	{
		int ran = rand() % numberOfGoals;

		if (isGoalTaken[ran] == true)
		{

			isGoalTaken[ran] = false;
			oldTime = newTime;
		}

	}

	playerGround = Graphics::ScreenHeight - 20;
	opponentGround = Graphics::ScreenHeight - 20;

	for (int n = 0; n < numberOfPlatforms; n++)
	{
		if (isCollading(player, platform[n]) && (platform[n].getYloc() - Player::yDimension < playerGround))

			playerGround = platform[n].getYloc() - Player::xDimension;

		if (isCollading(opponent, platform[n]) && (platform[n].getYloc() - Opponent::yDimension < opponentGround))

			opponentGround = platform[n].getYloc() - Opponent::xDimension;
	}



	for (int n = 0; n < numberOfGoals; n++)
	{
		if (goalAndPlayerColliding(player.getXloc(), player.getYloc(), Player::xDimension,
			Player::yDimension, goals[n].getXLoc(), goals[n].getYLoc(), Goal::goalWidth, Goal::goalHeight))
		{
			isGoalTaken[n] = true;
			playerScore.score += 1;
		}
		else if (goalAndPlayerColliding(opponent.getXloc(), opponent.getYloc(), Opponent::xDimension,
			Opponent::yDimension, goals[n].getXLoc(), goals[n].getYLoc(), Goal::goalWidth, Goal::goalHeight))
		{

			isGoalTaken[n] = true;
			opponentScore.score += 1;

		}


	}

	player.setBaseY(playerGround);
	opponent.setBaseY(opponentGround);
	player.updateLoc(wnd.kbd);
	opponent.update(goals, numberOfGoals, isGoalTaken, platform);
}



void Game::ComposeFrame()
{




	for (int n = 0; n < numberOfGoals; n++)
	{

		if (!isGoalTaken[n])

		{
			goals[n].drawGoal(gfx);
		}
	}

	player.drawPlayer(gfx);

	opponent.Draw(gfx);

	opponentScore.draw(opponent, gfx); 

	playerScore.draw(player, gfx);

	for (int n = 0; n < numberOfPlatforms; n++)
	{
		platform[n].drawPlatform(gfx);
	}

}

bool Game::isCollading(Player & player, Platform& platform) const
{
	bool o = (player.getXloc() + Player::xDimension) > platform.getXloc();
	o = o && ((player.getXloc()) < (platform.getXloc() + platform.getLength()));
	o = o && ((player.getYloc() + Player::yDimension) <= platform.getYloc());
	return o;

}

bool Game::isCollading(Opponent & opponent, Platform& platform) const
{
	bool o = (opponent.getXloc() + Opponent::xDimension) > platform.getXloc();
	o = o && ((opponent.getXloc()) < (platform.getXloc() + platform.getLength()));
	o = o && ((opponent.getYloc() + Opponent::yDimension) <= platform.getYloc());
	return o;
}
bool Game::goalAndPlayerColliding(int obj1XLoc, int obj1YLoc, int obj1Length, int obj1Width, int obj2XLoc, int obj2YLoc, int obj2Length, int obj2Width)
{
	return ((obj1XLoc + obj1Length > obj2XLoc) && (obj1XLoc < obj2XLoc + obj2Length) &&
		(obj1YLoc + obj1Width > obj2YLoc - obj2Width) && (obj1YLoc < obj2YLoc));
}
