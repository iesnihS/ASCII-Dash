#include "Object.h"

Object::Object()
{
	Init();
}

Object::~Object()
{
	delete _objectSprite;
}

CHAR_INFO* Object::GetObjectSprite()
{
	return _objectSprite;
}

void Object::Init()
{
	_sizeSprite.X = 20;
	_sizeSprite.Y = 20;
	_objectSprite = new CHAR_INFO[_sizeSprite.X * _sizeSprite.X];
	for(int i = 0; i < _sizeSprite.X; i ++)
	{
		for(int j=0; j< _sizeSprite.Y; j++)
		{
			_objectSprite[i + (j * (_sizeSprite.X - 1))].Char.AsciiChar = '\0';
		}
	}
	_objectSprite[0].Char.AsciiChar = 'H';
}
