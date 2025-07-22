//
// Created by Lukáš Blažek on 19.07.2025.
//

#include "../include/Resources.h"

#define ASSET_PATH "../../assets/"


Texture2D Resources::playerTexture = {};
Texture2D Resources::balloonSpriteSheet = {};

void Resources::LoadAllTextures()
{
	playerTexture = LoadTexture(ASSET_PATH "Player/player_idle.png");
	balloonSpriteSheet = LoadTexture(ASSET_PATH "Balloon/Balloons.png");
}

void Resources::UnloadAllTextures()
{
	UnloadTexture(playerTexture);
	UnloadTexture(balloonSpriteSheet);
}
