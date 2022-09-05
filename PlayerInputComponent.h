#pragma once
#include "Component.h"
#include "SDL.h"

class Player;
class Vector2;

class PlayerInputComponent : public Component
{
public:
	PlayerInputComponent(Player* _player);
	~PlayerInputComponent();

	void Update(SDL_Event* e);

	void OnMovementPressed(Vector2 dir);
	void OnMovementReleased(Vector2 dir);
	void OnAttackPressed();
	void OnAttackReleased();
	void OnDeflectPressed();
	void OnDeflectReleased();
	void OnDodgePressed();
	void OnDodgeReleased();

private:
	Player* player;
};