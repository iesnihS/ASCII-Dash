#pragma once

#include "Player.hpp"

enum EntityType {
	SpikeEntity,
	BlockEntity,
	Empty
} typedef ENTITY_TYPE;

class LevelManager
{

	LevelManager(COORD size, Player &player, EntityType *spriteArray);

	void Update();
	void handleJump();
	void Win();
	void Lose();

	Player& _player;
	ENTITY_TYPE** _entityMap;
	char **_mapBuffer;
	EntityType* _spriteArray;
	COORD _size;
	int _progress;
};

