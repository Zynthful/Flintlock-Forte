#pragma once
#include "Character.h"
#include "GameLoop.h"
#include "PlayerInputComponent.h"

class Player : public Character
{
public:
	Player(SDL_Renderer* renderer);
	~Player();

	PlayerInputComponent* GetInputComponent();

private:
	PlayerInputComponent* input;
};