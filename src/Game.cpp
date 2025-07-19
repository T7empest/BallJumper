//
// Created by Lukáš Blažek on 17.07.2025.
//

#include "Game.h"

#include "Player.h"

void Game::Init()
{
	m_player = new Player(400, 400);
	m_testBall = new Ball(400, 700);
}

void Game::Update(float dt)
{
	m_player->Move(dt);
}

void Game::Draw()
{
	m_player->Draw();
	m_testBall->Draw();
}

void Game::DeInit()
{
	delete m_player;
}