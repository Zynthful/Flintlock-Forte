#include "Projectile.h"
#include "VelocityComponent.h"
#include "ColliderComponent2D.h"

Projectile::Projectile(SDL_Renderer* _renderer, const char* _spritePath, Vector2 _dir, Vector2 _pos, int _targetLayer)
	: targetLayer(_targetLayer)
{
	SetPosition(_pos);

	sprite = &AddComponent<Sprite>(_renderer, _spritePath);

	// Setup collider
	collider = &AddComponent<ColliderComponent2D>(3, sprite);

	velComp = &AddComponent<VelocityComponent>(maxSpeed, acceleration, deceleration);
	
	velComp->StartAcceleratingTowards(_dir);
}

Projectile::~Projectile()
{
	delete collider;
	delete sprite;
}

void Projectile::OnBeginOverlap(ColliderComponent2D* source, ColliderComponent2D* other)
{
}

void Projectile::OnEndOverlap(ColliderComponent2D* source, ColliderComponent2D* other)
{
}

void Projectile::OnOverlapStay(ColliderComponent2D* source, ColliderComponent2D* other)
{
}

void Projectile::OnBeginOverlap(ColliderComponent2D* collider)
{
	// check if the collider is of the layer we want to target
	if (collider->GetLayer() == targetLayer)
	{
		// get health component
		// do damage if it exists
		// kill bullet
	}
}
