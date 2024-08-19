#include "LevelLoader.h"
#include "Grid.h"
#include <raylib.h>
#include <stddef.h>

#include <iostream>

static void MathFunctionToFixColorInCaseOurLevelDesignerIsAStupidFuckingIdiot(Color* color);
static unsigned char MathFunctionThatMakesTheOtherMathFunctionLessRepeatingCodeIGuess(unsigned char c);

void LevelLoader::LoadLvlAndSetGrid(const char* fileName)
{
	Image img = LoadImage(fileName);
	// RGBA bitmap

	std::vector<Tile> tiles;
	//Grid::SetGrid();

	auto p = Color(0, 0, 0);
	// Could be auto p = (Color){0,0,0,0};

	for (int x = 0; x < img.width; x++)
	{
		for (int y = 0; y < img.height; y++)
		{
			p.r = ((unsigned char*)img.data)[(y * img.width + x) * 4];
			p.g = ((unsigned char*)img.data)[(y * img.width + x) * 4 + 1];
			p.b = ((unsigned char*)img.data)[(y * img.width + x) * 4 + 2];
			p.a = ((unsigned char*)img.data)[(y * img.width + x) * 4 + 3];

			MathFunctionToFixColorInCaseOurLevelDesignerIsAStupidFuckingIdiot(&p);

			if (p.r == 0 && p.g == 0 && p.b == 0) {            // EMPTY
				//tiles.push_back(..);
			}
			else if (p.r == 255 && p.g == 255 && p.b == 255) { // WALL

			}


			else if (p.r == 255 && p.g == 0 && p.b == 0) { //    RED    - PLAYER
				
			}
			else if (p.r == 0 && p.g == 255 && p.b == 0) { //    GREEN  - CRATE

			}
			else if (p.r == 0 && p.g == 0 && p.b == 255) { //    BLUE   - PRESSURE

			}
			else if (p.r == 255 && p.g == 255 && p.b == 0) { //  ORANGE - WIN

			}
			else TraceLog(TraceLogLevel::LOG_ERROR, "Unknown tile color!!!");
		}
	}

}

static void MathFunctionToFixColorInCaseOurLevelDesignerIsAStupidFuckingIdiot(Color* color) {
	color->r = MathFunctionThatMakesTheOtherMathFunctionLessRepeatingCodeIGuess(color->r);
	color->g = MathFunctionThatMakesTheOtherMathFunctionLessRepeatingCodeIGuess(color->g);
	color->b = MathFunctionThatMakesTheOtherMathFunctionLessRepeatingCodeIGuess(color->b);
}

static unsigned char MathFunctionThatMakesTheOtherMathFunctionLessRepeatingCodeIGuess(unsigned char c) {
	if (c < 127) return 0;
	if (c >= 127) return 255;
}