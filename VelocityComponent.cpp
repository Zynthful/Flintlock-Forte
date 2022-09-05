#include "VelocityComponent.h"
#include "GameObject.h"



VelocityComponent::VelocityComponent()
{
	std::cout << "CONSTRUCT VEL COMP" << std::endl;
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
		velocity += destinationVel * acceleration;

		// then clamp to speed, somehow?
	}
	else if (velocity.RelativeMagnitude() != 0)
	{
		velocity -= velocity * deceleration;

		// then clamp to 0, somehow?
	}

	// move owning object
	Vector2 newPos = owner->GetPosition();
	newPos += velocity;
	owner->SetPosition(newPos);
}