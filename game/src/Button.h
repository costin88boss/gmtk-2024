#pragma once

#include <string>
#include <raylib.h>

class Button
{
public:
    Vector2 position;
    Vector2 size;
    Color color;
    std::string text;
    void (*onClickEvent)();

    Button( Vector2 position, Vector2 size, Color color, std::string text, void (*onClickEvent)() );

    bool IsHovered();
    void CheckForInput();
    void Draw();
};

Vector2 CenterRectPos( Vector2 position, Vector2 size );
Vector2 CenterTextPos( Vector2 position, Vector2 size, std::string text );