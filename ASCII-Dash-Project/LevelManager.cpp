#include "LevelManager.hpp"
#include "Bloc.h"
#include "Spike.h"
#include <iostream>

LevelManager::LevelManager(Player & player, ConsoleBuffer &console)
	: _player(player), _spriteArray(), _console(console), _size({ 50, 50 }), _mapBuffer({ 50 * 20, std::vector<CHAR_INFO>{50 * 20} })
{
	_entityMap = {{SpikeEntity}};
}

LevelManager::~LevelManager()
{
}

void LevelManager::Update()
{
	_console.DrawScreen(_mapBuffer);
}

void LevelManager::Win() {

}

void LevelManager::Lose() {

}


void LevelManager::handleJump()
{
	_player.Jump();
}
