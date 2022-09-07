#include "Vector2.h"

const Vector2 Vector2::up = Vector2(0, 1);
const Vector2 Vector2::down = Vector2(0, -1);
const Vector2 Vector2::right = Vector2(1, 0);
const Vector2 Vector2::left = Vector2(-1, 0);
const Vector2 Vector2::zero = Vector2(0, 0);

Vector2::Vector2(float _x, float _y)
	: x(_x), y(_y)
{
}

Vector2::Vector2(const Vector2& other)
	: x(other.x), y(other.y)
{
}

float Vector2::GetX() const
{
	return x;
}

float Vector2::GetY() const
{
	return y;
}

void Vector2::Set(float _x, float _y)
{
	SetX(_x);
	SetY(_y);
}

void Vector2::SetX(float _x)
{
	x = _x;
}

void Vector2::SetY(float _y)
{
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
	return sqrt(RelativeMagnitude());
}

float Vector2::RelativeMagnitude()
{
	return (x * x) + (y * y);
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

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	*this = *this - rhs;
	return *this;
}

Vector2& Vector2::operator*=(float rhs)
{
	*this = *this * rhs;
	return *this;
}

Vector2& Vector2::operator/=(float rhs)
{
	*this = *this / rhs;
	return *this;
}

bool Vector2::operator==(const Vector2& rhs)
{
	return x == rhs.x && y == rhs.y;
}

bool Vector2::operator!=(const Vector2& rhs)
{
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& ostream, const Vector2& rhs)
{
	return ostream << "(" << rhs.GetX() << ", " << rhs.GetY() << ")";
}

Vector2 operator*(float lhs, const Vector2& rhs)
{
	Vector2 result = Vector2(lhs * rhs.GetX(), lhs * rhs.GetY());
	return result;
}

Vector2 operator/(float lhs, const Vector2& rhs)
{
	Vector2 result = Vector2(rhs.GetX() / lhs, rhs.GetY() / lhs);
	return result;
}