#include "ConsoleBuffer.hpp"
#include <iostream>
#include <math.h>
#include <CustomTool.h>

ConsoleBuffer::ConsoleBuffer()
{
	InitBuffer();
	CONSOLE_FONT_INFOEX cfi = { sizeof(cfi) };
	GetCurrentConsoleFontEx(_consoleOutput, FALSE, &cfi);
	cfi.dwFontSize.Y = 6;                  // Height
	SetCurrentConsoleFontEx(_consoleOutput, FALSE, &cfi);
}

void ConsoleBuffer::InitBuffer()
{
	_consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	_bufferCoord = { 0,0 };
	_bufferSize = { GAME_WIDTH, GAME_HEIGHT };
	_writingRegion = { 0,0,GAME_WIDTH-1,GAME_HEIGHT-1 };
	
	ReadConsoleOutput(_consoleOutput, (CHAR_INFO*)_bufferInfo, _bufferSize,
		_bufferCoord, &_writingRegion);
}

void ConsoleBuffer::DrawChar(COORD charCoord, CHAR_INFO charInfo)
{
	if (charInfo.Char.AsciiChar == '\1') {
		return;
	}
	_bufferInfo[charCoord.X][charCoord.Y].Char.AsciiChar = charInfo.Char.AsciiChar;
	_bufferInfo[charCoord.X][charCoord.Y].Attributes = charInfo.Attributes;
}

//This method is using Console coordinates
void ConsoleBuffer::DrawSpriteAtCoord(COORD spriteCoord, Object &object)
{
	CHAR_INFO** dataSprite = object.GetObjectSprite();
	for(int i = 0; i < object._sizeSprite.Y; i++)
	{
		for(int j = 0; j< object._sizeSprite.X; j++)
		{
			COORD biDCoord = {i,j};
			biDCoord.X += spriteCoord.X;
			biDCoord.Y += spriteCoord.Y;
			DrawChar({ biDCoord.X , biDCoord.Y }, dataSprite[i][j]);
		}
	}
}

void ConsoleBuffer::DrawScreen(std::vector<std::vector<CHAR_INFO>> screen)
{
	for (int i = 0; i < screen.size(); i++)
	{
		for (int j = 0; j < screen[0].size(); j++)
		{
			COORD biDCoord = { i,j };
			DrawChar({ biDCoord.X , biDCoord.Y }, screen[i][j]);
		}
	}
}

//This method is using Level coordinates
void ConsoleBuffer::DrawSprite(Object &object)
{
	DrawSpriteAtCoord(object._levelPosition, object);
}

/*
void ConsoleBuffer::DrawLevelAtIndex(Level level, int index)
{
	Object* objects = level.GetObjectInConsoleCoord();
	for(int i =0; i < level.GetNumberOfObjects(); i ++)
	{
		DrawSprite(objects[i]);
	}
}*/

void ConsoleBuffer::Blit()
{
	WriteConsoleOutput(_consoleOutput,(CHAR_INFO*) _bufferInfo, _bufferSize,
		_bufferCoord, &_writingRegion);
}

void ConsoleBuffer::ClearConsoleBuffer()
{
	for(int i =0; i <GAME_HEIGHT; i++)
	{
		for(int j = 0; j< GAME_WIDTH; j++)
		{
			_bufferInfo[i][j].Char.AsciiChar = '\1';
		}
	}
}