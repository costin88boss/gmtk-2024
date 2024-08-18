#pragma once

#include <iostream>
#include "raylib.h"
#include "UI.hpp"
#include "LoadSaveTXT.hpp"
#include "Renderer.hpp"

enum Scene { TitleScreen };
Scene currentScene;

class SceneManage
{
public:
    static void UpdateScene()
    {
        switch ( currentScene )
        {
            case TitleScreen:
                ClearBackground( DARKBLUE );

                BeginDrawing();

                DrawFPS( 0, 0 );

                Renderer::RenderRect( LoadRectData( "resources/scenes/titleScreen/panel.txt" ) );
                Renderer::RenderText( LoadTextData( "resources/scenes/titleScreen/title.txt" ) );
                Renderer::RenderButton( LoadButtonData( "resources/scenes/titleScreen/playButton.txt" ) );

                if ( LoadButtonData( "resources/scenes/titleScreen/playButton.txt" ).IsClicked() )
                {
                    std::cout << "Button is clicked!\n"; 
                }

                EndDrawing();
                break;
        }
    }
};