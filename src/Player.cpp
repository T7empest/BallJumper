//
// Created by Lukáš Blažek on 18.07.2025.
//

#include "Player.h"

#include <iostream>
#include <vector>

#include "Input.h"
#include "Resources.h"
#include "Utils.h"

void Player::Draw() const
{
	DrawTextureRec(*m_texture, m_textureContainer, m_position, WHITE);
	DrawText(std::to_string(m_fallingSpeed).c_str(), m_position.x, m_position.y, 20, RED);
	DrawText(std::to_string(m_position.y / 100).c_str(), m_position.x, m_position.y - 100, 20, BLACK);
}

void Player::Update(float dt)
{
	Move(dt);
	if (!m_isGrounded)
	{
		m_fallingSpeed += m_acceleration;
		m_position.y += m_fallingSpeed * dt;
	}
	else
	{
		m_fallingSpeed = 0;
	}
	m_acceleration = PLAYER_ACCELERATION;
	m_speed = PLAYER_SPEED;
	if (m_isGrounded)
	{
		m_fallingSpeed = 0;
		m_acceleration = 0;
	}
}

void Player::Jump(float dt)
{
	if (CheckCollisionCircles
		(
			m_collisionCirclePos,
			m_collisionCircleRadius,
			m_collidedBall->GetCenter(),
			m_collidedBall->GetRadius() + 25.0f
		)
	)
	{
		m_fallingSpeed = -PLAYER_JUMP_HEIGHT;
		m_isGrounded = false;
	}
}

void Player::Hold(float dt)
{
}

void Player::CheckCollision(std::vector<Ball*> balls, float dt)
{

	// bind the position of hitbox to player position
	m_collisionCirclePos.x = m_position.x + (abs(m_textureContainer.width) / 2);
	m_collisionCirclePos.y = m_position.y + 20 + (m_textureContainer.height / 2);
	bool collided = false;
	for (const auto ball : balls)
	{
		if (CheckCollisionCircles(m_collisionCirclePos, m_collisionCircleRadius, ball->GetCenter(), ball->GetRadius()))
		{
			collided = true;
			FixCollisionOverlap(ball);
			CollisionDirection direction = GetCollisionDirection(ball);
			if (direction == CollisionDirection::DOWN)
			{
				m_acceleration = 0;
				m_isGrounded = true;
				m_position.y += ball->GetSpeed() * dt;
			}
			if (direction == CollisionDirection::LEFT || direction == CollisionDirection::RIGHT)
			{
				m_hitWall = true;
				m_position.y += ball->GetSpeed() * dt;
			}
			m_collidedBall = ball;
			break; // stop checking other balls once you hit one
		}
		m_isGrounded = false;
		m_hitWall = false;
	}

}

CollisionDirection Player::GetCollisionDirection(const Ball* ball) const
{
	Vector2 delta = Utils::Vector2Subtract(m_collisionCirclePos, ball->GetCenter());
	float distance = Utils::GetDistance(m_collisionCirclePos, ball->GetCenter());
	if (distance == 0.0f)
		return CollisionDirection::UP;

	Vector2 normal = { delta.x / distance, delta.y / distance };

	const Vector2 up = { 0.0f, -1.0f };
	const Vector2 down = { 0.0f, 1.0f };
	const Vector2 left = { -1.0f, 0.0f };
	const Vector2 right = { 1.0f, 0.0f };

	float dotUp = Utils::DotProduct(normal, up);
	float dotDown = Utils::DotProduct(normal, down);
	float dotLeft = Utils::DotProduct(normal, left);
	float dotRight = Utils::DotProduct(normal, right);

	float maxDot = dotUp;
	CollisionDirection dir = CollisionDirection::UP;

	if (dotDown > maxDot) {
		maxDot = dotDown;
		dir = CollisionDirection::DOWN;
	}
	if (dotLeft > maxDot) {
		maxDot = dotLeft;
		dir = CollisionDirection::LEFT;
	}
	if (dotRight > maxDot) {
		maxDot = dotRight;
		dir = CollisionDirection::RIGHT;
	}

	return dir;
}


void Player::FixCollisionOverlap(const Ball* ball)
{

	float centersDistance = Utils::GetDistance(m_collisionCirclePos, ball->GetCenter());
	float correctDistance = m_collisionCircleRadius + ball->GetRadius();

	// if (ball->GetPosition().x > m_position.x && Input::IsLeftHeld())
	// 	return;
	//
	// if (ball->GetPosition().x < m_position.x && Input::IsRightHeld())
	// 	return;

	if (centersDistance >= correctDistance + 5.0f)
		return;

	float overlap = correctDistance - centersDistance;

	float dx = m_collisionCirclePos.x - ball->GetCenter().x;
	float dy = m_collisionCirclePos.y - ball->GetCenter().y;

	float nx = dx / centersDistance;
	float ny = dy / centersDistance;

	m_position.x += nx * overlap;
	m_position.y += ny * overlap;

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
	if (Input::IsJumpPressed())
	{
		Jump(dt);
	}


}

Vector2 Player::GetCenterPosition() const
{
	float m_positionX = m_position.x + (abs(m_textureContainer.width) / 2);
	float m_positionY = m_position.y + 20 + (m_textureContainer.height / 2);

	return Vector2(m_positionX, m_positionY);
}

float Player::GetSpeed() const
{
	return m_fallingSpeed;
}
