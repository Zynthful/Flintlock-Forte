#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "VelocityComponent.h"

class Character : public GameObject
{
public:
	Character(SDL_Renderer* renderer);
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
	void SetSprite(Sprite* value);

	// Movement
	float GetSpeed() { return speed; }
	void SetSpeed(float value);
	
	VelocityComponent* GetVelocityComponent() { return velComp; }

protected:
	Sprite* sprite;

	// Movement Settings
	int speed = 7;

	VelocityComponent* velComp = &AddComponent<VelocityComponent>(speed);

};