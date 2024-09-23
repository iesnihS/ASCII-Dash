#include "Level.h"

Level::Level(Object * objects, int nbObjects)
{
	_levelBuffer = objects;
	_numberOfObjects = nbObjects;
}
Level::Level()
{
	_levelBuffer = nullptr;
	_numberOfObjects = 0;
}

Object * Level::GetObjectInConsoleCoord()
{
	return _levelBuffer;
}

int Level::GetNumberOfObjects()
{
	return _numberOfObjects;
}