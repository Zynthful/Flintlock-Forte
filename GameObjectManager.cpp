#include "GameObjectManager.h"
#include "GameObject.h"

/// <summary>
/// Calls Update on all gameObjects
/// </summary>
/// <param name="deltaTime">Realtime in seconds since last frame</param>
void GameObjectManager::Update(double deltaTime)
{
	for (auto& e : gameObjects)
	{
		// temp GetActive check until Refresh works
		if (e->GetActive())
		{
			e->Update(deltaTime);
		}
	}
}

/// <summary>
/// Calls Render on all gameObjects
/// </summary>
void GameObjectManager::Render()
{
	for (auto& e : gameObjects)
	{
		// temp GetActive check until Refresh works
		if (e->GetActive())
		{
			e->Render();
		}
	}
}

/// <summary>
///
/// </summary>
void GameObjectManager::Refresh()
{
}

/// <summary>
/// Registers a given GameObject to the manager, allowing it to be managed
/// </summary>
/// <param name="obj">The GameObject to register</param>
void GameObjectManager::RegisterGameObject(GameObject* obj)
{
	std::unique_ptr<GameObject> uPtr { obj };
	gameObjects.emplace_back(std::move(uPtr));
}

/// <summary>
/// Registers a collider to the manager
/// </summary>
/// <param name="colliderComp">The collider to manage</param>
void GameObjectManager::RegisterCollider(ColliderComponent2D* colliderComp)
{
	//std::unique_ptr<ColliderComponent2D> uPtr{ colliderComp };
	//colliderComps.emplace_back(std::move(uPtr));

	colliderComps.emplace_back(colliderComp);	// append component to end of vector
}