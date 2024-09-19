#pragma once
#include <Windows.h>
#include <vector>
#include <string>
class Object
{
	public:
		Object();
		~Object();
		CHAR_INFO** GetObjectSprite();
		COORD _sizeSprite = {};
	protected:
		void Init();
		CHAR_INFO** _objectSprite = nullptr;
		std::string _ASCIIArt = "";
		CHAR_INFO** ConvertASCIIArtToSpriteData();
};

