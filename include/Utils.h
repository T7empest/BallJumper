//
// Created by Lukáš Blažek on 19.07.2025.
//

#ifndef UTILS_H
#define UTILS_H
#include <raylib.h>

namespace Utils
{
	inline Vector2 Vector2Subtract(Vector2 vec1, Vector2 vec2)
	{
		return Vector2(vec1.x + vec2.x, vec1.y + vec2.y);
	}

	inline float GetDistance(Vector2 vec1, Vector2 vec2)
	{
		float dx = vec1.x - vec2.x;
		float dy = vec1.y - vec2.y;

		return sqrt((dx * dx) + (dy * dy));
	}
}

#endif //UTILS_H
