#pragma once
#include <vector>
#include <mdspan>
#include <Tile.h>

class Grid
{
public:
	//static void SetGrid(std::vector<Tile>* tiles, int width, int height);
	static void SetGrid(std::vector<Tile>* tiles, int widthSplit);
	static void DrawBackground();
private:
	Grid();
	~Grid();
	//static std::mdspan<Tile, std::extents<std::size_t, std::dynamic_extent, std::dynamic_extent>> m_grid;
	static std::vector<Tile> m_grid;
	static size_t m_widthSplit;
};

