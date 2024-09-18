#pragma once
#include <Windows.h>
#include "EventType.hpp"
#include "EventManager.hpp"

class InputManager {
public:
	InputManager();
	~InputManager();

	void PollEvent();

private:
	HANDLE _handle;
	DWORD _oldInputMode;
	PINPUT_RECORD _record;
	EventManager _eventManager;
};

