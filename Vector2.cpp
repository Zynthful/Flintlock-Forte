#include "Vector2.h"

Vector2::Vector2(int _x, int _y)
{
	x = _x;
	y = _y;
}

Vector2 Vector2::Normalized()
{
	float k = 1 / Magnitude();
	Vector2 result = Vector2(k * x, k * y);
	return result;
}

float Vector2::Magnitude()
{
	return sqrt(x * x + y * y);
}
