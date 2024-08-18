#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "SceneManage.h"

int main()
{
    Game game( 960, 600, "Game" );

    while ( game.IsRunning() )
    {
        SceneManage::Update();
    }
}