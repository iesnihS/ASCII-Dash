#pragma once

#include "Player.hpp"
#include "ConsoleBuffer.hpp"

enum EntityType {
	SpikeEntity,
	BlockEntity,
	NumberOfEntities
} typedef ENTITY_TYPE;

class LevelManager
{
public:
	LevelManager(Player &player, ConsoleBuffer &console);
	~LevelManager();

	void Update();
	void handleJump();
	void Win();
	void Lose();

private:
	Player& _player;
	std::vector<std::vector<ENTITY_TYPE>> _entityMap;
	std::vector<std::vector<CHAR_INFO>> _mapBuffer;
	std::vector<Object> _spriteArray;
	COORD _size;
	int _progress = 0;
	ConsoleBuffer& _console;
};

