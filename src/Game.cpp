//
// Created by Lukáš Blažek on 17.07.2025.
//

#include "Game.h"

#include <iostream>
#include <vector>
#include "raylib.h"
#include <__ostream/basic_ostream.h>

#include "Input.h"
#include "Player.h"

void Game::Init()
{
	m_player = new Player(400, 100);
	m_balls.push_back(new Ball(400, 700));
	m_balls.push_back(new Ball(650, 250));

	InitCamera();
}

void Game::Update(float dt)
{
	for (auto ball : m_balls)
	{
		ball->Update(dt);
	}
	addNewBall();
	m_player->Update(dt);
	m_player->CheckCollision(m_balls, dt);

	UpdateCamera();

}

void Game::Loop()
{
	while (!WindowShouldClose() && !GameEnded())
	{
		const float dt = GetFrameTime();

		Update(dt);

		BeginDrawing();
		ClearBackground(SKYBLUE);
		Draw();
		EndDrawing();

	}
}

void Game::Draw()
{
	int playerX = static_cast<int>(m_player->GetCenterPosition().x);
	int playerY = static_cast<int>(m_player->GetCenterPosition().y);
	int playerScore = playerY < 0 ? -static_cast<int>(m_player->GetCenterPosition().y)/100 : 0;
	BeginMode2D(camera);
		// background
		float parallaxSpeed = 0.5f; // background moves slower than camera
		float bgHeight = Resources::parallaxBackground.height * 2.0f; // scaled height

		float bgOffset = fmod(camera.target.y * parallaxSpeed, bgHeight);

		for (int i = -1; i <= 1; i++)
		{
			DrawTextureEx(Resources::parallaxBackground,
						  Vector2(-500, i * bgHeight - bgOffset),
						  0.0f, 2.0f, BLUE);
		}

		DrawText(std::to_string(playerScore).c_str(),
				playerX,
				playerY - 300,
				20,
				BLACK);

		m_player->Draw();

		for (auto ball : m_balls)
		{
			ball->Draw();
		}
	EndMode2D();

}

void Game::DeInit()
{
	delete m_player;
	for (auto ball : m_balls)
	{
		delete ball;
	}
}

void Game::InitCamera()
{
	camera.target = m_player->GetCenterPosition();
	camera.offset = Vector2
	(
		GameConstants::DEFAULT_WINDOW_WIDTH / 2,
		GameConstants::DEFAULT_WINDOW_HEIGHT / 2
	);
	camera.rotation = 0.0f;
	camera.zoom = 0.8f;
}

void Game::UpdateCamera()
{
	camera.target = { 400, m_player->GetCenterPosition().y };
}

void Game::addNewBall()
{
	double currentTime = GetTime();

	Vector2 playerPos = m_player->GetCenterPosition();

	if (currentTime - m_lastBallSpawnTime >= m_intervalOfBallSpawn)
		{
		m_balls.push_back(new Ball
		(
			static_cast<float>(GetRandomValue(playerPos.x - 300, playerPos.x + 300)),
			m_player->GetCenterPosition().y - 900
		));

		m_lastBallSpawnTime = currentTime;
		}
}

void Game::MenuLoop()
{
	while (!IsKeyReleased(KEY_SPACE) && !WindowShouldClose())
	{
		BeginDrawing();

		DrawTextureEx(Resources::parallaxBackground, Vector2(-500, 0), 0.0f, 2.0f, BLUE);
		DrawText
		(
			"Press SPACE to start",
			GetScreenWidth() / 2 - 225,
			GetScreenHeight() / 2,
			40,
			WHITE
		);
		EndDrawing();
	}
}

bool Game::GameEnded()
{
	if (m_player->GetSpeed() > 3000)
		return true;

	return false;
}
