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
		case SDL_SCANCODE_W:
			player->Move(Vector2(0, 1));
			break;
		case SDL_SCANCODE_A:
			player->Move(Vector2(-1, 0));
			break;
		case SDL_SCANCODE_S:
			player->Move(Vector2(0, -1));
			break;
		case SDL_SCANCODE_D:
			player->Move(Vector2(1, 0));
			break;
		}
		break;
	}
	case SDL_MOUSEBUTTONDOWN:
		break;
	case SDL_MOUSEBUTTONUP:
		break;
	}
}