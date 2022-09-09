#include "Projectile.h"
#include "VelocityComponent.h"
#include "ColliderComponent2D.h"
#include "HealthComponent.h"

Projectile::Projectile(SDL_Renderer* _renderer, const char* _spritePath, Vector2 _dir, Vector2 _pos, int _targetLayer)
	: targetLayer(_targetLayer)
{
	isBul = true;
	trgtLayer = 2;
	

	SetPosition(_pos);

	sprite = &AddComponent<Sprite>(_renderer, _spritePath);
	sprite->SetRect(_pos, 50, 50);

	// Setup collider
	collider = &AddComponent<ColliderComponent2D>(3, sprite);

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