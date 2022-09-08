#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* _renderer, const char* _path)
	: renderer(_renderer)
{
	SetSprite(_path);
}

Sprite::Sprite(SDL_Renderer* _renderer, const char* _path, SpriteAnimInfo* _animInfo)
	: renderer(_renderer), animInfo(_animInfo)
{
	SetSprite(_path, _animInfo);
}

Sprite::~Sprite()
{
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Sprite::Render()
{
	Component::Render();

	destinationRectangle.x = GetOwner()->GetPosition().GetX();
	destinationRectangle.y = -GetOwner()->GetPosition().GetY();


	SDL_Rect* sourceRectangle;
	if (animInfo == nullptr)
	{
		destinationRectangle.w = surface->w;
		destinationRectangle.h = surface->h;

		sourceRectangle = NULL;
	}
	else
	{
		destinationRectangle.w = animInfo->pxWidth;
		destinationRectangle.h = animInfo->pxHeight;

		sourceRectangle = new SDL_Rect();
		sourceRectangle->w = animInfo->pxWidth;
		sourceRectangle->h = animInfo->pxHeight;
		sourceRectangle->x = animInfo->currentFrameIndex * animInfo->pxInterval;
		sourceRectangle->y = 0;
	}

	SDL_RenderCopy(renderer, texture, sourceRectangle, &destinationRectangle);
}

void Sprite::Update(double deltaTime)
{
	Component::Update(deltaTime);

	if (animInfo != nullptr)
	{
		animInfo->currentFrameTime += deltaTime;
		if (animInfo->currentFrameTime > animInfo->numFrames / animInfo->fps )
		{
			NextFrame();
		}
	}
}

void Sprite::SetSprite(const char* _path, SpriteAnimInfo* _animInfo)
{
	SetSprite(_path);
	animInfo = _animInfo;
}

void Sprite::SetSprite(const char* _path)
{
	surface = IMG_Load(_path);
	if (surface == NULL)
	{
		std::cerr << "Image at path: " << _path << " could not be loaded! Error: " << SDL_GetError() << std::endl;
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Sprite::NextFrame()
{
	animInfo->currentFrameTime = 0;

	if (animInfo->currentFrameIndex + 1 >= animInfo->numFrames)
		animInfo->currentFrameIndex = 0;
	else
		animInfo->currentFrameIndex++;
}

SpriteAnimInfo::SpriteAnimInfo(int _numFrames, int _pxInterval, int _pxWidth, int _pxHeight, float _fps)
	: numFrames(_numFrames), pxInterval(_pxInterval), pxWidth(_pxWidth), pxHeight(_pxHeight), fps(_fps)
{
	currentFrameIndex = 0;
	currentFrameTime = 0;
}