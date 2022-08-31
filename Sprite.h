#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>



class Sprite {
public:
	Sprite(SDL_Renderer* renderer, std::string pathToSurface);
	virtual ~Sprite() {}

	virtual void Render();
	virtual void Update(double deltaTime);
	
	void SetVisible(bool visible) { this->visible = visible; }
	bool GetVisible() const { return visible; }

private:

	SDL_Texture* texture;
	bool visible;


protected:
	SDL_Renderer* renderer;
};