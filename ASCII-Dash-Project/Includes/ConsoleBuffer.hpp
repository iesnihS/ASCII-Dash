#pragma once
#include <Windows.h>
#include <vector>
#include "Object.hpp"
#define GAME_WIDTH 10
#define GAME_HEIGHT 50

class ConsoleBuffer
{
public:
	ConsoleBuffer();
	void Blit();
	void DrawChar(COORD, CHAR_INFO);
	void DrawSpriteAtCoord(COORD,Object&);
	void DrawSprite(Object&);
	void DrawScreen(std::vector<std::vector<CHAR_INFO>> screen);
	//void DrawLevelAtIndex(Level, int);
	void ClearConsoleBuffer();
private:
	void InitBuffer();
	HANDLE _consoleOutput;
	COORD _bufferSize;
	COORD _bufferCoord;
	SMALL_RECT _writingRegion;
	CHAR_INFO _bufferInfo[GAME_WIDTH * 20][GAME_HEIGHT * 20] = {};
};