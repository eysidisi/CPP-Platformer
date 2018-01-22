#include "Opponent.h"
Opponent::~Opponent()
{
}

void Opponent::update(Goal* goals, int numberOfGoals, bool* isGoalTaken, Platform *platform)
{	//jump code
	
		if (isJumping&& jumpFlag == 0)						//---------
		{											//---------
			jumpFlag = 1;							//---------
			startingY = yLoc;
		}											//---------
													//---------
		if (jumpFlag == 1)							//---------
		{											//---------
			if (yLoc >= (startingY - jumpLenght))		//---------
				yLoc -= jumpSpeed;	
							//---------
			else									
				jumpFlag = 2;						
		}											
													
		if (jumpFlag == 2)							
		{											
			if (yLoc < baseY)
			{
				yLoc += jumpSpeed;
				if (yLoc > baseY)
					yLoc = baseY;
			}
			else									
			{
				jumpFlag = 0;
				isJumping = false;
				if (yLoc + Opponent::yDimension > Graphics::ScreenHeight)
					yLoc = Graphics::ScreenHeight - Opponent::yDimension - 1;
				startingY = yLoc;
			}										//---------
		}											//---------
													//---------
													//---------
													//---------
		if (jumpFlag == 0 && baseY > yLoc)			//---------
			jumpFlag = 2;							//---------
													//----------------------------------------

	

	closestToken=findClosestToken(goals, numberOfGoals, isGoalTaken);
	isTokenAtSameLevel = ifTokenAtSameLevel(goals[closestToken]);

	if (isTokenAtSameLevel)
	{
		goAndGet(goals, closestToken);
	}

	if (!isTokenAtSameLevel)
	{
		isTokenAtUpperLevel = ifTokenAtUpperLevel(goals[closestToken]);
		
		if (isTokenAtUpperLevel)
		{
			isPlatformReachable = ifPlatformReachable(platform[closestToken]);

			if (isPlatformReachable)
			{
				isCloseEnough = ifCloseEnough(platform[closestToken]);

				if (isCloseEnough)
				{	
					isJumping = true;

					getToThePlatform(platform[closestToken]);

				}

				if (!isCloseEnough)
				{
					getCloseToPlatform(platform[closestToken]);
				}
			}

			if (!isPlatformReachable)
			{
				int tagettedPlatform = closestToken;

				if (baseY == Graphics::ScreenHeight - 20 && (startingY== Graphics::ScreenHeight - 20))
				{
					if (closestToken > 3)
					{
						if (ifCloseEnough(platform[7]))
						{
							isJumping = true;

							getToThePlatform(platform[7]);

						}

						else if (!ifCloseEnough(platform[7]))
						{
							getCloseToPlatform(platform[7]);
						}
					}

					else if (closestToken <= 3)
					{
						if (ifCloseEnough(platform[0]))
						{
							isJumping = true;

							getToThePlatform(platform[0]);

						}

						else if (!ifCloseEnough(platform[0]))
						{
							getCloseToPlatform(platform[0]);
						}

					}

				}

				else	if (closestToken < 4 && (findTheRelatedPlatform(platform) < 4))
				{
					while (ifPlatformReachable(platform[tagettedPlatform]) == false)
						tagettedPlatform -= 1;
					
					if (ifCloseEnough(platform[tagettedPlatform]))
					{
						isJumping = true;

						getToThePlatform(platform[tagettedPlatform]);
						
					}

					else if (!ifCloseEnough(platform[tagettedPlatform]))
					{
						getCloseToPlatform(platform[tagettedPlatform]);
					}

				}

				else if (closestToken < 4 && (findTheRelatedPlatform(platform) >= 5))
				{
					while (ifPlatformReachable(platform[tagettedPlatform]) == false)
						tagettedPlatform += 1;

					if (ifCloseEnough(platform[tagettedPlatform]))
					{
						isJumping = true;

						getToThePlatform(platform[tagettedPlatform]);

					}

					else if (!ifCloseEnough(platform[tagettedPlatform]))
					{
						getCloseToPlatform(platform[tagettedPlatform]);
					}
				}

				else if (closestToken >= 4 && (findTheRelatedPlatform(platform) < 4))
				{
					while (ifPlatformReachable(platform[tagettedPlatform]) == false)
						tagettedPlatform -= 1;

					if (ifCloseEnough(platform[tagettedPlatform]))
					{
						isJumping = true;

						getToThePlatform(platform[tagettedPlatform]);

					}

					else if (!ifCloseEnough(platform[tagettedPlatform]))
					{
						getCloseToPlatform(platform[tagettedPlatform]);
					}
				}

				else if(closestToken >= 4 && (findTheRelatedPlatform(platform) >= 5))
				{
					while (ifPlatformReachable(platform[tagettedPlatform]) == false)
						tagettedPlatform += 1;

					if (ifCloseEnough(platform[tagettedPlatform]))
					{
						isJumping = true;

						getToThePlatform(platform[tagettedPlatform]);

					}

					else if (!ifCloseEnough(platform[tagettedPlatform]))
					{
						getCloseToPlatform(platform[tagettedPlatform]);
					}
				}
			}
		}
		else                                            //Token is at lower level
		{
			isItReachableAtLowerLevel = ifItReachableAtLowerLevel(platform[findTheRelatedPlatform(platform)],platform[closestToken]);
			
			if (isItReachableAtLowerLevel)
			{
				isJumping = true;

				getToThePlatform(platform[closestToken]);

			}

			if(!isItReachableAtLowerLevel)
			{
				int tagettedPlatform = closestToken;
				if (closestToken < 4 && (findTheRelatedPlatform(platform) < 4))
				{
					while (ifItReachableAtLowerLevel(platform[findTheRelatedPlatform(platform)],platform[tagettedPlatform]) == false)
						tagettedPlatform += 1;

					if (ifCloseEnough(platform[tagettedPlatform]))
					{
						isJumping = true;

						getToThePlatform(platform[tagettedPlatform]);

					}

					else if (!ifCloseEnough(platform[tagettedPlatform]))
					{
						getCloseToPlatform(platform[tagettedPlatform]);
					}

				}
				else if (closestToken < 4 && (findTheRelatedPlatform(platform) >= 4))
				{
					while (ifItReachableAtLowerLevel(platform[findTheRelatedPlatform(platform)], platform[tagettedPlatform]) == false)
						tagettedPlatform += 1;

					if (ifCloseEnough(platform[tagettedPlatform]))
					{
						isJumping = true;

						getToThePlatform(platform[tagettedPlatform]);

					}

					else if (!ifCloseEnough(platform[tagettedPlatform]))
					{
						getCloseToPlatform(platform[tagettedPlatform]);
					}
				}

				else if (closestToken >= 4 && (findTheRelatedPlatform(platform) < 4))
				{
					while (ifItReachableAtLowerLevel(platform[findTheRelatedPlatform(platform)], platform[tagettedPlatform]) == false)
						tagettedPlatform -= 1;

					if (ifCloseEnough(platform[tagettedPlatform]))
					{
						isJumping = true;

						getToThePlatform(platform[tagettedPlatform]);

					}

					else if (!ifCloseEnough(platform[tagettedPlatform]))
					{
						getCloseToPlatform(platform[tagettedPlatform]);
					}
				}
			
				else if (closestToken >= 4 && (findTheRelatedPlatform(platform) >= 4))
				{
					while (ifItReachableAtLowerLevel(platform[findTheRelatedPlatform(platform)], platform[tagettedPlatform]) == false)
						tagettedPlatform -= 1;

					if (ifCloseEnough(platform[tagettedPlatform]))
					{
						isJumping = true;

						getToThePlatform(platform[tagettedPlatform]);

					}

					else if (!ifCloseEnough(platform[tagettedPlatform]))
					{
						getCloseToPlatform(platform[tagettedPlatform]);
					}
				}
			}
		}
	}

	if (yLoc + Opponent::yDimension > Graphics::ScreenHeight )
		yLoc = Graphics::ScreenHeight - Opponent::yDimension - 1;
}

