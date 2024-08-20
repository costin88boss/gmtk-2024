#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <stddef.h>
#include "Game.h"
#include "Tile.h"
#include "Object.h"

class Level
{
public:
    Level( size_t width, size_t height, std::vector<Object*> objects );

    void Update();
private:
    size_t m_width, m_height;
    std::vector<Tile> m_tiles;
    std::vector<Object*> m_objects;

    void DrawTiles();
    void DrawObjects();
    void DrawTile( Tile tile, int x, int y );
    void DrawObject( Object* obj );

    void UpdatePlayer( Player* player );
    void UpdatePlates();
    void UpdatePlate( Plate* plate );

    bool CheckForWallObj( int x, int y, size_t size);
    bool CheckEnding();
    bool CheckForWallCollision( int x, int y, size_t size );
    bool CheckForGate( int x, int y, size_t size );
    bool HandleBoxCollision( int x, int y, int moveX, int moveY, size_t size );
    bool HandleBoxCollisionC( int x, int y, int moveX, int moveY, size_t size );
    bool CheckIfBoxExists( int x, int y, size_t size, Box* exclude );
};