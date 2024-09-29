#pragma once
#include <Windows.h>
#include <vector>
#include "Object.hpp"
#include "GameManager.h"

#define GAME_WIDTH 120
#define GAME_HEIGHT 120

class ConsoleBuffer
{
public:
	ConsoleBuffer(GameManager&);
	void Blit();
	void DrawChar(COORD, CHAR_INFO);
	void DrawSprite(COORD,Object&);
	void DrawSprite(Object& object);
	void ClearBuffer();
private:
	GameManager& _gameManager;
	void InitBuffer();
	HANDLE _consoleOutput;
	COORD _bufferSize;
	COORD _bufferCoord;
	SMALL_RECT _writingRegion;
	CHAR_INFO _bufferInfo[GAME_WIDTH][GAME_HEIGHT] = {};
};