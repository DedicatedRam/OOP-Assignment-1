#pragma once
#include "Tile.h"
#include "Constants.h"

class Obstacle   : 	public Tile
{

private:
	int x, y;
	char symbol;

public:
	~Obstacle();
	Obstacle();
	Obstacle(int x, int y);
	char getSymbol();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	bool operator==(const Obstacle& rhs)const;

};

