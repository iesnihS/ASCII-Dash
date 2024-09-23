#pragma once
#include <Windows.h>
#include "EventType.hpp"
#include "LevelManager.hpp"

class InputManager {
public:
	InputManager(const LevelManager &eventManager);
	~InputManager();

	void PollEvent();

private:
	HANDLE _handle;
	DWORD _oldInputMode;
	INPUT_RECORD _record[128];
	const LevelManager& _levelManager;
};

