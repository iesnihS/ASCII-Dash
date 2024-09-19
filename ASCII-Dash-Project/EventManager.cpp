#include "EventManager.hpp"
#include <iostream>

EventManager::EventManager(const Player& player) : _player(player)
{
}

void EventManager::handleJump() const
{
	_player.Jump();
}
