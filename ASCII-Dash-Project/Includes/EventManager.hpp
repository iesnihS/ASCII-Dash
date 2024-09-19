#pragma once
#include "Player.hpp"

class EventManager
{
public:
	EventManager(const Player& player);
	void handleJump() const;

private:
	const Player& _player;
};

