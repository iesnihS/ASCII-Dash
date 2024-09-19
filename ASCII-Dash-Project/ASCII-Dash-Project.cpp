// ASCII-Dash-Project.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "ConsoleManager.hpp"
#include "ConsoleBuffer.hpp"
#include <iostream>
#include "Object.hpp"
#include "InputManager.hpp"
#include "EventManager.hpp"
#include "NYTimer.hpp"

int main()
{
    ConsoleManager console;
    ConsoleBuffer buffer;
    Player player;
    EventManager event(player);
    InputManager input(event);
    NYTimer timer;

    while (true) {
        input.PollEvent();
        buffer.Blit();
    }

    return 0;
}