#pragma once

#include <string>
#include "raylib.h"

class Text
{
public:
    std::string text;
    Vector2 position;
    u_int size;
    Color color;

    Text( Vector2 position, std::string text, u_int size, Color color );
    std::string GetData();
    static Text LoadData( std::string& data );
};

Text::Text( Vector2 position, std::string text, u_int size, Color color )
    :
    position( position ),
    text( text ),
    size( size ),
    color( color )
{}

class Rect
{
public:
    Vector2 position;
    Vector2 size;
    Color color;

    Rect( Vector2 position, Vector2 size, Color color );
};

Rect::Rect( Vector2 position, Vector2 size, Color color )
    :
    position( position ),
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