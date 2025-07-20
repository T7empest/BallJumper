//
// Created by Lukáš Blažek on 17.07.2025.
//

#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>

#include "Ball.h"
#include "Player.h"


class Game {
public:
	void Init();
	void Update(float dt);
	void Draw();
	void DeInit();

private:
	std::vector<Ball*> m_balls;
	Player* m_player = nullptr;
};



#endif //GAME_H
