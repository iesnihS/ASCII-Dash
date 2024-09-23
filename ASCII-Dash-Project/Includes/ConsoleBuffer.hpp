#pragma once
#include <Windows.h>
#include <vector>
#include "Object.hpp"
#include "Level.h"
#define GAME_WIDTH 300
#define GAME_HEIGHT 300

class ConsoleBuffer
{
public:
	ConsoleBuffer();
	void Blit();
	void DrawChar(COORD, CHAR_INFO);
	void DrawSpriteAtCoord(COORD,Object&);
	void DrawSprite(Object&);
	void DrawLevelAtIndex(Level, int);
private:
	void InitBuffer();
	HANDLE _consoleOutput;
	COORD _bufferSize;
	COORD _bufferCoord;
	SMALL_RECT _writingRegion;
	CHAR_INFO _bufferInfo[GAME_WIDTH][GAME_HEIGHT] = {};
};