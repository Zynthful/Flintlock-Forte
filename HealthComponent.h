#pragma once
#include "Component.h"
#include "MathUtils.h"

class HealthComponent : public Component
{
public:
	HealthComponent();
	~HealthComponent();

private:
	int health = 0;
	int maxHealth = 100;
	int startingHealth = 100;
	
	// cooldown after damage before damage can be applied again
	// TODO: implementation
	float damageCooldown = 0.0f;

public:
	float SetHealth(int value);	// returns clamped health val
	int GetHealth() { return health; }

	void SetMaxHealth(int value);
	int GetMaxHealth() { return maxHealth; }

	bool GetIsDead() { return health <= 0; }

	// todo: add damage source, heal source
	void TakeDamage(int amount);
	void Heal(int amount);

	virtual void Death();
};