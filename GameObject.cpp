#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	for (auto& c : components) c->Update();
	for (auto& c : components) c->Render();

}

void GameObject::Render()
{
}

void GameObject::Destroy()
{
	SetActive(false);
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
	position.Set(x, y);
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
	scale.Set(x, y);
}

bool GameObject::GetActive() const
{
	return active;
}

void GameObject::SetActive(bool value)
{
	active = value;
}