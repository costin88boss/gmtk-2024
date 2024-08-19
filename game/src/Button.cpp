#include "Button.h"

Button::Button( Vector2 position, Vector2 size, Color color, std::string text, void (*onClickEvent)() )
    :
    position( position ),
    size( size ),
    color( color ),
    text( text ),
    onClickEvent( onClickEvent )
{}

bool Button::IsHovered() const
{
    Vector2 pos = CenterRectPos( position, size );
    return ( GetMouseX() > pos.x && GetMouseX() < pos.x + size.x &&
             GetMouseY() > pos.y && GetMouseY() < pos.y + size.y );
}

void Button::Draw() const
{
    if ( IsHovered() )
    {
        DrawRectangleV( CenterRectPos( { position.x - 5, position.y - 5 }, size ),
                                       { size.x + 10, size.y + 10 }, 
                                       Color { 200, 200, 255, 40 }             );
        DrawRectangleV( CenterRectPos( position, size ), size, color );
    }
    else
    {
        DrawRectangleV( CenterRectPos( position, size ), size, color );
    }
    DrawText( text.c_str(), static_cast<int>(CenterTextPos( position, size, text ).x),
                            static_cast<int>(CenterTextPos( position, size, text ).y),
        static_cast<int>(size.y / 1.2), WHITE );
}

void Button::CheckForInput() const
{
    if ( IsHovered() && IsMouseButtonPressed( 0 ) )
    {
        PlaySound( LoadSound( "resources/sfx/select.wav" ) );
        this->onClickEvent();
    }
}

Vector2 CenterRectPos( Vector2 position, Vector2 size )
{
    return { position.x - size.x / 2, position.y - size.y / 2 };
}

Vector2 CenterTextPos( Vector2 position, Vector2 size, std::string text )
{
    return { position.x - text.length() * size.x / 36, position.y - size.y / 2.5f };
}