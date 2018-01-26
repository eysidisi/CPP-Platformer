#pragma once
#include "Player.h"
#include "Opponent.h"
#include "Graphics.h"
class Score
{
public:
	Score();
	~Score();


	int score;
	int xPlayer=0, xOpponent=400;
	int yPlayer=20, yOpponent=20;
	int playerWidth=10, opponentWidth=10;

public:
	 void draw(Player& pl, Graphics& gfx);
	 void draw(Opponent& op, Graphics& gfx);
};
