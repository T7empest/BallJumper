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

private:
	std::vector<Ball*> m_balls;
	Player* m_player = nullptr;

	Camera2D camera = { 0 };
};


#endif //GAME_H
