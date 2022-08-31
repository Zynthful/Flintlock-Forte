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

Vector2 Vector2::operator*(float rhs)
{
	Vector2 result = Vector2(rhs * x, rhs * y);
	return result;
}

Vector2 Vector2::operator/(float rhs)
{
	return (*this) * (1 / rhs);	// multiply by (1 / rhs)
}

std::ostream& operator<<(std::ostream& ostream, const Vector2& rhs)
{
	return ostream << "(" << rhs.x << ", " << rhs.y << ")";
}

Vector2 operator*(float lhs, const Vector2& rhs)
{
	Vector2 result = Vector2(lhs * rhs.x, lhs * rhs.y);
	return result;
}

Vector2 operator/(float lhs, const Vector2& rhs)
{
	Vector2 result = Vector2(rhs.x / lhs, rhs.y / lhs);
	return result;
}
