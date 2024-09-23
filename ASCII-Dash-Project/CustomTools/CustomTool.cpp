#include <CustomTool.h>
#include <math.h>
#include <iostream>

int Convert2DArrayCoordTo1DArrayCoord(int const & x, int const & y, int const & maxArrayWidth)
{
	return x + (y * (maxArrayWidth));
}

int* Convert1DArrayCoordTo2DArrayCoord(int const & x, int const& maxArrayWidth, int const& maxArrayHeight)
{
	int yCoord = ceil(x / (double)maxArrayWidth);
	int xCoord = x - (yCoord * maxArrayHeight);
	int coord[] = { xCoord, yCoord };
	return coord;
}

COORD Convert1DArrayCoordTo2DArrayCoord(short const& x, int const& maxArrayWidth, int const& maxArrayHeight)
{
	short yCoord = ceil(x / (double)maxArrayWidth);
	short xCoord = x - (yCoord * maxArrayHeight);
	return { xCoord, yCoord };
}