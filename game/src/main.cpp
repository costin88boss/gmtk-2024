#include <iostream>
#include "raylib.h"
#include "text.hpp"
#include "loadsavetxt.hpp"

int main(void)
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, "Game");

    InitAudioDevice();

    // Text( { 220, 270 }, "HELLO, WORLD!", 50, WHITE );
    std::string data = "text:HELLO, WORLD!\n"
                       "posX:220.0\n"
                       "posY:270.0\n"
                       "size:50\n"
                       "colorR:255\n"
                       "colorG:255\n"
                       "colorB:255\n"
                       "colorA:255\n";
    
    Text title = LoadTextDataFromString(data);

    while (!WindowShouldClose())
    {
        ClearBackground(RED);

        BeginDrawing();

        DrawFPS(0, 0);
        DrawRectangleGradientV( 300, 200, 200, 200, BLUE, GREEN);

        DrawText( title.text.c_str(),
                  title.position.x,
                  title.position.y, 
                  title.size, 
                  title.color );

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
}