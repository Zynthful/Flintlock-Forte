#pragma once
#include "Character.h"
#include "EnemyHealthComponent.h"

class Enemy : public Character
{
	// forward declare won't work???
	//class EnemyHealthComponent;

public:
	Enemy(SDL_Renderer* renderer, const char* spritePath);
	Enemy(SDL_Renderer* renderer, const char* spritePath, SpriteAnimInfo* _animInfo);
	~Enemy();

public:
	EnemyHealthComponent* GetHealthComponent() { return health; }

private:
	EnemyHealthComponent* health = nullptr;
};