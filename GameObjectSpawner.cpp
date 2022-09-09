#include "GameObjectSpawner.h"
#include "Enemy.h"

GameObjectSpawner::GameObjectSpawner(SDL_Renderer* _renderer, GameObject* _target)
	: renderer(_renderer), target(_target)
{
}

GameObjectSpawner::~GameObjectSpawner()
{
	enemies.clear();
}

void GameObjectSpawner::SpawnObj()
{
	// causes memory read access violation
	// somehow? 
	// ecs my DESPISED >:(
	Enemy* enemy = new Enemy(renderer, 2);
	enemy->SetPosition(spawnPos);
	enemy->SetTarget(target);
	enemies.push_back(enemy);
}

void GameObjectSpawner::Update(double deltaTime)
{
	GameObject::Update(deltaTime);

	currentSpawnTime += deltaTime;
	if (currentSpawnTime >= spawnTime)
	{
		currentSpawnTime = 0.0f;
		SpawnObj();
	}
}
