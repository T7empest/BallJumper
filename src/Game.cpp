//
// Created by Lukáš Blažek on 17.07.2025.
//

#include "Game.h"

#include <iostream>
#include <vector>
#include <__ostream/basic_ostream.h>

#include "Player.h"

void Game::Init()
{
	m_player = new Player(400, 100);
	m_balls.push_back(new Ball(400, 700));
	m_balls.push_back(new Ball(750, -150));

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

void Game::Draw()
{
	BeginMode2D(camera);
		m_player->Draw();
		float playerPos (m_player->GetCenterPosition().y / 10);

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
	camera.target = m_player->GetCenterPosition();
}

void Game::addNewBall()
{
	double currentTime = GetTime();

	Vector2 playerPos = m_player->GetCenterPosition();

	if (currentTime - m_lastBallSpawnTime >= m_intervalOfBallSpawn)
		{
		m_balls.push_back(new Ball
		(
			static_cast<float>(GetRandomValue(playerPos.x - 1000, playerPos.x + 1000)),
			m_player->GetCenterPosition().y - 800
		));

		m_lastBallSpawnTime = currentTime;
		}
}

