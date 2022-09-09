#pragma once
#include "Character.h"
#include "PlayerInputComponent.h"
#include "ColliderComponent2D.h"
#include "Projectile.h"

class PlayerHealthComponent;

class Player : public Character
{
public:
	Player(SDL_Renderer* _renderer, const char* _spritePath, int _layer = 0);
	Player(SDL_Renderer* _renderer, const char* _spritePath, SpriteAnimInfo* _animInfo, int _layer = 0);
	~Player();

private:
	// private copy constructor to prevent the creation of a player object
	Player(const Player&);

public:
	// Actions
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
	const char* bulSpritePath = "assets/Projectile/FlintlockBullet.png";
};