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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )

	
{
	for (int n = 0; n < numberOfPlatforms-4; n++)
		platform[n].init(50 + n * 90, 560-10*n , 50, 2);

	for (int n = 4; n < numberOfPlatforms ; n++)
		platform[n].init(50 + n * 90, 560 - 10 * (7-n), 50, 2);

	for (int n = 0; n < numberOfGoals; n++)
	{	
		if(!isGoalTaken[n])
		goals[n].init(platform[n].getXloc() + platform[n].getLength() / 2 - Goal::goalWidth / 2, platform[n].getYloc());
	}
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
	if (!gameStarted)
	{
		gfx.BeginFrame();
		cout << "Please Press SPACE to start the game" << endl;
		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			gameStarted = true;
		}
	}
	if (gameStarted)
	{
		ground = Graphics::ScreenHeight - 23;
		for (int n = 0; n < numberOfPlatforms; n++)
		{
			if (isCollading(player, platform[n]) && platform[n].getYloc() - platform[n].getWidth() - Player::yDimension < ground)

				ground = platform[n].getYloc() - Player::yDimension - 2;
		}

		player.setBaseY(ground);
		player.updateLoc(wnd.kbd);

		for (int n = 0; n < numberOfGoals; n++)
		{
			if (goalAndPlayerColliding(player.getXloc(), player.getYloc(), Player::xDimension,
				Player::yDimension, goals[n].getXLoc(), goals[n].getYLoc(), Goal::goalWidth, Goal::goalHeight
			))
				isGoalTaken[n] = true;
		}

	}
}



void Game::ComposeFrame()
{
	if (gameStarted)
	{
		player.drawPlayer(gfx);
		for (int n = 0; n < numberOfPlatforms; n++)
			platform[n].drawPlatform(gfx);

		for (int n = 0; n < numberOfGoals; n++)
		{
			if (!isGoalTaken[n])

			{
				goals[n].drawGoal(gfx);
			}
		}
	}
}

bool Game::isCollading(Player & player, Platform& platform) const
{
	return (((player.getXloc() + Player::xDimension / 2) > platform.getXloc()) && ((player.getXloc() + Player::xDimension / 2) < (platform.getXloc() + platform.getLength())) &&
		((player.getYloc() + Player::yDimension) < platform.getYloc() ));

}

bool Game::goalAndPlayerColliding(int obj1XLoc, int obj1YLoc, int obj1Length, int obj1Width, int obj2XLoc, int obj2YLoc, int obj2Length, int obj2Width)
{
	return ((obj1XLoc + obj1Length > obj2XLoc) && (obj1XLoc < obj2XLoc + obj2Length) &&
		(obj1YLoc + obj1Width > obj2YLoc - obj2Width) && (obj1YLoc < obj2YLoc ));
}
