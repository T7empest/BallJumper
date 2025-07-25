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
	void Draw();
	void DeInit();

	void InitCamera();
	void UpdateCamera();
	void addNewBall();

private:
	std::vector<Ball*> m_balls;

	Camera2D camera = { 0 };
	double m_lastBallSpawnTime = 0.0;
	const double m_intervalOfBallSpawn = 1.50;
	Player* m_player = nullptr;
};


#endif //GAME_H
