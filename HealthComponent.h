#pragma once
#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent();
	~HealthComponent();

private:
	int health = 0;
	int maxHealth = 100;
	int startingHealth = 100;

public:
	void SetHealth(int value);
	int GetHealth() { return health; }

	void SetMaxHealth(int value);
	int GetMaxHealth() { return maxHealth; }

	// todo: add damage source, heal source
	void TakeDamage(int amount);
	void Heal(int amount);

	virtual void Death();
};