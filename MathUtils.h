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
	static float Clamp(float value, const float& lowerBound, const float& upperBound);

	static Vector2 ClampVector2Magnitude(Vector2 vector, const float& lowerBound, const float& upperBound);
};