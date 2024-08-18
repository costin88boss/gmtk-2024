#include "Object.h"

Object::Object( Vector2 position ) 
    : 
    position( position )
{}

Rect::Rect( Vector2 position, Vector2 size, Color color )
    :
    Object( position ),
    size( size ),
    color( color )
{}