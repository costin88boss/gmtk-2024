#pragma once

#include <string>
#include <stddef.h>
#include "raylib.h"
#include "Game.h"

class Object
{
public:
    int x, y;
    size_t size;

    Object( int x, int y, size_t size );
    virtual void Move( int x, int y );
    virtual Texture2D GetSprite() = 0;
};

class Box : public Object
{
public:
    Box( int x, int y, size_t size );
    Texture2D GetSprite();
};

class Player : public Object
{
public:
    size_t resizes;

    Player( int x, int y, size_t size, size_t resizes );
    Texture2D GetSprite();
    void Move( int x, int y ) override;
};

class Gate : public Object
{
public:
    bool isOpen;

    Gate( int x, int y, size_t size );
    Texture2D GetSprite();
};

class Plate : public Object
{
public:
    Gate* gate;

    Plate( int x, int y, size_t size, Gate* gate );
    Texture2D GetSprite();

    void UpdatePlate( Object* obj );
};