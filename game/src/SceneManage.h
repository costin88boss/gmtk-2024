#pragma once

#include <vector>
#include <raylib.h>
#include "Button.h"

enum Scene { TITLE_SCREEN, GAMEPLAY };

class SceneManage
{
public:
    static void ChangeScene( Scene scene );
    static void Update();
private:
    static Scene m_currentScene;
};

void TitleScreen();
void Gameplay();