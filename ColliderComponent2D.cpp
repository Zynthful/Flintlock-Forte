#include "ColliderComponent2D.h"
#include "GameLoop.h"

ColliderComponent2D::ColliderComponent2D(SDL_Rect* rect)
{
	SetRect(rect);
	GameLoop::GetECSManager()->RegisterCollider(this);
}

ColliderComponent2D::ColliderComponent2D(int _x, int _y, int _w, int _h)
{
	SetRect(_x, _y, _w, _h);
	GameLoop::GetECSManager()->RegisterCollider(this);
}

ColliderComponent2D::ColliderComponent2D(Sprite* _sprite)
	: sprite(_sprite)
{
	SetRect(sprite);
	GameLoop::GetECSManager()->RegisterCollider(this);
}

ColliderComponent2D::~ColliderComponent2D()
{
	delete collider;
}

void ColliderComponent2D::Update(double deltaTime)
{
	SDL_RenderDrawRect(sprite->renderer, new SDL_Rect{ 300, 300, 100, 100 });
	if (sprite != nullptr)
	{
		SDL_RenderDrawRect(sprite->renderer, collider);
	}
	Component::Update(deltaTime);
	if (sprite != nullptr)
	{
		SetRect(sprite);
	}
}

void ColliderComponent2D::SetRect(int x, int y, int w, int h)
{
	collider->x = x;
	collider->y = y;
	collider->w = w;
	collider->h = h;
}

void ColliderComponent2D::SetRect(Sprite* sprite)
{
	*collider = sprite->GetRect();
}

void ColliderComponent2D::OnBeginOverlap(ColliderComponent2D* collider)
{
	GetOwner()->OnBeginOverlap(this, collider);
}

void ColliderComponent2D::OnEndOverlap(ColliderComponent2D* collider)
{
	GetOwner()->OnEndOverlap(this, collider);
}

void ColliderComponent2D::OnOverlapStay(ColliderComponent2D* collider)
{
	GetOwner()->OnOverlapStay(this, collider);
}