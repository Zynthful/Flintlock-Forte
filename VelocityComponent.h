#pragma once
#include "Component.h"
#include "Vector2.h"
#include "MathUtils.h"

class VelocityComponent : public Component
{
public:
	VelocityComponent(float& _maxSpeed, float& _acceleration, float& _deceleration);

	Vector2 GetVelocity() { return velocity; }

	void StartAcceleratingTowards(Vector2 dir);
	void StartDecelerating();

	virtual void Update(double deltaTime) override;

private:
	Vector2 velocity;
	Vector2 destinationVel;

	// should be >0
	float& acceleration;
	float& deceleration;

	// todo: make max speed only be capped by input rather than always capped
	float& maxSpeed;
};