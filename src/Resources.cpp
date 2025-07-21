//
// Created by Lukáš Blažek on 19.07.2025.
//

#include "../include/Resources.h"

#define ASSET_PATH "../../assets/"


Texture2D Resources::playerTexture = {};

void Resources::LoadAllTextures()
{
	playerTexture = LoadTexture(ASSET_PATH "Player/player_idle.png");
}

void Resources::UnloadAllTextures()
{
	UnloadTexture(playerTexture);
}
