//
// Created by Lukáš Blažek on 18.07.2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>
#include <vector>

#include "Ball.h"
#include "Resources.h"

constexpr float PLAYER_SPEED = 350;
constexpr float PLAYER_ACCELERATION = 18;
constexpr float PLAYER_FALLING_SPEED = 350;
constexpr float PLAYER_JUMP_HEIGHT = 1000;

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

	void Draw() const;

	void Update(float dt);

	void Move(float dt);

	void Jump(float dt);

	void Hold(float dt);

	void CheckCollision(std::vector<Ball*> balls, float dt);

	CollisionDirection GetCollisionDirection(const Ball* ball) const;

	void FixCollisionOverlap(const Ball* ball);

	Vector2 GetCenterPosition() const;

	float GetSpeed() const;

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
	Ball* m_collidedBall;
};



#endif //PLAYER_H
