#include "Score.h"



Score::Score()
{
}


Score::~Score()
{
}

void Score::draw(Player& pl, Graphics& gfx)
{
	for (int x = xPlayer; x < 8 * score + xPlayer; x++)
		for (int y = yPlayer; y < yPlayer + playerWidth; y++)
			gfx.PutPixel(x, y, Colors::Yellow);

	
		for (int y = yPlayer; y < yPlayer + playerWidth; y++)
			gfx.PutPixel(xPlayer+8*25, y, Colors::Yellow);
}

void Score::draw(Opponent& op, Graphics& gfx)
{
	for (int x = xOpponent; x < 8 * score + xOpponent; x++)
		for (int y = yOpponent; y < yOpponent + opponentWidth; y++)
			gfx.PutPixel(x, y, Colors::Green);

	for (int y = yOpponent; y < yOpponent + opponentWidth; y++)
		gfx.PutPixel(xOpponent + 8 * 25, y, Colors::Green);
}
