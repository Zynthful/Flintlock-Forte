#include "ColliderComponent2D.h"
#include "GameLoop.h"

ColliderComponent2D::ColliderComponent2D(SDL_Rect* rect)
{
	GameLoop::GetECSManager()->RegisterCollider(this);
	collider = rect;
}

ColliderComponent2D::ColliderComponent2D(int _x, int _y, int _w, int _h)
{
	collider->x = _x;
	collider->y = _y;
	collider->w = _w;
	collider->h = _h;
}

ColliderComponent2D::ColliderComponent2D(Sprite* sprite)
{
	collider = sprite->GetRect();
}

ColliderComponent2D::~ColliderComponent2D()
{

}

void ColliderComponent2D::OnBeginOverlap()
{

}

void ColliderComponent2D::OnEndOverlap()
{

}

void ColliderComponent2D::OnOverlapStay()
{

}