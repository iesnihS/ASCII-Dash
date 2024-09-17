#pragma once
#include <Windows.h>
#include <vector>
class Object
{
	public: 
		Object();
		std::vector<std::vector<CHAR_INFO>> GetObjectSprite();
	private:
		std::vector<std::vector<CHAR_INFO>> _objectSprite = {};
		unsigned int _uspriteSize; //width and height size
};

