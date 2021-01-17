#include "Player.h"
#include <iostream>
using namespace std;
Player::Player() : symbol(PLAYER), x(0), y(0), alive(true), escaped(false), dx(0), dy(0)
{
    PositionInMiddleOfGrid();
}

int Player::GetX()
{
    return x;
}

int Player::GetY()
{
    return y;
}

char Player::GetSymbol() const
{
    return symbol;
}

bool Player::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}

void Player::Move(int key)
{

    switch (key)
    {
    case KEY_LEFT:
        dx = -1;
        dy = 0;
        break;
    case KEY_RIGHT:
        dx = +1;
        dy = 0;
        break;
    case KEY_UP:
        dx = 0;
        dy = -1;
        break;
    case KEY_DOWN:
        dx = 0;
        dy = +1;
        break;
    default:
        // not a key we care about, so do nothing
        break;
    }
    /*if (((x + dx) >= 1) && ((x + dx) <= SIZE) && ((y + dy) >= 1) && ((y + dy) <= SIZE))
    {
        MoveBy();
        UpdatePosition(dx, dy);

    }*/
    MoveBy();
    UpdatePosition(dx, dy);
    
    if (x < 1) x = SIZE ; else if (x > SIZE) x = 1;
    if (y < 1) y = SIZE ; else if (y > SIZE) y = 1;

    // update mouse coordinates if move is possible
    

}
void Player::MoveBy()
{//playerTail position 0 needs to move head where currently is 
    
     for (int i = playerTails.size() -1; i >0; --i)
     { 
         playerTails[i].setX(playerTails[i - 1].getX());
         playerTails[i].setY(playerTails[i - 1].getY());          
     }
     if (playerTails.size() > 0)
     {
         playerTails[0].setX(GetX());
         playerTails[0].setY(GetY());
     }     
}
void Player::Grow()
{
    PlayerTail tailPiece;
    playerTails.push_back(tailPiece);
}

bool Player::isAlive() {
    return this->alive;
}

PlayerTail Player::getPlayerTail(int i)
{
    return playerTails[i];
}
int Player::getPlayerTailSize()
{
    return playerTails.size();
}
void Player::UpdatePosition(int dx, int dy)
{
    x += dx;
    y += dy;
}

void Player::PositionInMiddleOfGrid()
{
    x = SIZE / 2;
    y = SIZE / 2;
}