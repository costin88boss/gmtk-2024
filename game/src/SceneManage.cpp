#include "SceneManage.h"
#include "Button.h"

Scene SceneManage::m_currentScene = TITLE_SCREEN;

// Title Screen Variables
Button playButton( { 480, 300 }, { 200, 50 }, WHITE, "Play", &SceneManage::GoToNextScene );

void SceneManage::GoToNextScene()
{
    SceneManage::m_currentScene = ( Scene )( m_currentScene + 1 );
}

void SceneManage::Update()
{
    switch ( m_currentScene )
    {
        case TITLE_SCREEN:
            TitleScreen();
            break;
        case LEVEL1:
            Level1();
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

void Level1()
{
    BeginDrawing();
    ClearBackground( DARKPURPLE );
    DrawText( "Level 1", 380, 270, 60, WHITE );
    EndDrawing();
}