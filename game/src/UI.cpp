#include "UI.h"

Text::Text( Vector2 position, std::string text, u_int size, Color color )
    :
    Object( position ),
    text( text ),
    size( size ),
    color( color )
{}

Button::Button( Vector2 buttonPos,  Vector2 textPos,
            Vector2 buttonSize, int textSize, 
            Color buttonColor,  Color textColor, 
            std::string text )
            :
            Rect( buttonPos, buttonSize, buttonColor ),
            text( text ),
            textPosition( textPos ),
            textSize( textSize ),
            textColor( textColor )
{}

bool Button::IsClicked()
{
    if ( !( GetMouseX() > position.x && GetMouseX() < position.x + size.x &&
            GetMouseY() > position.y && GetMouseY() < position.y + size.y ) )
        return false;
    if ( !IsMouseButtonPressed(0) ) 
        return false;
    return true;
}