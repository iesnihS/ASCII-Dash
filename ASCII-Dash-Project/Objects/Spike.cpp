#include "Spike.h"
#include "iostream"
Spike::Spike(COORD coord, bool reverse) : Object(coord, 
		"\1\1\1\1\1\1\1\1\1Y7&\1\1\1\1\1\1\1\1"
		"\1\1\1\1\1\1\1\1Y5G7&\1\1\1\1\1\1\1"
		"\1\1\1\1\1\1\1Y5@@B7#\1\1\1\1\1\1"
		"\1\1\1\1\1\1JP@@@@#7B\1\1\1\1\1"
		"\1\1\1\1\1JG@@@@@@#7G\1\1\1\1"
		"\1\1\1\1?P&&&&&&&&B!P\1\1\1"
		"\1\1&?P#####&####G!5\1\1"
		"\1#7JGBBBBBBBBBBG5~Y\1"
	"	&!^!???????????7!~:Y" , 
	{ 20,0 }, 0x0001, reverse)
{
}