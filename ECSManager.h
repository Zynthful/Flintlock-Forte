#pragma once
#include "GameObject.h"
#include "ColliderComponent2D.h"

class ECSManager
{
public:
	void Update();
	void Render();
	void Refresh();

public:
	std::vector<ColliderComponent2D*>&
		GetColliderComponents() { return colliderComps; }

	std::vector<std::unique_ptr<GameObject>>&
		GetGameObjects() { return gameObjects; }

	void RegisterGameObject(GameObject* obj);
	GameObject& AddNewGameObject();

	void RegisterCollider(ColliderComponent2D* colliderComp);

private:
	std::vector<std::unique_ptr<GameObject>> gameObjects;
	std::vector<ColliderComponent2D*> colliderComps;
};
