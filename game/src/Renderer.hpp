#pragma once

#include "raylib.h"
#include "UI.hpp"

class Renderer
{
public:
    static void RenderText( const Text& text );
    static void RenderRect( const Rect& panel );
    static void RenderButton( const Button& button );
};

void Renderer::RenderText( const Text& text )
{
    DrawText( text.text.c_str(),
              text.position.x,
              text.position.y,
              text.size,
              text.color );
}

void Renderer::RenderRect( const Rect& rect )
{
    DrawRectangleV( rect.position, rect.size, rect.color );
}

void Renderer::RenderButton( const Button& button )
{
    DrawRectangleV( button.position, button.size, button.color );
    DrawText( button.text.c_str(), button.textPosition.x, button.textPosition.y, button.textSize, button.textColor );
}