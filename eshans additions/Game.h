#pragma once
#include <dos.h>
#include <stdio.h>
#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "PlayerTail.h"
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
    Obstacle ObsArray[10];
    bool directionChanged;
    int Score=0;
    int level=1;
    bool gameRunning = true;
   public:
       int lastKeyPressed;
       Obstacle obs;
      Player player;
      //PlayerTail playerTail;
      //vector<PlayerTail> playerTails;
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
      void checkIfEaten();
      int getLastKeyPressed();
      void setLastKeyPressed(int key);
      int getScore();
      void checkObsCol();
      int getLevel();
      Obstacle randObsGen();
};