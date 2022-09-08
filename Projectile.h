#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>

class ColliderComponent2D;
class VelocityComponent;
class Sprite;

class Projectile : public GameObject
{
public:
	Projectile(SDL_Renderer* _renderer, const char* _spritePath, Vector2 _dir, Vector2 _pos);
	~Projectile();

public:
	virtual void OnBeginOverlap(ColliderComponent2D* source, ColliderComponent2D* other) override;
	virtual void OnEndOverlap(ColliderComponent2D* source, ColliderComponent2D* other) override;
	virtual void OnOverlapStay(ColliderComponent2D* source, ColliderComponent2D* other) override;

private:
	ColliderComponent2D* collider = nullptr;
	VelocityComponent* velComp = nullptr;
	Sprite* sprite = nullptr;

	float maxSpeed = 20.0f;
	float acceleration = 30.0f;
	float deceleration = 30.0f;

	void OnBeginOverlap(ColliderComponent2D* collider);
};

