#pragma once

#include "Vector2.h"
#include "GameLoop.h"
#include "Sprite.h"

class Player 
{
public:
	Player();
	~Player();

	Vector2 pos;

	void Move(Vector2 dir);

	Sprite* playerSprite = NULL;

};