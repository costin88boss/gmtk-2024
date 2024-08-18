#pragma once

#include "raylib.h"

class Object
{
public:
    Vector2 position;
    
    Object( Vector2 position );
};

class Rect : public Object
{
public:
    Vector2 size;
    Color color;

    Rect( Vector2 position, Vector2 size, Color color );
};