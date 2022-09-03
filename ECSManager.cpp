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
GameObject& ECSManager::AddGameObject()
{
	GameObject* obj = new GameObject();
	std::unique_ptr<GameObject> uPtr{ obj };
	gameObjects.emplace_back(std::move(uPtr));
	return *obj;
}