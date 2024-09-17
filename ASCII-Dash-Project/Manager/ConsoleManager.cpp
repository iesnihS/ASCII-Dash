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
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLongPtr(consoleWindow, n_index, currentStyles);
    SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_DRAWFRAME);
    ShowWindow(consoleWindow, SW_SHOW);
}