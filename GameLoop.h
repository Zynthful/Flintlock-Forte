#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class GameLoop
{
public:
	void Initialise();
	void LoadContent();
	bool Update();
	void Render();
	void UnloadContent();
	void Quit();

private:
	
	// Game objects



	// SDL pointers
	SDL_Window* window;
	SDL_Renderer* renderer;
	

	// Game logic
	double deltaTime = 0;
	double lastFrameTime = 0;
	double currentFrameTime = 0;
};

