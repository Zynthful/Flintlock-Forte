#pragma once
#include <vector>	// to store a vector of managed objects
#include <memory>	// to use unique_ptr

class GameObject;
class ColliderComponent2D;

class GameObjectManager
{
public:
	void Update(double deltaTime);
	void Render();
	void Refresh();

public:
	void RegisterGameObject(GameObject* obj);
	void RegisterCollider(ColliderComponent2D* colliderComp);

	std::vector<ColliderComponent2D*>&
		GetColliderComponents() { return colliderComps; }

	std::vector<std::unique_ptr<GameObject>>&
		GetGameObjects() { return gameObjects; }

private:
	std::vector<std::unique_ptr<GameObject>> gameObjects;
	std::vector<ColliderComponent2D*> colliderComps;
};
