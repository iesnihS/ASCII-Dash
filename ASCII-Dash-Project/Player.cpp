#include "Player.hpp"
#include <iostream>


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
