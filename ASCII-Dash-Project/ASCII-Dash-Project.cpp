// ASCII-Dash-Project.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "ConsoleManager.hpp"
#include "ConsoleBuffer.hpp"
#include <iostream>
#include <Spike.h>
#include "Object.hpp"
#include "InputManager.hpp"
#include "EventManager.hpp"
#include "NYTimer.hpp"
#include "Level.h"

void SamuelMain()
{
    GameManager gm;
    std::srand(std::time(nullptr));
    ConsoleManager console;
    ConsoleBuffer buffer(gm);
    NYTimer nytimer;
    NYTimer score;

    Level level(std::deque<Object>(0));
    
    Player player;
    EventManager eventManager(player);
    InputManager inputManager(eventManager);
    float deltaTime = 0;

    while (!gm._gameFinished)
    {
        inputManager.PollEvent();
        deltaTime = nytimer.getElapsedSeconds(true);
        player.MovePlayer(deltaTime);
        level.UpdateLevel(deltaTime);


        buffer.ClearBuffer();
        player.DisplayPlayer(buffer);
        level.DisplaySprite(buffer);
        buffer.Blit();
    }
    buffer.ClearBuffer();
    buffer.Blit();
    std::cout << "GAME OVER" << std::endl;
    std::cout << "SCORE : " << score.getElapsedSeconds() << std::endl;
    Sleep(200);
}

int main()
{
    SamuelMain();
   // EduardMain();
    return 0;
}