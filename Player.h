#pragma once

#include "Vector2.h"
#include "GameLoop.h"

class Player 
{
public:
	Player();

	Vector2 pos;

	void Move(Vector2 dir);

};