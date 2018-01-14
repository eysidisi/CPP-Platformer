#include "Opponent.h"
#include <math.h>


Opponent::~Opponent()
{
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

int Opponent::findClosestToken(Goal* goals, int numberOfGoals, bool* isGoalTaken ) const
{
	int distance = 99999999;
	int placeOfGoal;
	for (int n = 0; n < numberOfGoals; n++)
	{
		if (!isGoalTaken[n])
		{
			int newDistance = getDistance(xLoc, goals[n].getXLoc(), yLoc, goals[n].getYLoc());

			if (newDistance < distance)
			{
				distance = newDistance;
				placeOfGoal = n;
			}
		}

	}
	return placeOfGoal;
}

int Opponent::getDistance(int x1, int x2, int y1, int y2) const
{
	return sqrt((x2 - x1) ^ 2+ (y2 - y1) ^ 2);
}

void Opponent::update(Goal* goals, int numberOfGoals, bool* isGoalTaken)
{
	findClosestToken(goals, numberOfGoals, isGoalTaken);
}

bool Opponent::isTokenAtSameLevel(Goal & token) const
{

	return (token.getYLoc()+token.goalHeight==yLoc+Opponent::yDimension);
}
