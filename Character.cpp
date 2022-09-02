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

Sprite* Character::GetSprite()
{
	return sprite;
}

void Character::SetSprite(Sprite* _sprite)
{
	sprite = _sprite;
}

void Character::Move(Vector2 dir)
{
	position = position + (dir * 20);
	sprite->SetPosition(position);
}