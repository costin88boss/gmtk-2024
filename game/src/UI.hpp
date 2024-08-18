#pragma once

#include <string>
#include "raylib.h"
#include "Object.hpp"

class Text : public Object
{
public:
    std::string text;
    u_int size;
    Color color;

    Text( Vector2 position, std::string text, u_int size, Color color );
};

Text::Text( Vector2 position, std::string text, u_int size, Color color )
    :
    Object( position, TextType ),
    text( text ),
    size( size ),
    color( color )
{}

class Button : public Rect
{
public:
    std::string text;
    Vector2 textPosition;
    u_int textSize;
    Color textColor;

    Button( Vector2 buttonPos,  Vector2 textPos,
            Vector2 buttonSize, int textSize, 
            Color buttonColor,  Color textColor, 
            std::string text );

    bool IsClicked();
};

Button::Button( Vector2 buttonPos,  Vector2 textPos,
            Vector2 buttonSize, int textSize, 
            Color buttonColor,  Color textColor, 
            std::string text )
            :
            Rect( buttonPos, buttonSize, buttonColor, ButtonType ),
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