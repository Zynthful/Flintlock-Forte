#include "TiledMap.h"

TiledMap::TiledMap(SDL_Renderer* sdlRenderer, std::string tiledMapFilename)
	: renderer(sdlRenderer), filename(tiledMapFilename)
{
	// Load tiles as a single texture
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if (surface == NULL)
	{
		std::cerr << "Image at path: " << tiledMapFilename << " could not be loaded! Error: " << SDL_GetError() << std::endl;
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);


	// Create tiles by iterating through the indices of our map
	// and creating rectangles to crop from the texture and
	// to render on the screen.
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {

			SDL_Rect sourceRect;
			sourceRect.x = (map[i][j] % sourceNTilesInRow) * sourceTileSizePx;
			sourceRect.y = (map[i][j] / sourceNTilesInRow) * sourceTileSizePx;
			sourceRect.h = sourceTileSizePx;
			sourceRect.w = sourceTileSizePx;

			SDL_Rect renderRect;
			renderRect.x = j * tileWidth;
			renderRect.y = i * tileHeight;
			renderRect.h = tileHeight;
			renderRect.w = tileWidth;

			Tile newTile = Tile();
			newTile.sourceRect = sourceRect;
			newTile.destinationRect = renderRect;
			tiles.push_back(newTile);
		}
	}
}


void TiledMap::Render()
{
	for (Tile& tile : tiles)
	{
		SDL_RenderCopy(renderer, texture, &tile.sourceRect, &tile.destinationRect);
	}
}



TiledMap::~TiledMap()
{
	SDL_DestroyTexture(texture);
}