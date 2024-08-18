#include "Scene.h"

Scene currentScene = TitleScreen;

void SceneManage::UpdateScene()
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