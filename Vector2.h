#pragma once

#include<iostream>

class Vector2
{
public:
	Vector2(int _x = 0, int _y = 0);

public:
	// Getters/setters
	int GetX() const;
	int GetY() const;
	void Set(int _x, int _y);
	void SetX(int _x);
	void SetY(int _y);

	// Vector utils
	Vector2 Normalized();
	float Magnitude();

	// Member operator overloads
	Vector2 operator+(const Vector2& rhs);
	Vector2 operator-(const Vector2& rhs);
	Vector2 operator*(float rhs);
	Vector2 operator/(float rhs);
	Vector2& operator+=(const Vector2& rhs);

private:
	int x;
	int y;
};

// Global operator overloads
std::ostream& operator<<(std::ostream& ostream, const Vector2& rhs);
Vector2 operator*(float lhs, const Vector2& rhs);
Vector2 operator/(float lhs, const Vector2& rhs);