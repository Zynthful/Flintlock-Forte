#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, const char* spritePath)
	: Character(renderer, spritePath)
{
}

Enemy::Enemy(SDL_Renderer* renderer, const char* spritePath, SpriteAnimInfo* _animInfo)
	: Character(renderer, spritePath)
{
}

Enemy::~Enemy()
{
}