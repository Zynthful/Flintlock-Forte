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
	destinationRectangle.x = position.GetX();
	destinationRectangle.y = -position.GetY();
	destinationRectangle.w = 300;
	destinationRectangle.h = 300;
	SDL_RenderCopy(renderer, texture, sourceRectangle, &destinationRectangle);
}

void Sprite::SetPosition(Vector2 _position)
{
	position = _position;
}
