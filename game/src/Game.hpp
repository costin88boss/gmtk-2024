#pragma once

#include <assert.h>
#include <string>
#include "raylib.h"
#include "Scene.hpp"

class Game
{
public:
    std::string title;
    u_int width, height;

    Game( const u_int width, const u_int height, const std::string& title );
    ~Game();

    bool IsRunning() const;
};

Game::Game( const u_int width, const u_int height, const std::string& title )
{
    assert( !GetWindowHandle() );

    this->width = width;
    this->height = height;
    this->title = title;

    SetConfigFlags( FLAG_VSYNC_HINT );
    InitWindow( width, height, title.c_str() );
    InitAudioDevice();
    currentScene = TitleScreen;
}

Game::~Game()
{
    assert( GetWindowHandle() );
    
    CloseAudioDevice();
    CloseWindow();
}

bool Game::IsRunning() const
{ return !WindowShouldClose(); }