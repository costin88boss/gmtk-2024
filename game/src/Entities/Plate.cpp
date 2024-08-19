#include "Plate.h"

Plate::Plate( size_t size, Gate* gate )
    :
    m_size( size ),
    m_gate( gate )
{}

void Plate::UpdateActivity( Movable* movableObj )
{
    if ( movableObj->size >= m_size )
    {
        m_gate->isOpen = true;
    }
    else
    {
        m_gate->isOpen = false;
    }
}