#include "raylib.h"

int main(void)
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, "Game");

    InitAudioDevice();

    

    while (!WindowShouldClose())
    {
        ClearBackground(RED);


        BeginDrawing();

        DrawFPS(0, 0);

        DrawRectangleGradientV(200, 200, 200, 200, BLUE, GREEN);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}