#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>

class Sprite;
class VelocityComponent;
struct SpriteAnimInfo;

class Character : public GameObject
{
public:
	Character(SDL_Renderer* _renderer, const char* _spritePath, int _layer = 0);
	Character(SDL_Renderer* _renderer, const char* _spritePath, SpriteAnimInfo* _animInfo, int _layer = 0);

	~Character();

public:
	virtual void Update(double deltaTime) override;

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

	ColliderComponent2D* collider = nullptr;
};