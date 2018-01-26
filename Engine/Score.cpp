#include "Score.h"



Score::Score()
{
}


Score::~Score()
{
}

void Score::draw(Player& pl, Graphics& gfx)
{
	for (int x = xPlayer; x < 1 * score + xPlayer; x++)
		for (int y = yPlayer; y < yPlayer + playerWidth; y++)
			gfx.PutPixel(x, y, Colors::Yellow);
}

void Score::draw(Opponent& op, Graphics& gfx)
{
	for (int x = xOpponent; x < 1 * score + xOpponent; x++)
		for (int y = yOpponent; y < yOpponent + opponentWidth; y++)
			gfx.PutPixel(x, y, Colors::Green);
}
