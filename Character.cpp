#include "Character.h"
#include "VelocityComponent.h"
#include "Sprite.h"
#include "ColliderComponent2D.h"

Character::Character(SDL_Renderer* _renderer, const char* _spritePath, int _layer)
	: renderer(_renderer)
{
	sprite = &AddComponent<Sprite>(_renderer, _spritePath);
	collider = &AddComponent<ColliderComponent2D>(_layer, sprite);
}

Character::Character(SDL_Renderer* _renderer, const char* _spritePath, SpriteAnimInfo* _animInfo, int _layer)
	: renderer(_renderer)
{
	sprite = &AddComponent<Sprite>(_renderer, _spritePath, _animInfo);
	collider = &AddComponent<ColliderComponent2D>(_layer, sprite);
}

Character::~Character()
{
}

void Character::Update(double deltaTime)
{
	GameObject::Update(deltaTime);
	
	if (sprite != nullptr)
	{
		collider->SetRect(sprite);
	}
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
