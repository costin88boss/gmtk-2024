#pragma once

#include <string>
#include <raylib.h>
#include "Utils.h"

class Button
{
public:
    Vector2 position;
    Vector2 size;
    Color color;
    std::string text;
    void (*onClickEvent)();

    Button( Vector2 position, Vector2 size, Color color, std::string text, void (*onClickEvent)() );

    bool IsHovered() const;
    void CheckForInput() const;
    void Draw() const;
};