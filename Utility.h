#pragma once
#ifndef DEF_UTILITY
#define DEF_UTILITY
#include <cstring>

class Utility
{
	public:
		static void clamp(int* valueAddr, int val, int min, int max);
};

#endif // !* DEF_UTILITY

