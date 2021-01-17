#pragma once

#include "constants.h"
#include <vector>
#include "PlayerTail.h"


class Player
{
    public:
        // constructor
        Player();
        Tile tile;
        PlayerTail playerTail;
        // assessors
        int GetX();
        int GetY();
        char GetSymbol() const;
        bool IsAtPosition(int x, int y);
        bool isAlive();
        PlayerTail getPlayerTail(int i);
        int getPlayerTailSize();

        // mutators
        void Move(int key);
        void Follow(const Player& next);
        void MoveBy();
        void Grow();

        char symbol;
        int  x, y;
        const int width = 20;
        const int height = 20;

    private:
        // data members
        bool alive;
        bool escaped;
        int dx;
        int dy;

        // supporting functions 
        vector<PlayerTail>playerTails;
        void PositionInMiddleOfGrid();
        void UpdatePosition(int dx, int dy);
};