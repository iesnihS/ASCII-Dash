#pragma once
#include <Windows.h>
#include <vector>
class Object
{
	public:
		Object();
		~Object();
		CHAR_INFO* GetObjectSprite();
		COORD _sizeSprite;
	private:
		void Init();
		CHAR_INFO* _objectSprite = {};
		
};

