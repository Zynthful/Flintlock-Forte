#include "Player.h"

Player::Player(SDL_Renderer* renderer)
{
	sprite = new Sprite(renderer, "assets/PlayerSprite.png");
}

void Player::Move(Vector2 dir)
{
	pos.x += dir.x;
	pos.y += dir.y;
}

Sprite* Player::GetSprite()
{
	return sprite;
}
