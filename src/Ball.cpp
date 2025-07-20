//
// Created by Lukáš Blažek on 18.07.2025.
//

#include "Ball.h"

void Ball::Draw()
{
	DrawCircleV(m_position, m_radius, RED);
}

Vector2 Ball::GetPosition()
{
	return m_position;
}

float Ball::GetRadius()
{
	return m_radius;
}
