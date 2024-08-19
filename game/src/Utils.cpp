#include "Utils.h"

Vector2 GetCenteredRectPos( Vector2 position, Vector2 size )
{
    return { position.x - size.x / 2, position.y - size.y / 2 };
}

Vector2 GetCenteredTextPos( Vector2 position, Vector2 size, std::string text )
{
    return { position.x - MeasureText( text.c_str(), size.y ) / 2, position.y - size.y / 2.25f };
}