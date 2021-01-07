#pragma once
#include <dos.h>
#include <stdio.h>
#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"
#include "Pellet.h"
#include "Tile.h"
#include <chrono>
#include <thread>

using namespace std;

class Game
{
private:
    bool directionChanged;
    int Score=0;
    int level;
   public:
       int lastKeyPressed;
       
      Player player;
      Pellet pellet;
      vector<Wall> walls;
      void Setup();
      void ProcessInput(int key);
      vector<vector<char>> PrepareGrid();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y); // TODO: can have one of these for pellets too
      void genPellet();
      void checkIfEaten();
      int getLastKeyPressed();
      void setLastKeyPressed(int key);
      int getScore();
};