#pragma once

class GameObject;

class Component
{
public:
	virtual ~Component();

public:
	virtual void Update(double deltaTime);
	virtual void Render();

	GameObject* GetOwner();
	void SetOwner(GameObject* obj);

protected:
	GameObject* owner;
};