#include <iostream>

#include "Game.h"
#include "raylib.h"
#include "Resources.h"

int main()
{
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(60);
	InitWindow(800, 800, "BallJumper");

	Resources::LoadAllTextures();

	Game game;
	game.Init();

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();

		game.Update(dt);

		BeginDrawing();
			ClearBackground(SKYBLUE);
			game.Draw();
		EndDrawing();
	}

	Resources::UnloadAllTextures();
	game.DeInit();

	CloseWindow();
}
