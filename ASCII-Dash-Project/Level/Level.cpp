#include "Level.h"
#include <iostream>
#include <string>
#include <cstdlib>

Level::Level(std::deque<Object> allObject)
{
	_allObjects = allObject;
}
void Level::UpdateLevel(float deltaTime)
{
	_lastTimeDecaled += deltaTime;
	_lastTimeSpawned += deltaTime;
	if(_lastTimeDecaled >= LEVEL_SPEED)
	{
		_lastTimeDecaled = 0;
		for (int i = 0; i < _allObjects.size(); i++)
		{
			Object &obj = _allObjects[i];
			COORD objCoord = obj.GetSpriteCoord();
			if (objCoord.X < (MINCOORD.X-obj._sizeSprite.X))
			{
				_allObjects.pop_front();
			}
			SHORT newXCoord = objCoord.X - 1;
			obj.SetSpriteCoord({ newXCoord, objCoord.Y });
		}
	}

	if(_lastTimeSpawned >= SPAWN_RATE)
	{
		_lastTimeSpawned = 0;

		int randomIndex = std::rand() % 2;
		Spike spike({0,0});
		spike.SetSpriteCoord({ MAXCOORD.X, (short) (randomIndex == 0 ? 0 : MAXCOORD.Y - spike._sizeSprite.Y)});
		_allObjects.push_back(spike);

	}
}

void Level::DisplaySprite(ConsoleBuffer &buffer)
{
	for(int i = 0; i < _allObjects.size(); i++)
	{
		buffer.DrawSprite(_allObjects[i]);
	}
}