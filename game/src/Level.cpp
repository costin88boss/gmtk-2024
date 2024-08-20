#include "Level.h"
#include "SceneManage.h"

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
    UpdatePlates();
    if ( CheckEnding() )
    {
        PlaySound( Game::sfx[ "End" ]);
        SceneManage::ChangeScene( (Scene) (SceneManage::m_currentScene + 1) );
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
         !HandleBoxCollisionC  ( player->x + hInput, player->y - vInput, hInput, vInput, player->size) &&
         !CheckForGate( player->x + hInput, player->y - vInput, player->size ) &&
         !CheckForWallObj( player->x + hInput, player->y - vInput, player->size ))
    {
        player->Move( hInput, -vInput );
        HandleBoxCollision( player->x, player->y, hInput, vInput, player->size);
    }
    else
    {
        PlaySound(Game::sfx["Wall"]);
    }
}

bool Level::CheckForWallObj( int x, int y, size_t size)
{
    std::vector<Vector2> positions;

    positions.push_back((Vector2){x           , y           });
    positions.push_back((Vector2){x + size - 1, y           });
    positions.push_back((Vector2){x           , y + size - 1});
    positions.push_back((Vector2){x + size - 1, y + size - 1});
    
    for ( Object* obj : m_objects )
    {
        if ( !dynamic_cast<Wall*>( obj ) ) continue;
        Wall* wall = dynamic_cast<Wall*>( obj );

        Vector2 wallV = { wall->x, wall->y };

        for ( int i = 0; i < 4; i++)
        {
            if ( ( positions[i].x == wallV.x && positions[i].y == wallV.y )||
                 ( positions[i].x == wallV.x && positions[i].y == wallV.y )||
                 ( positions[i].x == wallV.x && positions[i].y == wallV.y )||
                 ( positions[i].x == wallV.x && positions[i].y == wallV.y )  )
            {
                return true;
            }
        }
    }

    return false;
}

bool Level::CheckEnding()
{
    for ( Object* obj : m_objects )
    {
        if ( !dynamic_cast<End*>( obj ) ) continue;
        End* end = dynamic_cast<End*>(obj);
        
        for ( Object* obj : m_objects )
        {
            if ( !dynamic_cast<Player*>( obj ) ) continue;
            Player* player = dynamic_cast<Player*>(obj);

            if ( player->x == end->x && player->y == end->y && player->size == end->size )
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

void Level::UpdatePlates()
{
    for ( Object* obj : m_objects )
    {
        if ( !dynamic_cast<Plate*>( obj ) ) continue;
        UpdatePlate( dynamic_cast<Plate*>( obj ) );
    }
}
void Level::UpdatePlate( Plate* plate )
{
    std::vector<Vector2> positions;

    positions.push_back((Vector2){plate->x                  , plate->y                  });
    positions.push_back((Vector2){plate->x + plate->size - 1, plate->y                  });
    positions.push_back((Vector2){plate->x                  , plate->y + plate->size - 1});
    positions.push_back((Vector2){plate->x + plate->size - 1, plate->y + plate->size - 1});
    
    for ( Object* obj : m_objects )
    {
        if ( !dynamic_cast<Box*>( obj ) && !dynamic_cast<Player*>( obj ) ) continue;

        std::vector<Vector2> objPositions;

        objPositions.push_back((Vector2){obj->x                , obj->y                });
        objPositions.push_back((Vector2){obj->x + obj->size - 1, obj->y                });
        objPositions.push_back((Vector2){obj->x                , obj->y + obj->size - 1});
        objPositions.push_back((Vector2){obj->x + obj->size - 1, obj->y + obj->size - 1});

        for ( int i = 0; i < 4; i++)
        {
            if ( ( positions[i].x == objPositions[0].x && positions[i].y == objPositions[0].y) ||
                 ( positions[i].x == objPositions[1].x && positions[i].y == objPositions[1].y) ||
                 ( positions[i].x == objPositions[2].x && positions[i].y == objPositions[2].y) ||
                 ( positions[i].x == objPositions[3].x && positions[i].y == objPositions[3].y)   )
                {
                    plate->UpdatePlate( obj );
                }
        }
    }
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

bool Level::CheckForGate( int x, int y, size_t size )
{
    std::vector<Vector2> positions;

    positions.push_back((Vector2){x           , y            });
    positions.push_back((Vector2){x + size - 1, y            });
    positions.push_back((Vector2){x           , y + size - 1});
    positions.push_back((Vector2){x + size - 1, y + size - 1});
    
    for ( Object* obj : m_objects )
    {
        if ( !dynamic_cast<Gate*>( obj ) ) continue;
        Gate* gate = dynamic_cast<Gate*>( obj );

        std::vector<Vector2> gatePositions;

        gatePositions.push_back((Vector2){gate->x                 , gate->y                });
        gatePositions.push_back((Vector2){gate->x + gate->size - 1, gate->y                });
        gatePositions.push_back((Vector2){gate->x                 , gate->y + gate->size - 1});
        gatePositions.push_back((Vector2){gate->x + gate->size - 1, gate->y + gate->size - 1});

        for ( int i = 0; i < 4; i++)
        {
            if ( ( positions[i].x == gatePositions[0].x && positions[i].y == gatePositions[0].y) ||
                 ( positions[i].x == gatePositions[1].x && positions[i].y == gatePositions[1].y) ||
                 ( positions[i].x == gatePositions[2].x && positions[i].y == gatePositions[2].y) ||
                 ( positions[i].x == gatePositions[3].x && positions[i].y == gatePositions[3].y)   )
                {
                    return !gate->isOpen;
                }
        }
    }
    return false;
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
                    if ( size >= box->size && !CheckForWallCollision( box->x + moveX, box->y - moveY, box->size ) &&
                         !CheckIfBoxExists( box->x + moveX, box->y - moveY, box->size, box ) && 
                         !CheckForGate( box->x + moveX, box->y - moveY, box->size ) &&
                         !CheckForWallObj( box->x + moveX, box->y - moveY, box->size )) 
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

bool Level::HandleBoxCollisionC( int x, int y, int moveX, int moveY, size_t size )
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
                    if ( size >= box->size && !CheckForWallCollision( box->x + moveX, box->y - moveY, box->size ) &&
                         !CheckIfBoxExists( box->x + moveX, box->y - moveY, box->size, box ) && 
                         !CheckForGate( box->x + moveX, box->y - moveY, box->size) &&
                         !CheckForWallObj( box->x + moveX, box->y - moveY, box->size ) )
                    {
                        //box->x += moveX;
                        //box->y -= moveY;

                        return false;
                    }
                    return true;
                }
        }
    }
    return false;
}

bool Level::CheckIfBoxExists( int x, int y, size_t size, Box* exclude )
{
    std::vector<Vector2> positions;

    positions.push_back((Vector2){x           , y            });
    positions.push_back((Vector2){x + size - 1, y            });
    positions.push_back((Vector2){x           , y + size - 1});
    positions.push_back((Vector2){x + size - 1, y + size - 1});

    for ( Object* obj : m_objects )
    {
        if ( !dynamic_cast<Box*>( obj ) || dynamic_cast<Box*>( obj ) == exclude ) continue;
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
                return true;
            }
        }
    }

    return false;
}