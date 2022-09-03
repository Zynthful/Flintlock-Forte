#pragma once

class GameObject;

class Component
{
public:
	virtual ~Component();

public:
	virtual void Initialise();
	virtual void Update();
	virtual void Render();

	GameObject* GetOwner();
	void SetOwner(GameObject* obj);

protected:
	GameObject* owner;
};