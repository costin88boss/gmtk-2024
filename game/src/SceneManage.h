#pragma once

#include <vector>
#include <raylib.h>
#include "Button.h"

enum Scene { TITLE_SCREEN, LEVEL1, LEVEL2, LEVEL3, END_SCREEN };

class SceneManage
{
public:
    static void ChangeScene( Scene scene );
    static void Update();
    static Scene m_currentScene;
private:
};

void TitleScreen();
void Level1();
void Level2();
void Level3();
void EndScreen();