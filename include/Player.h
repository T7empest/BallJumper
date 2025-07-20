//
// Created by Lukáš Blažek on 18.07.2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>
#include <vector>

#include "Ball.h"
#include "Resources.h"

constexpr float PLAYER_SPEED = 100;
constexpr float PLAYER_ACCELERATION = 3;
constexpr float PLAYER_FALLING_SPEED = 150;

enum class CollisionDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};


class Player {
public:
	Player(float posX, float posY)
		: m_position(Vector2(posX, posY)) {}

	void Draw();

	void Update(float dt);

	void Move(float dt);

	void Jump(float dt);

	void Hold(float dt);

	void CheckCollision(std::vector<Ball*> balls);

	CollisionDirection GetCollisionDirection(Ball* ball);

	void FixCollisionOverlap(Ball* ball);

private:
	Vector2 m_position;
	float m_speed = PLAYER_SPEED;
	float m_fallingSpeed = PLAYER_FALLING_SPEED;
	float m_acceleration = PLAYER_ACCELERATION;

	Texture2D* m_texture = &Resources::playerTexture;
	Rectangle m_textureContainer = {
		0,
		0,
		static_cast<float>(m_texture->width),
		static_cast<float>(m_texture->height)
	};

	Vector2 m_collisionCirclePos = {}; // bound => set every frame
	float m_collisionCircleRadius = 40;

	bool m_isGrounded = false;
	bool m_hitWall = false;
};



#endif //PLAYER_H
