#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "Vector2.h"
#include "Component.h"
#include "GameObject.h"

class Sprite : public Component
{
public:
	Sprite(SDL_Renderer* _renderer, const char* _path);
	~Sprite();
	
public:
	virtual void Render() override;
	
	SDL_Rect* GetRect();

private:
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
};