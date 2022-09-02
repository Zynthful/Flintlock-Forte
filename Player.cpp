#include "Player.h"

Player::Player()
{
}

void Player::Move(Vector2 dir)
{
	pos.x += dir.x;
	pos.y += dir.y;
}