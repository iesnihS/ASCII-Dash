#include "LevelManager.h"
#include "Bloc.h";

LevelManager::LevelManager()
{
   _numberOfLevel = 1;
    _allLevels = new Level[1];
    _indexLevel = 0;

   Bloc bloc1({ 0,0 });
   Object objs[1];
   objs[0] = bloc1;

   //Level level1(objs, 1);
}
LevelManager::~LevelManager()
{
    delete _allLevels;
}
Level LevelManager::GetCurrentLevel()
{
    return _allLevels[_indexLevel];
}