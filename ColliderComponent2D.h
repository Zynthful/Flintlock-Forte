#pragma once
#include "Component.h"
#include "SDL.h"
#include "Sprite.h"

class ColliderComponent2D : public Component
{
public:
	// create collider rect directly using a rect
	ColliderComponent2D(SDL_Rect* rect);
	// create collider rect from position and width/height values
	ColliderComponent2D(int _x, int _y, int _w, int _h);
	// create collider rect from sprite, using sprite rect as collider bounds
	ColliderComponent2D(Sprite* sprite);

	~ColliderComponent2D();

public:
	virtual void Update(double deltaTime) override;

public:
	SDL_Rect* GetRect() { return collider; }
	void SetRect(SDL_Rect* value) { collider = value; }
	void SetRect(int x, int y, int w, int h);
	void SetRect(Sprite* sprite);

public:
	void OnBeginOverlap(ColliderComponent2D* collider);
	void OnEndOverlap(ColliderComponent2D* collider);
	void OnOverlapStay(ColliderComponent2D* collider);

	// Delegates
public:

private:
	SDL_Rect* collider = new SDL_Rect();

	Sprite* sprite = nullptr;
};
