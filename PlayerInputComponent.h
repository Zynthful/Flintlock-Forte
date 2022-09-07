#pragma once
#include "Component.h"
#include "SDL.h"
#include "Vector2.h"

class Player;
class Vector2;

class PlayerInputComponent : public Component
{
public:
	PlayerInputComponent(Player* _player);
	~PlayerInputComponent();

	void UpdateInput(SDL_Event& e);

	void OnMovementKeyPressed(Vector2 dir);
	void OnMovementKeyReleased(Vector2 dir);
	void OnAttackPressed();
	void OnAttackReleased();
	void OnDeflectPressed();
	void OnDeflectReleased();
	void OnDodgePressed();
	void OnDodgeReleased();

private:
	// pointer to player
	// as a component, should just get owner instead
	// and cast to Player class?
	Player* player;

	// this warning means nothing
	// fuck off
	// initialised to SDL_NUM_SCANCODES to basically mean none
	// reset on key up
	SDL_Scancode lastKeyPressed = SDL_Scancode::SDL_NUM_SCANCODES;

	Vector2 dir = Vector2(0, 0);
	bool wHeld = false;
	bool aHeld = false;
	bool sHeld = false;
	bool dHeld = false;
};