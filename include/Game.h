//
// Created by Lukáš Blažek on 17.07.2025.
//

#ifndef GAME_H
#define GAME_H
#include <memory>

#include "Ball.h"
#include "Player.h"


class Game {
public:
	void Init();
	void Update(float dt);
	void Draw();
	void DeInit();

private:
	Player* m_player = nullptr;
	Ball* m_testBall = nullptr;
};



#endif //GAME_H
