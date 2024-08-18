#pragma once

#include "raylib.h"

enum ObjectType { EmptyType, RectType, TextType, ButtonType };

class Object
{
public:
    Vector2 position;
    ObjectType type;
    
    Object( Vector2 position, ObjectType type );
};

Object::Object( Vector2 position, ObjectType type ) 
    : 
    position( position ),
    type( type )
{}

class Rect : public Object
{
public:
    Vector2 size;
    Color color;

    Rect( Vector2 position, Vector2 size, Color color );
    Rect( Vector2 position, Vector2 size, Color color, ObjectType type );
};

Rect::Rect( Vector2 position, Vector2 size, Color color )
    :
    Object( position, RectType ),
    size( size ),
    color( color )
{}
Rect::Rect( Vector2 position, Vector2 size, Color color, ObjectType type )
    :
    Object( position, type ),
    size( size ),
    color( color )
{}