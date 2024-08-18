#pragma once

#include <fstream>
#include <string>
#include "UI.hpp"

std::string LoadStringFromFile( const std::string& filePath );
void SaveStringToFile( const std::string& string, const std::string& filePath );

Text LoadTextDataFromFile( const std::string& filePath );
Text LoadTextDataFromString( const std::string& string );
Rect LoadRectDataFromFile( const std::string& filePath );
Rect LoadRectDataFromString( const std::string& string );
Button LoadButtonDataFromFile( const std::string& filePath );
Button LoadButtonDataFromString( const std::string& string );

std::string ParseStringForTag( const std::string& string, const std::string& tag );

std::string LoadStringFromFile( const std::string& filePath )
{
    std::ifstream file( filePath );
    std::string buffer;
    std::string out;
    while ( getline( file, buffer ) )
    {
        out += buffer;
        out += '\n';
    }

    file.close();
    
    return out;
}

void SaveStringToFile( const std::string& string, const std::string& filePath )
{
    std::ofstream file;

    file.open( filePath, std::ios_base::app);
    file << string; 

    file.close();
}

Text LoadTextDataFromFile( const std::string& filePath )
{
    std::string data = LoadStringFromFile( filePath );
    Text text = LoadTextDataFromString( data );

    return text;
}

Text LoadTextDataFromString( const std::string& string )
{
    std::string outText;
    Vector2 outPos;
    int outSize;
    Color outColor;

    outText = ParseStringForTag( string, "text" );

    outPos.x = std::stof( ParseStringForTag( string, "posX" ) );
    outPos.y = std::stof( ParseStringForTag( string, "posY" ) );

    outSize = std::stoi( ParseStringForTag( string, "size" ));

    outColor.r = std::stoi( ParseStringForTag( string, "colorR" ) );
    outColor.g = std::stoi( ParseStringForTag( string, "colorG" ) );
    outColor.b = std::stoi( ParseStringForTag( string, "colorB" ) );
    outColor.a = std::stoi( ParseStringForTag( string, "colorA" ) );

    Text out( outPos, outText, outSize, outColor );

    return out;
}

Rect LoadRectDataFromFile( const std::string& filePath )
{
    std::string data = LoadStringFromFile( filePath );
    Rect rect = LoadRectDataFromString( data );

    return rect;
}

Rect LoadRectDataFromString( const std::string& string )
{
    Vector2 outPos;
    Vector2 outSize;
    Color outColor;

    outPos.x = std::stof( ParseStringForTag( string, "posX" ) );
    outPos.y = std::stof( ParseStringForTag( string, "posY" ) );

    outSize.x = std::stof( ParseStringForTag( string, "sizeX" ) );
    outSize.y = std::stof( ParseStringForTag( string, "sizeY" ) );

    outColor.r = std::stoi( ParseStringForTag( string, "colorR" ) );
    outColor.g = std::stoi( ParseStringForTag( string, "colorG" ) );
    outColor.b = std::stoi( ParseStringForTag( string, "colorB" ) );
    outColor.a = std::stoi( ParseStringForTag( string, "colorA" ) );

    Rect out( outPos, outSize, outColor );

    return out;
}

Button LoadButtonDataFromFile( const std::string& filePath )
{
    std::string data = LoadStringFromFile( filePath );
    Button button = LoadButtonDataFromString( data );

    return button;
}

Button LoadButtonDataFromString( const std::string& string )
{
    Vector2 outPos;
    Vector2 outSize;
    Color outColor;

    std::string outText;
    Vector2 outTextPos;
    int outTextSize;
    Color outTextColor;

    outPos.x = std::stof( ParseStringForTag( string, "posX" ) );
    outPos.y = std::stof( ParseStringForTag( string, "posY" ) );

    outSize.x = std::stof( ParseStringForTag( string, "sizeX" ) );
    outSize.y = std::stof( ParseStringForTag( string, "sizeY" ) );

    outColor.r = std::stoi( ParseStringForTag( string, "colorR" ) );
    outColor.g = std::stoi( ParseStringForTag( string, "colorG" ) );
    outColor.b = std::stoi( ParseStringForTag( string, "colorB" ) );
    outColor.a = std::stoi( ParseStringForTag( string, "colorA" ) );


    outText = ParseStringForTag( string, "text" );

    outTextPos.x = std::stof( ParseStringForTag( string, "textPosX" ) );
    outTextPos.y = std::stof( ParseStringForTag( string, "textPosY" ) );

    outTextSize = std::stoi( ParseStringForTag( string, "textSize" ));

    outTextColor.r = std::stoi( ParseStringForTag( string, "textColorR" ) );
    outTextColor.g = std::stoi( ParseStringForTag( string, "textColorG" ) );
    outTextColor.b = std::stoi( ParseStringForTag( string, "textColorB" ) );
    outTextColor.a = std::stoi( ParseStringForTag( string, "textColorA" ) );

    Button out( outPos, outTextPos, outSize, outTextSize, outColor, outTextColor, outText );

    return out;
}

std::string ParseStringForTag( const std::string& string, const std::string& tag )
{
    std::string out;
    std::string buffer;

    for ( int i = 0; i < string.length(); i++ )
    {
        buffer += string.at( i );

        if ( buffer == ( tag + ":" ) )
        {
            i++;
            while ( string.at( i ) != '\n' )
            {
                out += string.at( i );
                i++;
            }

            return out;
        }
        else if ( string.at( i ) == '\n' )
        {
            buffer.clear();
        }
    }

    return "";
}