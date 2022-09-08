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
	Sprite(SDL_Renderer* _renderer, const char* _path, int animNumSprites, int pxInterval, int pxWidth, int pxHeight, float animFPS = 8.0f);
	~Sprite();
	
public:
	virtual void Render() override;
	virtual void Update() override;
	
	SDL_Rect* GetRect();

	void NextFrame();

private:
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	int animNumSprites = 1;
	int animPxInterval = 32;
	int animPxWidth = 200;
	int animPxHeight = 45;
	float animFPS = 8.0f;
	int currentAnimIndex = 0;
};