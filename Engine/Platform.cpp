#include "Platform.h"






Platform::~Platform()
{
}

void Platform::drawPlatform(Graphics & gfx) const
{
	for (int i = xLoc; i <= xLoc + length; i++)
		gfx.PutPixel(i, yLoc, Colors::White);
	
	for (int i = xLoc; i <= xLoc + length; i++)
		gfx.PutPixel(i, yLoc + width, Colors::White);
	
	
	for (int i = yLoc; i <= yLoc+  width; i++)
		gfx.PutPixel(xLoc, i, Colors::White);

	for (int i = yLoc; i <= yLoc + width; i++)
		gfx.PutPixel(xLoc + length, i, Colors::White);
}

int Platform::getXloc()
{
	return xLoc;
}

int Platform::getYloc()
{
	return yLoc;
}

int Platform::getLength()
{
	return length;
}

int Platform::getWidth()
{
	return width;
}

void Platform::init(int xLocl, int yLocl, int lengthl, int widthl)
{
	xLoc = xLocl;
	yLoc = yLocl;
	length = lengthl;
	width = widthl;

}
