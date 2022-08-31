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

	Vector2 operator+(const Vector2& rhs);
	Vector2 operator-(const Vector2& rhs);

};