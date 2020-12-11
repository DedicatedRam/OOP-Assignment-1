#pragma once
#include "Game.h"
#include "Wall.h"
#include "Player.h"

class Pellet : public Wall
{

private:
	// Attributes
	int x, y;
	bool Consumed;

public: 
	Pellet(int newX, int newY);
	void genPelletsLvl1();
};

