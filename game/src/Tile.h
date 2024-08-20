#pragma once

#include <vector>
#include <stddef.h>

class Tile
{
public:
    bool isEmpty;

    Tile();
    Tile( bool isEmpty );
};

std::vector<Tile> NewGrid( size_t width, size_t height );