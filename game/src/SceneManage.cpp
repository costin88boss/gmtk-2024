#include "SceneManage.h"
#include "Level.h"

Scene SceneManage::m_currentScene = TITLE_SCREEN;

// Title Screen Variables
Button playButton( { 480, 240 },
                   { 400, 50 },
                   Color { 0, 0, 0, 160 },
                   "Start",
                   [](){ SceneManage::ChangeScene( LEVEL1 ); } );
// Gameplay Variables
const Color BG_COLOR = (Color){ 57, 75, 88, 255 };

// Level 1 Variables
End lv1_end( 12, 3, 2 );
Player lv1_player( 2, 2, 2, 0 );
Box lv1_box1( 10, 3, 2 );
Box lv1_box2( 4, 3, 1 );
Gate lv1_gate( 6, 3, 1);
Plate lv1_plate( 8, 3, 2, &lv1_gate );
Wall lv1_wall1( 6, 1 );
Wall lv1_wall2( 6, 2 );

std::vector<Object*> lv1Objects = 
{ 
    &lv1_end,
    &lv1_plate,
    &lv1_gate,
    &lv1_wall1,
    &lv1_wall2,
    &lv1_box1,
    &lv1_box2,
    &lv1_player
};

// Level 2 Variables

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
            BeginDrawing();
            ClearBackground( BG_COLOR );
            TitleScreen();
            EndDrawing();
            break;
        case LEVEL1:
            BeginDrawing();
            ClearBackground( BG_COLOR );
            Level1();
            EndDrawing();
            break;
        case LEVEL2:
            BeginDrawing();
            ClearBackground( BG_COLOR );
            Level2();
            EndDrawing();
            break;
        case LEVEL3:
            BeginDrawing();
            ClearBackground( BG_COLOR );
            Level3();
            EndDrawing();
            break;
    }
    if ( !IsSoundPlaying( Game::music ) )
    {
        PlaySound( Game::music );
    }
}

void TitleScreen()
{
    DrawRectangleV( { 230, 0 }, { 500, 600 }, Color { 0, 0, 0, 120 } );
    DrawText( "RESCALE", 285, 60, 80, WHITE );
    playButton.CheckForInput();
    playButton.Draw();
}

void Level1()
{
    level1.Update();
}

void Level2()
{

}

void Level3()
{
    
}