#include "Game.h"
#include <cstdlib>
#include <time.h>
#include "Pellet.h"
#include "Player.h"
#include <iostream>


int Game::getLevel() {
    return this->level;
}

void Game::Setup()
{
    srand(time(NULL));
    //assign the games pellet at some random position
    genPellet();
    genObs();


}

Player Game::getPlayer() {
    return this->player;
}

int Game::getScore() {

    return this->Score;
}
void Game::checkIfEaten()
{
    if ((player.GetX() == pellet.getX()) && (player.GetY() == pellet.getY())) {
        cout << "PlayerTail: (" << player.playerTail.getX() << ", " << player.playerTail.getY() << ")" << endl;
        cout << pellet.getX() << ", " << pellet.getY() << endl;
        player.Grow();
        genPellet();
        Score++;
        genObs();
    }

}


void Game::checkObsCol() {
    int x = 0;
    for each (Obstacle Obs in ObsArray)
    {
        if (level == 2) {
            cout << x << ": " << Obs.getX() << ", " << Obs.getY() << endl;
        }
        if ((player.GetX() == Obs.getX()) && (player.GetY() == Obs.getY())) {
            this->gameRunning = false;
        }
    }
}

Obstacle Game::randObsGen() {
    int r1 = 0;
    int r2 = 0;
    do
    {
        r2 = rand() % (20);
    } while ((r2 == 0) && (r2 != pellet.getY()) && (r2 != player.GetY()));
    do
    {
        r1 = rand() % (20) ;
    } while ((r1 == 0) && (r1 != pellet.getX()) && (r1 != player.GetX()));
    Obstacle ob(r1+1, r2+1);

    return ob;
}

void Game::genObs() {
    if (level == 2) {
        this->ObsArray[0] = randObsGen();
        this->ObsArray[1] = randObsGen();
        this->ObsArray[2] = randObsGen();
        this->ObsArray[3] = randObsGen();
        this->ObsArray[4] = randObsGen();
        
    }
    if (level == 3) {
        this->ObsArray[0] = randObsGen();
        this->ObsArray[1] = randObsGen();
        this->ObsArray[2] = randObsGen();
        this->ObsArray[3] = randObsGen();
        this->ObsArray[4] = randObsGen();
        this->ObsArray[5] = randObsGen();
        this->ObsArray[6] = randObsGen();
        this->ObsArray[7] = randObsGen();
        this->ObsArray[8] = randObsGen();
        this->ObsArray[9] = randObsGen();
    }
}
//       in here you can check the grid to see if there's a wall or anything before deciding the random position is good and creating a Pellet object
void Game::genPellet() {


    int r1 = 0;
    int r2 = 0;
    do
    {
        r2 = rand() % (20);
    } while (r2 == 0);
    do
    {
        r1 = rand() % (20);
    } while (r1 == 0);

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

    this_thread::sleep_for(chrono::milliseconds(100));
    player.Move(key);
    checkIfEaten();
    checkObsCol();

    if ((Score == 5) && (level == 1)) {
        level = 2;
        Score = 0;
    }
    if ((Score == 5) && (level == 2)) {
        level = 3;
        Score = 0;
    }
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
            Obstacle cellAsObstacle(col, row);
            if (row == player.GetY() && col == player.GetX())
            {
                line.push_back(player.GetSymbol());
            }


            else if (IsWallAtPosition(col, row))
            {
                line.push_back(WALL);
            }

            // Count returns the number of times cellAsObstacle is found in the ObsArray, thus if it returns 0, we can treat this as false
            else if (std::count(std::begin(ObsArray), std::end(ObsArray), cellAsObstacle)) {
                line.push_back(OBSTACLE);
            }


            /*for each (Obstacle Obs in ObsArray)
            {
                if ((row == Obs.getY()) && (col == Obs.getX())) {
                    line.push_back(OBSTACLE);
                }
            }*/

            else if ((row == pellet.getY()) && (col == pellet.getX())) {
                line.push_back(PELLET);
            }
            /*else if ((row == playerTail.getY()) && (col == playerTail.getX()))
            {
                line.push_back(PLAYERTAIL);//playerTail.getSymbol());
               // player.Grow();
            }*/
            else
            {
                bool eating = false;
                for (size_t i = 0; i < player.getPlayerTailSize(); ++i)
                {
                    if ((row == player.getPlayerTail(i).getY()) && (col == player.getPlayerTail(i).getX()))
                    {
                        line.push_back(PLAYERTAIL);//playerTail.getSymbol());
                       
                    }
                }
                if (!eating)
                {
                    line.push_back(FLOOR);
                }
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
    return gameRunning;
}