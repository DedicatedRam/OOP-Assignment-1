#pragma once
//#include "Player.h"
#include "Constants.h"
#include "Tile.h"
#include <vector>

using namespace std;

class PlayerTail
{
private:
	// Attributes
	int x, y;
	bool Consumed;
	char symbol;
	

public:
	~PlayerTail();
	PlayerTail();
	PlayerTail(int X, int Y);
	char getSymbol();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	Tile tile;
	//void MoveBy(Tile& in_loc);
	//void Follow(const PlayerTail& next);

};

