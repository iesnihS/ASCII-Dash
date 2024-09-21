// ASCII-Dash-Project.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "ConsoleManager.hpp"
#include "ConsoleBuffer.hpp"
#include <iostream>
#include <Spike.h>
#include "Object.hpp"
#include "InputManager.hpp"
#include "EventManager.hpp"
#include "NYTimer.hpp"

void SamuelMain()
{
    ConsoleManager console;
    ConsoleBuffer buffer;
    Spike obj;
    buffer.DrawSprite({ 0,0 }, obj);
    buffer.Blit();
    Sleep(10000);
}

void EduardMain()
{

}

int main()
{
    SamuelMain();
   // EduardMain();
    return 0;
}