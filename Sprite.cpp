#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* _renderer, const char* _path)
	: renderer(_renderer)
{
	surface = IMG_Load(_path);

	if (surface == NULL)
	{
		std::cerr << "Image at path: " << _path << " could not be loaded! Error: " << SDL_GetError() <<  std::endl;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

Sprite::~Sprite()
{
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Sprite::Render()
{
	Component::Render();

	SDL_Rect* sourceRectangle = NULL;

	SDL_Rect destinationRectangle;
	destinationRectangle.x = GetOwner()->GetPosition().GetX();
	destinationRectangle.y = -GetOwner()->GetPosition().GetY();
	destinationRectangle.w = surface->w;
	destinationRectangle.h = surface->h;
	SDL_RenderCopy(renderer, texture, sourceRectangle, &destinationRectangle);
}

SDL_Rect* Sprite::GetRect()
{
	SDL_Rect* rect = new SDL_Rect();
	rect->w = surface->w;
	rect->h = surface->h;
	rect->x = GetOwner()->GetPosition().GetX();
	rect->y = GetOwner()->GetPosition().GetY();
	return rect;
}
