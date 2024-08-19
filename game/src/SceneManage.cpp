#include "SceneManage.h"

Scene SceneManage::m_currentScene = TITLE_SCREEN;

// Title Screen Variables
Button playButton( { 480, 300 },
                   { 400, 50 },
                   ( Color ){ 0, 0, 20, 160 },
                   "Start",
                   [](){ SceneManage::ChangeScene( GAMEPLAY ); } );

void SceneManage::ChangeScene( Scene scene )
{
    SceneManage::m_currentScene = scene;
}

void SceneManage::Update()
{
    switch ( m_currentScene )
    {
        case TITLE_SCREEN:
            TitleScreen();
            break;
        case GAMEPLAY:
            Gameplay();
            break;
    }
}

void TitleScreen()
{
    BeginDrawing();
    ClearBackground( DARKBLUE );
    DrawRectangleV( { 220, 0 }, { 500, 600 }, (Color){ 0, 0, 0, 120 } );
    DrawText( "Title", 400, 60, 60, WHITE );
    playButton.CheckForInput();
    playButton.Draw();
    EndDrawing();
}

void Gameplay()
{
    BeginDrawing();
    ClearBackground( DARKPURPLE );
    DrawRectangleV( { 50, 50 }, { 860, 500 }, ( Color ){ 0, 0, 0, 140 } );
    DrawText( "Gameplay", 340, 270, 60, WHITE );
    EndDrawing();
}