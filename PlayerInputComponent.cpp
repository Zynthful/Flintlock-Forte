#include "PlayerInputComponent.h"
#include "Player.h"

PlayerInputComponent::PlayerInputComponent(Player* _player)
	: player(_player)
{
	//player = static_cast<Character*>(GetOwner());
}

PlayerInputComponent::~PlayerInputComponent()
{
}

void PlayerInputComponent::UpdateInput(SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
	{
		// compare key pressed against last key pressed against.
		// if it matches, stop
		if (lastKeyPressed == e.key.keysym.scancode)
			break;

		// assign last key pressed to the key pressed
		lastKeyPressed = e.key.keysym.scancode;
		

		switch (e.key.keysym.scancode)
		{
			// Movement
		case SDL_SCANCODE_W:
			if (wHeld)
				break;
			wHeld = true;
			dir += Vector2::up;
			OnMovementKeyPressed(dir);
			break;
		case SDL_SCANCODE_A:
			if (aHeld)
				break;
			aHeld = true;
			dir += Vector2::left;
			OnMovementKeyPressed(dir);
			break;
		case SDL_SCANCODE_S:
			if (sHeld)
				break;
			sHeld = true;
			dir += Vector2::down;
			OnMovementKeyPressed(dir);
			break;
		case SDL_SCANCODE_D:
			if (dHeld)
				break;
			dHeld = true;
			dir += Vector2::right;
			OnMovementKeyPressed(dir);
			break;
			// Actions
		case SDL_SCANCODE_SPACE:
			OnDodgePressed();
			break;
		}
		break;
	}
	case SDL_KEYUP:
	{
		// reset last key pressed
		lastKeyPressed = SDL_Scancode::SDL_NUM_SCANCODES;

		switch (e.key.keysym.scancode)
		{
			// Movement
		case SDL_SCANCODE_W:
			wHeld = false;
			dir -= Vector2::up;
			OnMovementKeyPressed(dir);
			OnMovementKeyReleased();
			break;
		case SDL_SCANCODE_A:
			aHeld = false;
			dir -= Vector2::left;
			OnMovementKeyPressed(dir);
			OnMovementKeyReleased();
			break;
		case SDL_SCANCODE_S:
			sHeld = false;
			dir -= Vector2::down;
			OnMovementKeyPressed(dir);
			OnMovementKeyReleased();
			break;
		case SDL_SCANCODE_D:
			dHeld = false;
			dir -= Vector2::right;
			OnMovementKeyPressed(dir);
			OnMovementKeyReleased();
			break;
		case SDL_SCANCODE_SPACE:
			OnDodgeReleased();
			break;
		}
		break;
	}
	case SDL_MOUSEBUTTONDOWN:
		OnAttackPressed();
		break;
	case SDL_MOUSEBUTTONUP:
		OnAttackReleased();
		break;
	}

	//std::cout << dir << std::endl;
}

void PlayerInputComponent::OnMovementKeyPressed(Vector2 dir)
{
	player->Move(dir);
}

void PlayerInputComponent::OnMovementKeyReleased()
{
	// only stop moving if we aren't holding any movement keys still
	// maybe change to check for dir == 0?
	if (!wHeld && !aHeld && !sHeld && !dHeld)
	{
		player->StopMoving();
	}
}

void PlayerInputComponent::OnAttackPressed()
{
}

void PlayerInputComponent::OnAttackReleased()
{
}

void PlayerInputComponent::OnDeflectPressed()
{
}

void PlayerInputComponent::OnDeflectReleased()
{
}

void PlayerInputComponent::OnDodgePressed()
{
}

void PlayerInputComponent::OnDodgeReleased()
{
}