//
// Created by Lukáš Blažek on 18.07.2025.
//

#ifndef BALL_H
#define BALL_H
#include <raylib.h>


class Ball {
public:
	Ball(float posX, float posY)
		: m_position(Vector2(posX, posY)) {}

	void Draw();

	Vector2 GetPosition();
	float GetRadius();

private:
	Vector2 m_position;
	float m_radius = 50;
};



#endif //BALL_H
