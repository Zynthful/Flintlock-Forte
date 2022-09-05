#pragma once
#include "GameObject.h"
#include "Sprite.h"

class Character : public GameObject
{
public:
	Character(SDL_Renderer* renderer);
	~Character();

public:
	// Movement
	void Move(Vector2 dir);
	void StopMoving();

public:
	// Getters/setters

	// Sprite
	Sprite* GetSprite() { return sprite; }
	void SetSprite(Sprite* value);

	// Movement
	float GetSpeed() { return speed; }
	void SetSpeed(float value);
	float GetAcceleration() { return acceleration; }
	void SetAcceleration(float value);
	float GetDeceleration() { return deceleration; }
	void SetDeceleration(float value);
	
	Vector2 GetVelocity() { return velocity; }

protected:
	Sprite* sprite;

	// Movement Settings
	float speed = 10;
	float acceleration = 1;
	float deceleration = 1;

	Vector2 velocity;

};