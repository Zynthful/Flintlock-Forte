#pragma once
#include "GameObject.h"

class ECSManager
{
public:
	ECSManager();

	void Update();
	void Render();
	void Refresh();

	void RegisterGameObject(GameObject* obj);
	GameObject& AddNewGameObject();

private:
	std::vector<std::unique_ptr<GameObject>> gameObjects;
};
