#pragma once
#include "Level.h"
class LevelManager
{
public:
    LevelManager();
    Level GetCurrentLevel();
    ~LevelManager();
private:
    Level _currentLevel;
    Level* _allLevels;
    int _indexLevel = 0;
    int _numberOfLevel = 0;
};

