#include "Tile.h"

Tile::Tile() {

}

Tile::Tile(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Tile::getX() {
	return this->x;
}
int Tile::getY() {
	return this->y;
}

bool Tile::isAtPos(int x, int y)
{
	if ((this->x == x) && (this->y == y)){
		return true;
	}
	return false;
}