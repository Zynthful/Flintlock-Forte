#include "Character.h"
#include "VelocityComponent.h"
#include "Sprite.h"
#include "ColliderComponent2D.h"

Character::Character(SDL_Renderer* _renderer, int _layer)
	: GameObject(_layer), renderer(_renderer)
{	
	// should be overriden in derived class
	SetName("Character");
	defaultSpritePath = "";

	// can be overriden in derived class
	speed = 7;
	acceleration = 3;
	deceleration = 5;
}

Character::~Character()
{
	delete sprite;
	delete velComp;
	delete collider;
}

void Character::Update(double deltaTime)
{
	GameObject::Update(deltaTime);
}

void Character::Move(Vector2 dir)
{
	velComp->StartAcceleratingTowards(dir * speed);
}

void Character::StopMoving()
{
	velComp->StartDecelerating();
}

void Character::SetAnimation(SpriteAnimInfo* info)
{
	if (sprite == nullptr)
	{
		// todo: initialise sprite comp if it's null
		// for now we just return
		return;
	}
	sprite->Set(info);
}

void Character::SetSpeed(float value)
{
	speed = value;
}