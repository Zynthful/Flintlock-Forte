#include "Character.h"

Character::Character(SDL_Renderer* _renderer, const char* _spritePath)
	: renderer(_renderer)
{
	sprite = &AddComponent<Sprite>(_renderer, _spritePath, 4, 200, 200, 145, 16);
}

Character::~Character()
{
}

void Character::Update(double deltaTime)
{
	GameObject::Update(deltaTime);
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
