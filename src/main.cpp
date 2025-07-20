#include <iostream>

#include "Game.h"
#include "raylib.h"
#include "Resources.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE (-1)

class Application
{
public:
	static void run()
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
			const float dt = GetFrameTime();

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
};

int main()
{
	try { Application::run(); }

	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}