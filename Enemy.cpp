#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, const char* spritePath)
	: Character(renderer, spritePath)
{
}

Enemy::~Enemy()
{
}