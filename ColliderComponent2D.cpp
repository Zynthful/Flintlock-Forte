#include "ColliderComponent2D.h"
#include "GameLoop.h"

ColliderComponent2D::ColliderComponent2D(int _layer, SDL_Rect* rect)
	: layer(_layer)
{
	GameLoop::GetECSManager()->RegisterCollider(this);
	SetRect(rect);
}

ColliderComponent2D::ColliderComponent2D(int _layer, int _x, int _y, int _w, int _h)
	: layer(_layer)
{
	SetRect(_x, _y, _w, _h);
}

ColliderComponent2D::ColliderComponent2D(int _layer,  Sprite* sprite)
	: layer(_layer)
{
	SetRect(sprite);
}

ColliderComponent2D::~ColliderComponent2D()
{

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