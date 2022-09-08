#include "Character.h"

Character::Character(SDL_Renderer* _renderer, const char* _spritePath)
	: renderer(_renderer)
{
	sprite = &AddComponent<Sprite>(_renderer, _spritePath);
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
