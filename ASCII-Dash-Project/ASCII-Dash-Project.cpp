// ASCII-Dash-Project.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "ConsoleManager.hpp"
#include "ConsoleBuffer.hpp"
#include <iostream>
#include <Spike.h>
#include "Bloc.h"
#include "Object.hpp"
#include "InputManager.hpp"
#include "EventManager.hpp"
#include "NYTimer.hpp"
#include "Level.h"
#include "LevelManager.h"

void SamuelMain()
{
    ConsoleManager console;
    ConsoleBuffer buffer;
    LevelManager levelManager;
    Spike obj({ 0,0 });
    Bloc bloc({20,20});

    Object* objs = new Object[2];
    objs[0] = obj;
    objs[1] = bloc;

    Level level(objs, 2);
    buffer.DrawLevelAtIndex(level, 0);
    buffer.Blit();
    Sleep(10000);

    for (int i = 0; i < 2; i++)
    {
        delete &objs[i];  // Properly delete each object (virtual destructor will be called)
    }
    delete objs;
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