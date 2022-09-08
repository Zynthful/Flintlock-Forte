#include "HealthComponent.h"

HealthComponent::HealthComponent()
{
}

HealthComponent::~HealthComponent()
{
}

void HealthComponent::SetHealth(int value)
{
	health = value;
}

void HealthComponent::SetMaxHealth(int value)
{
	maxHealth = value;
}

void HealthComponent::TakeDamage(int amount)
{
}

void HealthComponent::Heal(int amount)
{
}

void HealthComponent::Death()
{
}
