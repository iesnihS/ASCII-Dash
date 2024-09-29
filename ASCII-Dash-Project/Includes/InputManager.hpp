#pragma once
#include <Windows.h>
#include "EventType.hpp"
#include "EventManager.hpp"

class InputManager {
public:
	InputManager(const EventManager &eventManager);
	~InputManager();

	bool PollEvent();

private:
	HANDLE _handle;
	DWORD _oldInputMode;
	INPUT_RECORD _record[128];
	const EventManager& _eventManager;
};

