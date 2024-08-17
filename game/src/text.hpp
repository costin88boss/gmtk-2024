#pragma once

#include "raylib.h"
#include <string>

class Text
{
public:
    std::string text;
    Vector2 position;
    u_int size;
    Color color;

    Text( Vector2 position, std::string text, u_int size, Color color );
    std::string GetData();
    static Text LoadData( std::string& data );
};

Text::Text( Vector2 position, std::string text, u_int size, Color color )
    :
    position( position ),
    text( text ),
    size( size ),
    color( color )
{}

std::string Text::GetData()
{
    std::string textData;

    textData.append( "text:" );
    textData.append( text );
    textData.append( "\n" );
    textData.append( "posX:" );
    textData.append( std::to_string( position.x ) );
    textData.append( "\n" );
    textData.append( "posY:" );
    textData.append( std::to_string( position.y ) );
    textData.append( "\n" );
    textData.append( "size:" );
    textData.append( std::to_string( size ) );
    textData.append( "\n" );
    textData.append( "colorR:" );
    textData.append( std::to_string( color.r ) );
    textData.append( "\n" );
    textData.append( "colorG:" );
    textData.append( std::to_string( color.r ) );
    textData.append( "\n" );
    textData.append( "colorB:" );
    textData.append( std::to_string( color.r ) );
    textData.append( "\n" );
    textData.append( "colorA:" );
    textData.append( std::to_string( color.r ) );
    textData.append( "\n" );

    return textData;
}