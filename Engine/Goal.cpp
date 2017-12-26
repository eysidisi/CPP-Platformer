#include "Goal.h"




Goal::~Goal()
{
}

void Goal::drawGoal(Graphics& gfx)
{
	for (int i = xLoc; i < xLoc+width; i++)
		for (int j = yLoc; j > yLoc-length; j--)
			gfx.PutPixel(i, j, Colors::Yellow);
}

void Goal::init(int x, int y)
{
	xLoc = x;
	yLoc = y;
}
