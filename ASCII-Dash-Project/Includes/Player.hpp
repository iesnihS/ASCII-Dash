#pragma once

#include <Object.hpp>

class Player : public Object
{
public:
	Player();
	void Jump();
	void Update();
private:
	COORD _position;
	COORD _velocity;
	bool _isGrounded;
};

