#include "Player.h"

Player::Player(SDL_Renderer* renderer)
	: Character(renderer)
{
	input = new PlayerInputComponent(this);
}

Player::~Player()
{
	delete input;
	delete collider;
}

void Player::Attack()
{
}

void Player::Deflect()
{
}

void Player::Dodge()
{
}

PlayerInputComponent* Player::GetInputComponent()
{
	return input;
}
