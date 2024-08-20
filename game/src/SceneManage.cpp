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
Player lv1_player( 2, 2, 2, 0 );
Box lv1_box1( 10, 3, 2 );
Box lv1_box2( 4, 3, 1 );
Gate lv1_gate( 6, 3, 1);
Plate lv1_plate( 8, 3, 2, &lv1_gate );

std::vector<Object*> lv1Objects = 
{ 
    &lv1_plate,
    &lv1_gate,
    &lv1_box1,
    &lv1_box2,
    &lv1_player
};

Level level1( 16, 8, lv1Objects );

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