#include "PlayerTail.h"

// Constructor 
PlayerTail::PlayerTail() {
	symbol = PLAYERTAIL;
}

void PlayerTail::updateXArr(int X) {
	
	rotate(prevXpos.begin(), prevXpos.end(), prevXpos.end());	// rotates everything so that the value at the end is now at the start
	prevXpos.insert(prevXpos.begin(), X);

}

void PlayerTail::updateYArr(int Y) {

	rotate(prevYpos.begin(), prevYpos.end(), prevYpos.end());
	prevYpos.insert(prevYpos.begin(), Y);

}

void PlayerTail::extendTail() {
	tailLength++;
}

int PlayerTail::getLength() {
	return this->tailLength;
}

std::vector<int> PlayerTail::returnArrayY() {
	return this->prevYpos;
}

std::vector<int> PlayerTail::returnArrayX() {
	return this->prevXpos;
}

void PlayerTail::setLength(int len) {
	this->tailLength = len;
}
