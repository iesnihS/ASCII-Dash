#include "CustomTool.h"
#include <iostream>
#include "Object.hpp"

Object::Object()
{
	Init();
}

Object::~Object()
{
	for (int i = 0; i < _sizeSprite.Y; i++)
	{
		delete _objectSprite[i];
	}
	delete _objectSprite;
}

CHAR_INFO** Object::GetObjectSprite()
{
	return _objectSprite;
}

void Object::Init()
{
	_sizeSprite.Y = floor(_ASCIIArt.size() / (double)_sizeSprite.X);

	_objectSprite = new CHAR_INFO*[_sizeSprite.Y];
	for (int i = 0; i < _sizeSprite.Y; i++)
	{
		_objectSprite[i] = new CHAR_INFO[_sizeSprite.X];
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
			_objectSprite[i][j].Attributes = 0x0001;
		}
	}
}
