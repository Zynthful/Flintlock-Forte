#include "Sprite.h"


Sprite::Sprite(SDL_Renderer* sdlRenderer, std::string pathToSurface) 
	: renderer(sdlRenderer)
{
	SDL_Surface* surface = IMG_Load(pathToSurface.c_str());

	if (surface == NULL) {
		std::cerr << "Could not load surface at path: " << pathToSurface << std::endl;
		return;
	}

	visible = true;

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	
	SDL_FreeSurface(surface);

}



void Sprite::Update(double deltaTime) {
}



void Sprite::Render() {

	if (this->visible) {


		SDL_Rect destinationRect{ 0, 0, 32, 32 };

		SDL_RenderCopy(renderer, texture, NULL, &destinationRect);

	}
}


