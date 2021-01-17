#include "raylib.h"
#include "Game.h"

int main()
{
    InitWindow(900, 600, "OOP Assignment 1");
    SetTargetFPS(60);

    Game game;
    game.Setup();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        string scoreText = "Your score: " + to_string(game.getScore());
        string levelText = "Current level: " + to_string(game.getLevel());
        DrawText(scoreText.c_str() , 610, 10, 20, BLACK);
        DrawText(levelText.c_str(), 610, 30, 20, BLACK);

        if (game.IsRunning())
        {
            if (IsKeyDown(KEY_RIGHT)) { 
                game.setLastKeyPressed(KEY_RIGHT); 
                game.ProcessInput(KEY_RIGHT);  
            }
            if (IsKeyDown(KEY_LEFT))  { 
                game.setLastKeyPressed(KEY_LEFT);
                game.ProcessInput(KEY_LEFT); 
                
            }

            if (IsKeyDown(KEY_UP))    {
                game.setLastKeyPressed(KEY_UP);
                game.ProcessInput(KEY_UP); 
                
            }

            if (IsKeyDown(KEY_DOWN))  {

                game.setLastKeyPressed(KEY_DOWN);
                game.ProcessInput(KEY_DOWN);
            }
            string info = to_string(game.getPlayer().GetX()) + to_string(game.getPlayer().GetY());
            DrawText(info.c_str(), 610, 70, 20, BLACK);
        }
        else
        {
            DrawText("You died!", 610, 50, 40, LIGHTGRAY);
        }

        const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));

        const auto grid = game.PrepareGrid();

        for (int x = 0; x < SIZE; x++)
        {
            for (int y = 0; y < SIZE; y++)
            {
                int xPosition = x * cellSize;
                int yPosition = y * cellSize;

                switch (grid[y][x])
                {
                    case FLOOR:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN); break;
                    case WALL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIGHTGRAY); break;
                    case PLAYER: DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);     break;
                    case PLAYERTAIL: DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);       break;
                    case PELLET: DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);       break;
                    case OBSTACLE:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);  break;
                    default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
                }

                // draw lines around each tile, remove this if you don't like it!
                DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
            }
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}