#include "Game.h"
#include <cstdlib>
#include <time.h>
#include "Pellet.h"
#include "Player.h"
#include <iostream>

void Game::Setup()
{
    
    //walls.push_back(Wall(r1, r2));
    //Pellet p1 (r1, r2);

    //assign the games pellet at some random position
    genPellet();
    

    
    //walls.push_back(Wall(4, 7));
   /*walls.push_back(Wall(9, 15));
    walls.push_back(Wall(15, 4));
    walls.push_back(Wall(1, 1))*/;
}


void Game::checkIfEaten() 
{
    if ((player.GetX() == pellet.getX()) && (player.GetY() == pellet.getY())) {
        
        cout << "Player: (" << player.GetX() << ", " << player.GetY() << ")" << endl;
        cout << "Pellet: (" << pellet.getX() << ", " << pellet.getY() << ")" << endl;
        pellet.~Pellet();
        genPellet();
        cout << "New pellet loc: (" << pellet.getX() << ", " << pellet.getY() << ")" << endl;
    }
    
}
// for loop to check where the wall position is walls.erase(walls.begin() + indexOfWall);


// TODO: don't pass in an x and a y here, generate random nubmers inside the function
//       in here you can check the grid to see if there's a wall or anything before deciding the random position is good and creating a Pellet object
void Game::genPellet() {
     
    srand(time(NULL));
    int r1 = rand() % (1 + 19);
    int r2 = rand() % (1 + 19);
    Pellet p(r1, r2);
    //set the pellets position
    //p.setX(r1);
    //p.setY(r2);
    //assign this pellet to the game
    this->pellet = p;
}

void Game::ProcessInput(int key)
{
    checkIfEaten();
    player.Move(key);
    
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