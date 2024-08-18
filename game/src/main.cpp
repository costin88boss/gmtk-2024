#include <iostream>
#include "raylib.h"
#include "Game.h"
#include "UI.h"
#include "LoadSaveTXT.h"
#include "Renderer.h"
#include "Scene.h"

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