#pragma once
#include "GameObject.h"

class ECSManager
{
private:
	std::vector<std::unique_ptr<GameObject>> gameObjects;

public:
	void Update();
	void Render();
	void Refresh();

	GameObject& AddGameObject();
};
