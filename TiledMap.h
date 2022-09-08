#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <list>
#include <iostream>


const int mapWidth = 10;
const int mapHeight = 4;
const int map[mapHeight][mapWidth] = {
	{5, 6, 6, 6, 6, 6, 6, 6, 6, 7},
	{19, 20, 20, 20, 20, 20, 20, 20, 20, 21},
	{19, 20, 20, 20, 20, 20, 20, 20, 20, 21},
	{1, 20, 20, 20, 20, 20, 20, 20, 20, 2}
};

struct Tile {
	SDL_Rect sourceRect;		// rect info about the source tile in the tilemap image
	SDL_Rect destinationRect;	// where to render the source tile
};

class TiledMap {
public:
	TiledMap(SDL_Renderer* sdlRenderer,
		std::string tiledMapFilename);
	~TiledMap();

	void Render();

private:
	void CreateTiles();

	const int sourceTileSizePx = 32;
	const int sourceNTilesInRow = 14;	// how many tiles per row
	const int tileWidth = 64;
	const int tileHeight = 64;

	std::list<Tile> tiles;

	std::string filename;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};