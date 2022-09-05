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
	void OnBeginOverlap();
	void OnEndOverlap();
	void OnOverlapStay();

private:
	SDL_Rect* collider = new SDL_Rect();

	int layer = 0;
};
