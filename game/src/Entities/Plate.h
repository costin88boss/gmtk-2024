#pragma once

#include <stddef.h>
#include "Gate.h"
#include "Movable.h"

class Plate
{
public:
    Plate( size_t size, Gate* gate );

    void UpdateActivity( Movable* movableObj );
private:
    size_t m_size;
    Gate* m_gate;
};