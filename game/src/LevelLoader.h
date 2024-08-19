#pragma once


class LevelLoader
{
public:
	// WARNING: levels should be done in .bmp because usage of ms paint will be expected, which is shitty enough to save BMPs as .png wrongly
	static void LoadLvlAndSetGrid(const char* fileName);
	// Bad design mistake with the Grid being static lol
};

