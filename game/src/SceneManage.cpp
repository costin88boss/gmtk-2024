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
#pragma region lvl1
// Level 1 Variables
End lv1_end( 12, 3, 1 );
Player lv1_player( 1, 2, 1, 0 );
Box lv1_box( 3, 3, 1 );
Gate lv1_gate( 8, 3, 1);
Plate lv1_plate( 5, 4, 1, &lv1_gate );
Wall lv1_wall1( 8, 1 );
Wall lv1_wall2( 8, 2 );
Wall lv1_wall3( 8, 4 );
Wall lv1_wall4( 8, 5 );
Wall lv1_wall5( 8, 6 );

std::vector<Object*> lv1Objects = 
{ 
    &lv1_end,
    &lv1_plate,
    &lv1_gate,
    &lv1_wall1,
    &lv1_wall2,
    &lv1_wall3,
    &lv1_wall4,
    &lv1_wall5,
    &lv1_box,
    &lv1_player
};

Level level1( 16, 8, lv1Objects );
#pragma endregion
#pragma region lvl2

// Level 2 Variables
End lv2_end( 9, 8, 2 );
Player lv2_player( 1, 1, 1, 1 );
Box lv2_box( 4, 2, 2 );
Gate lv2_gate( 9, 6, 1);
Plate lv2_plate( 7, 2, 2, &lv2_gate );
Wall lv2_wall1( 1, 6 );
Wall lv2_wall2( 2, 6 );
Wall lv2_wall3( 3, 6 );
Wall lv2_wall4( 4, 6 );
Wall lv2_wall5( 5, 6 );
Wall lv2_wall6( 6, 6 );
Wall lv2_wall7( 7, 6 );
Wall lv2_wall8( 8, 6 );
//Wall lv2_wall9( 9, 5 );
//Wall lv2_wall10( 10, 5 );
Wall lv2_wall11( 11, 6 );
Wall lv2_wall12( 12, 6 );

std::vector<Object*> lv2Objects = 
{ 
    &lv2_end,
    &lv2_plate,
    &lv2_gate,
    &lv2_wall1,
    &lv2_wall2,
    &lv2_wall3,
    &lv2_wall4,
    &lv2_wall5,
    &lv2_wall6,
    &lv2_wall7,
    &lv2_wall8,
    //&lv2_wall9,
    //&lv2_wall10,
    &lv2_wall11,
    &lv2_wall12,
    &lv2_box,
    &lv2_player
};

Level level2( 14, 12, lv2Objects );
#pragma endregion
#pragma region lvl3



// Level 3 Variables
End lv3_end( 15, 7, 2 );
Gate lv3_gate1( 8, 2, 1);
Gate lv3_gate2( 8, 3, 1);
Gate lv3_gate3( 14, 5, 1 );
Plate lv3_plate1( 6, 1, 1, &lv3_gate1);
Plate lv3_plate2( 6, 4, 1, &lv3_gate2);
Plate lv3_plate3( 14, 1, 2, &lv3_gate3);
Box lv3_box1( 4, 1, 1 );
Box lv3_box2( 4, 4, 1 );
Box lv3_box3( 12, 1, 2 );
Wall lv3_wall1( 1, 5 );
Wall lv3_wall2( 2, 5 );
Wall lv3_wall3( 3, 5 );
Wall lv3_wall4( 4, 5 );
Wall lv3_wall5( 5, 5 );
Wall lv3_wall6( 6, 5 );
Wall lv3_wall7( 7, 5 );
Wall lv3_wall8( 8, 5 );
Wall lv3_wall9( 9, 5 );
Wall lv3_wall10( 10, 5 );
Wall lv3_wall11( 11, 5 );
Wall lv3_wall12( 12, 5 );
Wall lv3_wall13( 13, 5 );
Wall lv3_wall14( 15, 5 );
Wall lv3_wall15( 16, 5 );
Wall lv3_wall16( 8, 1 );
Wall lv3_wall17( 8, 4 );
Player lv3_player( 1, 1, 2, 2 );

std::vector<Object*> lv3Objects = 
{ 
    &lv3_end,
    &lv3_gate1,
    &lv3_gate2,
    &lv3_gate3,
    &lv3_plate1,
    &lv3_plate2,
    &lv3_plate3,
    &lv3_box1,
    &lv3_box2,
    &lv3_box3,
    &lv3_wall1,
    &lv3_wall2,
    &lv3_wall3,
    &lv3_wall4,
    &lv3_wall5,
    &lv3_wall6,
    &lv3_wall7,
    &lv3_wall8,
    &lv3_wall9,
    &lv3_wall10,
    &lv3_wall11,
    &lv3_wall12,
    &lv3_wall13,
    &lv3_wall14,
    &lv3_wall15,
    &lv3_wall16,
    &lv3_wall17,
    &lv3_player
};

Level level3( 18, 10, lv3Objects );
#pragma endregion


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
        case END_SCREEN:
            BeginDrawing();
            ClearBackground( BG_COLOR );
            EndScreen();
            EndDrawing();
            break;
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
    level2.Update();
}

void Level3()
{
    level3.Update();
}

void EndScreen()
{
    DrawRectangleV( { 230, 0 }, { 500, 600 }, Color { 0, 0, 0, 120 } );
    DrawText( "Thank you for playing!", 150, 120, 60, WHITE );
    DrawText( "Made By Pixels & Costin", 285, 240, 30, WHITE );
}