#pragma once
#include "Component.h"
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "Vector2.h"

struct SpriteAnimInfo
{
	SpriteAnimInfo(
		const char* _spritesheetPath, int _numFrames, int _pxInterval,
		int _pxWidth, int _pxHeight, float _fps);

	const char* spritesheetPath;

	int currentFrameIndex;
	double currentFrameTime;
	int numFrames;
	float fps;

	int pxInterval;
	int pxWidth;
	int pxHeight;
};

class Sprite : public Component
{
public:
	// For single image, no anim
	Sprite(SDL_Renderer* _renderer, const char* _path);
	// For tilesheet animations
	Sprite(SDL_Renderer* _renderer, SpriteAnimInfo* _animInfo);

	~Sprite();
	
public:
	virtual void Render() override;
	virtual void Update(double deltaTime) override;
	
public:
	SDL_Rect GetRect() { return destinationRectangle; }
	void SetRect(SDL_Rect* value) { destinationRectangle = *value; }

	SDL_Renderer* GetRenderer() { return renderer; }

	void Set(const char* _path);		// For single image, no anim
	void Set(SpriteAnimInfo* _info);	// For tilesheet animations

public:
	void NextFrame();

private:
	SDL_Surface* surface;
	SDL_Texture* texture;

	SDL_Renderer* renderer;

	SDL_Rect destinationRectangle;

	SpriteAnimInfo* animInfo = nullptr;
};