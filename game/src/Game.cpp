#include "Game.h"

std::unordered_map<std::string, Texture2D> Game::sprites;
Sound Game::music;

Game::Game( const size_t width, const size_t height, const std::string& title )
{
    assert( !GetWindowHandle() );

    this->width = width;
    this->height = height;
    this->title = title;

    SetConfigFlags( FLAG_VSYNC_HINT );
    InitWindow(static_cast<int>(width), static_cast<int>(height), title.c_str() );
    InitAudioDevice();

    Game::sprites.clear();
    Game::sprites["Tile"] = LoadTexture( "resources/sprites/Tile.png" );
    Game::sprites["Wall"] = LoadTexture( "resources/sprites/Wall.png" );
    Game::sprites["Box1"] = LoadTexture( "resources/sprites/Box1.png" );
    Game::sprites["Player1"] = LoadTexture( "resources/sprites/Player1.png" );
    Game::sprites["Player2"] = LoadTexture( "resources/sprites/Player2.png" );
    Game::sprites["Player3"] = LoadTexture( "resources/sprites/Player3.png" );

    Game::music = LoadSound( "resources/music/Rescale.wav" );
}

Game::~Game()
{
    assert( GetWindowHandle() );
    
    UnloadSound( Game::music );
    CloseAudioDevice();
    CloseWindow();
}

bool Game::IsRunning() const
{ return !WindowShouldClose(); }