#pragma once
#include "Vector2.h"

class MathUtils
{
public:
	/// <summary>
	/// Clamps value between given bounds
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="value"></param>
	/// <param name="lowerBound"></param>
	/// <param name="upperBound"></param>
	/// <returns></returns>
	static int Clamp(int value, const int& lowerBound, const int& upperBound);

	static Vector2 ClampVector2Magnitude(Vector2 vector, const int& lowerBound, const int& upperBound);
};