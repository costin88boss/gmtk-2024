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
    std::string spriteKey = "resources/sprites/Box";
    spriteKey += 48 + size; // 48-57 in ASCII is 0-9 
    spriteKey.append(".png");

    return LoadTexture( spriteKey.c_str() );
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