#pragma once
#include <Windows.h>

int Convert2DArrayCoordTo1DArrayCoord(int const& x, int const& y, int const& maxArrayWidth);
int* Convert1DArrayCoordTo2DArrayCoord(int const& x, int const& maxArrayWidth, int const& maxArrayHeight);
COORD Convert1DArrayCoordTo2DArrayCoord(short const& x, int const& maxArrayWidth, int const& maxArrayHeight);