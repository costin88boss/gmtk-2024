#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "SceneManage.h"

int main()
{
    SetTraceLogLevel(0); // ALL logs - may be removed at release

    Game game( 960, 600, "Game" );

    while ( game.IsRunning() )
    {
        SceneManage::Update();
    }
}