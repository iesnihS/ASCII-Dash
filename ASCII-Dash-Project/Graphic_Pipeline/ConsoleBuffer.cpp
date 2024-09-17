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
	ReadConsoleOutput(_consoleOutput, (CHAR_INFO*)_bufferInfo, _bufferSize,
		_bufferCoord, &_writingRegion);

	std::cout << "Le char 0,0 est : " << (_bufferInfo[0][0].Char.AsciiChar == 0) << std::endl;
}

void ConsoleBuffer::DrawChar(COORD charCoord, CHAR_INFO charInfo)
{
	_bufferInfo[charCoord.X][charCoord.Y].Char.AsciiChar = charInfo.Char.AsciiChar;
	_bufferInfo[charCoord.X][charCoord.Y].Attributes = charInfo.Attributes;
}

void ConsoleBuffer::Blit()
{
	WriteConsoleOutput(_consoleOutput, (CHAR_INFO*)_bufferInfo, _bufferSize,
		_bufferCoord, &_writingRegion);
}