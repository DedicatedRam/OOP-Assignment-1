#pragma once
#include "constants.h"

class Player
{
    public:
        // constructor
        Player();

        // assessors
        int GetX();
        int GetY();
        char GetSymbol() const;
        bool IsAtPosition(int x, int y);
        bool isAlive();

        // mutators
        void Move(int key);
        void setX(int X);
        void setY(int Y);

        char symbol;
        int  x, y;

    private:
        // data members
        bool alive;
        bool escaped;
        int dx;
        int dy;
        

        // supporting functions 
        void PositionInMiddleOfGrid();
        void UpdatePosition(int dx, int dy);
};