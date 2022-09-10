#include "GameLoop.h"
#include "GameObjectSpawner.h"

// Declare static vars
ECSManager* GameLoop::ecsManager = new ECSManager();

void GameLoop::Initialise()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return;
	}
	else {
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
			return;
		}

		window = SDL_CreateWindow("IntoGames", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
			return;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL) {
			std::cerr << "SDL could not initialize renderer! SDL_Error: " << SDL_GetError() << std::endl;
		}
	}
}

void GameLoop::LoadContent()
{
	ocean = new GameObject();
	ocean->SetScale(2.5f, 2.5f);
	ocean->AddComponent<Sprite>(renderer, "assets/Terrain/ocean.png");

	shipBase = new GameObject();
	shipBase->SetScale(2.3f, 2.3f);
	shipBase->SetPosition(-100, -100);
	shipBase->AddComponent<Sprite>(renderer, "assets/Terrain/Ship/ship_base.png");

	player = new Player(renderer, 1);
	player->SetPosition(200, -200);
	
	// temp solution to spawning enemies
	// spawns enemies at increasing distances from the player, all at once
	for (int i = 0; i < numEnemies; i++)
	{
		Enemy* enemy = new Enemy(renderer, 2);
		Vector2 spawnPos = enemySpawnPos + (enemySpawnInterval * i);
		enemy->SetPosition(spawnPos);
		enemy->SetTarget(player);
	}

	//enemySpawner = new GameObjectSpawner(renderer, player);
}

bool GameLoop::Update()
{
	SDL_Delay(20);

	// Calculate frame time, etc.
	lastFrameTime = currentFrameTime;
	currentFrameTime = SDL_GetPerformanceCounter();
	deltaTime = (double)(currentFrameTime - lastFrameTime) / (double)SDL_GetPerformanceFrequency();

	/* Poll for events. SDL_PollEvent() returns 0 when there are no  */
	/* more events on the event queue, our while loop will exit when */
	/* that occurs.                                                  */
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT) {
			return false;
		}

		// Update player input
		player->GetInputComponent()->UpdateInput(e);
	}

	// invoke Update on GameObjects and Components
	ecsManager->Update(deltaTime);

	// Loop through all colliders on each layer
	// Check for collision against other colliders on that layer
	// Invoke relevant events
	auto& colliders = ecsManager->GetColliderComponents();
	for (int i = 0; i < colliders.size(); i++)
	{
		// don't check for collision if this collider's owner is disabled
		if (!colliders[i]->GetOwner()->GetActive())
			continue;

		for (int j = i + 1; j < colliders.size(); j++)
		{
			// don't check for collision if this collider's owner is disabled
			if (!colliders[j]->GetOwner()->GetActive())
				continue;

			// todo: make OnBegin and OnEnd not call every frame

			// beware, this std::cout WILL ruin your fps
			//std::cout << "Comparing " << colliders[i]->GetOwner()->GetName() << " against " << colliders[j]->GetOwner()->GetName() << std::endl;
			if (SDL_HasIntersection(colliders[i]->GetRect(), colliders[j]->GetRect()))
			{
				colliders[i]->OnBeginOverlap(colliders[j]);
				colliders[j]->OnBeginOverlap(colliders[i]);
			}
			else
			{
				colliders[i]->OnEndOverlap(colliders[j]);
				colliders[j]->OnEndOverlap(colliders[i]);
			}
		}
	}
	return true;
}

void GameLoop::Render()
{
	// Change the background colour here
	SDL_SetRenderDrawColor(renderer, 60, 60, 60, 0);
	SDL_RenderClear(renderer);

	// =================================
	// RENDER OTHER OBJECTS HERE
	// ORDER OF RENDERING MATTERS (later = renders on top)

	// invoke Render on GameObjects and Components
	ecsManager->Render();
	//ecsManager->Update(deltaTime);	// uncomment to see sdl draw rect boxes on colliders
										// i know, cringe

	// =================================
	SDL_RenderPresent(renderer);
}

// Unload assets to release memory
void GameLoop::UnloadContent()
{
	//delete enemySpawner;
	delete player;
	delete ocean;
	delete shipBase;
}

void GameLoop::Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	window = NULL;
	SDL_Quit();
}

ECSManager* GameLoop::GetECSManager()
{
	return ecsManager;
}
