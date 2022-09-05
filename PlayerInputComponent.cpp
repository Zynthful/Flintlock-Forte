#include "PlayerInputComponent.h"
#include "Player.h"

PlayerInputComponent::PlayerInputComponent(Player* _player)
	: player(_player)
{

}

PlayerInputComponent::~PlayerInputComponent()
{

}

void PlayerInputComponent::Update(SDL_Event* e)
{
	switch (e->type)
	{
	case SDL_KEYDOWN:
	{
		switch (e->key.keysym.scancode)
		{
			// Movement
		case SDL_SCANCODE_W:
			OnMovementPressed(Vector2(0, 1));
			break;
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
		switch (e->key.keysym.scancode)
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