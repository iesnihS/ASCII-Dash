#include "InputManager.hpp"
#include <windows.h>
#include <exception>


InputManager::InputManager()
{
	_handle = GetStdHandle(STD_INPUT_HANDLE);
	if (_handle == INVALID_HANDLE_VALUE)
		throw std::exception();

	if (!GetConsoleMode(_handle, &(_oldInputMode)))
		throw std::exception();
}

InputManager::~InputManager()
{
	SetConsoleMode(_handle, _oldInputMode);
}

void InputManager::PollEvent()
{
	DWORD numread = 128;

	if (!ReadConsoleInputW(
		_handle,      // input buffer handle
		_record,     // buffer to read into
		128,         // size of read buffer
		&numread)) // number of records read
		throw std::exception();

	// Dispatch the events to the appropriate handler.

	for (int i = 0; i < numread; i++)
	{
		INPUT_RECORD event = _record[i];
		switch (event.EventType)
		{
		case KEY_EVENT: // keyboard input
			if (event.Event.KeyEvent.bKeyDown && event.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
				_eventManager.handleJump();
			break;
		case MOUSE_EVENT: // mouse input
			if (event.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				_eventManager.handleJump();
			break;

		default:
			break;
		}
	}
}
