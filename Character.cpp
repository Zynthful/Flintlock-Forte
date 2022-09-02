#include "Character.h"

Character::Character(SDL_Renderer* renderer)
{
	sprite = new Sprite(renderer, "assets/PlayerSprite.png");
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

}