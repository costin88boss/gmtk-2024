#pragma once

#include <fstream>
#include <string>
#include "UI.h"

std::string LoadStringFromFile( const std::string& filePath );
void SaveStringToFile( const std::string& string, const std::string& filePath );

Text LoadTextData( const std::string& filePath );
Text ReadTextData( const std::string& string );
Rect LoadRectData( const std::string& filePath );
Rect ReadRectData( const std::string& string );
Button LoadButtonData( const std::string& filePath );
Button ReadButtonData( const std::string& string );

std::string ParseStringForTag( const std::string& string, const std::string& tag );