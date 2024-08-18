#include "Button.h"
#include "iostream"

Button::Button( Vector2 position, Vector2 size, Color color, std::string text, void (*onClickEvent)() )
    :
    position( position ),
    size( size ),
    color( color ),
    text( text ),
    onClickEvent( onClickEvent )
{}

void Button::Draw()
{
    DrawRectangleV( CenterRectPos( position, size ), size, color );
    DrawText( text.c_str(), CenterTextPos( position, size ).x,
                            CenterTextPos( position, size ).y,
                            ( size.x + size.y ) / 6, BLACK );
}

void Button::CheckForInput()
{
    Vector2 pos = CenterRectPos( position, size );
    if ( GetMouseX() > pos.x && GetMouseX() < pos.x + size.x &&
         GetMouseY() > pos.y && GetMouseY() < pos.y + size.y    )
    {
        if ( IsMouseButtonPressed( 0 ) )
        {
            this->onClickEvent();
        }
    }
}

Vector2 CenterRectPos( Vector2 position, Vector2 size )
{
    return { position.x - size.x / 2, position.y - size.y / 2 };
}

Vector2 CenterTextPos( Vector2 position, Vector2 size )
{
    return { position.x - size.x / 4.2f, position.y - size.y / 2.3f };
}