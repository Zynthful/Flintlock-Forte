#pragma once
#include<iostream>

class Vector2
{
public:
	Vector2(float _x = 0, float _y = 0);
	Vector2(const Vector2& other);

public:
	// Getters/setters
	float GetX() const;
	float GetY() const;
	void Set(float _x, float _y);
	void SetX(float _x);
	void SetY(float _y);

	// Vector utils
	Vector2 Normalized();
	float Magnitude();
	float RelativeMagnitude();	// magnitude without sqrt

public:
	// Member operator overloads
	Vector2 operator+(const Vector2& rhs);
	Vector2 operator-(const Vector2& rhs);
	Vector2 operator*(float rhs);
	Vector2 operator/(float rhs);
	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);
	Vector2& operator*=(float rhs);
	Vector2& operator/=(float rhs);
	bool operator==(const Vector2& rhs);
	bool operator!=(const Vector2& rhs);

private:
	float x;
	float y;

public:
	const static Vector2 up;
	const static Vector2 down;
	const static Vector2 right;
	const static Vector2 left;
	const static Vector2 zero;
};

// Global operator overloads
std::ostream& operator<<(std::ostream& ostream, const Vector2& rhs);
Vector2 operator*(float lhs, const Vector2& rhs);
Vector2 operator/(float lhs, const Vector2& rhs);