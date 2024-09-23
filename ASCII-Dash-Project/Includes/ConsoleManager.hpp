#pragma once
#include <Windows.h>
class ConsoleManager
{
public:
    ConsoleManager();
    HWND _windowHandle;

private:
    void FormatConsole();
};