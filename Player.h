#pragma once
#include "Character.h"
#include "PlayerInputComponent.h"
#include "ColliderComponent2D.h"
#include "Projectile.h"

class Player : public Character
{
public:
	Player(SDL_Renderer* _renderer, const char* _spritePath);
	Player(SDL_Renderer* _renderer, const char* _spritePath, SpriteAnimInfo* _animInfo);
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
	PlayerInputComponent* GetInputComponent();

private:
	PlayerInputComponent* input;

	Vector2 bulSpawnOffset = Vector2(100, -50);
	const char* bulSpritePath = "assets/Projectile/FlintlockBullet.png";
};