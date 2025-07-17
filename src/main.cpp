#include <iostream>

#include "Game.h"
#include "raylib.h"

int main()
{
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(60);
	InitWindow(800, 800, "BallJumper");

	Game game;
	game.Init();

	while (!WindowShouldClose())
	{
		game.Update();
		BeginDrawing();
		ClearBackground(SKYBLUE);
		game.Draw();
		EndDrawing();
	}
	CloseWindow();
}