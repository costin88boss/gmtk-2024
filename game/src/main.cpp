#include "raylib.h"
#include "Grid.h"
#include <mdspan>

int main(void)
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, "Game");

    InitAudioDevice();

    int i = 0;
    std::vector<Tile> asd =
    { 
        Tile {++i},
    };


    Grid::SetGrid(&asd, 6);

    while (!WindowShouldClose())
    {
        ClearBackground(RED);


        BeginDrawing();

        DrawFPS(0, 0);

        Grid::DrawBackground();

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}