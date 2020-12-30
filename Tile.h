#pragma once
using namespace std;
class Tile
{
private:
	int x, y;
	
public: 
	// Constructor
	Tile();
	Tile(int x, int y);

	// Functions
	int getX();
	int getY();
	bool isAtPos(int x, int y);

};

