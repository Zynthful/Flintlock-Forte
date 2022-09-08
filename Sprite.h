#pragma once
#include "Component.h"
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "Vector2.h"

class GameObject;

struct SpriteAnimInfo
{
	SpriteAnimInfo(int _numFrames, int _pxInterval, int _pxWidth, int _pxHeight, float _fps);

	int currentFrameIndex;
	double currentFrameTime;

	int numFrames;
	int pxInterval;
	int pxWidth;
	int pxHeight;
	float fps;
};

class Sprite : public Component
{
public:
	// For single image, no anim
	Sprite(SDL_Renderer* _renderer, const char* _path);

	// For tilesheet animations
	Sprite(SDL_Renderer* _renderer, const char* _path, SpriteAnimInfo* _animInfo);

	~Sprite();
	
public:
	virtual void Render() override;
	virtual void Update(double deltaTime) override;
	
	SDL_Rect GetRect() { return destinationRectangle; }

	// For tilesheet animations
	void SetSprite(const char* _path, SpriteAnimInfo* _info);

	// For single image, no anim
	void SetSprite(const char* _path);

	void NextFrame();

private:
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	SDL_Rect destinationRectangle;

	SpriteAnimInfo* animInfo = nullptr;
};