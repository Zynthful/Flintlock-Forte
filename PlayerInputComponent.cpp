#include "PlayerInputComponent.h"
#include "Player.h"

PlayerInputComponent::PlayerInputComponent(Player* _player)
	: player(_player)
{
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
			OnMovementPressed(Vector2(0, 1));
			return;
			// break yourself
		case SDL_SCANCODE_A:
			OnMovementPressed(Vector2(-1, 0));
			break;
		case SDL_SCANCODE_S:
			OnMovementPressed(Vector2(0, -1));
			break;
		case SDL_SCANCODE_D:
			OnMovementPressed(Vector2(1, 0));
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
			OnMovementReleased(Vector2(0, 1));
			break;
		case SDL_SCANCODE_A:
			OnMovementReleased(Vector2(-1, 0));
			break;
		case SDL_SCANCODE_S:
			OnMovementReleased(Vector2(0, -1));
			break;
		case SDL_SCANCODE_D:
			OnMovementReleased(Vector2(1, 0));
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
}

void PlayerInputComponent::OnMovementPressed(Vector2 dir)
{
	player->Move(dir);
}

void PlayerInputComponent::OnMovementReleased(Vector2 dir)
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