#pragma once
#ifndef __NY_TIMER__
#define __NY_TIMER__

#include <windows.h>

class NYTimer
{
public:
	LARGE_INTEGER lastUpdateTime;
	LONGLONG freq;

	NYTimer();

	void start(void);

	float getElapsedSeconds(bool restart = false);

	unsigned long getElapsedMs(bool restart = false);
};

#endif