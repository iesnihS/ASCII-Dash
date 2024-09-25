#include "Player.hpp"
#include <iostream>

Player::Player() : Object({0,0},
	"BY????????????????JB"
	"B ? ~777!^ ^!777~!B"
	"B ? 7G7 ? G ^ : PJ7P ? 7B"
	"B ? ~J ? ? ? ^ : ? ? ? J!7B"
	"BJ!? 5 ? J ? ? JJ ? ? J ? Y ? !7B"
	"BJ!JG ? JJJJJJJJ ? PY!? B"
	"BJ7777777777777777 ? B"
	"BJ7777777777777777 ? B"
	"BP5555555555555555PB",
	{ 20,0 })
{
}
void Player::Jump()
{
	if (!_isGrounded) {
		_velocity.Y = 5;
		_isGrounded = !_isGrounded;
	}
}

void Player::Update()
{
	if (_isGrounded) {
		return;
	}
	_position.X += _velocity.X;
	_position.Y += _velocity.Y;
	if (_position.Y < 0) {
		_position.Y = 0;
		_isGrounded = !_isGrounded;
	}
}
