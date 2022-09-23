#pragma once
#include "GameObjectComponentSystem.h"
#include "Component.h"
#include <vector>
#include <memory>	// to use unique_ptr
#include <assert.h>	// to use assert for helping w/ debugging
#include "Vector2.h"

class ColliderComponent2D;

class GameObject
{
public:
	GameObject(int _layer = 0);
	~GameObject();

private:
	std::vector<std::unique_ptr<Component>> components;
	ComponentList compList;
	ComponentBitset compBitset;

public:
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void Destroy();

	template <typename T>
	bool HasComponent() const
	{
		return compBitset[GetComponentTypeID<T>()];	// get the value of the bitset at the index of the component type id
													// 1: entity has the component
													// 0: entity does NOT have the component
	}

	template<typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args) 
	{
		// prevent adding a component if a component of that type is already on this entity
		assert(("AddComponent: The component type you are trying to add already exists on this entity! Only one component of each type is allowed to exist on an entity.",
			!HasComponent<T>()));

		T* comp(new T(std::forward<TArgs>(args)...));	// construct component with given arguments
		std::unique_ptr<Component> uPtr{ comp };		// create uniqure ptr of component
		components.emplace_back(std::move(uPtr));		// store comp to our vector of components by moving it directly (as we cannot copy a unique ptr)

		// initialise component
		// if successful, proceed with adding component
		compList[GetComponentTypeID<T>()] = comp;	// assign created component to our component list, using the type ID as the index
		compBitset[GetComponentTypeID<T>()] = true;	// the entity now has this component, so set the bitset (which is used to find out this information) to true
		comp->SetOwner(this);						// set the owning entity of the component to this
		return *comp;								// return reference to component added

		// if initialisation was unsuccessful, return null reference
		return *static_cast<T*>(nullptr);
	}

	template<typename T>
	T& GetComponent() const
	{
		assert(HasComponent<T>());						// prevent getting component if it this entity does not have it
		auto ptr(compList[GetComponentTypeID<T>()]);	// declare pointer to component, using the component type id as the index to find our given component type
		return *static_cast<T*>(ptr);					// return dereferenced component, casted to derived type}
	}
	
	virtual void OnBeginOverlap(ColliderComponent2D* source, ColliderComponent2D* other);
	virtual void OnEndOverlap(ColliderComponent2D* source, ColliderComponent2D* other);
	virtual void OnOverlapStay(ColliderComponent2D* source, ColliderComponent2D* other);

	// Active getter/setter
	bool GetActive() const;
	void SetActive(bool value);

	int GetLayer() { return layer; }

	std::string GetName() const { return name; }
	void SetName(std::string value) { name = value; }

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
	Vector2 scale;
	std::string name;

	int layer;

	// bullet stuff
	bool isBul = false;
	int trgtLayer;
	int damage;
};