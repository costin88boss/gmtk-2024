#pragma once

#include <iostream>
#include "raylib.h"
#include "UI.h"
#include "LoadSaveTXT.h"
#include "Renderer.h"

enum Scene { TitleScreen };

class SceneManage
{
public:
    static void UpdateScene();
};