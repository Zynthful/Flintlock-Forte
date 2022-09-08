#include "Character.h"

Character::Character(SDL_Renderer* renderer, const char* spritePath)
{
	sprite = &AddComponent<Sprite>(renderer, spritePath);
}

Character::~Character()
{
}

void Character::Update()
{
	GameObject::Update();
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
