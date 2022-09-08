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
			// don't call multiple KeyDowns if we're already holding
			if (wHeld)
				break;
			wHeld = true;
			OnMovementKeyPressed(Vector2::up);
			break;
		case SDL_SCANCODE_A:
			if (aHeld)
				break;
			aHeld = true;
			OnMovementKeyPressed(Vector2::left);
			break;
		case SDL_SCANCODE_S:
			if (sHeld)
				break;
			sHeld = true;
			OnMovementKeyPressed(Vector2::down);
			break;
		case SDL_SCANCODE_D:
			if (dHeld)
				break;
			dHeld = true;
			OnMovementKeyPressed(Vector2::right);
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
			OnMovementKeyReleased(Vector2::up);
			break;
		case SDL_SCANCODE_A:
			aHeld = false;
			OnMovementKeyReleased(Vector2::left);
			break;
		case SDL_SCANCODE_S:
			sHeld = false;
			OnMovementKeyReleased(Vector2::down);
			break;
		case SDL_SCANCODE_D:
			dHeld = false;
			OnMovementKeyReleased(Vector2::right);
			break;
		case SDL_SCANCODE_SPACE:
			OnDodgeReleased();
			break;
		}
		break;
	}
	case SDL_MOUSEBUTTONDOWN:
	{
		int x, y;	// mouse pos
		SDL_GetMouseState(&x, &y);
		OnAttackPressed(x, -y);
	}
		break;
	case SDL_MOUSEBUTTONUP:
		OnAttackReleased();
		break;
	}

	//std::cout << dir << std::endl;
}

void PlayerInputComponent::OnMovementKeyPressed(Vector2 _dir)
{
	// maybe check dir == _dir instead of checking for keys held?
	dir += _dir;
	player->Move(dir);
}

void PlayerInputComponent::OnMovementKeyReleased(Vector2 _dir)
{
	dir -= _dir;

	// only stop moving if our input isn't in any given direction
	if (dir == Vector2::zero)
	{
		player->StopMoving();
	}
	// otherwise continue moving in current direction
	else
	{
		player->Move(dir);
	}
}

void PlayerInputComponent::OnAttackPressed(int mouseX, int mouseY)
{
	Vector2 attackDir = (Vector2(mouseX, mouseY) - player->GetPosition()).Normalized();
	player->Attack(attackDir);
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