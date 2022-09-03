#include "GameLoop.h"

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
	player = new Player(renderer);
}

bool GameLoop::Update()
{
	SDL_Delay(20);

	SDL_Event e;
	/* Poll for events. SDL_PollEvent() returns 0 when there are no  */
	/* more events on the event queue, our while loop will exit when */
	/* that occurs.                                                  */

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT) {
			return false;
		}

		// Update player input
		player->GetInputComponent()->Update(&e);
	}


	// Update game state

	// Invoke ECS events
	ecsManager->Update();

	// Loop through all colliders on each layer
	// Check for collision against other colliders on that layer
	// Invoke relevant events

	//const int size = 4;
	//SDL_Rect* colliders[size];
	//for (int i = 0; i < size; i++)
	//{
	//	for (int j = i + 1; j < size; j++)
	//	{
	//		std::cout << "Comparing " << i << " against " << j << std::endl;
	//		if (SDL_HasIntersection(colliders[i], colliders[j]))
	//		{

	//		}
	//		else
	//		{

	//		}
	//	}
	//}


	return true;
}



void GameLoop::Render()
{
	// Change the background colour here
	SDL_SetRenderDrawColor(renderer, 60, 60, 60, 0);
	SDL_RenderClear(renderer);

	// Render any other object here.
	player->GetSprite()->Render();

	SDL_RenderPresent(renderer);

}

// Unload assets to release memory
void GameLoop::UnloadContent()
{
	delete player;
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
