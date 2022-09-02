#pragma once
#include "Character.h"
#include "GameLoop.h"

class Player : public Character
{
public:
	Player(SDL_Renderer* renderer);
	~Player();
};