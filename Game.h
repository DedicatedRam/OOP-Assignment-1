#pragma once
#include "raylib.h"
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
#include "Obstacle.h"

using namespace std;

class Game
{
private:
    Obstacle ObsArray[100];
    bool directionChanged;
    int Score=0;
    int level=1;
    bool gameRunning = true;
   public:
       int lastKeyPressed;
       Obstacle obs;
      Player player;
      Pellet pellet;
      vector<Wall> walls;
      void Setup();
      void ProcessInput(int key);
      vector<vector<char>> PrepareGrid();
      Player getPlayer();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y); // TODO: can have one of these for pellets too
      void genPellet();
      void genObs();
      void genObsLvl4();
      void checkIfEaten();
      int getLastKeyPressed();
      void setLastKeyPressed(int key);
      int getScore();
      void checkObsCol();
      int getLevel();
      Obstacle randObsGen();
      Obstacle obsGen(int x, int y);
};