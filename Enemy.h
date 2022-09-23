#pragma once
#include "Character.h"
#include "EnemyHealthComponent.h"
#include <math.h>

class EnemyHealthComponent;

class Enemy : public Character
{
public:
	Enemy(SDL_Renderer* renderer, int _layer = 0);
	~Enemy();

public:
	virtual void Update(double deltaTime) override;
	
public:
	void SetTarget(GameObject* obj) { target = obj; }
	void Attack(Vector2 dir);

public:
	//EnemyHealthComponent* GetHealthComponent() { return health; }

private:
	GameObject* target = nullptr;	// target obj to move towards
	//EnemyHealthComponent* health;

	const float attackDistance = 100.0f;

	EnemyHealthComponent* health;
};