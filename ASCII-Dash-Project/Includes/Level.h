#pragma once
#include <Windows.h>
#include "Object.hpp"

class Level
{
public :
	Level();
		Level(Object *objects, int nbObjects);
		Object * GetObjectInConsoleCoord();
		int GetNumberOfObjects();
	private :
		Object * _levelBuffer;
		int _numberOfObjects = 0;
		int _index = 0;
		COORD _levelSize = { 40,300 };
};

