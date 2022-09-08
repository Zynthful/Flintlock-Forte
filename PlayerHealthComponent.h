#pragma once
#include "HealthComponent.h"
class PlayerHealthComponent : public HealthComponent
{
public:
	virtual void Death() override;
};