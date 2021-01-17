#include "raylib.h"
#include "Game.h"

int main()
{
	InitWindow(900, 600, "OOP Assignment 1");
	SetTargetFPS(60);
	string fileNameWood = "./resources/eagle.png";
	string fileNameSnakeHead = "./resources/snakeHead.png";
	string fileNameSnakeTail = "./resources/snakeTail.png";
	string fileNameRat = "./resources/rat.png";
	string fileNameBackground = "./resources/background.png";

	Texture2D head = LoadTexture(fileNameSnakeHead.c_str());
	Texture2D tail = LoadTexture(fileNameSnakeTail.c_str());
	Texture2D wood = LoadTexture(fileNameWood.c_str());
	Texture2D rat = LoadTexture(fileNameRat.c_str());
	Texture2D bckGround = LoadTexture(fileNameBackground.c_str());


	Game game;
	game.Setup();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);
		string scoreText = "Your score: " + to_string(game.getScore());
		string levelText = "Current level: " + to_string(game.getLevel());
		DrawText(scoreText.c_str(), 610, 10, 20, BLACK);
		DrawText(levelText.c_str(), 610, 30, 20, BLACK);

		if (game.IsRunning())
		{
			if (IsKeyPressed(KEY_RIGHT)) {
				game.setLastKeyPressed(KEY_RIGHT);
				game.ProcessInput(KEY_RIGHT);


			}
			if (IsKeyPressed(KEY_LEFT)) {
				game.setLastKeyPressed(KEY_LEFT);
				game.ProcessInput(KEY_LEFT);

			}

			if (IsKeyPressed(KEY_UP)) {
				game.setLastKeyPressed(KEY_UP);
				game.ProcessInput(KEY_UP);

			}

			if (IsKeyPressed(KEY_DOWN)) {

				game.setLastKeyPressed(KEY_DOWN);
				game.ProcessInput(KEY_DOWN);
			}
			else if ((!IsKeyPressed(KEY_DOWN)) && (!IsKeyPressed(KEY_UP)) && (!IsKeyPressed(KEY_LEFT)) && (!IsKeyPressed(KEY_RIGHT))) {
				game.ProcessInput(game.getLastKeyPressed());
			}
			string info = to_string(game.getPlayer().GetX()) + to_string(game.getPlayer().GetY());
			DrawText(info.c_str(), 610, 70, 20, BLACK);
		}
		else
		{
			DrawText("You died!", 610, 50, 40, LIGHTGRAY);
			DrawText("Press e to play", 610, 80, 30, LIGHTGRAY);
			DrawText("again", 610, 100, 30, LIGHTGRAY);
			if (IsKeyPressed(KEY_E)) {
				game.Reset();
				game.Setup();
			}
		}

		const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));

		const auto grid = game.PrepareGrid();

		for (int x = 0; x < SIZE; x++)
		{
			for (int y = 0; y < SIZE; y++)
			{
				int xPosition = x * cellSize;
				int yPosition = y * cellSize;
				int lastKey = game.getLastKeyPressed();
				float rotation = 0;
				float tailRot = 0;
				switch (lastKey)
				{
				case KEY_RIGHT: rotation = 0; break;
				case KEY_LEFT: rotation = 180; break;
				case KEY_DOWN: rotation = 90; break;
				case KEY_UP: rotation = 270; break;
				default:
					break;
				}
				switch (grid[y][x])
				{
				
				case WALL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIGHTGRAY); break;
				case PLAYER:  DrawTexturePro(head, { 0.0f,0.0f,(float)head.width,(float)head.height }, { (float)xPosition+(cellSize/2),(float)yPosition + (cellSize / 2),(float)cellSize, (float)cellSize }, {(float) cellSize/2, (float)cellSize/2 }, rotation, WHITE); break;
				case FLOOR:  DrawTexturePro(bckGround, { 0.0f,0.0f,(float)bckGround.width,(float)bckGround.height }, { (float)xPosition+(cellSize/2),(float)yPosition + (cellSize / 2),(float)cellSize, (float)cellSize }, {(float) cellSize/2, (float)cellSize/2 }, 0.0f, WHITE); break;


				case OBSTACLE:  DrawTexturePro(wood, { 0.0f,0.0f,(float)wood.width,(float)wood.height }, 
					{ (float)xPosition + (cellSize/2),(float)yPosition + (cellSize/2),
					(float)cellSize, (float)cellSize }, 
					{(float) cellSize/2, (float)cellSize/2 },
					0.0f, WHITE); break;



				case PELLET:  DrawTexturePro(rat, { 0.0f,0.0f,(float)rat.width,(float)rat.height }, { (float)xPosition+(cellSize/2),(float)yPosition + (cellSize / 2),(float)cellSize, (float)cellSize }, {(float) cellSize/2, (float)cellSize/2 }, 0.0f, WHITE); break;
				case PLAYERTAIL:  DrawTexturePro(tail, { 0.0f,0.0f,(float)tail.width,(float)tail.height }, { (float)xPosition+(cellSize/2),(float)yPosition + (cellSize / 2),(float)cellSize, (float)cellSize }, {(float) cellSize/2, (float)cellSize/2 }, rotation, WHITE); break;
				//case PLAYERTAIL: DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLUE);  break;
				default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
				}



				// draw lines around each tile, remove this if you don't like it!
				//DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
			}
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}