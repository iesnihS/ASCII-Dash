#include "ConsoleBuffer.hpp"
#include <iostream>

ConsoleBuffer::ConsoleBuffer()
{
	InitBuffer();
}

void ConsoleBuffer::InitBuffer()
{
	_consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	_bufferCoord = { 0,0 };
	_bufferSize = { GAME_WIDTH, GAME_HEIGHT };
	_writingRegion = { 0,0,GAME_WIDTH-1,GAME_HEIGHT-1 };
	ReadConsoleOutput(_consoleOutput, _bufferInfo, _bufferSize,
		_bufferCoord, &_writingRegion);
}

void ConsoleBuffer::DrawChar(COORD charCoord, CHAR_INFO charInfo)
{
	if (charInfo.Char.AsciiChar == '\0') 
		return;

	_bufferInfo[charCoord.X + (charCoord.Y*(GAME_WIDTH- 1))].Char.AsciiChar = charInfo.Char.AsciiChar;
	_bufferInfo[charCoord.X+ (charCoord.Y * (GAME_WIDTH - 1))].Attributes = charInfo.Attributes;
}

void ConsoleBuffer::DrawSprite(COORD spriteCoord, Object* object)
{
	for(int i = 0;i<object->_sizeSprite.X * object->_sizeSprite.Y; i++)
	{

	}
}

void ConsoleBuffer::Blit()
{
	WriteConsoleOutput(_consoleOutput, _bufferInfo, _bufferSize,
		_bufferCoord, &_writingRegion);
}