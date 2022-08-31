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

Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 result = Vector2(x + rhs.x, y + rhs.y);
	return result;
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 result = Vector2(x - rhs.x, y - rhs.y);
	return result;
}

std::ostream& operator<<(std::ostream& ostream, const Vector2& rhs)
{
	return ostream << "(" << rhs.x << ", " << rhs.y << ")";
}
