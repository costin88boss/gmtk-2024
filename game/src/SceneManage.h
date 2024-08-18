#pragma once

#include <stddef.h>
#include <vector>
#include <raylib.h>

enum Scene { TITLE_SCREEN, LEVEL1 };

class SceneManage
{
public:
    static void GoToNextScene();
    static void Update();
private:
    static Scene m_currentScene;
};

void TitleScreen();
void Level1();