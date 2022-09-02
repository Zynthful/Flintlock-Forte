#pragma once
#include "SDL.h"

class Player;

class PlayerInputComponent
{
public:
	PlayerInputComponent(Player* _player);
	~PlayerInputComponent();

	void Update(SDL_Event* e);
private:
	Player* player;
};