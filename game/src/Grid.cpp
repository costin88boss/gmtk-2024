#include "Grid.h"

#include <iostream>

std::vector<Tile> Grid::m_grid = std::vector<Tile>(0);
size_t Grid::m_widthSplit = 0;

Grid::Grid() {

}

Grid::~Grid()
{

}

//void Grid::SetGrid(std::vector<Tile>* tiles, int width, int height)
void Grid::SetGrid( std::vector<Tile>* tiles, int widthSplit)
{
	//m_grid = std::mdspan<Tile, std::extents<std::size_t, std::dynamic_extent, std::dynamic_extent>> (tiles->data(), width, height);
	m_grid = std::vector<Tile>(*tiles); // intentional copy
	m_widthSplit = widthSplit;
}

/*
for (std::size_t i = 0; i < m_grid.extent(0); ++i) {
	for (std::size_t j = 0; j < m_grid.extent(1); ++j) {
		m_grid(nullptr, nullptr, nullptr, nullptr) = Tile();
	}
	std::cout << std::endl;
}*/
void Grid::DrawBackground() {
	for (size_t i = 0; i < m_grid.size(); i++)
	{
		size_t j = i % m_widthSplit;
		std::cout << m_grid.at(i).test << " ";
		if (j == m_widthSplit - 1) std::cout << std::endl;
	}
}