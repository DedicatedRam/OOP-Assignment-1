#include "PlayerTail.h"
#include <iostream>

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


// TODO: There is an issue with this, for some reason the if doesnt run correctly. Ask jamie or someone for advice 
bool PlayerTail::checkForCol(Player user) {
	for (size_t i = 0; i < getLength(); i++)
	{
		int YcurCheck = prevYpos[i];
		
		for (size_t i = 0; i < getLength(); i++)
		{
			int XcurCheck = prevXpos[i];
			if ((XcurCheck == user.GetX()) && (YcurCheck == user.GetY())) {
				
				cout << "Player pos: (" << user.GetX() << ", " << user.GetY() << ") " << endl;
				cout << "Tail pos: (" << XcurCheck << ", " << YcurCheck << ")" << endl;
				return true;
			}
			else
			{
				cout << "Nothing" << endl;
				return false;
			}
		}
	}
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
