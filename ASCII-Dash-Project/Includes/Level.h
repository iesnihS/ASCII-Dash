#pragma once
#include <Windows.h>
#include <queue>
#include "Spike.h"
#include "ConsoleBuffer.hpp"

#define MINCOORD COORD({ 0,0 })
#define MAXCOORD COORD({120,30})
class Level
{
public:
	Level(std::deque<Object>);
	void UpdateLevel(float);
	void DisplaySprite(ConsoleBuffer&);

private:
	double const SPAWN_RATE = 8; //in seconds
	double const LEVEL_SPEED = 0.25;//in seconds
	float const LEVEL_DIFFICULTY_GROW = 0.000000005f;
	float _difficulty = 0;
	float _lastTimeDecaled = 0;
	float _lastTimeSpawned = 0;
	std::deque<Object> _allObjects;
	
};

