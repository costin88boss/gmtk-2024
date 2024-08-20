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
    std::vector<Vector2> positions;

    positions.push_back((Vector2){x           , y            });
    positions.push_back((Vector2){x + size - 1, y            });
    positions.push_back((Vector2){x           , y + size - 1});
    positions.push_back((Vector2){x + size - 1, y + size - 1});
    
    for ( Object* obj : m_objects )
    {
        if ( !dynamic_cast<Box*>( obj ) ) continue;
        Box* box = dynamic_cast<Box*>( obj );

        std::vector<Vector2> boxPositions;

        boxPositions.push_back((Vector2){box->x                , box->y                });
        boxPositions.push_back((Vector2){box->x + box->size - 1, box->y                });
        boxPositions.push_back((Vector2){box->x                , box->y + box->size - 1});
        boxPositions.push_back((Vector2){box->x + box->size - 1, box->y + box->size - 1});

        for ( int i = 0; i < 4; i++)
        {
            if ( ( positions[i].x == boxPositions[0].x && positions[i].y == boxPositions[0].y) ||
                 ( positions[i].x == boxPositions[1].x && positions[i].y == boxPositions[1].y) ||
                 ( positions[i].x == boxPositions[2].x && positions[i].y == boxPositions[2].y) ||
                 ( positions[i].x == boxPositions[3].x && positions[i].y == boxPositions[3].y)   )
                {
                    if ( size >= box->size && !CheckForWallCollision( box->x + moveX, box->y - moveY, box->size ) )
                    {
                        box->x += moveX;
                        box->y -= moveY;

                        return false;
                    }
                    return true;
                }
        }
    }
    return false;
}