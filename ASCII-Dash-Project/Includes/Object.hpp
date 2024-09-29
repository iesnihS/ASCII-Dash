#pragma once
#include <Windows.h>
#include <vector>
#include <string>
class Object
{
	public:
		Object() = default;
		Object(COORD, std::string, COORD, int, bool);
		std::vector<std::vector<CHAR_INFO>> GetObjectSprite();
		COORD _sizeSprite = {0,0};
		COORD GetSpriteCoord();
		void SetSpriteCoord(COORD);
	protected:
		void Init();
		std::vector<std::vector<CHAR_INFO>> _objectSprite;
		std::string _ASCIIArt = ""; //the ASCII ART need to respect the size of its object
		void ConvertASCIIArtToSpriteData();
		COORD _coordObject;
		int _currentColor = 0x0001;
		bool _reverseSprite;
};

