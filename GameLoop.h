#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "GameObjectManager.h"
#include "Vector2.h"

class GameObjectSpawner;
class Player;
class Enemy;

class GameLoop
{
public:
	void Initialise();
	void LoadContent();
	bool Update();
	void Render();
	void UnloadContent();
	void Quit();

	static GameObjectManager* GetObjManager() { return gameObjManager; }

private:
	static GameObjectManager* gameObjManager;

	// Game objects
	Player* player;

	//GameObjectSpawner* enemySpawner = nullptr;
	int numEnemies = 1;
	Vector2 enemySpawnInterval = Vector2(200, 0);
	Vector2 enemySpawnPos = Vector2(1400, -200);

	// SDL pointers
	SDL_Window* window;
	SDL_Renderer* renderer;

	GameObject* shipBase = nullptr;
	GameObject* ocean = nullptr;
	
	// Game logic
	double deltaTime = 0;
	double lastFrameTime = 0;
	double currentFrameTime = 0;
};

