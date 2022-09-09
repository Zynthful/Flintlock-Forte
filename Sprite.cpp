#include "Sprite.h"
#include "GameObject.h"

Sprite::Sprite(SDL_Renderer* _renderer, const char* _path)
	: renderer(_renderer)
{
	Set(_path);
}

Sprite::Sprite(SDL_Renderer* _renderer, SpriteAnimInfo* _animInfo)
	: renderer(_renderer), animInfo(_animInfo)
{
	Set(_animInfo);
}

Sprite::~Sprite()
{
	if (surface != nullptr)
		SDL_FreeSurface(surface);

	if (texture != nullptr)
		SDL_DestroyTexture(texture);
}

void Sprite::Render()
{
	Component::Render();

	if (surface == nullptr || texture == nullptr)
		return;

	destinationRectangle.x = GetOwner()->GetPosition().GetX();
	destinationRectangle.y = -GetOwner()->GetPosition().GetY();

	SDL_Rect* sourceRectangle;
	if (animInfo == nullptr)
	{
		destinationRectangle.w = surface->w * GetOwner()->GetScale().GetX();
		destinationRectangle.h = surface->h * GetOwner()->GetScale().GetY();

		sourceRectangle = NULL;
	}
	else
	{
		destinationRectangle.w = animInfo->pxWidth * GetOwner()->GetScale().GetX();
		destinationRectangle.h = animInfo->pxHeight * GetOwner()->GetScale().GetY();

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

void Sprite::Set(const char* _path)
{
	surface = IMG_Load(_path);
	if (surface == NULL)
	{
		std::cerr << "Image at path: " << _path << " could not be loaded! Error: " << SDL_GetError() << std::endl;
		return;
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Sprite::Set(SpriteAnimInfo* _animInfo)
{
	Set(_animInfo->spritesheetPath);
	animInfo = _animInfo;
}

void Sprite::NextFrame()
{
	animInfo->currentFrameTime = 0;

	if (animInfo->currentFrameIndex + 1 >= animInfo->numFrames)
		animInfo->currentFrameIndex = 0;
	else
		animInfo->currentFrameIndex++;
}

SpriteAnimInfo::SpriteAnimInfo(
	const char* _spritesheetPath, int _numFrames, int _pxInterval,
	int _pxWidth, int _pxHeight, float _fps)
	: spritesheetPath(_spritesheetPath), numFrames(_numFrames),
	pxInterval(_pxInterval), pxWidth(_pxWidth),
	pxHeight(_pxHeight), fps(_fps)
{
	currentFrameIndex = 0;
	currentFrameTime = 0;
}