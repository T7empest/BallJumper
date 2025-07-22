//
// Created by Lukáš Blažek on 18.07.2025.
//

#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <raylib.h>
#include <__ostream/basic_ostream.h>


class Ball {
public:
	Ball(float posX, float posY)
		: m_position(Vector2(posX, posY))
	{
		m_balloonType = GetRandomValue(1, 4);
	}

	void Update(float dt);
	void Draw();

	Vector2 GetCenter() const;
	float GetRadius() const;

private:
	Vector2 m_position;
	Vector2 m_center;
	float m_radius = 73;
	int m_balloonType;
	Rectangle m_textureContainer = {};
};



#endif //BALL_H
