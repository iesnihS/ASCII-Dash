#pragma once

#include <Object.hpp>

class Player : public Object
{
public:
	Player();
	Player(const Player &) = default;
	Player(Player &&) = default;
	void Jump();
	void Update();
private:
	COORD _position;
	COORD _velocity;
	bool _isGrounded;
};

