#include "PlayerTail.h"

PlayerTail::PlayerTail() {
	symbol = PLAYERTAIL;
	Consumed = false;
}

PlayerTail::PlayerTail(int X, int Y)
	:x(X), y(Y)
{
	symbol = PLAYERTAIL;
	Consumed = false;

}

// Functions 



char PlayerTail::getSymbol()
{
	return this->symbol;
}

PlayerTail::~PlayerTail()
{

}
void PlayerTail::setX(int x) {
	this->x = x;
}
void PlayerTail::setY(int y) {
	this->y = y;
}
int PlayerTail::getX() {
	return x;
}
int PlayerTail::getY() {
	return y;
}
/*
void PlayerTail::Follow(const PlayerTail& next)
{
	tile = next.tile;
}
void PlayerTail::MoveBy(Tile& in_loc)
{
	//tile.isAtPos(x, y);
	//IsAtPosition(x, y);
}*/
/*const Tile& PlayerTail::GetLocation() const
{
	return tile;
	// TODO: insert return statement here
}*/