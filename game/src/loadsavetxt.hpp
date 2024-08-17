#pragma once

#include <fstream>
#include <string>

std::string LoadStringFromFile( const std::string& filePath );
void SaveStringToFile( const std::string& string, const std::string& filePath );
Text LoadTextDataFromFile( const std::string& filePath );
Text LoadTextDataFromString( const std::string& string );
std::string ParseStringForTag( const std::string& string, const std::string& tag );

std::string LoadStringFromFile( const std::string& filePath )
{
    std::ifstream file( filePath );
    std::string string;
    while ( getline( file, string ) ) {}

    file.close();
    
    return string;
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

    std::string textStr = ParseStringForTag( string, "text" );
    std::string posXStr = ParseStringForTag( string, "posX" );
    std::string posYStr = ParseStringForTag( string, "posY" );
    std::string sizeStr = ParseStringForTag( string, "size" );
    std::string colorRStr = ParseStringForTag( string, "colorR" );
    std::string colorGStr = ParseStringForTag( string, "colorG" );
    std::string colorBStr = ParseStringForTag( string, "colorB" );
    std::string colorAStr = ParseStringForTag( string, "colorA" );

    outText = textStr;

    outPos.x = std::stof( posXStr );
    outPos.y = std::stof( posYStr );

    outSize = std::stoi( sizeStr );

    outColor.r = std::stoi( colorRStr );
    outColor.g = std::stoi( colorGStr );
    outColor.b = std::stoi( colorBStr );
    outColor.a = std::stoi( colorAStr );

    Text out( outPos, outText, outSize, outColor );

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