#include "Player.h"

Player::Player()
{

}

Player::~Player()
{
	delete playerSprite;
}


void Player::Move(Vector2 dir)
{
	pos.x += dir.x;
	pos.y += dir.y;
}