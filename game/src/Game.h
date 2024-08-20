#pragma once

#include <assert.h>
#include <string>
#include <unordered_map>
#include "raylib.h"

class Game
{
public:
    std::string title;
    size_t width, height;
    static std::unordered_map<std::string, Texture2D> sprites;
    static Sound music;

    Game( const size_t width, const size_t height, const std::string& title );
    ~Game();

    bool IsRunning() const;
};