#pragma once

#include <raylib.h>
#include "Entities/Gate.h"
#include "Entities/Plate.h"
#include "Entities/Movable.h"

struct Tile {
	//Texture2D* bgTexture;
	int test;
	// TO-DO
	// LevelEntity primaryEntity; --- pressure plate/gate

	Gate gate;  // an open gate could be used for no gate ( aka null gate )
	Plate plate;// a plate with m_size = 0 and m_gate = nullptr could be used for no plate ( aka null plate )
	
	// PhysicalEntity secondaryEntity; --- player/crate

	Movable* movableObj; // nullptr for no movableobj
	// or smth like that
	
};