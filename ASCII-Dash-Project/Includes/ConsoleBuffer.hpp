#pragma once
#include <Windows.h>
#define GAME_WIDTH 50
#define GAME_HEIGHT 50

class ConsoleBuffer
{
public:
	ConsoleBuffer();
	void Blit();
	void DrawChar(COORD, CHAR_INFO);
private:
	void InitBuffer();
	HANDLE _consoleOutput;
	COORD _bufferSize;
	COORD _bufferCoord;
	SMALL_RECT _writingRegion;
	CHAR_INFO _bufferInfo[GAME_WIDTH][GAME_HEIGHT] = {};
};