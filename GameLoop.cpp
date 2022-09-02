#include "GameLoop.h"

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

	while (SDL_PollEvent(&e) != 0) {

		if (e.type == SDL_QUIT) {
			return false;
		}

		switch (e.type)
		{
		case SDL_KEYDOWN:
		{
			switch (e.type)
			{
			case SDL_SCANCODE_W:
				player->Move(Vector2(0, 1));
				break;
			case SDL_SCANCODE_A:
				player->Move(Vector2(-1, 0));
				break;
			case SDL_SCANCODE_S:
				player->Move(Vector2(0, -1));
				break;
			case SDL_SCANCODE_D:
				player->Move(Vector2(1, 0));
				break;
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		}
	}

	// Update game state
	


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
