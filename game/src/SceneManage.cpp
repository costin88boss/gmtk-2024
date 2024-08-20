#include "SceneManage.h"
#include "Level.h"

Scene SceneManage::m_currentScene = TITLE_SCREEN;

// Title Screen Variables
Button playButton( { 480, 240 },
                   { 400, 50 },
                   Color { 0, 0, 0, 160 },
                   "Start",
                   [](){ SceneManage::ChangeScene( GAMEPLAY ); } );
// Gameplay Variables
const Color BG_COLOR = (Color){ 57, 75, 88, 255 };

// Level 1 Variables
Player lv1_player( 2, 2, 1, 0 );
Box lv1_box1( 7, 3, 1 );

std::vector<Object*> level1Objects = 
{ 
    &lv1_player,
    &lv1_box1 
};

Level level1( 16, 8, level1Objects );

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
    if ( !IsSoundPlaying( Game::music ) )
    {
        PlaySound( Game::music );
    }
}

void TitleScreen()
{
    BeginDrawing();
    ClearBackground( BG_COLOR );
    DrawRectangleV( { 230, 0 }, { 500, 600 }, Color { 0, 0, 0, 120 } );
    DrawText( "RESCALE", 285, 60, 80, WHITE );
    playButton.CheckForInput();
    playButton.Draw();
    EndDrawing();
}

void Gameplay()
{
    BeginDrawing();
    ClearBackground( BG_COLOR );
    level1.Update();
    EndDrawing();
}