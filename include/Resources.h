//
// Created by Lukáš Blažek on 19.07.2025.
//

#ifndef RESOURCES_H
#define RESOURCES_H
#include <raylib.h>
#include <unordered_map>


namespace Resources
{
	extern Texture2D playerTexture;
	extern Texture2D balloonSpriteSheet;
	extern Texture2D parallaxBackground;

	void LoadAllTextures();
	void UnloadAllTextures();
}



#endif //RESOURCES_H
