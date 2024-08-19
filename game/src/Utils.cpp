#include "Utils.h"

Vector2 GetCenteredRectPos( Vector2 position, Vector2 size )
{
    return { position.x - size.x / 2, position.y - size.y / 2 };
}

Vector2 GetCenteredTextPos( Vector2 position, Vector2 size, std::string text )
{
    return { position.x - text.length() * size.x / 36, position.y - size.y / 2.5f };
}