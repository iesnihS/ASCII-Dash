#include "Player.hpp"
#include <iostream>
#include <math.h>
#include "Level.h"

Player::Player():Object({ 1,0 },
	"5777!!77!5"
	"5~? J!!J ? ~Y"
	"57J ? ? ? ? J7Y"
	"57 ? 7777 ? 75"
	"PJJJ ? ? JJJP",
	{ 12,0 }, 0x0002, false)
{
}

void Player::DisplayPlayer(ConsoleBuffer &buffer)
{
	buffer.DrawSprite(*this);
}

void Player::Jump() const
{
	Player* ptrPlayer = const_cast<Player*>(this);
	ptrPlayer->_coordObject.Y -= 1;
	ptrPlayer->_coordObject.Y = max(1, _coordObject.Y);
}

void Player::MovePlayer(float deltaTime)
{
	_timeSinceFell += deltaTime;
	if (_timeSinceFell < SPEED_FALL)
		return;

	_timeSinceFell = 0;
	_coordObject.Y += 1;
	_coordObject.Y = min(MAXCOORD.Y - _sizeSprite.Y - 1, _coordObject.Y);
}
