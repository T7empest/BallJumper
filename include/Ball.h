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

private:
	Vector2 m_position;
};



#endif //BALL_H
