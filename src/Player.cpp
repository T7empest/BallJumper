//
// Created by Lukáš Blažek on 18.07.2025.
//

#include "Player.h"

#include "Input.h"
#include "Resources.h"

void Player::Draw()
{

	DrawTextureRec(*m_texture, m_textureContainer, m_position, WHITE);
}

void Player::Jump(float dt)
{
}

void Player::Hold(float dt)
{
}

void Player::Move(float dt)
{

	if (Input::IsLeftHeld())
	{
		m_position.x -= m_speed * dt;
		m_textureContainer.width = -abs(m_textureContainer.width);
	}
	if (Input::IsRightHeld())
	{
		m_position.x += m_speed * dt;
		m_textureContainer.width = abs(m_textureContainer.width);

	}
}
