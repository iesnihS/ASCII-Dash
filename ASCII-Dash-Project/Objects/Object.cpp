#include "Object.h"

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
	_sizeSprite.X = 20;
	_sizeSprite.Y = 20;
	_objectSprite = new CHAR_INFO*[_sizeSprite.Y];
	for (int i = 0; i < _sizeSprite.Y; i++)
	{
		_objectSprite[i] = new CHAR_INFO[_sizeSprite.X];
		for (int j = 0; j < _sizeSprite.X; j++)
		{
			_objectSprite[i][j].Char.AsciiChar = '\0';
		}
	}
}

CHAR_INFO** Object::ConvertASCIIArtToSpriteData()
{
	return nullptr;
}
