#pragma once

#include <Object.hpp>
#include "ConsoleBuffer.hpp"

class Player : public Object
{
public:
	Player();
	void Jump() const;
	void DisplayPlayer(ConsoleBuffer&);
	void MovePlayer(float deltaTime);
private:
	COORD position;
	float const SPEED_FALL = 0.3f;
	float _timeSinceFell = 0;
};

