#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"

using namespace std;

class Game
{
   public:
      Player player;
      Pellet pellet;
      // TODO: collection of walls is good, you can add those to here
      //       but you probably also want a single Pellet object
      vector<Wall> walls;
      void Setup();
      void ProcessInput(int key);
      vector<vector<char>> PrepareGrid();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y); // TODO: can have one of these for pellets too
      void genPellet(int x, int y);
      bool checkIfEaten(int x, int y);
};