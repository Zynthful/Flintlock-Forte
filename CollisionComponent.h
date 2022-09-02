#pragma once
#include "SDL.h"

class CollisionComponent
{
public:
	CollisionComponent();
	~CollisionComponent();

public:
	void OnBeginOverlap();
	void OnEndOverlap();
	void OnOverlapStay();

private:
	SDL_Rect* collider;

	int layer;
};
