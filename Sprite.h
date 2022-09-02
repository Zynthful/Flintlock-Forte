#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "Vector2.h"

class Sprite
{
public:
	Sprite(SDL_Renderer* _renderer, const char* _path);
	~Sprite();
	
public:
	void Render();

	void SetPosition(Vector2 _position);

private:
	Vector2 position;

	SDL_Texture* texture;
	SDL_Renderer* renderer;
};