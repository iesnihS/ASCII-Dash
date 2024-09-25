#pragma once
#include <Windows.h>
#include <vector>
#include "Object.hpp"
#define GAME_WIDTH 1000
#define GAME_HEIGHT 1000

class ConsoleBuffer
{
public:
	ConsoleBuffer();
	void Blit();
	void Clear();
	void DrawChar(COORD, CHAR_INFO);
	void DrawSpriteAtCoord(COORD,Object&);
	void DrawSprite(Object&);
	void DrawScreen(std::vector<std::vector<CHAR_INFO>> screen);
	//void DrawLevelAtIndex(Level, int);
private:
	void InitBuffer();
	HANDLE _consoleOutput;
	COORD _bufferSize;
	COORD _bufferCoord;
	SMALL_RECT _writingRegion;
	CHAR_INFO _bufferInfo[GAME_WIDTH][GAME_HEIGHT] = {};
};