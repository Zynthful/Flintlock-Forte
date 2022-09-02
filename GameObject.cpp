#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

Vector2 GameObject::GetPosition()
{
	return position;
}

void GameObject::SetPosition(Vector2 _position)
{
	position = _position;
}

void GameObject::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

Vector2 GameObject::GetScale()
{
	return scale;
}

void GameObject::SetScale(Vector2 _scale)
{
	scale = _scale;
}

void GameObject::SetScale(int x, int y)
{
	scale.x = x;
	scale.y = y;
}
