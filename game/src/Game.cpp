#include "Game.h"

std::unordered_map<std::string, Texture2D> Game::sprites;
Sound Game::music;
std::unordered_map<std::string, Sound> Game::sfx;

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
    Game::sprites["Box2"] = LoadTexture( "resources/sprites/Box2.png" );
    Game::sprites["Box3"] = LoadTexture( "resources/sprites/Box3.png" );
    Game::sprites["Player1"] = LoadTexture( "resources/sprites/Player1.png" );
    Game::sprites["Player2"] = LoadTexture( "resources/sprites/Player2.png" );
    Game::sprites["Player3"] = LoadTexture( "resources/sprites/Player3.png" );
    Game::sprites["Gate1O"] = LoadTexture( "resources/sprites/Gate1-Open.png" );
    Game::sprites["Gate1C"] = LoadTexture( "resources/sprites/Gate1-Closed.png" );
    Game::sprites["Gate2O"] = LoadTexture( "resources/sprites/Gate2-Open.png" );
    Game::sprites["Gate2C"] = LoadTexture( "resources/sprites/Gate2-Closed.png" );
    Game::sprites["Gate3O"] = LoadTexture( "resources/sprites/Gate3-Open.png" );
    Game::sprites["Gate3C"] = LoadTexture( "resources/sprites/Gate3-Closed.png" );
    Game::sprites["Plate1"] = LoadTexture( "resources/sprites/Plate1.png" );
    Game::sprites["Plate2"] = LoadTexture( "resources/sprites/Plate2.png" );
    Game::sprites["Plate3"] = LoadTexture( "resources/sprites/Plate3.png" );

    Game::sfx["Move"] = LoadSound( "resources/sfx/move.wav" );

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