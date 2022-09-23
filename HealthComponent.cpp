#include "HealthComponent.h"
#include "GameObject.h"

HealthComponent::HealthComponent()
{
	SetHealth(startingHealth);
}

HealthComponent::~HealthComponent()
{
}

float HealthComponent::SetHealth(int value)
{
	health = MathUtils::Clamp(value, 0.0f, maxHealth);
	if (health <= 0)
	{
		Death();
	}
	else
	{
		isAlive = true;
	}
	return health;
}

void HealthComponent::SetMaxHealth(int value)
{
	maxHealth = value;
}

void HealthComponent::TakeDamage(int amount)
{
	SetHealth(health - amount);
}

void HealthComponent::Heal(int amount)
{
	SetHealth(health + amount);
}

void HealthComponent::Death()
{
	if (!isAlive)
		return;

	isAlive = false;
	health = 0;						// in case health is not already at 0
	GetOwner()->SetActive(false);	// disable this obj. note: should not do this if we want to trigger a death anim or other state
}
