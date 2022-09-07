#include "MathUtils.h"

float MathUtils::Clamp(float value, const float& lowerBound, const float& upperBound)
{
	if (value > upperBound)
		value = upperBound;
	else if (value < lowerBound)
		value = lowerBound;

	return value;
}

Vector2 MathUtils::ClampVector2Magnitude(Vector2 vector, const float& lowerBound, const float& upperBound)
{
	float magnitude = vector.Magnitude();
	float clampedMagnitude = Clamp(magnitude, lowerBound, upperBound);

	// Return zero vector if magnitude is 0
	if (magnitude == 0)
		return Vector2(0, 0);

	float clampScalar = clampedMagnitude / magnitude;
	return vector *= clampScalar;
}