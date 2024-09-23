// ASCII-Dash-Project.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "ConsoleManager.hpp"
#include "ConsoleBuffer.hpp"
#include <iostream>
#include <Spike.h>
#include "Bloc.h"
#include "Object.hpp"
#include "InputManager.hpp"
#include "NYTimer.hpp"
#include "Level.h"

void SamuelMain()
{
    ConsoleManager console;
    ConsoleBuffer buffer;
    buffer.ClearConsoleBuffer();
    Sleep(10000);

}

void EduardMain()
{

}

int main()
{
    system("mode 650");
    SamuelMain();
   // EduardMain();
    return 0;
}