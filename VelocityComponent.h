#pragma once
#include "Component.h"
#include "Vector2.h"

class VelocityComponent : public Component
{
public:
	VelocityComponent();

	Vector2 GetVelocity() { return velocity; }

	void StartAcceleratingTowards(Vector2 dir);
	void StartDecelerating();

	virtual void Update() override;

private:
	Vector2 velocity;
	float acceleration = 1;
	float deceleration = 1;

	Vector2 destinationVel;

};