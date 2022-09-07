#include "VelocityComponent.h"
#include "GameObject.h"

VelocityComponent::VelocityComponent(float& _maxSpeed, float& _acceleration, float& _deceleration)
	: maxSpeed(_maxSpeed), acceleration(_acceleration), deceleration(_deceleration)
{
}

/// <summary>
/// Begins accelerating towards a given velocity.
/// </summary>
/// <param name="dir"></param>
void VelocityComponent::StartAcceleratingTowards(Vector2 dir)
{
	destinationVel = dir;
}

/// <summary>
/// Begins decelerating back to 0.
/// </summary>
void VelocityComponent::StartDecelerating()
{
	destinationVel = Vector2();
}

void VelocityComponent::Update()
{
	Component::Update();

	// handle accel/decel
	if (destinationVel.RelativeMagnitude() != 0)
	{
		velocity += destinationVel.Normalized() * acceleration;
		velocity = MathUtils::ClampVector2Magnitude(velocity, 0, maxSpeed);
	}
	else if (velocity.RelativeMagnitude() != 0)
	{
		velocity -= (velocity.Normalized() * deceleration);
		velocity = MathUtils::ClampVector2Magnitude(velocity, 0, maxSpeed);
	}

	// move owning object
	Vector2 newPos = owner->GetPosition();
	Vector2 prevPos = newPos;
	newPos += velocity;
	owner->SetPosition(newPos);
}