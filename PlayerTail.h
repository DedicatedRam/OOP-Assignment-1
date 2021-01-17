#pragma once
#include "Player.h"
#include <vector>
#include <algorithm>
using namespace std;

class PlayerTail: public Player{;
private :
	int tailLength = 1;
	vector<int> prevXpos = { 0 };
	vector<int> prevYpos = { 0 };
	//int prevXpos[25] = { 0 };// init these values to 0
	//int prevYpos[25] = { 0 };
	char symbol;

public:
	// Constructor
	PlayerTail();
	//PlayerTail(int x, int y);
	void extendTail();
	void updateXArr(int X);
	void updateYArr(int Y);
	int getLength();
	vector<int> returnArrayY();
	vector<int> returnArrayX();


};

