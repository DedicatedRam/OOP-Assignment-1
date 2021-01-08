#include "Obstacle.h"

// Constructor 

Obstacle::Obstacle() {
	symbol = OBSTACLE;
}

Obstacle::Obstacle(int X, int Y)
	:x(X), y(Y)
{
	symbol = OBSTACLE;
}

// Destructor

Obstacle::~Obstacle() {

}

// Functions

char Obstacle::getSymbol() {
	return this->symbol;
}

int Obstacle::getX() {
	return this->x;
}
int Obstacle::getY() {
	return this->y;
}
void Obstacle::setX(int X) {
	this->x = X;
}
void Obstacle::setY(int Y) {
	this->y = Y;
}