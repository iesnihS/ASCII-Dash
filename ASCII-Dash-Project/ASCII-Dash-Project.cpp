// ASCII-Dash-Project.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "ConsoleManager.hpp"
#include "ConsoleBuffer.hpp"
#include <iostream>
#include <Object.h>
int main()
{
    ConsoleManager console;
    ConsoleBuffer buffer;
    Object obj;

    buffer.DrawSprite({ 0,0 }, &obj);

    buffer.Blit();
    Sleep(10000);
    return 0;
}