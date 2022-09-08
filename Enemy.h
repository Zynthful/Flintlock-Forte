#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(SDL_Renderer* renderer, const char* spritePath);
	~Enemy();
};