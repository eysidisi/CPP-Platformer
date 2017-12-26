#include "Missile.h"



Missile::~Missile()
{
}

void Missile::DrawMissile(Graphics &gfx)
{
	for (int i = xLoc; i < xLoc + length; i++)
		gfx.PutPixel(i, yLoc, Colors::Green);
}

void Missile::UpdateMissile()
{
	
		xLoc += speed;
	

}
