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

Sprite::Sprite(SDL_Renderer* _renderer, const char* _path,
	int _numFrames, int _pxInterval, int _pxWidth, int _pxHeight, float _animFPS)
	: renderer(_renderer),
	numFrames(_numFrames), animPxInterval(_pxInterval), animPxWidth(_pxWidth), animPxHeight(_pxHeight), animFPS(_animFPS)
{
	surface = IMG_Load(_path);
	if (surface == NULL)
	{
		std::cerr << "Image at path: " << _path << " could not be loaded! Error: " << SDL_GetError() << std::endl;
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

	SDL_Rect destinationRectangle;
	destinationRectangle.x = GetOwner()->GetPosition().GetX();
	destinationRectangle.y = -GetOwner()->GetPosition().GetY();
	destinationRectangle.w = surface->w;
	destinationRectangle.h = surface->h;

	SDL_Rect* sourceRectangle;
	if (numFrames <= 1)
	{
		sourceRectangle = NULL;
	}
	else
	{
		sourceRectangle = new SDL_Rect();
		sourceRectangle->w = animPxWidth;
		sourceRectangle->h = animPxHeight;
		sourceRectangle->x = currentFrameIndex * animPxInterval;
		sourceRectangle->y = 0;
	}


	SDL_RenderCopy(renderer, texture, sourceRectangle, &destinationRectangle);
}

void Sprite::Update(double deltaTime)
{
	Component::Update(deltaTime);

	if (numFrames > 1)
	{
		currentFrameTime += deltaTime;
		if (currentFrameTime > numFrames / animFPS )
		{
			NextFrame();
		}
	}
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

void Sprite::NextFrame()
{
	currentFrameTime = 0;

	if (currentFrameIndex + 1 >= numFrames)
		currentFrameIndex = 0;
	else
		currentFrameIndex++;
}
