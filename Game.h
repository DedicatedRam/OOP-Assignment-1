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
#include "PlayerTail.h"

using namespace std;

class Game
{
private:
    PlayerTail tail;
    Obstacle ObsArray[100];
    bool directionChanged;
    int Score=0;
    int level=1;
    bool gameRunning = true;
    Sound ping;
    Sound hawk;
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
      bool IsWallAtPosition(int x, int y); 
      void genPellet();
      void genObs();
      void genObsLvl4();
      void checkIfEaten();
      int getLastKeyPressed();
      void setLastKeyPressed(int key);
      int getScore();
      void setScore(int s);
      void setLevel(int l);
      void Reset();
      void clearObs();
      void readSaveFile();
      void saveScoreToFile(int level, int score);
      void checkObsCol();
      int getLevel();
      Obstacle randObsGen();
      Obstacle obsGen(int x, int y);
      Game(Sound sf1, Sound sf2);
};