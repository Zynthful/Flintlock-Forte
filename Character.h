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
	Character(SDL_Renderer* _renderer, int _layer = 0);

	~Character();

public:
	// GameObject function overrides
	virtual void Update(double deltaTime) override;

public:
	// Movement
	void Move(Vector2 dir);
	void StopMoving();

public:
	// Movement get/set
	float GetSpeed() { return speed; }
	void SetSpeed(float value);
	
	// Components get/set
	Sprite* GetSprite() { return sprite; }

protected:
	// SDL pointers
	SDL_Renderer* renderer;

	// Components
	ColliderComponent2D* collider;
	VelocityComponent* velComp;

	// Sprite/anim settings
	Sprite* sprite;
	const char* defaultSpritePath;
	std::vector<SpriteAnimInfo> anims;

	// Movement Settings
	float speed;
	float acceleration;
	float deceleration;
};