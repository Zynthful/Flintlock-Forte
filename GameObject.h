#pragma once
#include "Vector2.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

public:
	// Position getters/setters
	Vector2 GetPosition();
	void SetPosition(Vector2 _position);
	void SetPosition(int x, int y);

	// Scale getters/setters
	Vector2 GetScale();
	void SetScale(Vector2 _scale);
	void SetScale(int x, int y);

private:
	Vector2 position;
	Vector2 scale = Vector2(1, 1);
};