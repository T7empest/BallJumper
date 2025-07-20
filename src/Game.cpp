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
}

void Game::Update(float dt)
{
	m_player->CheckCollision(m_balls);
	m_player->Update(dt);
}

void Game::Draw()
{
	m_player->Draw();

	for (auto ball : m_balls)
	{
		ball->Draw();
	}
}

void Game::DeInit()
{
	delete m_player;
	for (auto ball : m_balls)
	{
		delete ball;
	}
}