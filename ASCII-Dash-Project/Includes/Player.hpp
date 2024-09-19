#pragma once

#include <Object.hpp>

class Player : public Object
{
public:
	void Jump() const;
private:
	COORD position;
};

