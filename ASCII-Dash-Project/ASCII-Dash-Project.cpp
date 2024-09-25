// ASCII-Dash-Project.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "ConsoleManager.hpp"
#include "ConsoleBuffer.hpp"
#include <iostream>
#include <Spike.h>
#include "Bloc.h"
#include "Object.hpp"
#include "InputManager.hpp"
#include "NYTimer.hpp"
#include "LevelManager.hpp"

int main()
{
    //system("mode 650");
    ConsoleManager console;
    ConsoleBuffer buffer;
    Spike spike({ 20,0 });
    Bloc bloc({ 20,20 });
    Player player;


    Object* objs = new Object[3];
    objs[0] = Object();
    objs[SpikeEntity] = spike;
    objs[BlockEntity] = bloc;

    LevelManager level(player, buffer);
    while (true) {
        level.Update();
    }
    return 0;
}