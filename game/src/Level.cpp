#include "Level.h"
#include <iostream>

const size_t SPRITE_SIZE = 48;

Level::Level( size_t width, size_t height, std::vector<Object*> objects )
    :
    m_width( width ),
    m_height( height ),
    m_objects( objects )
{
    m_tiles = NewGrid( width, height );
}

void Level::Update()
{
    this->DrawTiles();
    this->DrawObjects();
    for ( Object* obj : m_objects )
    {
        if ( dynamic_cast<Player*>( obj ) )
        {
            UpdatePlayer( dynamic_cast<Player*>( obj ));
        }
    }
}

void Level::DrawTiles()
{
    for ( int j = 0; j < m_height; j++ )
    {
        for ( int i = 0; i < m_width; i++ )
        {
            DrawTile( m_tiles[ j * m_width + i ], i, j );
        }
    }
}

void Level::DrawObjects()
{
    for ( Object* obj : m_objects )
    {
        DrawObject( obj );
    }
}

void Level::DrawTile( Tile tile, int x, int y )
{
    Vector2 centerOffset = { ( GetScreenWidth()  - ( m_width  * SPRITE_SIZE ) ) / 2,
                             ( GetScreenHeight() - ( m_height * SPRITE_SIZE ) ) / 2  };
    if ( tile.isEmpty )
    {
        DrawTextureEx( Game::sprites["Tile"], 
                    { x * SPRITE_SIZE + centerOffset.x, y * SPRITE_SIZE + centerOffset.y }, 
                    0, SPRITE_SIZE / 16, WHITE );
    }
    else
    {
        DrawTextureEx( Game::sprites["Wall"], 
                    { x * SPRITE_SIZE + centerOffset.x, y * SPRITE_SIZE + centerOffset.y }, 
                    0, SPRITE_SIZE / 16, WHITE );
    }
}

void Level::DrawObject( Object* obj )
{
    Vector2 centerOffset = { ( GetScreenWidth()  - ( m_width  * SPRITE_SIZE ) ) / 2,
                             ( GetScreenHeight() - ( m_height * SPRITE_SIZE ) ) / 2  };

    DrawTextureEx( obj->GetSprite(), 
                { obj->x * SPRITE_SIZE + centerOffset.x, obj->y * SPRITE_SIZE + centerOffset.y }, 
                0, SPRITE_SIZE / 16, WHITE );
}

void Level::UpdatePlayer( Player* player )
{
    int hInput = IsKeyPressed( KEY_D ) - IsKeyPressed( KEY_A );
    int vInput = IsKeyPressed( KEY_W ) - IsKeyPressed( KEY_S );
    if ( !CheckForWallCollision( player->x + hInput, player->y - vInput, player->size ) &&
         !HandleBoxCollision   ( player->x + hInput, player->y - vInput, hInput, vInput, player->size ))
        player->Move( hInput, -vInput );
}

bool Level::CheckForWallCollision( int x, int y, size_t size )
{
    bool out = true;
    switch ( size )
    {
        case 1:
            if ( m_tiles[ y * m_width + x ].isEmpty )
                out = false;
            break;
        case 2:
            if ( m_tiles[ y * m_width + x ].isEmpty &&
                 m_tiles[ (y + 1) * m_width + (x + 1) ].isEmpty )
                out = false;
            break;
        case 3:
            if ( m_tiles[ y * m_width + x ].isEmpty &&
                 m_tiles[ (y + 1) * m_width + (x + 1) ].isEmpty &&
                 m_tiles[ (y + 2) * m_width + (x + 2) ].isEmpty )
                out = false;
            break;
    }
    return out;
}

bool Level::HandleBoxCollision( int x, int y, int moveX, int moveY, size_t size )
{
    bool out = true;
    
    for ( Object* obj : m_objects )
    {
        if ( !dynamic_cast<Box*>( obj ) ) continue;
        Box* box = dynamic_cast<Box*>( obj );
        switch ( size )
        {
            case 1:
                if ( box->x == x && box->y == y )
                {
                    if ( size >= box->size &&
                        !CheckForWallCollision( box->x + moveX, box->y - moveY, box->size ) )
                    {
                        box->x += moveX;
                        box->y -= moveY;
                        out = false;
                    }
                }
                else
                {
                    out = false;
                }
                break;
            case 2:
                if ( box->x == x     && box->y == y &&
                     box->x == x + 1 && box->y == y + 1 )
                {
                    if ( size >= box->size )
                    {
                        box->x += moveX;
                        box->y -= moveY;
                        out = false;
                    }
                }
                else
                {
                    out = false;
                }
                break;
            case 3:
                if ( box->x == x     && box->y == y &&
                     box->x == x + 1 && box->y == y + 1 && 
                     box->x == x + 2 && box->y == y + 2  )
                {
                    if ( size >= box->size )
                    {
                        box->x += moveX;
                        box->y -= moveY;
                        out = false;
                    }
                }
                else
                {
                    out = false;
                }
                break;
        }
    }
    return out;
}