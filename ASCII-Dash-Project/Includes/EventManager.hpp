#pragma once
#include "Player.hpp"

class EventManager
{
public:
	void handleJump();

private:
	Player& player;
};

