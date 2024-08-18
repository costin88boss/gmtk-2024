#pragma once

#include "raylib.h"
#include "UI.h"

class Renderer
{
public:
    static void RenderText( const Text& text );
    static void RenderRect( const Rect& panel );
    static void RenderButton( const Button& button );
};