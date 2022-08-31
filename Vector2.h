#pragma once

#include<iostream>

class Vector2
{
public:
	Vector2(int _x = 0, int _y = 0);

	int x;
	int y;
	
	Vector2 Normalized();
	float Magnitude();

	// Member operator overloads
	Vector2 operator+(const Vector2& rhs);
	Vector2 operator-(const Vector2& rhs);
	Vector2 operator*(float rhs);
	Vector2 operator/(float rhs);

};

// Global operator overloads
std::ostream& operator<<(std::ostream& ostream, const Vector2& rhs);
Vector2 operator*(float lhs, const Vector2& rhs);
Vector2 operator/(float lhs, const Vector2& rhs);