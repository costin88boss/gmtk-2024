#pragma once

#include <string>
#include "raylib.h"
#include "Object.h"

class Text : public Object
{
public:
    std::string text;
    size_t size;
    Color color;

    Text( Vector2 position, std::string text, size_t size, Color color );
};

class Button : public Rect
{
public:
    std::string text;
    Vector2 textPosition;
    int textSize;
    Color textColor;

    Button( Vector2 buttonPos,  Vector2 textPos,
            Vector2 buttonSize, int textSize, 
            Color buttonColor,  Color textColor, 
            std::string text );

    bool IsClicked();
};