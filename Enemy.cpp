#include "Enemy.h"
#include "Sprite.h"
#include "ColliderComponent2D.h"
#include "VelocityComponent.h"

Enemy::Enemy(SDL_Renderer* _renderer, int _layer)
	: Character(_renderer, _layer)
{
	defaultSpritePath = "assets/Character/Enemy/idle_0.png";
	SetName("Enemy");

	speed = 4;
	sprite = &AddComponent<Sprite>(renderer, defaultSpritePath);
	collider = &AddComponent<ColliderComponent2D>(sprite);
	velComp = &AddComponent<VelocityComponent>(speed, acceleration, deceleration);
	//health = &AddComponent<EnemyHealthComponent>();
}

Enemy::~Enemy()
{
}

void Enemy::Update(double deltaTime)
{
	Character::Update(deltaTime);

	// move towards or attack target if we have one
	if (target != NULL)
	{
		// check target's position is not nan
		if (!isnan(target->GetPosition().GetX()) && !isnan(target->GetPosition().GetY()))
		{
			// calculate Enemy->Player vector
			Vector2 EP = target->GetPosition() - GetPosition();
			Vector2 dir = EP.Normalized();

			// attack if we are in a given distance
			if (EP.Magnitude() <= attackDistance)
			{
				StopMoving();
				Attack(dir);
			}
			// otherwise, move towards target
			else
			{
				Move(dir);
			}
		}
	}
}

void Enemy::Attack(Vector2 dir)
{
}
