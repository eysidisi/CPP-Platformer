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
	ground = Graphics::ScreenHeight - 23;
	for (int n = 0; n < numberOfPlatforms; n++)
	{
		if (isCollading(player, platform[n]) && platform[n].getYloc() - platform[n].getWidth() - Player::yDimension < ground)

			ground = platform[n].getYloc()  - Player::yDimension-2;
	}

	 

	player.setBaseY(ground);
	player.updateLoc(wnd.kbd);

	if (isPlayerFired)
		(*playerMissile).UpdateMissile();
	
		
}



void Game::ComposeFrame()
{
	player.drawPlayer(gfx);

	for (int n = 0; n < numberOfPlatforms; n++)
		platform[n].drawPlatform(gfx);

	if (isPlayerFired)
		(*playerMissile).DrawMissile(gfx);
	
}

bool Game::isCollading(Player & player, Platform& platform) const
{
	return (((player.getXloc() + Player::xDimension / 2) > platform.getXloc()) && ((player.getXloc() + Player::xDimension / 2) < (platform.getXloc() + platform.getLength())) &&
		((player.getYloc() + Player::yDimension) < platform.getYloc() ));

}