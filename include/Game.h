//
// Created by Lukáš Blažek on 17.07.2025.
//

#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>

#include "Ball.h"
#include "Player.h"

namespace GameConstants
{
	inline constexpr int DEFAULT_WINDOW_WIDTH{800};
	inline constexpr int DEFAULT_WINDOW_HEIGHT{800};
}

class Game {
public:
	void Init();
	void Update(float dt);
	void Loop();
	void Draw();
	void DeInit();

	void MenuLoop();
	bool GameEnded();

	void InitCamera();
	void UpdateCamera();
	void addNewBall();

private:

	std::vector<Ball*> m_balls;

	Camera2D camera = { 0 };
	double m_lastBallSpawnTime = 0.0f;
	const double m_intervalOfBallSpawn = 1.50f;
	Player* m_player = nullptr;

	// background
	float m_scrollingBack = 0.0f;
	float m_scrollingFront = 0.0f;
};


#endif //GAME_H
