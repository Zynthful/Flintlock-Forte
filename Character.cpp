#include "Character.h"

Character::Character(SDL_Renderer* renderer, const char* spritePath)
{
	sprite = new Sprite(renderer, spritePath);
	sprite->SetPosition(position);
}

Character::~Character()
{
	delete sprite;
}

void Character::Update()
{
	GameObject::Update();
	sprite->SetPosition(position);
}

void Character::SetSprite(Sprite* value)
{
	sprite = value;
}

void Character::SetSpeed(float value)
{
	speed = value;
}

void Character::Move(Vector2 dir)
{
	velComp->StartAcceleratingTowards(dir * speed);
}

void Character::StopMoving()
{
	velComp->StartDecelerating();
}
