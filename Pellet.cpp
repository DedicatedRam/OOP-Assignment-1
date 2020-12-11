#include "Pellet.h"
#include "Wall.h"


// Constructor

Pellet::Pellet(int newX, int newY)
{
	x = newX;
	y = newY;
	Wall(x, y);
	Consumed = false;
	
}

// Functions 

void Pellet::genPelletsLvl1() 
{
	
}

