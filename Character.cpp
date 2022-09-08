#include "Character.h"
#include "VelocityComponent.h"
#include "Sprite.h"

Character::Character(SDL_Renderer* _renderer, const char* _spritePath)
	: renderer(_renderer)
{
	sprite = &AddComponent<Sprite>(_renderer, _spritePath);
}

Character::Character(SDL_Renderer* _renderer, const char* _spritePath, SpriteAnimInfo* _animInfo)
	: renderer(_renderer)
{
	sprite = &AddComponent<Sprite>(_renderer, _spritePath, _animInfo);
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
