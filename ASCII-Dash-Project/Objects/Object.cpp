#include "CustomTool.h"
#include <iostream>
#include "Object.hpp"

Object::Object(COORD coord = {0,0}, std::string ascii = "", COORD size={0,0}, int color = 0x0001) : _ASCIIArt(ascii), _sizeSprite(size) , _currentColor(color)
{
	_coordObject = coord;
	Init();
}

std::vector<std::vector<CHAR_INFO>> Object::GetObjectSprite()
{
	return _objectSprite;
}

COORD Object::GetSpriteCoord()
{
	return _coordObject;
}

void Object::Init()
{
	_sizeSprite.Y = floor(_ASCIIArt.size() / (double)_sizeSprite.X);
	_objectSprite = std::vector<std::vector<CHAR_INFO>>(_sizeSprite.Y);

	for (int i = 0; i < _sizeSprite.Y; i++)
	{
		_objectSprite[i] = std::vector<CHAR_INFO>(_sizeSprite.X);
		for (int j = 0; j < _sizeSprite.X; j++)
		{
			_objectSprite[i][j].Char.AsciiChar = '\1';
		}
	}
	ConvertASCIIArtToSpriteData();
}

void Object::ConvertASCIIArtToSpriteData()
{
	for (int i = 0; i < _sizeSprite.Y; i++)
	{
		for (int j = 0; j < _sizeSprite.X; j++)
		{
			_objectSprite[i][j].Char.AsciiChar = _ASCIIArt[Convert2DArrayCoordTo1DArrayCoord(j,i, _sizeSprite.X)];
			_objectSprite[i][j].Attributes = _currentColor;
		}
	}
}

void Object::SetSpriteCoord(COORD newCoord)
{
	_coordObject.X = newCoord.X;
	_coordObject.Y = newCoord.Y;
}
