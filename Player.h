#pragma once
#include "Character.h"
#include <SDL.h>
#include <SDL_image.h>
#include "PlayerHealthComponent.h"
#include "PlayerInputComponent.h"

class Projectile;
class ColliderComponent2D;

class Player : public Character
{
public:
	Player(SDL_Renderer* _renderer, int _layer = 0);
	~Player();

public:
	// Actions
	virtual void Move(Vector2 dir) override;
	virtual void StopMoving() override;

	void Attack(Vector2 dir);
	void Deflect();
	void Dodge();

public:
	// Getters/setters
	PlayerInputComponent* GetInputComponent() { return input; }
	PlayerHealthComponent* GetHealthComponent() { return health; }

private:
	PlayerInputComponent* input = nullptr;
	PlayerHealthComponent* health = nullptr;

	Vector2 bulSpawnOffset = Vector2(100, -50);
};