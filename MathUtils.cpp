#include "MathUtils.h"

int MathUtils::Clamp(int value, const int& lowerBound, const int& upperBound)
{
	if (value > upperBound)
		value = upperBound;
	else if (value < lowerBound)
		value = lowerBound;

	return value;
}

Vector2 MathUtils::ClampVector2Magnitude(Vector2 vector, const int& lowerBound, const int& upperBound)
{

	int magnitude = (int)vector.Magnitude();
	int clampedMagnitude = Clamp(magnitude, lowerBound, upperBound);

	// Return zero vector if magnitude is 0
	if (magnitude == 0)
		return Vector2(0, 0);

	float clampScalar = (float)clampedMagnitude / (float)magnitude;
	return vector *= clampScalar;
}