bool Opponent::ifTokenAtSameLevel(Goal & token) const
{

	return (token.getYLoc()==yLoc+Opponent::yDimension);
}

bool Opponent::ifTokenAtUpperLevel(Goal & token) const
{
	return (token.getYLoc()<startingY+Opponent::xDimension);
}

bool Opponent::ifPlatformReachable(Platform & platform) const
{
	return ((startingY - jumpLenght + Opponent::yDimension) < platform.getYloc());
}

bool Opponent::ifCloseEnough(Platform & platform) const
{
	return ((abs(xLoc + Opponent::xDimension / 2 - platform.getXloc()) <= 40) || (abs(xLoc + Opponent::xDimension / 2 - platform.getXloc() - platform.getLength()) <= 40));
	
}

void Opponent::goAndGet(Goal * goals, int wantedGoal) 
{
	if (xLoc > goals[wantedGoal].getXLoc())
		xLoc = xLoc - speed;
	else
		xLoc = xLoc + speed;
}

void Opponent::Draw(Graphics &gfx)
{
	gfx.PutPixel(7 + xLoc, 0 + yLoc, 0, 0, 0);
	gfx.PutPixel(8 + xLoc, 0 + yLoc, 0, 0, 0);
	gfx.PutPixel(9 + xLoc, 0 + yLoc, 0, 0, 0);
	gfx.PutPixel(10 + xLoc, 0 + yLoc, 0, 0, 0);
	gfx.PutPixel(11 + xLoc, 0 + yLoc, 0, 0, 0);
	gfx.PutPixel(12 + xLoc, 0 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 1 + yLoc, 0, 0, 0);
	gfx.PutPixel(6 + xLoc, 1 + yLoc, 0, 0, 0);
	gfx.PutPixel(7 + xLoc, 1 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 1 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 1 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 1 + yLoc, 50, 200, 88);
	gfx.PutPixel(11 + xLoc, 1 + yLoc, 50, 200, 88);
	gfx.PutPixel(12 + xLoc, 1 + yLoc, 50, 200, 88);
	gfx.PutPixel(13 + xLoc, 1 + yLoc, 0, 0, 0);
	gfx.PutPixel(14 + xLoc, 1 + yLoc, 0, 0, 0);
	gfx.PutPixel(3 + xLoc, 2 + yLoc, 0, 0, 0);
	gfx.PutPixel(4 + xLoc, 2 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 2 + yLoc, 50, 200, 88);
	gfx.PutPixel(6 + xLoc, 2 + yLoc, 50, 200, 88);
	gfx.PutPixel(7 + xLoc, 2 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 2 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 2 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 2 + yLoc, 50, 200, 88);
	gfx.PutPixel(11 + xLoc, 2 + yLoc, 50, 200, 88);
	gfx.PutPixel(12 + xLoc, 2 + yLoc, 50, 200, 88);
	gfx.PutPixel(13 + xLoc, 2 + yLoc, 50, 200, 88);
	gfx.PutPixel(14 + xLoc, 2 + yLoc, 50, 200, 88);
	gfx.PutPixel(15 + xLoc, 2 + yLoc, 0, 0, 0);
	gfx.PutPixel(16 + xLoc, 2 + yLoc, 0, 0, 0);
	gfx.PutPixel(2 + xLoc, 3 + yLoc, 0, 0, 0);
	gfx.PutPixel(3 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(4 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(5 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(6 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(7 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(11 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(12 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(13 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(14 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(15 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(16 + xLoc, 3 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 3 + yLoc, 0, 0, 0);
	gfx.PutPixel(2 + xLoc, 4 + yLoc, 0, 0, 0);
	gfx.PutPixel(3 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(4 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(5 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(6 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(7 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(11 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(12 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(13 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(14 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(15 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(16 + xLoc, 4 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 4 + yLoc, 0, 0, 0);
	gfx.PutPixel(1 + xLoc, 5 + yLoc, 0, 0, 0);
	gfx.PutPixel(2 + xLoc, 5 + yLoc, 50, 200, 88);
	gfx.PutPixel(3 + xLoc, 5 + yLoc, 0, 0, 0);
	gfx.PutPixel(4 + xLoc, 5 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 5 + yLoc, 50, 200, 88);
	gfx.PutPixel(6 + xLoc, 5 + yLoc, 50, 200, 88);
	gfx.PutPixel(7 + xLoc, 5 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 5 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 5 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 5 + yLoc, 50, 200, 88);
	gfx.PutPixel(11 + xLoc, 5 + yLoc, 0, 0, 0);
	gfx.PutPixel(12 + xLoc, 5 + yLoc, 0, 0, 0);
	gfx.PutPixel(13 + xLoc, 5 + yLoc, 0, 0, 0);
	gfx.PutPixel(14 + xLoc, 5 + yLoc, 0, 0, 0);
	gfx.PutPixel(15 + xLoc, 5 + yLoc, 50, 200, 88);
	gfx.PutPixel(16 + xLoc, 5 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 5 + yLoc, 50, 200, 88);
	gfx.PutPixel(18 + xLoc, 5 + yLoc, 0, 0, 0);
	gfx.PutPixel(1 + xLoc, 6 + yLoc, 0, 0, 0);
	gfx.PutPixel(2 + xLoc, 6 + yLoc, 0, 0, 0);
	gfx.PutPixel(3 + xLoc, 6 + yLoc, 255, 255, 255);
	gfx.PutPixel(4 + xLoc, 6 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 6 + yLoc, 0, 0, 0);
	gfx.PutPixel(6 + xLoc, 6 + yLoc, 50, 200, 88);
	gfx.PutPixel(7 + xLoc, 6 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 6 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 6 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 6 + yLoc, 0, 0, 0);
	gfx.PutPixel(11 + xLoc, 6 + yLoc, 255, 255, 255);
	gfx.PutPixel(12 + xLoc, 6 + yLoc, 255, 255, 255);
	gfx.PutPixel(13 + xLoc, 6 + yLoc, 0, 0, 0);
	gfx.PutPixel(14 + xLoc, 6 + yLoc, 0, 0, 0);
	gfx.PutPixel(15 + xLoc, 6 + yLoc, 0, 0, 0);
	gfx.PutPixel(16 + xLoc, 6 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 6 + yLoc, 50, 200, 88);
	gfx.PutPixel(18 + xLoc, 6 + yLoc, 0, 0, 0);
	gfx.PutPixel(0 + xLoc, 7 + yLoc, 0, 0, 0);
	gfx.PutPixel(1 + xLoc, 7 + yLoc, 0, 0, 0);
	gfx.PutPixel(2 + xLoc, 7 + yLoc, 255, 255, 255);
	gfx.PutPixel(3 + xLoc, 7 + yLoc, 255, 255, 255);
	gfx.PutPixel(4 + xLoc, 7 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 7 + yLoc, 0, 0, 0);
	gfx.PutPixel(6 + xLoc, 7 + yLoc, 50, 200, 88);
	gfx.PutPixel(7 + xLoc, 7 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 7 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 7 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 7 + yLoc, 0, 0, 0);
	gfx.PutPixel(11 + xLoc, 7 + yLoc, 255, 255, 255);
	gfx.PutPixel(12 + xLoc, 7 + yLoc, 255, 255, 255);
	gfx.PutPixel(13 + xLoc, 7 + yLoc, 0, 0, 0);
	gfx.PutPixel(14 + xLoc, 7 + yLoc, 0, 0, 0);
	gfx.PutPixel(15 + xLoc, 7 + yLoc, 0, 0, 0);
	gfx.PutPixel(16 + xLoc, 7 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 7 + yLoc, 50, 200, 88);
	gfx.PutPixel(18 + xLoc, 7 + yLoc, 50, 200, 88);
	gfx.PutPixel(19 + xLoc, 7 + yLoc, 0, 0, 0);
	gfx.PutPixel(0 + xLoc, 8 + yLoc, 0, 0, 0);
	gfx.PutPixel(1 + xLoc, 8 + yLoc, 0, 0, 0);
	gfx.PutPixel(2 + xLoc, 8 + yLoc, 255, 255, 255);
	gfx.PutPixel(3 + xLoc, 8 + yLoc, 255, 255, 255);
	gfx.PutPixel(4 + xLoc, 8 + yLoc, 255, 255, 255);
	gfx.PutPixel(5 + xLoc, 8 + yLoc, 0, 0, 0);
	gfx.PutPixel(6 + xLoc, 8 + yLoc, 50, 200, 88);
	gfx.PutPixel(7 + xLoc, 8 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 8 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 8 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 8 + yLoc, 0, 0, 0);
	gfx.PutPixel(11 + xLoc, 8 + yLoc, 255, 255, 255);
	gfx.PutPixel(12 + xLoc, 8 + yLoc, 255, 255, 255);
	gfx.PutPixel(13 + xLoc, 8 + yLoc, 255, 255, 255);
	gfx.PutPixel(14 + xLoc, 8 + yLoc, 255, 255, 255);
	gfx.PutPixel(15 + xLoc, 8 + yLoc, 0, 0, 0);
	gfx.PutPixel(16 + xLoc, 8 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 8 + yLoc, 50, 200, 88);
	gfx.PutPixel(18 + xLoc, 8 + yLoc, 50, 200, 88);
	gfx.PutPixel(19 + xLoc, 8 + yLoc, 0, 0, 0);
	gfx.PutPixel(0 + xLoc, 9 + yLoc, 0, 0, 0);
	gfx.PutPixel(1 + xLoc, 9 + yLoc, 50, 200, 88);
	gfx.PutPixel(2 + xLoc, 9 + yLoc, 0, 0, 0);
	gfx.PutPixel(3 + xLoc, 9 + yLoc, 0, 0, 0);
	gfx.PutPixel(4 + xLoc, 9 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 9 + yLoc, 0, 0, 0);
	gfx.PutPixel(6 + xLoc, 9 + yLoc, 50, 200, 88);
	gfx.PutPixel(7 + xLoc, 9 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 9 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 9 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 9 + yLoc, 50, 200, 88);
	gfx.PutPixel(11 + xLoc, 9 + yLoc, 0, 0, 0);
	gfx.PutPixel(12 + xLoc, 9 + yLoc, 0, 0, 0);
	gfx.PutPixel(13 + xLoc, 9 + yLoc, 0, 0, 0);
	gfx.PutPixel(14 + xLoc, 9 + yLoc, 0, 0, 0);
	gfx.PutPixel(15 + xLoc, 9 + yLoc, 50, 200, 88);
	gfx.PutPixel(16 + xLoc, 9 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 9 + yLoc, 50, 200, 88);
	gfx.PutPixel(18 + xLoc, 9 + yLoc, 50, 200, 88);
	gfx.PutPixel(19 + xLoc, 9 + yLoc, 0, 0, 0);
	gfx.PutPixel(0 + xLoc, 10 + yLoc, 0, 0, 0);
	gfx.PutPixel(1 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(2 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(3 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(4 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(5 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(6 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(7 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(11 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(12 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(13 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(14 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(15 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(16 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(18 + xLoc, 10 + yLoc, 50, 200, 88);
	gfx.PutPixel(19 + xLoc, 10 + yLoc, 0, 0, 0);
	gfx.PutPixel(0 + xLoc, 11 + yLoc, 0, 0, 0);
	gfx.PutPixel(1 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(2 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(3 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(4 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(5 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(6 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(7 + xLoc, 11 + yLoc, 20, 14, 18);
	gfx.PutPixel(8 + xLoc, 11 + yLoc, 18, 11, 14);
	gfx.PutPixel(9 + xLoc, 11 + yLoc, 18, 12, 14);
	gfx.PutPixel(10 + xLoc, 11 + yLoc, 18, 12, 14);
	gfx.PutPixel(11 + xLoc, 11 + yLoc, 21, 13, 16);
	gfx.PutPixel(12 + xLoc, 11 + yLoc, 24, 11, 15);
	gfx.PutPixel(13 + xLoc, 11 + yLoc, 0, 0, 0);
	gfx.PutPixel(14 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(15 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(16 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(18 + xLoc, 11 + yLoc, 50, 200, 88);
	gfx.PutPixel(19 + xLoc, 11 + yLoc, 0, 0, 0);
	gfx.PutPixel(0 + xLoc, 12 + yLoc, 0, 0, 0);
	gfx.PutPixel(1 + xLoc, 12 + yLoc, 50, 200, 88);
	gfx.PutPixel(2 + xLoc, 12 + yLoc, 50, 200, 88);
	gfx.PutPixel(3 + xLoc, 12 + yLoc, 50, 200, 88);
	gfx.PutPixel(4 + xLoc, 12 + yLoc, 50, 200, 88);
	gfx.PutPixel(5 + xLoc, 12 + yLoc, 50, 200, 88);
	gfx.PutPixel(6 + xLoc, 12 + yLoc, 23, 9, 23);
	gfx.PutPixel(7 + xLoc, 12 + yLoc, 135, 26, 68);
	gfx.PutPixel(8 + xLoc, 12 + yLoc, 135, 26, 68);
	gfx.PutPixel(9 + xLoc, 12 + yLoc, 135, 26, 68);
	gfx.PutPixel(10 + xLoc, 12 + yLoc, 135, 26, 68);
	gfx.PutPixel(11 + xLoc, 12 + yLoc, 135, 26, 68);
	gfx.PutPixel(12 + xLoc, 12 + yLoc, 135, 26, 68);
	gfx.PutPixel(13 + xLoc, 12 + yLoc, 135, 26, 68);
	gfx.PutPixel(14 + xLoc, 12 + yLoc, 0, 0, 0);
	gfx.PutPixel(15 + xLoc, 12 + yLoc, 50, 200, 88);
	gfx.PutPixel(16 + xLoc, 12 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 12 + yLoc, 50, 200, 88);
	gfx.PutPixel(18 + xLoc, 12 + yLoc, 50, 200, 88);
	gfx.PutPixel(19 + xLoc, 12 + yLoc, 0, 0, 0);
	gfx.PutPixel(1 + xLoc, 13 + yLoc, 0, 0, 0);
	gfx.PutPixel(2 + xLoc, 13 + yLoc, 50, 200, 88);
	gfx.PutPixel(3 + xLoc, 13 + yLoc, 50, 200, 88);
	gfx.PutPixel(4 + xLoc, 13 + yLoc, 50, 200, 88);
	gfx.PutPixel(5 + xLoc, 13 + yLoc, 0, 0, 0);
	gfx.PutPixel(6 + xLoc, 13 + yLoc, 135, 26, 68);
	gfx.PutPixel(7 + xLoc, 13 + yLoc, 135, 26, 68);
	gfx.PutPixel(8 + xLoc, 13 + yLoc, 135, 26, 68);
	gfx.PutPixel(9 + xLoc, 13 + yLoc, 135, 26, 68);
	gfx.PutPixel(10 + xLoc, 13 + yLoc, 135, 26, 68);
	gfx.PutPixel(11 + xLoc, 13 + yLoc, 135, 26, 68);
	gfx.PutPixel(12 + xLoc, 13 + yLoc, 135, 26, 68);
	gfx.PutPixel(13 + xLoc, 13 + yLoc, 135, 26, 68);
	gfx.PutPixel(14 + xLoc, 13 + yLoc, 135, 26, 68);
	gfx.PutPixel(15 + xLoc, 13 + yLoc, 0, 0, 0);
	gfx.PutPixel(16 + xLoc, 13 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 13 + yLoc, 50, 200, 88);
	gfx.PutPixel(18 + xLoc, 13 + yLoc, 0, 0, 0);
	gfx.PutPixel(1 + xLoc, 14 + yLoc, 0, 0, 0);
	gfx.PutPixel(2 + xLoc, 14 + yLoc, 50, 200, 88);
	gfx.PutPixel(3 + xLoc, 14 + yLoc, 50, 200, 88);
	gfx.PutPixel(4 + xLoc, 14 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 14 + yLoc, 135, 26, 68);
	gfx.PutPixel(6 + xLoc, 14 + yLoc, 135, 26, 68);
	gfx.PutPixel(7 + xLoc, 14 + yLoc, 135, 26, 68);
	gfx.PutPixel(8 + xLoc, 14 + yLoc, 135, 26, 68);
	gfx.PutPixel(9 + xLoc, 14 + yLoc, 251, 192, 224);
	gfx.PutPixel(10 + xLoc, 14 + yLoc, 251, 192, 224);
	gfx.PutPixel(11 + xLoc, 14 + yLoc, 251, 192, 224);
	gfx.PutPixel(12 + xLoc, 14 + yLoc, 251, 192, 224);
	gfx.PutPixel(13 + xLoc, 14 + yLoc, 135, 26, 68);
	gfx.PutPixel(14 + xLoc, 14 + yLoc, 135, 26, 68);
	gfx.PutPixel(15 + xLoc, 14 + yLoc, 0, 0, 0);
	gfx.PutPixel(16 + xLoc, 14 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 14 + yLoc, 50, 200, 88);
	gfx.PutPixel(18 + xLoc, 14 + yLoc, 0, 0, 0);
	gfx.PutPixel(2 + xLoc, 15 + yLoc, 0, 0, 0);
	gfx.PutPixel(3 + xLoc, 15 + yLoc, 50, 200, 88);
	gfx.PutPixel(4 + xLoc, 15 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 15 + yLoc, 135, 26, 68);
	gfx.PutPixel(6 + xLoc, 15 + yLoc, 135, 26, 68);
	gfx.PutPixel(7 + xLoc, 15 + yLoc, 135, 26, 68);
	gfx.PutPixel(8 + xLoc, 15 + yLoc, 251, 192, 224);
	gfx.PutPixel(9 + xLoc, 15 + yLoc, 251, 192, 224);
	gfx.PutPixel(10 + xLoc, 15 + yLoc, 251, 192, 224);
	gfx.PutPixel(11 + xLoc, 15 + yLoc, 251, 192, 224);
	gfx.PutPixel(12 + xLoc, 15 + yLoc, 251, 192, 224);
	gfx.PutPixel(13 + xLoc, 15 + yLoc, 251, 192, 224);
	gfx.PutPixel(14 + xLoc, 15 + yLoc, 135, 26, 68);
	gfx.PutPixel(15 + xLoc, 15 + yLoc, 0, 0, 0);
	gfx.PutPixel(16 + xLoc, 15 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 15 + yLoc, 0, 0, 0);
	gfx.PutPixel(2 + xLoc, 16 + yLoc, 0, 0, 0);
	gfx.PutPixel(3 + xLoc, 16 + yLoc, 50, 200, 88);
	gfx.PutPixel(4 + xLoc, 16 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 16 + yLoc, 135, 26, 68);
	gfx.PutPixel(6 + xLoc, 16 + yLoc, 135, 26, 68);
	gfx.PutPixel(7 + xLoc, 16 + yLoc, 135, 26, 68);
	gfx.PutPixel(8 + xLoc, 16 + yLoc, 251, 192, 224);
	gfx.PutPixel(9 + xLoc, 16 + yLoc, 251, 192, 224);
	gfx.PutPixel(10 + xLoc, 16 + yLoc, 251, 192, 224);
	gfx.PutPixel(11 + xLoc, 16 + yLoc, 251, 192, 224);
	gfx.PutPixel(12 + xLoc, 16 + yLoc, 251, 192, 224);
	gfx.PutPixel(13 + xLoc, 16 + yLoc, 251, 192, 224);
	gfx.PutPixel(14 + xLoc, 16 + yLoc, 135, 26, 68);
	gfx.PutPixel(15 + xLoc, 16 + yLoc, 0, 0, 0);
	gfx.PutPixel(16 + xLoc, 16 + yLoc, 50, 200, 88);
	gfx.PutPixel(17 + xLoc, 16 + yLoc, 0, 0, 0);
	gfx.PutPixel(3 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(4 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(6 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(7 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(8 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(9 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(10 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(11 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(12 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(13 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(14 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(15 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(16 + xLoc, 17 + yLoc, 0, 0, 0);
	gfx.PutPixel(5 + xLoc, 18 + yLoc, 0, 0, 0);
	gfx.PutPixel(6 + xLoc, 18 + yLoc, 0, 0, 0);
	gfx.PutPixel(7 + xLoc, 18 + yLoc, 50, 200, 88);
	gfx.PutPixel(8 + xLoc, 18 + yLoc, 50, 200, 88);
	gfx.PutPixel(9 + xLoc, 18 + yLoc, 50, 200, 88);
	gfx.PutPixel(10 + xLoc, 18 + yLoc, 50, 200, 88);
	gfx.PutPixel(11 + xLoc, 18 + yLoc, 50, 200, 88);
	gfx.PutPixel(12 + xLoc, 18 + yLoc, 50, 200, 88);
	gfx.PutPixel(13 + xLoc, 18 + yLoc, 0, 0, 0);
	gfx.PutPixel(14 + xLoc, 18 + yLoc, 0, 0, 0);
	gfx.PutPixel(7 + xLoc, 19 + yLoc, 0, 0, 0);
	gfx.PutPixel(8 + xLoc, 19 + yLoc, 0, 0, 0);
	gfx.PutPixel(9 + xLoc, 19 + yLoc, 0, 0, 0);
	gfx.PutPixel(10 + xLoc, 19 + yLoc, 0, 0, 0);
	gfx.PutPixel(11 + xLoc, 19 + yLoc, 0, 0, 0);
	gfx.PutPixel(12 + xLoc, 19 + yLoc, 0, 0, 0);
}

int Opponent::findClosestToken(Goal* goals, int numberOfGoals, bool* isGoalTaken) const
{
	double distance = 99999999;
	int placeOfGoal;
	for (int n = 0; n < numberOfGoals; n++)
	{
		if (!isGoalTaken[n])
		{
			double newDistance = getDistance(xLoc, goals[n].getXLoc(), startingY, goals[n].getYLoc());

			if (newDistance < distance)
			{
				distance = newDistance;
				placeOfGoal = n;
			}
		}

	}
	return placeOfGoal;
}

double Opponent::getDistance(int x1, int x2, int y1, int y2) const
{
	double a = pow((x2 - x1),2) ;
	a = a + pow((y2 - y1) , 2);
	a = sqrtf(a);
	return a;
}


int Opponent::getXloc()
{
	return xLoc;
}

int Opponent::getYloc()
{
	return yLoc;
}

void Opponent::setBaseY(int newBaseY)
{
	this->baseY = newBaseY;
}

void Opponent::getToThePlatform(Platform & platform)
{
	if (xLoc + Opponent::xDimension / 2 > (platform.getXloc() + platform.getLength() / 2))
	{
		xLoc = xLoc - speed;

		if (xLoc + Opponent::xDimension / 2 < (platform.getXloc() + platform.getLength() / 2))
			xLoc = (platform.getXloc() + platform.getLength() / 2) - Opponent::xDimension / 2;
	}
	else if (xLoc + Opponent::xDimension / 2 < (platform.getXloc() + platform.getLength() / 2))
	{
		xLoc = xLoc + speed;
		
		if(xLoc + Opponent::xDimension / 2 > (platform.getXloc() + platform.getLength() / 2))
			xLoc = (platform.getXloc() + platform.getLength() / 2) - Opponent::xDimension / 2;
	}
}

void Opponent::getCloseToPlatform(Platform & platform) 
{
	if (abs(xLoc + Opponent::xDimension - platform.getXloc()) < abs(xLoc + Opponent::xDimension - platform.getXloc() - platform.getLength()))
	{
		if (xLoc + Opponent::xDimension > platform.getXloc())
			xLoc = xLoc - speed;
		else
			xLoc = xLoc + speed;

	}
	else
		if (xLoc + Opponent::xDimension > platform.getXloc()+ platform.getLength())
			xLoc = xLoc - speed;
		else
			xLoc = xLoc + speed;

}


bool Opponent::ifItReachableAtLowerLevel(Platform playerP, Platform p2) const
{
	int numOfDifference = (p2.getYloc() - playerP.getYloc()) / 25;
	
	if (numOfDifference == 0)
		numOfDifference = 1;
	
	numOfDifference *= 100;

	if (playerP.getXloc() > p2.getXloc())
	{
		if (playerP.getXloc() - p2.getXloc() - p2.getLength() < numOfDifference)
			return true;
		else
			return false;

	}

	else
	{

		if (p2.getXloc() - playerP.getXloc() - playerP.getLength() < numOfDifference)
			return true;
		else
			return false;

	}
	
}

int Opponent::findTheRelatedPlatform(Platform * platform) //opponentin oldugu platformu bulur
{
	double distance = 999999;
	int platformNumber;
	for (int n = 0; n < numberOfPlatforms; n++)
	{
		double newDistance = getDistance(xLoc, platform[n].getXloc(), yLoc, platform[n].getYloc());
		if (newDistance < distance)
		{
			distance = newDistance;
			platformNumber = n;
		}
	}

	return platformNumber;
}

