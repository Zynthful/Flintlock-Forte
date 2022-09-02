#include "Player.h"

Player::Player(SDL_Renderer* renderer)
	: Character(renderer)
{
	input = new PlayerInputComponent(this);
}

Player::~Player()
{

}

PlayerInputComponent* Player::GetInputComponent()
{
	return input;
}
