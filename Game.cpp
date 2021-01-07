#include "Game.h"
#include <cstdlib>
#include <time.h>
#include "Pellet.h"
#include "Player.h"
#include <iostream>



void Game::Setup()
{
    
    //assign the games pellet at some random position
    genPellet();
    

    
}

int Game::getScore() {

    return this->Score;
}
void Game::checkIfEaten() 
{
    if ((player.GetX() == pellet.getX()) && (player.GetY() == pellet.getY())) {
        
        
        pellet.~Pellet();
        genPellet();
        cout << Score << endl;
        Score++;
    }
    
}
// for loop to check where the wall position is walls.erase(walls.begin() + indexOfWall);


// TODO: don't pass in an x and a y here, generate random nubmers inside the function
//       in here you can check the grid to see if there's a wall or anything before deciding the random position is good and creating a Pellet object
void Game::genPellet() {
     
    srand(time(NULL));
    int r1 = rand() % (1 + 19);
    int r2 = rand() % (1 + 19);
    if (r2 == 0) { genPellet(); }
    if (r1 == 0) { genPellet(); }
    Pellet p(r1, r2);
    //set the pellets position
    //assign this pellet to the game
    this->pellet = p;
}



int Game::getLastKeyPressed() {
    return this->lastKeyPressed;
}
void Game::setLastKeyPressed(int key) {
    this->lastKeyPressed = key;
}



void Game::ProcessInput(int key)
{
        
    
        player.Move(key);
        checkIfEaten();
        this_thread::sleep_for(chrono::milliseconds(50));
    
}

/// <summary>
/// This function builds up a 2D grid of characters representing the current state of the game.
/// The characters are later used to decide which colour sqaure to display, but you could display images instead.
/// </summary>
vector<vector<char>> Game::PrepareGrid()
{
    // create the 2D grid
    vector<vector<char>> grid;

    // for each row
    for (int row = 1; row <= SIZE; ++row)
    {
        // create the inner vector to add to the 2D grid
        vector<char> line;

        // for each column, work out what's in that position and add the relevant char to the 2D grid
        for (int col = 1; col <= SIZE; ++col)
        {
            if (row == player.GetY() && col == player.GetX())
            {
                line.push_back(player.GetSymbol());
            }
            else if (IsWallAtPosition(col, row))
            {
                line.push_back(WALL);
            }
            else if ((row == pellet.getY()) && (col == pellet.getX())){
                line.push_back(PELLET);
            }
            else
            {
                line.push_back(FLOOR);
            }
        }

        // now that the row is full, add it to the 2D grid
        grid.push_back(line);
    }

    return grid;
}

bool Game::IsWallAtPosition(int x, int y)
{
    for (size_t i = 0; i < walls.size(); ++i)
    {
        if (walls[i].IsAtPosition(x, y))
        {
            return true;
        }
    }

    return false;
}

bool Game::IsRunning()
{
    // depending on your game you'll need to modify this to return false
    // maybe it's when the player runs out of moves, maybe it's when they get caught, it's up to you!
    return true;
}