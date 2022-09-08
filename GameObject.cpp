#include "GameObject.h"
#include "GameLoop.h"

GameObject::GameObject()
{
	// Register this object to the ECSManager
	GameLoop::GetECSManager()->RegisterGameObject(this);
}

GameObject::~GameObject()
{
}

void GameObject::Update(double deltaTime)
{
	for (auto& c : components) c->Update(deltaTime);
}

void GameObject::Render()
{
	for (auto& c : components) c->Render();
}

void GameObject::Destroy()
{
	SetActive(false);
}

void GameObject::OnBeginOverlap(ColliderComponent2D* source, ColliderComponent2D* other)
{
}

void GameObject::OnEndOverlap(ColliderComponent2D* source, ColliderComponent2D* other)
{
}

void GameObject::OnOverlapStay(ColliderComponent2D* source, ColliderComponent2D* other)
{
}

Vector2 GameObject::GetPosition() const
{
	return position;
}

void GameObject::SetPosition(Vector2& _position)
{
	position = _position;
}

void GameObject::SetPosition(float x, float y)
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

void GameObject::SetScale(float x, float y)
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