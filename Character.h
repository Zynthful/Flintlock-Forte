#pragma once
#include "GameObject.h"
#include "Sprite.h"

class Character : public GameObject
{
public:
	Character(SDL_Renderer* renderer);
	~Character();

public:
	// Sprite getter/setter
	Sprite* GetSprite();
	void SetSprite(Sprite* _sprite);

	// Movement
	void Move(Vector2 dir);

protected:
	Sprite* sprite;
};