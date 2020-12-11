#include "Game.h"
#include <cstdlib>
#include <time.h>
#include "Pellet.h"
#include "Player.h"

void Game::Setup()
{
    srand(time(NULL));
    int r1 = rand() % (1 + 19);
    int r2 = rand() % (1 + 19);
    //walls.push_back(Wall(r1, r2));
    //Pellet p1 (r1, r2);

    genPellet(r1, r2);
    genPellet(r2, r1);

   /* walls.push_back(Wall(4, 7));
    walls.push_back(Wall(9, 15));
    walls.push_back(Wall(15, 4));
    walls.push_back(Wall(1, 1))*/;
}

bool Game::checkIfEaten(int x, int y) 
{
    if (player.IsAtPosition(x, y)) {
        //walls.pop_back(Wall(x, y));
        return true;
    }
    return false;
}
// for loop to check where the wall position is walls.erase(walls.begin() + indexOfWall);

void Game::genPellet(int x, int y) {
    walls.push_back(Wall(x, y));
    bool Consumed = false;
}

void Game::ProcessInput(int key)
{
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