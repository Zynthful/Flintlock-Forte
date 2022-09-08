#pragma once
#include "Vector2.h"
#include "Component.h"
#include "ECS.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	// ECS
protected:
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void Destroy();

	// Active getter/setter
	bool GetActive() const;
	void SetActive(bool value);

	template <typename T> bool HasComponent() const
	{
		return componentBitSet[GetComponentTypeID<T>];
	}

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->SetOwner(this);
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		// ensures that the component added is in the correct position in the array of component types
		componentArray[GetComponentTypeID<T>()] = c;
		componentBitSet[GetComponentTypeID<T>()] = true;

		c->Initialise();
		return *c;
	}

	template <typename T> T& GetComponent() const
	{
		auto ptr(componentArray[GetComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

public:
	// Position getters/setters
	Vector2 GetPosition() const;
	void SetPosition(Vector2& _position);
	void SetPosition(float x, float y);

	// Scale getters/setters
	Vector2 GetScale();
	void SetScale(Vector2 _scale);
	void SetScale(float x, float y);

protected:
	bool active = true;
	Vector2 position;
	Vector2 scale = Vector2(1, 1);
};