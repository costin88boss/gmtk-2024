#include <iostream>
#include "raylib.h"
#include "Game.hpp"
#include "UI.hpp"
#include "LoadSaveTXT.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"

int main()
{
    Game game( 960, 600, "Game" );

    InitAudioDevice();

    

    while (!WindowShouldClose())
    {
        ClearBackground(RED);


        BeginDrawing();

        DrawFPS(0, 0);

        DrawRectangleGradientV(200, 200, 200, 200, BLUE, GREEN);

        EndDrawing();
    }
}