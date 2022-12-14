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

void VelocityComponent::Update(double deltaTime)
{
	Component::Update(deltaTime);

	// handle accel/decel
	if (destinationVel.RelativeMagnitude() != 0)
	{
		velocity += destinationVel.Normalized() * acceleration;
		velocity = MathUtils::ClampVector2Magnitude(velocity, 0, maxSpeed);
	}
	else if (velocity.RelativeMagnitude() != 0)
	{
		Vector2 prevVel = velocity;
		velocity -= (velocity.Normalized() * deceleration);
		velocity = MathUtils::ClampVector2Magnitude(velocity, 0, maxSpeed);
		if ((velocity.GetX() < 0 && prevVel.GetX() > 0) || (velocity.GetX() > 0 && prevVel.GetX() < 0))
		{
			velocity.SetX(0);
		}
		if ((velocity.GetY() < 0 && prevVel.GetY() > 0) || (velocity.GetY() > 0 && prevVel.GetY() < 0))
		{
			velocity.SetY(0);
		}
	}

	// move owning object
	Vector2 newPos = owner->GetPosition();
	Vector2 prevPos = newPos;
	newPos += velocity;
	owner->SetPosition(newPos);
}