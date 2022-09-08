#include "Projectile.h"

Projectile::Projectile(SDL_Renderer* _renderer, const char* _spritePath, Vector2 _dir, Vector2 _pos)
{
	SetPosition(_pos);

	sprite = &AddComponent<Sprite>(_renderer, _spritePath);
	collider = &AddComponent<ColliderComponent2D>(sprite);
	velComp = &AddComponent<VelocityComponent>(maxSpeed, acceleration, deceleration);
	
	velComp->StartAcceleratingTowards(_dir);
}

Projectile::~Projectile()
{
	delete collider;
	delete sprite;
}