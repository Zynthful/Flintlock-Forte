#pragma once
#include "Character.h"
#include "PlayerInputComponent.h"
#include "ColliderComponent2D.h"

class Player : public Character
{
public:
	Player(SDL_Renderer* renderer);
	~Player();

	PlayerInputComponent* GetInputComponent();

private:
	// private copy constructor to prevent the creation of a player object
	Player(const Player&);

private:
	PlayerInputComponent* input;
	ColliderComponent2D* collider;
};