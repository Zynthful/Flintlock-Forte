#pragma once
#include "HealthComponent.h"
class EnemyHealthComponent : public HealthComponent
{
public:
	virtual void Death() override;
};

