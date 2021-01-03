#pragma once
using namespace std;
#include "Tile.h"
#include "Player.h"

// TODO: inheriting from Wall is a little weird, maybe make a generic Tile base class
class Pellet : public Tile
{

private:
	// Attributes
	int x, y;
	bool Consumed;
	char symbol;

public: 
	Pellet();
	void genPelletsLvl1();
	char getSymbol();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};

