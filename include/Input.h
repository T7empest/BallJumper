//
// Created by Lukáš Blažek on 19.07.2025.
//

#ifndef INPUT_H
#define INPUT_H
#include <raylib.h>

namespace Input
{
	inline bool IsLeftHeld()
	{
		return IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT);
	}
	inline bool IsRightHeld()
	{
		return IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT);
	}
	inline bool IsJumpPressed()
	{
		return IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_W) || IsKeyDown(KEY_UP);
	}
}

#endif //INPUT_H
