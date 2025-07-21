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

	InitCamera();
}

void Game::Update(float dt)
{
	m_player->CheckCollision(m_balls);
	m_player->Update(dt);
	UpdateCamera();
}

void Game::Draw()
{
	BeginMode2D(camera);
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
	camera.zoom = 0.5f;
}

void Game::UpdateCamera()
{
	camera.target = m_player->GetCenterPosition();
}

