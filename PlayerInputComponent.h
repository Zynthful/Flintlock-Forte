#pragma once
#include "Component.h"
#include "SDL.h"

class Player;

class PlayerInputComponent : public Component
{
public:
	PlayerInputComponent(Player* _player);
	~PlayerInputComponent();

	void Update(SDL_Event* e);
private:
	Player* player;
};