// ASCII-Dash-Project.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "ConsoleManager.hpp"
#include "ConsoleBuffer.hpp"
#include <iostream>
<<<<<<< HEAD
#include <Spike.h>
=======
#include "Object.hpp"
#include "InputManager.hpp"
#include "EventManager.hpp"
#include "NYTimer.hpp"

>>>>>>> f522dfaf685e4345355315c0c97cdba720d9f12a
int main()
{
    ConsoleManager console;
    ConsoleBuffer buffer;
<<<<<<< HEAD
    Spike obj;

    buffer.DrawSprite({ 0,0 }, obj);
    buffer.Blit();
    Sleep(10000);   
=======
    Player player;
    EventManager event(player);
    InputManager input(event);
    NYTimer timer;
    Object obj;

    buffer.DrawSprite({ 0,0 }, &obj);

    while (true) {
        input.PollEvent();
        buffer.Blit();
    }

>>>>>>> f522dfaf685e4345355315c0c97cdba720d9f12a
    return 0;
}