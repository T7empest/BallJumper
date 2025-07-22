//
// Created by Lukáš Blažek on 18.07.2025.
//

#include "Ball.h"

#include "Resources.h"

void Ball::Update(float dt)
{
	m_position.y += 50 * dt;
	m_center = Vector2(m_position.x + m_radius, m_position.y + m_radius + 17);
}

void Ball::Draw()
{
	float spriteWidth = static_cast<float>(Resources::balloonSpriteSheet.width) / 3;
	float spriteHeight = static_cast<float>(Resources::balloonSpriteSheet.height) / 4;
	m_textureContainer = {
		0.0f,
		0.0f,
		spriteWidth,
		spriteHeight - 12
	};

	if (m_balloonType == 1)
	{
		DrawTextureRec
		(
			Resources::balloonSpriteSheet,
			m_textureContainer,
			m_position,
			WHITE
		);
	}
	else if (m_balloonType == 2)
	{
		m_textureContainer.y = spriteHeight;
		DrawTextureRec
		(
			Resources::balloonSpriteSheet,
			m_textureContainer,
			m_position,
			WHITE
		);
	}
	else if (m_balloonType == 3)
	{
		m_textureContainer.y = 2 * spriteHeight;
		DrawTextureRec
		(
			Resources::balloonSpriteSheet,
			m_textureContainer,
			m_position,
			WHITE
		);
	}
	else if (m_balloonType == 4)
	{
		m_textureContainer.y = 3 * spriteHeight;
		DrawTextureRec
		(
			Resources::balloonSpriteSheet,
			m_textureContainer,
			m_position,
			WHITE
		);
	}
	else
	{
		throw std::runtime_error("failed to draw balloon");
	}
}

Vector2 Ball::GetCenter() const
{
	return m_center;
}

float Ball::GetRadius() const
{
	return m_radius;
}
