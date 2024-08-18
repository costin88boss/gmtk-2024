#include <iostream>
#include "raylib.h"
#include "Game.hpp"
#include "UI.hpp"
#include "LoadSaveTXT.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"

int main()
{
    Game game( 960, 600, "Game" );

    while ( game.IsRunning() )
    {
        SceneManage::UpdateScene();
    }
}