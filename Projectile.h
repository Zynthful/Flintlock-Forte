#pragma once
#include "GameObject.h"
#include "ColliderComponent2D.h"
#include "VelocityComponent.h"

class Projectile : public GameObject
{
public:
	Projectile(SDL_Renderer* _renderer, const char* _spritePath, Vector2 _dir, Vector2 _pos);
	~Projectile();

private:
	ColliderComponent2D* collider = nullptr;
	VelocityComponent* velComp = nullptr;
	Sprite* sprite = nullptr;

	float maxSpeed = 3.0f;
	float acceleration = 3.0f;
	float deceleration = 3.0f;
};

