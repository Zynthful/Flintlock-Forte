#include "Enemy.h"
#include "VelocityComponent.h"

Enemy::Enemy(SDL_Renderer* renderer, const char* spritePath)
	: Character(renderer, spritePath)
{
	health = &AddComponent<EnemyHealthComponent>();

	speed = 4;
}

Enemy::Enemy(SDL_Renderer* renderer, const char* spritePath, SpriteAnimInfo* _animInfo)
	: Character(renderer, spritePath)
{
	health = &AddComponent<EnemyHealthComponent>();

}

Enemy::~Enemy()
{
}

void Enemy::Update(double deltaTime)
{
	Character::Update(deltaTime);
	// Move towards target if we have one
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
