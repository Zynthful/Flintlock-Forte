#pragma once
#include "Character.h"
#include "PlayerInputComponent.h"
#include "ColliderComponent2D.h"

class Player : public Character
{
public:
	Player(SDL_Renderer* renderer, const char* spritePath);
	~Player();

private:
	// private copy constructor to prevent the creation of a player object
	Player(const Player&);

public:
	// Actions
	void Attack();
	void Deflect();
	void Dodge();

public:
	// Getters/setters
	PlayerInputComponent* GetInputComponent();

private:
	PlayerInputComponent* input;
	ColliderComponent2D* collider;
};