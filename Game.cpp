#include "Game.h"
#include <cstdlib>
#include <time.h>
#include "Pellet.h"
#include "Player.h"
#include <iostream>


Game::Game(Sound sf1, Sound sf2) {
    this->ping = sf1;
    this->hawk = sf2;
}

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

void Game::Reset() {
    tail.setLength(0);
    setLevel(1);
    setScore(1);
    this->gameRunning = true;
    clearObs();
}

void Game::setLevel(int l) {
    this->level = l;
}

void Game::setScore(int s) {
    this->Score = s;
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

        cout << "Pellet loc: (" << pellet.getX() << ", " << pellet.getY() << ")" << endl;
        genPellet();
        Score++;
        for (int i = 0; i < tail.getLength(); i++)
        {
            cout << tail.returnArrayX()[i] << ", " << tail.returnArrayY()[i] << endl;
        }
        tail.extendTail();
        genObs();
        PlaySound(ping);
    }
    tail.updateXArr(player.GetX());
    tail.updateYArr(player.GetY());

}


void Game::checkObsCol() {
    int x = 0;
    for each (Obstacle Obs in ObsArray)
    {
        
        if ((player.GetX() == Obs.getX()) && (player.GetY() == Obs.getY())) {
            PlaySound(hawk);
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
    } while ((r2 == 0) && (r2 != pellet.getY()) && (r2 != player.GetY()) && (r2 != player.GetY()+1) && (r2 != player.GetY()+2) && (r2 != player.GetY() - 1) && (r2 != player.GetY() - 2));
    do
    {
        r1 = rand() % (20) ;
    } while ((r1 == 0) && (r1 != pellet.getX()) && (r1 != player.GetX()) && (r1 != player.GetX() + 1) && (r1 != player.GetX() + 2) && (r1 != player.GetX() - 1) && (r1 != player.GetX() - 2));;
    Obstacle ob(r1+1, r2+1);

    return ob;
}

Obstacle Game::obsGen(int x, int y) {
    Obstacle ob(x, y);
    return ob;
}

void Game::genObsLvl4() {
    for each (Obstacle obs in ObsArray)
    {
        obs.~Obstacle();
    }
    if (Score == 1) {
        this->ObsArray[0] = obsGen(2, 4);
        this->ObsArray[1] = obsGen(2, 5);
        this->ObsArray[2] = obsGen(2, 6);
        this->ObsArray[3] = obsGen(2, 7);
        this->ObsArray[4] = obsGen(3, 7);
        this->ObsArray[5] = obsGen(4, 4);
        this->ObsArray[6] = obsGen(4, 5);
        this->ObsArray[7] = obsGen(4, 7);
        this->ObsArray[8] = obsGen(5, 5);
        this->ObsArray[9] = obsGen(5, 7);
        this->ObsArray[10] = obsGen(6, 5);
        this->ObsArray[11] = obsGen(6, 7);
        pellet.~Pellet();
        Pellet p(4, 6);
        this->pellet = p;
    }
    if (Score == 2) {
        this->ObsArray[0] = obsGen(6, 9);
        this->ObsArray[1] = obsGen(6, 10);
        this->ObsArray[2] = obsGen(6, 11);
        this->ObsArray[3] = obsGen(6, 12);
        this->ObsArray[4] = obsGen(6, 13);
        this->ObsArray[5] = obsGen(6, 14);
        this->ObsArray[6] = obsGen(7, 9);
        this->ObsArray[7] = obsGen(8, 9);
        this->ObsArray[8] = obsGen(8, 11);
        this->ObsArray[9] = obsGen(8, 12);
        this->ObsArray[10] = obsGen(8, 13);
        this->ObsArray[11] = obsGen(8, 14);
        this->ObsArray[12] = obsGen(8, 15);
        this->ObsArray[13] = obsGen(9, 9);
        this->ObsArray[14] = obsGen(9, 15);
        this->ObsArray[15] = obsGen(10, 9);
        this->ObsArray[16] = obsGen(10, 10);
        this->ObsArray[17] = obsGen(10, 11);
        this->ObsArray[18] = obsGen(10, 12);
        this->ObsArray[19] = obsGen(10, 13);
        this->ObsArray[20] = obsGen(10, 15);
        this->ObsArray[21] = obsGen(11, 13);
        this->ObsArray[22] = obsGen(11, 15);
        this->ObsArray[23] = obsGen(12, 13);
        this->ObsArray[24] = obsGen(12, 15);
        pellet.~Pellet();
        Pellet p(9, 10);
        this->pellet = p;
    }

    if (Score == 3) {
        this->ObsArray[0] = obsGen(5, 7);
        this->ObsArray[1] = obsGen(5, 9);
        this->ObsArray[2] = obsGen(5, 11);
        this->ObsArray[3] = obsGen(5, 12);
        this->ObsArray[4] = obsGen(5, 13);
        this->ObsArray[5] = obsGen(5, 14);
        this->ObsArray[6] = obsGen(5, 15);
        this->ObsArray[7] = obsGen(6, 7);
        this->ObsArray[8] = obsGen(6, 9);
        this->ObsArray[9] = obsGen(6, 15);
        this->ObsArray[10] = obsGen(7, 7);
        this->ObsArray[11] = obsGen(7, 9);
        this->ObsArray[12] = obsGen(7, 10);
        this->ObsArray[13] = obsGen(7, 11);
        this->ObsArray[14] = obsGen(7, 12);
        this->ObsArray[15] = obsGen(7, 13);
        this->ObsArray[16] = obsGen(7, 15);
        this->ObsArray[17] = obsGen(8, 7);
        this->ObsArray[18] = obsGen(8, 9);
        this->ObsArray[19] = obsGen(8, 13);
        this->ObsArray[20] = obsGen(8, 15);
        this->ObsArray[21] = obsGen(9, 7);
        this->ObsArray[22] = obsGen(9, 9);
        this->ObsArray[23] = obsGen(9, 11);
        this->ObsArray[24] = obsGen(9, 13);
        this->ObsArray[25] = obsGen(9, 15);
        this->ObsArray[26] = obsGen(10, 7);
        this->ObsArray[27] = obsGen(10, 9);
        this->ObsArray[28] = obsGen(10, 11);
        this->ObsArray[29] = obsGen(10, 13);
        this->ObsArray[30] = obsGen(10, 15);
        this->ObsArray[31] = obsGen(11, 7);
        this->ObsArray[32] = obsGen(11, 9);
        this->ObsArray[33] = obsGen(11, 11);
        this->ObsArray[34] = obsGen(11, 13);
        this->ObsArray[35] = obsGen(11, 15);
        this->ObsArray[36] = obsGen(12, 7);
        this->ObsArray[37] = obsGen(12, 9);
        this->ObsArray[38] = obsGen(12, 11);
        this->ObsArray[39] = obsGen(12, 13);
        this->ObsArray[40] = obsGen(12, 15);
        this->ObsArray[41] = obsGen(13, 7);
        this->ObsArray[42] = obsGen(13, 11);
        this->ObsArray[43] = obsGen(13, 15);
        this->ObsArray[44] = obsGen(14, 7);
        this->ObsArray[45] = obsGen(14, 8);
        this->ObsArray[46] = obsGen(14, 9);
        this->ObsArray[47] = obsGen(14, 10);
        this->ObsArray[48] = obsGen(14, 11);
        this->ObsArray[49] = obsGen(14, 12);
        this->ObsArray[50] = obsGen(14, 13);
        this->ObsArray[51] = obsGen(14, 14);
        this->ObsArray[52] = obsGen(14, 15);
        pellet.~Pellet();
        Pellet p(8, 11);
        this->pellet = p;
        player.setX(4);
        player.setY(2);
    }
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
    if (level == 4) {
        genObsLvl4();
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

void Game::clearObs() {
    for (int i = 0; i < 100; i++)
    {
        ObsArray[i] = obsGen(0, 0);
    }
}

int Game::getLastKeyPressed() {
    return this->lastKeyPressed;
}
void Game::setLastKeyPressed(int key) {
    this->lastKeyPressed = key;
}



void Game::ProcessInput(int key)
{
    if ((Score == 2) && (level == 1)) {
        level = 2;
        Score = 0;
    }
    if ((Score == 2) && (level == 2)) {
        level = 3;
        Score = 0;
    }
    if ((Score == 2) && (level == 3)) {
        level = 4;
        Score = 0;
    }
    int curLevel = getLevel();
    int waitTime = (450 / curLevel);

    player.Move(key);

    checkIfEaten();
    checkObsCol();

    this_thread::sleep_for(chrono::milliseconds(waitTime));
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

            else if ((row == pellet.getY()) && (col == pellet.getX())) {
                line.push_back(PELLET);
            }
            else 
            {
                bool isTailFound = false;
                for (int i = 0; i < tail.getLength(); i++)
                {
                    if ((row == tail.returnArrayY()[i]) && (col == tail.returnArrayX()[i])) {
                        line.push_back(PLAYERTAIL);
                        isTailFound = true;
                        break;
                    }
                }
                if (!isTailFound) {
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