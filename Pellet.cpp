#include "Pellet.h"
#include "Wall.h"


// Constructor

Pellet::Pellet() {
	symbol = PELLET;
	Consumed = false;
}

Pellet::Pellet(int X, int Y)
	:x(X), y(Y)
{
	symbol = PELLET;
	Consumed = false;
	
}

// Functions 

char Pellet::getSymbol() {
	return this->symbol;
}

Pellet::~Pellet() {
	
}


void Pellet::setX(int x) {
	this->x = x;
}
void Pellet::setY(int y) {
	this->y = y;
}
int Pellet::getX(){
	return x;
}
int Pellet::getY() {
	return y;
}
