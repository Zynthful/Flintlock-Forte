#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "VelocityComponent.h"

class Character : public GameObject
{
public:
	Character(SDL_Renderer* _renderer, const char* _spritePath);
	~Character();

public:
	virtual void Update() override;

	// Movement
	void Move(Vector2 dir);
	void StopMoving();

public:
	// Getters/setters

	// Sprite
	Sprite* GetSprite() { return sprite; }
	void SetSprite(Sprite* value) { sprite = value; }

	// Movement
	float GetSpeed() { return speed; }
	void SetSpeed(float value);
	
	VelocityComponent* GetVelocityComponent() { return velComp; }

protected:
	Sprite* sprite;

	// Movement Settings
	float speed = 7;
	float acceleration = 3;
	float deceleration = 5;

	VelocityComponent* velComp = &AddComponent<VelocityComponent>(speed, acceleration, deceleration);

	SDL_Renderer* renderer;
};