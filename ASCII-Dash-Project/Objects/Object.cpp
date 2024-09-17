#include "Object.h"

Object::Object()
{
	//_objectSprite[0][0].Char.AsciiChar = 'D' ;
}

std::vector<std::vector<CHAR_INFO>> Object::GetObjectSprite()
{
	return _objectSprite;
}

