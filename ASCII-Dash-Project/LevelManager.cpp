#include "LevelManager.hpp"

LevelManager::LevelManager(COORD size, Player & player, EntityType* spriteArray) : _player(player), _spriteArray(spriteArray)
{
	_entityMap = nullptr;
	_mapBuffer = nullptr;
}

void LevelManager::Update()
{
	_progress += 1;
	if (_progress >= _size.X) {
		Win();
	}
	_player.Update();
}

void LevelManager::Win() {

}

void LevelManager::Lose() {

}


void LevelManager::handleJump()
{
	_player.Jump();
}
