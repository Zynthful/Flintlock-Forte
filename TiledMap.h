#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <list>
#include <iostream>

// note: this assumes all tiles are equal size
const int mapWidth = 40;	// how many columns of tiles
const int mapHeight = 18;	// how many rows of tiles
const int map[mapHeight][mapWidth] =
{
	// enter map tile data here
	// fml
	{576, 579, 54, 54},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
};

struct Tile
{
	SDL_Rect sourceRect;		// rect info about the source tile in the tilemap image
	SDL_Rect destinationRect;	// where to render the source tile
};

class TiledMap
{
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