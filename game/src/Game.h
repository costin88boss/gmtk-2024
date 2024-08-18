#pragma once

#include <assert.h>
#include <string>
#include "raylib.h"

class Game
{
public:
    std::string title;
    size_t width, height;

    Game( const size_t width, const size_t height, const std::string& title );
    ~Game();

    bool IsRunning() const;
};