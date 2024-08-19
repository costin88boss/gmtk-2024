#include "Game.h"

Game::Game( const size_t width, const size_t height, const std::string& title )
{
    assert( !GetWindowHandle() );

    this->width = width;
    this->height = height;
    this->title = title;

    SetConfigFlags( FLAG_VSYNC_HINT );
    InitWindow(static_cast<int>(width), static_cast<int>(height), title.c_str() );
    InitAudioDevice();
}

Game::~Game()
{
    assert( GetWindowHandle() );
    
    CloseAudioDevice();
    CloseWindow();
}

bool Game::IsRunning() const
{ return !WindowShouldClose(); }