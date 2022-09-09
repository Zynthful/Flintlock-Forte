#pragma once
#include "GameObject.h"
#include <vector>
#include <SDL.h>

class Enemy;

// todo: implement templated obj type instead of just enemies
class GameObjectSpawner : public GameObject
{
public:
	GameObjectSpawner(SDL_Renderer* _renderer, GameObject* _target);
	~GameObjectSpawner();

public:
	void SpawnObj();
	virtual void Update(double deltaTime) override;

public:
	std::vector<Enemy*> GetEnemies() { return enemies; }

private:
	SDL_Renderer* renderer = nullptr;	// pointer to SDL renderer needed for constructing sprites
	GameObject* target = nullptr;		// target for enemy AI

	std::vector<Enemy*> enemies;

	float spawnTime = 3.0f;
	float currentSpawnTime = 0.0f;
	Vector2 spawnPos = Vector2(1400, -200);
	//int maxEnemies = 3;

};

