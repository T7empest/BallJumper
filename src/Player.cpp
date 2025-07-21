//
// Created by Lukáš Blažek on 18.07.2025.
//

#include "Player.h"

#include <iostream>
#include <vector>

#include "Input.h"
#include "Resources.h"
#include "Utils.h"

void Player::Draw()
{

	DrawTextureRec(*m_texture, m_textureContainer, m_position, WHITE);
}

void Player::Update(float dt)
{
	Move(dt);
	m_fallingSpeed += m_acceleration;
	m_position.y += m_fallingSpeed * dt;
	if (m_isGrounded)
		m_fallingSpeed = 0;
	else
		m_fallingSpeed += m_acceleration;
	m_acceleration = PLAYER_ACCELERATION;
	m_speed = PLAYER_SPEED;
	DrawText(std::to_string(m_isGrounded).c_str(), 50, 50, 12, RED);
}

void Player::Jump(float dt)
{
	m_acceleration -= 100;
	m_isGrounded = false;
}

void Player::Hold(float dt)
{
}

void Player::CheckCollision(std::vector<Ball*> balls)
{
	m_isGrounded = false;
	m_hitWall = false;
	for (const auto ball : balls)
	{
		if (CheckCollisionCircles(
				ball->GetPosition(),
				ball->GetRadius(),
				m_collisionCirclePos,
				m_collisionCircleRadius)
				)
		{
			CollisionDirection direction = GetCollisionDirection(ball);
			if (direction == CollisionDirection::DOWN)
			{
				m_acceleration = 0;
				m_isGrounded = true;
			}

			if (direction == CollisionDirection::LEFT || direction == CollisionDirection::RIGHT)
			{
				m_hitWall = true;
			}
			FixCollisionOverlap(ball);
		}

	}
}

CollisionDirection Player::GetCollisionDirection(Ball* ball)
{
	Vector2 delta = Utils::Vector2Subtract(m_collisionCirclePos, ball->GetPosition());
	float angle = atan2f(delta.y, delta.x) * (180.0f / PI); // in degrees

	if (angle >= -45 && angle <= 45)
		return CollisionDirection::RIGHT;
	if (angle > 45 && angle < 135)
		return CollisionDirection::DOWN;
	if (angle >= 135 || angle <= -135)
		return CollisionDirection::LEFT;
	return CollisionDirection::UP;
}

void Player::FixCollisionOverlap(Ball* ball)
{
	float centersDistance = Utils::GetDistance(m_collisionCirclePos, ball->GetPosition());
	float correctDistance = m_collisionCircleRadius + ball->GetRadius();

	// if (ball->GetPosition().x > m_position.x && Input::IsLeftHeld())
	// 	return;
	//
	// if (ball->GetPosition().x < m_position.x && Input::IsRightHeld())
	// 	return;

	if (centersDistance >= correctDistance)
		return;

	float overlap = correctDistance - centersDistance;

	float dx = m_collisionCirclePos.x - ball->GetPosition().x;
	float dy = m_collisionCirclePos.y - ball->GetPosition().y;

	float nx = dx / centersDistance;
	float ny = dy / centersDistance;

	m_position.x += nx * overlap;
	m_position.y += ny * overlap;

	m_collisionCirclePos.x = m_position.x + (abs(m_textureContainer.width) / 2);
	m_collisionCirclePos.y = m_position.y + (m_textureContainer.height / 2);
}


void Player::Move(float dt)
{

	if (Input::IsLeftHeld() && !m_hitWall)
	{
		m_position.x -= m_speed * dt;
		m_textureContainer.width = -abs(m_textureContainer.width);
	}
	if (Input::IsRightHeld() && !m_hitWall)
	{
		m_position.x += m_speed * dt;
		m_textureContainer.width = abs(m_textureContainer.width);
	}
	if (Input::IsJumpPressed() && m_isGrounded || Input::IsJumpPressed() && m_hitWall)
	{
		// TODO: fix the bug during jumping
		Jump(dt);
	}

	// bind the position of hitbox to player position
	m_collisionCirclePos.x = m_position.x + (abs(m_textureContainer.width) / 2);
	m_collisionCirclePos.y = m_position.y + 20 + (m_textureContainer.height / 2);
}

Vector2 Player::GetCenterPosition()
{
	float m_positionX = m_position.x + (abs(m_textureContainer.width) / 2);
	float m_positionY = m_position.y + 20 + (m_textureContainer.height / 2);

	return Vector2(m_positionX, m_positionY);
}
