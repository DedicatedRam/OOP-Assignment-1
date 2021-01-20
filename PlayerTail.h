#pragma once
#include "Player.h"
#include <vector>
#include <algorithm>
using namespace std;

class PlayerTail: public Player{;
private :
	int tailLength = 0;
	vector<int> prevXpos = { 0 };
	vector<int> prevYpos = { 0 };
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
	void setLength(int len);
	bool checkForCol(Player user);


};

