#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

class Sprite
{
public:
	Sprite(SDL_Renderer* _renderer, const char* _path);
	~Sprite();
	
public:
	void Render();

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
};