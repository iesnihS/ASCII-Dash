#pragma once
#include <Windows.h>
#include <vector>
#include <string>
class Object
{
	public:
		Object();
		Object(COORD levelPosition, std::string asciiArt, COORD sizeSprite);
		~Object();
		CHAR_INFO** GetObjectSprite();
		COORD _sizeSprite = {0,0};
		COORD _levelPosition = { 0,0 };
	protected:
		void Init();
		CHAR_INFO** _objectSprite = nullptr;
		std::string _ASCIIArt = ""; //the ASCII ART need to respect the size of its object
		void ConvertASCIIArtToSpriteData();
};

