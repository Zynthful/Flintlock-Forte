#pragma once
#include "Component.h"
#include "SDL.h"
#include "Sprite.h"

class ColliderComponent2D : public Component
{
public:
	// create collider rect directly using a rect
	ColliderComponent2D(int _layer, SDL_Rect* rect);
	// create collider rect from position and width/height values
	ColliderComponent2D(int _layer, int _x, int _y, int _w, int _h);
	// create collider rect from sprite, using sprite rect as collider bounds
	ColliderComponent2D(int _layer, Sprite* sprite);

	~ColliderComponent2D();

public:
	SDL_Rect* GetRect() { return collider; }
	void SetRect(SDL_Rect* value) { collider = value; }

	int GetLayer() { return layer; }
	void SetLayer(int value) { layer = value; }

public:
	void OnBeginOverlap(ColliderComponent2D* collider);
	void OnEndOverlap(ColliderComponent2D* collider);
	void OnOverlapStay(ColliderComponent2D* collider);

	// Delegates
public:

private:
	SDL_Rect* collider = new SDL_Rect();

	int layer = 0;
};
