#include <iostream>
#include "raylib.h"
#include "UI.hpp"
#include "loadsavetxt.hpp"
#include "Renderer.hpp"

int main()
{
    SetConfigFlags( FLAG_VSYNC_HINT );
    InitWindow( 960, 600, "Game" );
    InitAudioDevice();

    Rect rect = LoadRectDataFromFile( "resources/scenes/titleScreen/panel.txt" );
    Text title = LoadTextDataFromFile( "resources/scenes/titleScreen/title.txt" );
    Button button = LoadButtonDataFromFile( "resources/scenes/titleScreen/playButton.txt" );

    while ( !WindowShouldClose() )
    {
        ClearBackground( DARKBLUE );

        BeginDrawing();

        DrawFPS( 0, 0 );

        Renderer::RenderRect( rect );
        Renderer::RenderText( title );
        Renderer::RenderButton( button );

        if ( button.IsClicked() )
        {
            std::cout << "Button is clicked!\n"; 
        }

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
}