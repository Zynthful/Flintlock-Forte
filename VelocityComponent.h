#pragma once
#include "Component.h"
#include "Vector2.h"
#include "MathUtils.h"

class VelocityComponent : public Component
{
public:
	VelocityComponent(float& maxSpeed);

	Vector2 GetVelocity() { return velocity; }

	void StartAcceleratingTowards(Vector2 dir);
	void StartDecelerating();

	virtual void Update() override;

private:
	Vector2 velocity;
	float acceleration = 2;
	float deceleration = 2;

	Vector2 destinationVel;

	float& maxSpeed;
};