#include "Object.h"

Object::Object( int x, int y, size_t size )
    :
    x( x ),
    y( y ),
    size( size )
{}

void Object::Move( int x, int y )
{
    this->x += x;
    this->y += y;
}

Box::Box( int x, int y, size_t size )
    :
    Object( x, y, size )
{}

Texture2D Box::GetSprite()
{
    std::string spriteKey = "Box";
    spriteKey += 48 + size; // 48-57 in ASCII is 0-9 

    return Game::sprites[spriteKey];
}

Player::Player( int x, int y, size_t size, size_t resizes )
    :
    Object( x, y, size ),
    resizes( resizes )
{}

Texture2D Player::GetSprite()
{
    std::string spriteKey = "Player";
    spriteKey += 48 + size; // 48-57 in ASCII is 0-9 
    return Game::sprites[spriteKey];//LoadTexture( filePath.c_str() );
}

void Player::Move( int x, int y )
{
    this->x += x;
    this->y += y;
    if ( x != 0 || y != 0 )
        PlaySound(Game::sfx["Move"]);
}

Gate::Gate( int x, int y, size_t size )
    :
    Object( x, y, size )
{}

Texture2D Gate::GetSprite()
{
    switch ( size )
    {
        case 1:
            if ( isOpen )
                return Game::sprites["Gate1O"];
            else
                return Game::sprites["Gate1C"];
        case 2:
            if ( isOpen )
                return Game::sprites["Gate2O"];
            else
                return Game::sprites["Gate2C"];
        case 3:
            if ( isOpen )
                return Game::sprites["Gate3O"];
            else
                return Game::sprites["Gate3C"];
    }
}

Plate::Plate( int x, int y, size_t size, Gate* gate )
    :
    Object( x, y, size ),
    gate( gate ),
    activated( false )
{}

Texture2D Plate::GetSprite()
{
    switch ( size )
    {
        case 1:
            return Game::sprites["Plate1"];
        case 2:
            return Game::sprites["Plate2"];
        case 3:
            return Game::sprites["Plate3"];
    }
}

void Plate::UpdatePlate( Object* obj )
{
    if ( obj->size >= size )
    {
        gate->isOpen = true;
        if ( !activated )
        {
            activated = true;
            PlaySound( Game::sfx[ "Plate" ] );
        }
    }
    else
    {
        gate->isOpen = false;
    }
}

void Plate::Reset()
{
    if ( activated )
    {
        activated = false;
        PlaySound( Game::sfx[ "Plate" ] );
    }
    gate->isOpen = false;
}

Wall::Wall( int x, int y )
    :
    Object( x, y, 1 )
{}

Texture2D Wall::GetSprite()
{
    return Game::sprites[ "Wall" ];
}

End::End( int x, int y, size_t size )
    :
    Object( x, y, size )
{}

Texture2D End::GetSprite()
{
    switch (size)
    {
        case 1:
            return Game::sprites["End1"];
        case 2:
            return Game::sprites["End2"];
        case 3:
            return Game::sprites["End3"];
    }
}