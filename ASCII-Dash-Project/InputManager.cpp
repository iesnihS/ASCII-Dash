#include "InputManager.hpp"
#include <windows.h>
#include <exception>
#include <iostream>


InputManager::InputManager(const EventManager &eventManager) : _eventManager(eventManager)
{
	_handle = GetStdHandle(STD_INPUT_HANDLE);
	if (_handle == INVALID_HANDLE_VALUE)
		throw std::exception();

	if (!GetConsoleMode(_handle, &(_oldInputMode)))
		throw std::exception();

	// Enable the window and mouse input events.

	DWORD fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(_handle, fdwMode))
		throw std::exception();

}

InputManager::~InputManager()
{
	SetConsoleMode(_handle, _oldInputMode);
}

bool InputManager::PollEvent() //return if an event was register
{
	DWORD numread = 128;
	DWORD numEvents = 0;

	GetNumberOfConsoleInputEvents(_handle, &numEvents);
	if (!numEvents)
		return false;
	if (!ReadConsoleInput(
		_handle,      // input buffer handle
		_record,     // buffer to read into
		128,         // size of read buffer
		&numread)) // number of records read 
		return false;

	// Dispatch the events to the appropriate handler.

	for (int i = 0; i < numread; i++)
	{
		INPUT_RECORD event = _record[i];
		switch (event.EventType)
		{
		case KEY_EVENT: // keyboard input
			if (event.Event.KeyEvent.bKeyDown && event.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
			{
				_eventManager.handleJump();
				return true;
			}
			return false;
			
		case MOUSE_EVENT: // mouse input
			if (event.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				_eventManager.handleJump();
				return true;
			}
			return false;
		default:
			return false;
		}
	}
}
