#include "ECSManager.h"

// calls Update on all gameObjects
void ECSManager::Update()
{
	for (auto& e : gameObjects) e->Update();
}

// calls Render on all gameObjects
void ECSManager::Render()
{
	for (auto& e : gameObjects) e->Render();
}

// looks for inactive components and removes them
void ECSManager::Refresh()
{
	gameObjects.erase(std::remove_if(std::begin(gameObjects), std::end(gameObjects),
		[](const std::unique_ptr<GameObject>& mGameObject)
		{
			return !mGameObject->GetActive();
		}),
		std::end(gameObjects));
}

// Adds a gameobject to the world
GameObject& ECSManager::AddNewGameObject()
{
	GameObject* obj = new GameObject();
	RegisterGameObject(obj);
	return *obj;
}

// Register GameObject to our vector of gameObjects
void ECSManager::RegisterGameObject(GameObject* obj)
{
	std::unique_ptr<GameObject> uPtr { obj };
	gameObjects.emplace_back(std::move(uPtr));
}

void ECSManager::RegisterCollider(ColliderComponent2D* colliderComp)
{
	std::unique_ptr<ColliderComponent2D> uPtr{ colliderComp };
	colliderComps.emplace_back(std::move(uPtr));
}