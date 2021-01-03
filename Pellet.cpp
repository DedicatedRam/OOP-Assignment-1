#include "Pellet.h"
#include "Wall.h"


// Constructor


Pellet::Pellet()
{
	symbol = PELLET;
	Consumed = false;
	
}

// Functions 

char Pellet::getSymbol() {
	return this->symbol;
}


void Pellet::setX(int x) {
	this->x = x;
}
void Pellet::setY(int y) {
	this->y = y;
}
int Pellet::getX(){
	return this->x;
}
int Pellet::getY() {
	return this->y;
}
