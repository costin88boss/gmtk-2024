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
    Vector2 pos = GetCenteredRectPos( position, size );
    return ( GetMouseX() > pos.x && GetMouseX() < pos.x + size.x &&
             GetMouseY() > pos.y && GetMouseY() < pos.y + size.y );
}

void Button::Draw() const
{
    if ( IsHovered() )
    {
        DrawRectangleV( GetCenteredRectPos( { position.x - 5, position.y - 5 }, size ),
                                       { size.x + 10, size.y + 10 }, 
                                       Color { 255, 255, 255, 60 } );
        DrawRectangleV( GetCenteredRectPos( position, size ), size, color );
    }
    else
    {
        DrawRectangleV( GetCenteredRectPos( position, size ), size, color );
    }
    DrawText( text.c_str(), static_cast<int>(GetCenteredTextPos( position, size, text ).x),
                            static_cast<int>(GetCenteredTextPos( position, size, text ).y),
        static_cast<int>(size.y), WHITE );
}

void Button::CheckForInput() const
{
    if ( IsHovered() && IsMouseButtonPressed( 0 ) )
    {
        PlaySound( LoadSound( "resources/sfx/select.wav" ) );
        this->onClickEvent();
    }
}