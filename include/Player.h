//
// Created by Lukáš Blažek on 18.07.2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>

#include "Resources.h"


class Player {
public:
	Player(float posX, float posY)
		: m_position(Vector2(posX, posY)) {}

	void Draw();

	void Move(float dt);

	void Jump(float dt);

	void Hold(float dt);

private:
	Vector2 m_position;
	float m_speed = 100;

	Texture2D* m_texture = &Resources::playerTexture;
	Rectangle m_textureContainer = {
		0,
		0,
		static_cast<float>((*m_texture).width),
		static_cast<float>((*m_texture).height)
	};
};



#endif //PLAYER_H
