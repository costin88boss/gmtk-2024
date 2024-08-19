#pragma once

#include <stddef.h>

class Movable
{
public:
    size_t size;
    virtual void Move( int x, int y ) = 0;
};

class Box : public Movable
{
public:
    void Move( int x, int y );
};

class Player : public Movable
{
public:
    size_t resizes;
    void Move( int x, int y );
};