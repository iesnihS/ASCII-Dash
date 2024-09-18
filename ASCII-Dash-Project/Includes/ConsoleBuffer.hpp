#pragma once
#include <Windows.h>
#include <vector>
#include "Object.h"
#define GAME_WIDTH 50
#define GAME_HEIGHT 50

class ConsoleBuffer
{
public:
	ConsoleBuffer();
	void Blit();
	void DrawChar(COORD, CHAR_INFO);
	void DrawSprite(COORD, Object*);
private:
	void InitBuffer();
	HANDLE _consoleOutput;
	COORD _bufferSize;
	COORD _bufferCoord;
	SMALL_RECT _writingRegion;
	CHAR_INFO _bufferInfo[GAME_WIDTH * GAME_HEIGHT] = {};
};