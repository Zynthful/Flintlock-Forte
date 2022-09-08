#include "ColliderComponent2D.h"
#include "GameLoop.h"

ColliderComponent2D::ColliderComponent2D(int _layer, SDL_Rect* rect)
	: layer(_layer)
{
	GameLoop::GetECSManager()->RegisterCollider(this);
	collider = rect;
}

ColliderComponent2D::ColliderComponent2D(int _layer, int _x, int _y, int _w, int _h)
	: layer(_layer)
{
	collider->x = _x;
	collider->y = _y;
	collider->w = _w;
	collider->h = _h;
}

ColliderComponent2D::ColliderComponent2D(int _layer,  Sprite* sprite)
	: layer(_layer)
{
	*collider = sprite->GetRect();
}

ColliderComponent2D::~ColliderComponent2D()
{

}

void ColliderComponent2D::OnBeginOverlap(ColliderComponent2D* collider)
{
	//GetOwner()->OnBeginOverlap(this, collider);
}

void ColliderComponent2D::OnEndOverlap(ColliderComponent2D* collider)
{
	//GetOwner()->OnEndOverlap(this, collider);
}

void ColliderComponent2D::OnOverlapStay(ColliderComponent2D* collider)
{
	//GetOwner()->OnOverlapStay(this, collider);
}