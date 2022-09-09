#pragma once
#include "Character.h"
#include "EnemyHealthComponent.h"
#include <math.h>

class EnemyHealthComponent;

class Enemy : public Character
{
public:
	Enemy(SDL_Renderer* renderer, const char* spritePath);
	Enemy(SDL_Renderer* renderer, const char* spritePath, SpriteAnimInfo* _animInfo);
	~Enemy();

public:
	virtual void Update(double deltaTime) override;
	
	void SetTarget(GameObject* obj) { target = obj; }
	void Attack(Vector2 dir);

public:
	EnemyHealthComponent* GetHealthComponent() { return health; }

private:
	GameObject* target = nullptr;	// target obj to move towards
	EnemyHealthComponent* health = nullptr;

	const float attackDistance = 100.0f;
};