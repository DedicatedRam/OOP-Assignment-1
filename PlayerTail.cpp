#include "PlayerTail.h"

// Constructor 
PlayerTail::PlayerTail() {
	symbol = PLAYERTAIL;
}

void PlayerTail::updateXArr(int X) {
	
	rotate(prevXpos.begin(), prevXpos.end(), prevXpos.end());	// rotates everything so that the value at the end is now at the start
	prevXpos.insert(prevXpos.begin(), X);

			//for (int i = 24; i > 0; i--)
			//{
			//	if (prevXpos[24] != 0) {	// If element 24 is not 0, means that the array is full and values must be shifted
			//		prevXpos[24] = 0;		// So the 24th element is set to 0 
			//	}
			//	if ((i != 24)) {
			//		prevXpos[i + 1] = prevXpos[i];		// Then all the other elements gets shifted up by one to make room at the start of the 
			//											// Array for the latest value
			//	}
			//	
			//}
			//prevXpos[0] = X;			// Then the new value is assigned 
}

void PlayerTail::updateYArr(int Y) {

	rotate(prevYpos.begin(), prevYpos.end(), prevYpos.end());
	prevYpos.insert(prevYpos.begin(), Y);


	/*for (int i = 24; i > 0; i--)
	{
		if (prevYpos[24] != 0) {
			prevYpos[24] = 0;
		}
		if (i !=24) {
			prevYpos[i + 1] = prevYpos[i];
		}

	}
	prevYpos[0] = Y;*/
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
