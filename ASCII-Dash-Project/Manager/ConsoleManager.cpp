#include "ConsoleManager.hpp"
#include <iostream>
#include <stdio.h>
#include <windows.h>

ConsoleManager::ConsoleManager()
{
    FormatConsole();
}

void ConsoleManager::FormatConsole()
{
    int n_index = GWL_STYLE;
    LONG_PTR currentStyles = WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL;
    _windowHandle = GetConsoleWindow();
    SetWindowLongPtr(_windowHandle, n_index, currentStyles);
    SetWindowPos(_windowHandle, 0, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_DRAWFRAME);
    ShowWindow(_windowHandle, SW_SHOW);
}