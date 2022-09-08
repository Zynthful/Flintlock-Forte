#include "HealthComponent.h"

HealthComponent::HealthComponent()
{
	SetHealth(startingHealth);
}

HealthComponent::~HealthComponent()
{
}

float HealthComponent::SetHealth(int value)
{
	return health = MathUtils::Clamp(value, 0.0f, maxHealth);
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
	if (GetIsDead())
		return;

	SetHealth(0);
}
