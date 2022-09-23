#include "Projectile.h"
#include "VelocityComponent.h"
#include "ColliderComponent2D.h"
#include "HealthComponent.h"

Projectile::Projectile(SDL_Renderer* _renderer, Vector2 _dir, Vector2 _pos, int _targetLayer)
	: targetLayer(_targetLayer)
{
	SetPosition(_pos);
	SetName("Projectile");

	isBul = true;
	trgtLayer = 2;
	damage = 40;

	defaultSpritePath = "assets/Projectile/FlintlockBullet.png";

	sprite = &AddComponent<Sprite>(_renderer, defaultSpritePath);
	collider = &AddComponent<ColliderComponent2D>(sprite);
	velComp = &AddComponent<VelocityComponent>(maxSpeed, acceleration, deceleration);
	velComp->StartAcceleratingTowards(_dir);
}

Projectile::~Projectile()
{
	delete collider;
	delete velComp;
	delete sprite;
}

void Projectile::OnBeginOverlap(ColliderComponent2D* source, ColliderComponent2D* other)
{
	GameObject::OnBeginOverlap(source, other);
	DoBulletStuff(collider);
}

void Projectile::OnEndOverlap(ColliderComponent2D* source, ColliderComponent2D* other)
{
	GameObject::OnEndOverlap(source, other);

}

void Projectile::OnOverlapStay(ColliderComponent2D* source, ColliderComponent2D* other)
{
	GameObject::OnOverlapStay(source, other);

}

void Projectile::Update(double deltaTime)
{
	GameObject::Update(deltaTime);
	currentLifeTime += deltaTime;
	if (currentLifeTime >= lifeTime)
	{
		Destroy();
	}
}

void Projectile::DoBulletStuff(ColliderComponent2D* collider)
{

}