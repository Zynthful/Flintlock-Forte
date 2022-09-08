#include "Projectile.h"
#include "VelocityComponent.h"

Projectile::Projectile(SDL_Renderer* _renderer, const char* _spritePath, Vector2 _dir, Vector2 _pos)
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

void Projectile::OnBeginOverlap(ColliderComponent2D* collider)
{
	// check for enemy layer
	if (collider->GetLayer() == 2)
	{
		// damage enemy
		// kill bullet
	}
}
