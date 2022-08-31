#pragma once

#include "Vector2.h"
#include "GameLoop.h"
#include "Sprite.h"

class Sprite;

class Player 
{
public:
	Player(SDL_Renderer* renderer);

	Vector2 pos;

	void Move(Vector2 dir);

	Sprite* GetSprite();

private:
	Sprite* sprite;

};