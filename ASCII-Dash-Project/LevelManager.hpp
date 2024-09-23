#pragma once

#include "Player.hpp"

enum EntityType {
	Spike,
	Block,
	Empty
} typedef ENTITY_TYPE;

class LevelManager
{

	LevelManager(COORD size);

	void update();

	const Player& player;
	ENTITY_TYPE **entityMap;
	char **mapBuffer;
	COORD size;
};

