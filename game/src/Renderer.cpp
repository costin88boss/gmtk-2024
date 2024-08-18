#include "Renderer.h"

void Renderer::RenderText( const Text& text )
{
    DrawText( text.text.c_str(),
        static_cast<int>(text.position.x),
        static_cast<int>(text.position.y),
        static_cast<int>(text.size),
              text.color );
}

void Renderer::RenderRect( const Rect& rect )
{
    DrawRectangleV( rect.position, rect.size, rect.color );
}

void Renderer::RenderButton( const Button& button )
{
    DrawRectangleV( button.position, button.size, button.color );
    DrawText( button.text.c_str(), static_cast<int>(button.textPosition.x), static_cast<int>(button.textPosition.y), button.textSize, button.textColor);
}