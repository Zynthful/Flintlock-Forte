#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* _renderer, const char* _path)
	: renderer(_renderer)
{
	SDL_Surface* imgSurface = IMG_Load(_path);

	if (imgSurface == NULL)
	{
		std::cerr << "Image at path: " << _path << " could not be loaded! Error: " << SDL_GetError() <<  std::endl;
	}

	texture = SDL_CreateTextureFromSurface(renderer, imgSurface);

	SDL_FreeSurface(imgSurface);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}

void Sprite::Render()
{
	SDL_Rect* sourceRectangle = NULL;

	SDL_Rect destinationRectangle;
	destinationRectangle.x = 0;
	destinationRectangle.y = 0;
	destinationRectangle.w = 100;
	destinationRectangle.h = 100;
	SDL_RenderCopy(renderer, texture, sourceRectangle, &destinationRectangle);
}
