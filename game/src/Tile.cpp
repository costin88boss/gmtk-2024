#include "Tile.h"

Tile::Tile() : isEmpty( false ) {}
Tile::Tile( bool isEmpty ) : isEmpty( isEmpty ) {}

std::vector<Tile> NewGrid( size_t width, size_t height )
{
    std::vector<Tile> grid;

    for ( int j = 0; j < height; j++ )
    {
        for ( int i = 0; i < width; i++ )
        {
            if ( i == 0 || i == width - 1 || j == 0 || j == height - 1 )
            {
                grid.push_back( Tile() );
            }
            else
            {
                grid.push_back( Tile( true ) );
            }
        }
    }

    return grid;
}