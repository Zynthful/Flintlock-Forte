#include "Character.h"

Character::Character(SDL_Renderer* renderer)
{
	sprite = new Sprite(renderer, "assets/PlayerSprite.png");
	sprite->SetPosition(position);
}

Character::~Character()
{
	delete sprite;
}

void Character::SetSprite(Sprite* value)
{
	sprite = value;
}

void Character::SetSpeed(float value)
{
	speed = value;
}

void Character::SetAcceleration(float value)
{
	acceleration = value;
}

void Character::SetDeceleration(float value)
{
	deceleration = value;
}

void Character::Move(Vector2 dir)
{
	velocity = dir * speed;	// temp, does not enforce accel/decel
	position += velocity;
	sprite->SetPosition(position);
}

void Character::StopMoving()
{
}
