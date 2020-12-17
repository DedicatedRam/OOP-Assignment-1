#pragma once
#include "Game.h"
#include "Tile.h"
#include "Player.h"

// TODO: inheriting from Wall is a little weird, maybe make a generic Tile base class
class Pellet : public Tile
{

private:
	// Attributes
	int x, y;
	bool Consumed;

public: 
	Pellet();
	void genPelletsLvl1();
	void setX(int x);
	void setY(int y);
};

