#pragma once
using namespace std;
#include "Tile.h"
#include "Player.h"

class Pellet : public Tile
{

private:
	// Attributes
	int x, y;
	bool Consumed;
	char symbol;

public: 
	~Pellet();
	Pellet();
	Pellet(int X, int Y);
	char getSymbol();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};

