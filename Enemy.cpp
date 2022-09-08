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
		if (!isnan(target->GetPosition().GetX()) && !isnan(target->GetPosition().GetY()))
		{
			Move((target->GetPosition() - GetPosition()).Normalized());
		}
	}
	std::cout << velComp->GetVelocity() << ", " << velComp->GetAcceleration() << ", " << velComp->GetDeceleration() << ", " << velComp->destinationVel << ", " << velComp->destinationVel.RelativeMagnitude() << std::endl;
}
