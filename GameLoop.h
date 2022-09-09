#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Player.h"
#include "ECSManager.h"
#include "TiledMap.h"
#include "Enemy.h"

class GameObjectSpawner;
class Player;

class GameLoop
{
public:
	void Initialise();
	void LoadContent();
	bool Update();
	void Render();
	void UnloadContent();
	void Quit();

	static ECSManager* GetECSManager();

private:
	// Entity Component System Manager
	static ECSManager* ecsManager;

	// Game objects
	Player* player;

	//GameObjectSpawner* enemySpawner = nullptr;

	Enemy* enemy1 = nullptr;
	Enemy* enemy2 = nullptr;
	Enemy* enemy3 = nullptr;
	Enemy* enemy4 = nullptr;
	int numEnemies = 100;
	Vector2 enemySpawnInterval = Vector2(200, 0);
	Vector2 enemySpawnPos = Vector2(1400, -200);

	// SDL pointers
	SDL_Window* window;
	SDL_Renderer* renderer;

	TiledMap* map;

	GameObject* shipBase = nullptr;
	GameObject* ocean = nullptr;
	
	// Game logic
	double deltaTime = 0;
	double lastFrameTime = 0;
	double currentFrameTime = 0;
};

