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
			wHeld = true;
			dir += Vector2::up;
			OnMovementPressed(dir);
			break;
		case SDL_SCANCODE_A:
			aHeld = true;
			dir += Vector2::left;
			OnMovementPressed(dir);
			break;
		case SDL_SCANCODE_S:
			sHeld = true;
			dir += Vector2::down;
			OnMovementPressed(dir);
			break;
		case SDL_SCANCODE_D:
			dHeld = true;
			dir += Vector2::right;
			OnMovementPressed(dir);
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
			dir -= Vector2::up;
			wHeld = false;
			if (!wHeld && !aHeld && !sHeld && !dHeld)
			{
				OnMovementReleased();
			}
			break;
		case SDL_SCANCODE_A:
			dir -= Vector2::left;
			aHeld = false;
			if (!wHeld && !aHeld && !sHeld && !dHeld)
			{
				OnMovementReleased();
			}
			break;
		case SDL_SCANCODE_S:
			sHeld = false;
			dir -= Vector2::down;
			if (!wHeld && !aHeld && !sHeld && !dHeld)
			{
				OnMovementReleased();
			}
			break;
		case SDL_SCANCODE_D:
			dHeld = false;
			dir -= Vector2::right;
			if (!wHeld && !aHeld && !sHeld && !dHeld)
			{
				OnMovementReleased();
			}
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

void PlayerInputComponent::OnMovementPressed(Vector2 dir)
{
	player->Move(dir);
}

void PlayerInputComponent::OnMovementReleased()
{
	player->StopMoving();
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